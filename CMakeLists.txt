cmake_minimum_required(VERSION 3.10)
project(jsruntime LANGUAGES CXX)
#find package
find_package(rapidjson REQUIRED)
find_package(libuv REQUIRED)

#find v8 
#INSTALL v8 
find_program(NUGET nuget)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/nuget.exe
    DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/build/tools
)
execute_process(COMMAND
${CMAKE_CURRENT_SOURCE_DIR}/build/tools/nuget.exe install v8-v143-x64 -OutputDirectory  ${CMAKE_CURRENT_SOURCE_DIR}/build/packages
)
set(HEADER_V8_PATH  ${CMAKE_CURRENT_SOURCE_DIR}/build/packages/v8-v143-x64.11.9.169.4/include)
set(LIB_V8_PATH_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/build/packages/v8-v143-x64.11.9.169.4/lib/Release)
set(LIB_V8_PATH_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/build/packages/v8-v143-x64.11.9.169.4/lib/Debug)

add_executable(longjs src/main.cpp)

#include 
target_include_directories(longjs 
    PRIVATE ${HEADER_V8_PATH}
)

target_link_libraries(longjs PRIVATE rapidjson
                        PRIVATE libuv::uv
                        debug ${LIB_V8_PATH_DEBUG}/third_party_zlib.dll.lib
                        debug ${LIB_V8_PATH_DEBUG}/v8.dll.lib
                        debug ${LIB_V8_PATH_DEBUG}/v8_libbase.dll.lib
                        debug ${LIB_V8_PATH_DEBUG}/v8_libplatform.dll.lib
                        debug ${LIB_V8_PATH_DEBUG}/third_party_abseil-cpp_absl.dll.lib
                        debug ${LIB_V8_PATH_DEBUG}/third_party_icu_icui18n.dll.lib
                        optimized ${LIB_V8_PATH_RELEASE}/third_party_icu_icui18n.dll.lib
                        optimized ${LIB_V8_PATH_RELEASE}/third_party_zlib.dll.lib
                        optimized ${LIB_V8_PATH_RELEASE}/v8.dll.lib
                        optimized ${LIB_V8_PATH_RELEASE}/v8_libbase.dll.lib
                        optimized ${LIB_V8_PATH_RELEASE}/v8_libplatform.dll.lib
                        optimized ${LIB_V8_PATH_RELEASE}/third_party_abseil-cpp_absl.dll.lib
)

add_compile_definitions(V8_COMPRESS_POINTERS)
add_compile_definitions(V8_ENABLE_SANDBOX)
