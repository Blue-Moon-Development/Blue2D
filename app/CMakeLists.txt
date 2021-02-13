
add_executable(app main.cpp)
#target_compile_features(app PRIVATE std_cxx_${CMAKE_CXX_STANDARD})
target_link_libraries(app PRIVATE blue2d)
target_include_directories(app PRIVATE "../")