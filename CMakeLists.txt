cmake_minimum_required(VERSION 3.10)

project(cy_pan VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE "Debug")

# 对应qt pro 需要依赖的qt库
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Network Widgets REQUIRED)

include_directories(include/view/)
include_directories(include/common/)
include_directories(include/service/)
include_directories(include/thirdparty/)
include_directories(${PROJECT_BINARY_DIR})

# 查找.ui文件的路径
set(CMAKE_AUTOUIC_SEARCH_PATHS
    ./resource/ui/
)

FILE(GLOB_RECURSE QT_UI_LIST "resource/ui/*.ui")
message(STATUS "QT_UI_LIST = ${QT_UI_LIST}")
FILE(GLOB_RECURSE QT_HEADER_LIST CMAKE_CONFIGURE_DEPENDS "include/*.h")
message(STATUS "QT_HEADER_LIST = ${QT_HEADER_LIST}")
FILE(GLOB_RECURSE QT_SOURCE_LIST CMAKE_CONFIGURE_DEPENDS "src/*.cpp")
message(STATUS "QT_SOURCE_LIST =  ${QT_SOURCE_LIST}")

set(PROJECT_SOURCES
    main.cpp
)
add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
    ${QT_UI_LIST}  # 这里需要手动把UI文件对应的文件 也放到这里
    ${QT_HEADER_LIST}
    ${QT_SOURCE_LIST} 
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt6::Network)

# 部署应用程序
execute_process(COMMAND windeployqt.exe ${CMAKE_SOURCE_DIR}/build/cy_pan.exe)

# 单元测试使用
enable_testing()
add_subdirectory(test)