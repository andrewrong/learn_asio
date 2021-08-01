# 项目的名字
PROJECT(HELLO)

# 规定cmake的最小版本号的要求
cmake_minimum_required(VERSION 3.17)

add_definitions(-DASIO_STANDALONE)
add_definitions(-DASIO_HAS_STD_ADDRESSOF)
add_definitions(-DASIO_HAS_STD_ARRAY)
add_definitions(-DASIO_HAS_CSTDINT)
add_definitions(-DASIO_HAS_STD_SHARED_PTR)
add_definitions(-DASIO_HAS_STD_TYPE_TRAITS)
add_definitions(-DASIO_HAS_VARIADIC_TEMPLATES)
add_definitions(-DASIO_HAS_STD_FUNCTION)
add_definitions(-DASIO_HAS_STD_CHRONO)
add_definitions(-DBOOST_ALL_NO_LIB)
add_definitions(-D_WIN32_WINNT=0x0501)
add_definitions(-D_WINSOCK_DEPRECATED_NO_WARNINGS)

# 设置C++编译器的一些参数
set(CMAKE_CXX_FLAGS "-std=c++11")

# 设置一个变量;
SET(SRC_LIST src/main.cpp)



# cmake中用来打印输出使用，message命令还是很好用的
MESSAGE(STATUS "This is Binary dir " ${PROJECT_BINARY_DIR})
MESSAGE(STATUS "This is Source dir " ${PROJECT_SOURCE_DIR})
MESSAGE(STATUS "This is module dir " ${CMAKE_MODULE_PATH})

#将最后的二进制文件输出到指定目录，这是可以规定输出路径
#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#将最后的库文件输出到指定目录，这是可以规定输出路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_subdirectory(src bin)

install(CODE "message (\"sample install message\")")
# install指令用于make install的时候使用，要安装哪些文件和对应的输出目的点
install(TARGETS hello
        RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
        ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/libstatic
        )
# 将非目标的可执行文件安装到指定目录
install(PROGRAMS runhello.sh DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
# 将普通文件安装到指定目录
install(FILES COPYRIGHT README.md DESTINATION ${CMAKE_INSTALL_PREFIX}/doc)
# 将某一个目录下面的文件安装到指定目录
install(DIRECTORY doc/ DESTINATION ${CMAKE_INSTALL_PREFIX}/doc)
