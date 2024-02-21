cmake_minimum_required(VERSION 3.12)
project(sofaCompatTest)

sofa_find_package(Sofa.Config REQUIRED)
sofa_find_package(Sofa.Type REQUIRED)
sofa_find_package(Sofa.Geometry REQUIRED)
sofa_find_package(Sofa.Topology REQUIRED)
sofa_find_package(Sofa.LinearAlgebra REQUIRED)

## Emscripten-specific
if(CMAKE_CXX_COMPILER MATCHES "em\\+\\+")

set(CMAKE_EXE_LINKER_FLAGS_INIT "-s WASM=0")
set(CMAKE_EXECUTABLE_SUFFIX ".html")

endif()

add_executable(${PROJECT_NAME} sofaCompatTest.cpp)
target_link_libraries(${PROJECT_NAME} Sofa.Config Sofa.Type Sofa.Geometry Sofa.Topology Sofa.LinearAlgebra )
