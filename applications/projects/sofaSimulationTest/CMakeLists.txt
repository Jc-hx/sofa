cmake_minimum_required(VERSION 3.12)
project(sofaSimulationTest)

sofa_find_package(Sofa.Config REQUIRED)
sofa_find_package(Sofa.Type REQUIRED)
sofa_find_package(Sofa.Geometry REQUIRED)
sofa_find_package(Sofa.Topology REQUIRED)
sofa_find_package(Sofa.Helper REQUIRED)
sofa_find_package(Sofa.LinearAlgebra REQUIRED)
sofa_find_package(Sofa.DefaultType REQUIRED)
sofa_find_package(Sofa.Core REQUIRED)
sofa_find_package(Sofa.Framework REQUIRED)
sofa_find_package(Sofa.Simulation REQUIRED)

## Emscripten-specific
if(CMAKE_CXX_COMPILER MATCHES "em\\+\\+")

set(CMAKE_EXE_LINKER_FLAGS_INIT "-s WASM=0")
set(CMAKE_EXECUTABLE_SUFFIX ".html")

endif()

add_executable(${PROJECT_NAME} sofaSimulationTest.cpp)
target_link_libraries(${PROJECT_NAME} Sofa.Config Sofa.Type Sofa.Geometry Sofa.Topology Sofa.Helper Sofa.LinearAlgebra Sofa.DefaultType Sofa.Core Sofa.Framework Sofa.Simulation )
