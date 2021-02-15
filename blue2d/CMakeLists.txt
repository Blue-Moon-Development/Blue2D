
find_package(glfw3 CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm CONFIG REQUIRED)

add_library(blue2d Blue2D.cpp Blue2D.h Display.h Display.cpp Shader.cpp Shader.h Bindable.h Common.h Util.cpp Util.h Log.cpp Log.h MsgBox.cpp MsgBox.h BlueException.cpp BlueException.h Mesh.cpp Mesh.h Vertex.h)
target_link_libraries(blue2d PUBLIC glfw spdlog::spdlog imgui::imgui GLEW::GLEW glm)
target_precompile_headers(blue2d
        PUBLIC
            Common.h
            Log.h
        PRIVATE
            <string>
            <utility>
            <memory>
            <iostream>
            <fstream>
            <sstream>
            <map>
            <vector>
            <unordered_map>
            <array>
            <algorithm>
            <cmath>
            <cstdint>
            <functional>
            <random>
            <list>
            <set>
            <unordered_set>
            <optional>
            <variant>
            <iomanip>
            <queue>
            <cstdio>
            <cassert>
            <cerrno>
            <cstdint>
            )


#target_compile_features(blue2d PUBLIC std_cxx_${CMAKE_CXX_STANDARD})