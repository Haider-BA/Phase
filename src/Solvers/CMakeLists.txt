set(HEADERS Solver.h
            Poisson.h
            Piso.h
            FractionalStep.h)

set(SOURCES Solver.cpp
            Poisson.cpp
            Piso.cpp
            FractionalStep.cpp)

add_subdirectory(Multiphase)
add_subdirectory(Coupled)

add_library(Solvers ${HEADERS} ${SOURCES})
target_link_libraries(Solvers Discretization ImmersedBoundary Utilities)
