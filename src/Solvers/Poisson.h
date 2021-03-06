#ifndef POISSON_H
#define POISSON_H

#include "Solver.h"
#include "Equation.h"

class Poisson : public Solver
{
public:

    Poisson(const Input& input, FiniteVolumeGrid2D& grid);
    virtual Scalar solve(Scalar timeStep);
    virtual Scalar computeMaxTimeStep(Scalar maxCo, Scalar prevTimeStep) const { return INFINITY; }

    ScalarFiniteVolumeField& phi, &gamma;

protected:

    Equation<ScalarFiniteVolumeField> phiEqn_;

};

#endif
