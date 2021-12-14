cmake_minimum_required(VERSION 3.0)

# C++ std 14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-no-pie")

project(BkavAI)

#OpenCV
set(OpenCV_DIR ${CMAKE_SOURCE_DIR}/local)
find_package(OpenCV REQUIRED HINTS ${OpenCV_DIR})
#find_package(OpenCV REQUIRED)

#Libevent
set(LIBEVENT_LIBS "-levent")
find_library(EVENT_LIBRARY REQUIRED PATHS /usr/lib /usr/local/lib)

#OpenGL 
find_package(OpenGL REQUIRED)

#glfw3
set(glfw3_LIBS "-lglfw" )
find_package(glfw3 REQUIRED) 

#GLUT 
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})

#Setup
include_directories(glad/include)
file(GLOB SOURCES 
		src/*.cpp 
		glad/src/*.c
		src/Config/*.h
		src/EventManager/*.cpp
		src/Processor/*.cpp
		src/Processor/LoadProcessor/*.cpp
		src/Processor/ObjectManager/*.cpp
		src/Processor/ProfileManager/*.cpp
		src/Protocol/*.cpp
		src/Render/*.cpp
		src/Render/MJPEG/*.cpp
		src/Render/OpenCV/*.cpp
		src/Render/OpenGL/*.cpp

)
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    ${OpenCV_LIBS}
    ${LIBEVENT_LIBS}
    ${OPENGL_LIBRARY}
    ${glfw3_LIBS}
    ${GLUT_LIBRARY}
    -lpthread
    -lGL
    -ldl 
)

