
find_package(glfw3 CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(GLEW REQUIRED)

add_library(blue2d Blue2D.cpp Blue2D.h Display.h Display.cpp)
target_link_libraries(blue2d PUBLIC glfw spdlog::spdlog imgui::imgui GLEW::GLEW)

#target_compile_features(blue2d PUBLIC std_cxx_${CMAKE_CXX_STANDARD})