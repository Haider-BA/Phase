add_executable(phasePoisson phasePoisson.cpp)
target_link_libraries(phasePoisson System FiniteVolumeGrid2D Viewers Solvers)

add_executable(phasePiso phasePiso.cpp)
target_link_libraries(phasePiso System FiniteVolumeGrid2D Viewers Solvers)

add_executable(phasePisoMultiphase phasePisoMultiphase.cpp)
target_link_libraries(phasePisoMultiphase System FiniteVolumeGrid2D Viewers Multiphase)

add_executable(phaseCoupled phaseCoupled.cpp)
target_link_libraries(phaseCoupled System FiniteVolumeGrid2D Viewers Coupled)

add_executable(phaseFractionalStep phaseFractionalStep.cpp)
target_link_libraries(phaseFractionalStep System FiniteVolumeGrid2D Viewers Solvers)

add_executable(phaseFractionalStepMultiphase phaseFractionalStepMultiphase.cpp)
target_link_libraries(phaseFractionalStepMultiphase System FiniteVolumeGrid2D Viewers Multiphase)

add_executable(phasePartitionTest phasePartitionTest.cpp)
target_link_libraries(phasePartitionTest System FiniteVolumeGrid2D Viewers Communicator)
