# 用这种方式来寻找max.h的具体目录，这样可以防止直接写死路径
#FIND_PATH(maxHpp max.h)
#IF(maxHpp)
#    include_directories(${maxHpp})
#ENDIF(maxHpp)

# 添加可执行文件,
# add_subdirectory(lib)

include_directories("asio-1.18.1/include")
set(CMAKE_MODULE_PATH  ${PROJECT_SOURCE_DIR}/cmake)
#find_package(MAX)
#if (MAX_FOUND)
#    add_executable(hello main.cpp)
#    include_directories(${MAX_INCLUDE_DIR})
#    TARGET_LINK_LIBRARIES(hello ${MAX_LIBRARY})
#else (MAX_FOUND)
#    message(status "don't found")
#    add_executable(hello main.cpp)
#endif(MAX_FOUND)

add_executable(hello main.cpp)
# cmake会自己找到对应的库，估计是按照max这个名字去寻找的libmax.so的库文件，在lib下面存在，并且自己分析得到对应的库文件
#target_link_libraries(hello max)

