cmake_minimum_required(VERSION 2.8)
find_package( OpenCV REQUIRED )

set(source ./OrthogonalMatchingPursuit.cc)
add_executable(omp.out ${source})
target_link_libraries(omp.out ${OpenCV_LIBS})
