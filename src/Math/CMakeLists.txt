set(HEADERS Matrix.h
            SparseMatrix.h
            SparseVector.h
            BisectionSearch.h
            SecantSearch.h
            BilinearInterpolation.h)

set(SOURCES Matrix.cpp
            SparseMatrix.cpp
            SparseVector.cpp
            BisectionSearch.cpp
            SecantSearch.cpp
            BilinearInterpolation.cpp)

add_library(Math ${HEADERS} ${SOURCES})
target_link_libraries(Math lapacke lapack openblas)
