
cmake_minimum_required(VERSION 3.5)

project (instantclientConnect LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

link_directories(D:/devtools/instantclient.21.12/sdk/lib/msvc)

aux_source_directory(src SRC)

add_executable( ${PROJECT_NAME}
                ${SRC}
            )

# if(MSVC)
#     target_compile_options(${PROJECT_NAME} PUBLIC "/Zc:__cplusplus") // 这个设置会让__cplusplus值变为201402
# endif()

INCLUDE_DIRECTORIES(${log4cplus_INCLUDE_DIRS} D:/devtools/instantclient.21.12/sdk/include)
# TARGET_LINK_LIBRARIES(${PROJECT_NAME} PRIVATE oraocci21)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} PUBLIC oraocci21)

