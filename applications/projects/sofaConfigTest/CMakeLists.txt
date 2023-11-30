cmake_minimum_required(VERSION 3.12)
project(sofaConfigTest)

sofa_find_package(Sofa.Config REQUIRED)

add_executable(${PROJECT_NAME} sofaConfigTest.cpp)
target_link_libraries(${PROJECT_NAME} Sofa.Config  )
