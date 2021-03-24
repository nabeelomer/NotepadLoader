cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 20)

project(NotepadOnMacOS)

include(asmjit/CMakeLists.txt)
set(CMAKE_C_FLAGS "-O0 -g -march=native -fshort-wchar -Wno-multichar -mstackrealign")

include_directories(asmjit/src/asmjit)
add_executable(NotepadOnMacOS src/main.c src/crt.c src/log.c src/pe_linker.c src/bridge.cc)
target_link_libraries(NotepadOnMacOS asmjit)