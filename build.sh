

clang -O0 -g -march=native -fshort-wchar -Wno-multichar -Iinclude -mstackrealign -Ipeloader -L/usr/local/opt/llvm/lib -Wl,-rpath,/usr/local/opt/llvm/lib -lm ./src/mpclient.c ./src/pe_linker.c ./src/winstrings.c ./src/log.c ./src/crt.c -o launcher