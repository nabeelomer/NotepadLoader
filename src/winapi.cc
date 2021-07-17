#include <asmjit/asmjit.h>
#include <stdio.h>
#include <sys/mman.h>
#include <vector>
#include <string>

using namespace asmjit;

std::vector<std::string> names;

extern "C" void* GenerateStub(char* name)
{
    names.push_back("Generated Stub for " + std::string(name));

    CodeHolder code;
    code.init(Environment(Environment::Arch::kArchX64));
    x86::Assembler as(&code);

    as.mov(x86::rdi, imm(names.back().c_str()));
    as.mov(x86::rax, imm((void*)puts));
    as.int3();
    as.call(x86::rax);
    as.ret();

    auto buffer = code.textSection();
    uint8_t* data = buffer->data();
    size_t length = buffer->bufferSize();

    char* funcAddr = (char*) mmap(NULL, length, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANONYMOUS | MAP_PRIVATE, 0, 0);
    memcpy(funcAddr, data, length);

    return (void*) funcAddr;
}
