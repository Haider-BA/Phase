set(HEADERS FiniteVolumeGrid2D.h
            StructuredRectilinearGrid.h
            CgnsUnstructuredGrid.h
            ConstructGrid.h)

set(SOURCES FiniteVolumeGrid2D.cpp
            StructuredRectilinearGrid.cpp
            CgnsUnstructuredGrid.cpp
            ConstructGrid.cpp)

add_subdirectory(Node)
add_subdirectory(Cell)
add_subdirectory(Face)
add_subdirectory(Link)

add_library(FiniteVolumeGrid2D ${HEADERS} ${SOURCES})
target_link_libraries(FiniteVolumeGrid2D System Geometry Cell Face Link Node)
