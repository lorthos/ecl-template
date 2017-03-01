#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.6)
project(ecl_template)

# Enable debug symbols by default
#if(CMAKE_BUILD_TYPE STREQUAL "")
#    set(CMAKE_BUILD_TYPE Debug)
#endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") # -DSFML_STATIC")

# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

# Define sources and executable
set(EXECUTABLE_NAME "ecl_template")

set(SOURCE_FILES
        src/ecltemplate/cpp/main.cpp
        src/ecltemplate/cpp/ui.h
        src/ecltemplate/cpp/ui.cpp
        src/ecltemplate/cpp/bob.h src/ecltemplate/cpp/bob.cpp src/ecltemplate/cpp/engine.h src/ecltemplate/cpp/engine.cpp src/ecltemplate/cpp/input.cpp src/ecltemplate/cpp/update.cpp src/ecltemplate/cpp/draw.cpp)

add_executable(ecl_template ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

# Detect and add SFML
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
#set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2 REQUIRED system window graphics audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

# Detect and add BOX2D
find_package(ECL REQUIRED)
if(ECL_FOUND)
    include_directories(${ECL_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${ECL_LIBRARY})
endif()

if(APPLE)
    SET(CMAKE_EXE_LINKER_FLAGS "-framework Foundation -w")
endif()

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

