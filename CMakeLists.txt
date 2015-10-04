cmake_minimum_required(VERSION 2.7)

project(raytracer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(PROJECT_TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)
set(PROJECT_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(PROJECT_LIBRARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(PROJECT_BART_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/bart)

add_subdirectory(${PROJECT_SOURCE_DIR} ${PROJECT_BINARY_DIR})

include_directories(${PROJECT_SOURCE_DIR} ${PROJECT_LIBRARY_DIR} ${PROJECT_TEST_DIR})

set(SOURCE_FILES
        src/main.cpp
        src/Scene.h
        src/Definition.h src/Viewpoint.h src/Scene.cpp
        ${PROJECT_BART_DIR}/animation.c
        ${PROJECT_BART_DIR}/animation.h
        ${PROJECT_BART_DIR}/kbsplpos.c
        ${PROJECT_BART_DIR}/kbsplpos.h
        ${PROJECT_BART_DIR}/kbsplrot.c
        ${PROJECT_BART_DIR}/kbsplrot.h
        ${PROJECT_BART_DIR}/parse.cpp
        ${PROJECT_BART_DIR}/parse.h
        ${PROJECT_BART_DIR}/quat.c
        ${PROJECT_BART_DIR}/quat.h
        ${PROJECT_LIBRARY_DIR}/catch.hpp
        src/Vector.h
        src/Point.h
        src/Color.cpp
        src/Color.h
        src/Light.cpp
        src/Light.h
        src/Material.cpp
        src/Material.h
        src/Primitive.cpp
        src/Primitive.h
        src/Planes.cpp
        src/Planes.h
        src/Solids.cpp
        src/Solids.h
        src/Point.cpp
        src/Vector.cpp
        src/VPBase.cpp
        src/VPBase.h
        src/Texture.cpp
        src/Texture.h
        src/TriangleMesh.cpp
        src/TriangleMesh.h
        src/Utils.h
        src/Utils.cpp
        src/PrimColle.cpp
        src/PrimColle.h
        src/Screen.cpp
        src/Screen.h
        src/BoundingVolume.cpp
        src/BoundingVolume.h
        src/Ray.cpp src/Ray.h
        src/Matrix.cpp
        src/Matrix.h
        src/Tree.cpp
        src/Tree.h
        src/KDTree.cpp
        src/KDTree.h
        test/Utils_tests.cpp)

add_executable(raytracer ${SOURCE_FILES})

# set(EXECUTABLE_OUTPUT_PATH ~/Desktop)
# set_target_properties(raytracer PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_BINARY_DIR})

install (TARGETS raytracer DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)