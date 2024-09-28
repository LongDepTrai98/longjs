cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
project(jsruntime LANGUAGES CXX)
#find package
find_package(rapidjson REQUIRED)
find_package(libuv REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glew REQUIRED) 

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
message(${HEADER_V8_PATH})
set(LIB_V8_PATH_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/build/packages/v8-v143-x64.11.9.169.4/lib/Release)
set(LIB_V8_PATH_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/build/packages/v8-v143-x64.11.9.169.4/lib/Debug)

add_executable(longjs 
                src/main.cpp
               include/engine/app.hpp
               include/engine/function.hpp
               src/engine/app.cpp
               include/engine/environment.hpp
               src/engine/environment.cpp
               include/uuid/uuid_4.h
               src/uuid/uuid_4.cpp
               include/uuid/UuidGenerator.h
               src/uuid/UuidGenerator.cpp
               include/engine/workspace.hpp
               src/engine/workspace.cpp
               include/engine/jsobject.hpp
               src/engine/jsobject.cpp
               include/engine/module.hpp
               src/engine/module.cpp
               include/engine/app_timer.hpp
               src/engine/app_timer.cpp
               include/fs/fs.hpp
               src/fs/fs.cpp
               include/helper/v8helper.hpp
               include/helper/rapidhelper.hpp
               include/pattern/singleton.hpp
               include/pattern/noncopyable/noncopyable.hpp
               src/pattern/singleton.cpp
               include/binder/glfwbinder.hpp
               src/binder/glfwbinder.cpp
               include/binder/cppbinder.hpp
               src/binder/cppbinder.cpp
               include/binder/glfwobject.hpp
               src/binder/glfwobject.cpp
               include/binder/glbinder.hpp
               src/binder/glbinder.cpp)

#include 
target_include_directories(longjs 
    PRIVATE ${HEADER_V8_PATH}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)





#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(longjs PRIVATE rapidjson
                        PRIVATE libuv::uv
                        PRIVATE glfw
                        PRIVATE GLEW::glew 
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
