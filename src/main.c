#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

#include "winnt_types.h"
#include "pe_linker.h"
#include "ntoskernel.h"
#include "log.h"

void* GenerateStub(char* name);

int main(int argc, char **argv, char **envp)
{
    GenerateStub();
    exit(0);
    PIMAGE_DOS_HEADER DosHeader;
    PIMAGE_NT_HEADERS PeHeader;

    struct pe_image image = {
        .entry  = NULL,
        .name   = "./bins/notepad.exe",
    };

    // Load the mpengine module.
    if (pe_load_library(image.name, &image.image, &image.size) == false) {
        LogMessage("You must add the dll and vdm files to the engine directory");
        return 1;
    }

    // Handle relocations, imports, etc.
    link_pe_images(&image, 1);

    // Fetch the headers to get base offsets.
    DosHeader   = (PIMAGE_DOS_HEADER) image.image;
    PeHeader    = (PIMAGE_NT_HEADERS)(image.image + DosHeader->e_lfanew);

    // Call DllMain()
    image.entry();
    return 0;
}
