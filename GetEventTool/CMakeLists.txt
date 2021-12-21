cmake_minimum_required(VERSION 3.0)

# C++ std 14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-no-pie")

project(Get_Event_Tool)

#OpenCV
set(OpenCV_DIR ${CMAKE_SOURCE_DIR}/local)
find_package(OpenCV REQUIRED HINTS ${OpenCV_DIR})
#find_package(OpenCV REQUIRED)
 
# Curl lib
#set(CURL_LIBS "-lcurl") 
#find_package(CURL REQUIRED)

#libCURL
set(curl libcurl.so)
link_directories(${CMAKE_SOURCE_DIR}/libcurl/lib)
include_directories(${CMAKE_SOURCE_DIR}/libcurl/include)
include_directories(${CMAKE_SOURCE_DIR}/src)
#Setup
file(GLOB SOURCES src/*.cpp )
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    ${OpenCV_LIBS}
#    ${CURL_LIBS}
#    ${LIBEVENT_LIBS}
	${curl}
    -lpthread
)

