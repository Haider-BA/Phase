#ifndef IMMERSED_BOUNDARY_H
#define IMMERSED_BOUNDARY_H

#include "ImmersedBoundaryObject.h"

class Solver;

class ImmersedBoundary
{
public:

    enum {SOLID = 1, FLUID = 2, IB = 3};

    ImmersedBoundary(const Input& input, Solver &solver);

    Equation<ScalarFiniteVolumeField> eqns(ScalarFiniteVolumeField& field);

    Equation<VectorFiniteVolumeField> eqns(VectorFiniteVolumeField& field);
    Equation<VectorFiniteVolumeField> eqns(const ScalarFiniteVolumeField& rho, VectorFiniteVolumeField& field);

    const std::vector<ImmersedBoundaryObject>& ibObjs() const { return ibObjs_; }

    bool isIbCell(const Cell& cell) const;

    ScalarFiniteVolumeField &cellStatus_;

protected:

    void setCellStatus();

    const Solver &solver_;
    std::vector<ImmersedBoundaryObject> ibObjs_;

};

#endif
