#set(LIB_SRC_LIST max.cpp)
aux_source_directory(. LIB_SRC_LIST)
# 添加库文件
add_library(max SHARED ${LIB_SRC_LIST})
# 静态库文件
add_library(static_max STATIC ${LIB_SRC_LIST})
# add_library本身不能有相同的targetname，通过这条语句可以在输出的时候进行修改
set_target_properties(static_max PROPERTIES OUTPUT_NAME max)
# 动态连接库版本的设置 version表示库版本 soversion表示api版本
set_target_properties(max PROPERTIES VERSION 1.2 SOVERSION 1)

# 安装库文件
install(FILES max.h DESTINATION include/max)
install(TARGETS max static_max
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        )
message(STATUS 'my cmakefile.txt path ' ${CMAKE_CURRENT_BINARY_DIR})