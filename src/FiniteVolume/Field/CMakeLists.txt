set(HEADERS Field.h
            FiniteVolumeField.h
            ScalarFiniteVolumeField.h
            VectorFiniteVolumeField.h
            TensorFiniteVolumeField.h)

set(SOURCES Field.tpp
            FiniteVolumeField.tpp
            ScalarFiniteVolumeField.cpp
            VectorFiniteVolumeField.cpp
            TensorFiniteVolumeField.cpp)

add_library(Field ${HEADERS} ${SOURCES})
target_link_libraries(Field Geometry FiniteVolumeGrid2D)
