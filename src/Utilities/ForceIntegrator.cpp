#include <boost/algorithm/string.hpp>

#include "ForceIntegrator.h"

//- Public static functions

std::vector<ForceIntegrator> ForceIntegrator::initForceIntegrators(const Input &input,
                                                                   const ScalarFiniteVolumeField &p,
                                                                   const ScalarFiniteVolumeField &mu,
                                                                   const VectorFiniteVolumeField &u)
{
    if(input.caseInput().count("Integrators") == 0)
        return std::vector<ForceIntegrator>();

    std::vector<ForceIntegrator> forceIntegrators;

    std::string patchInput = input.caseInput().get<std::string>("Integrators.ForceIntegrators.patches");
    std::vector<std::string> patchNames;

    boost::split(patchNames, patchInput, boost::is_any_of(", "), boost::token_compress_on);

    for(const std::string& patchName: patchNames)
    {
        printf("Initializing a force integrator on patch \"%s\".\n", patchName.c_str());

        forceIntegrators.push_back(
                    ForceIntegrator(p.grid.patches().find(patchName)->second, p, mu, u)
                    );
    }

    return forceIntegrators;
}

// Constructors
ForceIntegrator::ForceIntegrator(const Patch &patch,
                                 const ScalarFiniteVolumeField &p,
                                 const ScalarFiniteVolumeField &mu,
                                 const VectorFiniteVolumeField &u)
    :
      patch_(patch),
      p_(p),
      mu_(mu),
      u_(u)
{

}

Vector2D ForceIntegrator::integrate() const
{
    Vector2D fn = Vector2D(0., 0.), ft = Vector2D(0., 0.);

    for(const Face &face: patch_.faces())
    {
        const Cell &cell = face.lCell();
        const Vector2D sfn = face.outwardNorm(cell.centroid());
        const Vector2D sft = -sfn.tangentVec();

        fn += p_(face)*sfn;
        ft += mu_(cell)*dot(u_(cell) - u_(face), sft.unitVec())*sft;
    }

    printf("Net normal force on patch \"%s\": %s\n", patch_.name.c_str(), to_string(fn).c_str());
    printf("Net tangential force on patch \"%s\": %s\n", patch_.name.c_str(), to_string(ft).c_str());
    printf("Net force on patch \"%s\": %s\n", patch_.name.c_str(), to_string(fn + ft).c_str());

    return fn + ft;
}
