cmake_minimum_required(VERSION 3.12)
project(sofaConfigTest)

sofa_find_package(Sofa.Config REQUIRED)

## Emscripten-specific
if(CMAKE_CXX_COMPILER MATCHES "em\\+\\+")

  message(STATUS "em++ compiler: Emscripten - Compilation Config (application)")

  # Locate where the Emscripten compiler resides in relative to this toolchain file.
if ("${EMSCRIPTEN_ROOT_PATH}" STREQUAL "")
  get_filename_component(GUESS_EMSCRIPTEN_ROOT_PATH "~/emsdk/upstream/emscripten/" ABSOLUTE)
  if (EXISTS "${GUESS_EMSCRIPTEN_ROOT_PATH}/emranlib")
    set(EMSCRIPTEN_ROOT_PATH "${GUESS_EMSCRIPTEN_ROOT_PATH}")
  endif()
endif()

# If not found by above search, locate using the EMSCRIPTEN environment variable.
if ("${EMSCRIPTEN_ROOT_PATH}" STREQUAL "")
  set(EMSCRIPTEN_ROOT_PATH "$ENV{EMSCRIPTEN}")
endif()

# Abort if not found.
if ("${EMSCRIPTEN_ROOT_PATH}" STREQUAL "")
  message(FATAL_ERROR "Could not locate the Emscripten compiler toolchain directory! Either set the EMSCRIPTEN environment variable, or pass -DEMSCRIPTEN_ROOT_PATH=xxx to CMake to explicitly specify the location of the compiler!")
endif()

message(STATUS "EMSCRIPTEN_ROOT_PATH is set to: ${EMSCRIPTEN_ROOT_PATH}")

list(APPEND CMAKE_MODULE_PATH "${EMSCRIPTEN_ROOT_PATH}/cmake/Modules")

#Linux
set(EMCC_SUFFIX "")

# Specify the compilers to use for C and C++
set(CMAKE_C_COMPILER "${EMSCRIPTEN_ROOT_PATH}/emcc${EMCC_SUFFIX}")
set(CMAKE_CXX_COMPILER "${EMSCRIPTEN_ROOT_PATH}/em++${EMCC_SUFFIX}")
set(CMAKE_NM "${EMSCRIPTEN_ROOT_PATH}/emnm${EMCC_SUFFIX}")
set(CMAKE_AR "${EMSCRIPTEN_ROOT_PATH}/emar${EMCC_SUFFIX}")
set(CMAKE_RANLIB "${EMSCRIPTEN_ROOT_PATH}/emranlib${EMCC_SUFFIX}")

set(CMAKE_C_COMPILER_AR "${CMAKE_AR}")
set(CMAKE_CXX_COMPILER_AR "${CMAKE_AR}")
set(CMAKE_C_COMPILER_RANLIB "${CMAKE_RANLIB}")
set(CMAKE_CXX_COMPILER_RANLIB "${CMAKE_RANLIB}")

set(CMAKE_EXE_LINKER_FLAGS_INIT "-s WASM=0")
set(CMAKE_EXECUTABLE_SUFFIX ".html")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s SIDE_MODULE=1")

endif()

add_executable(${PROJECT_NAME} sofaConfigTest.cpp)
target_link_libraries(${PROJECT_NAME} Sofa.Config  )
