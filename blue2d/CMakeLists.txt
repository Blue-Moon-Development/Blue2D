
find_package(glfw3 CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

add_library(blue2d Blue2D.cpp Blue2D.h)
target_link_libraries(blue2d PUBLIC glfw spdlog::spdlog imgui::imgui)

#target_compile_features(blue2d PUBLIC std_cxx_${CMAKE_CXX_STANDARD})