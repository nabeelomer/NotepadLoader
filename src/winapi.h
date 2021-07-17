//
// Created by Nabeel Omer on 05/04/2021.
//

#pragma once

typedef struct _STARTUPINFO {
    DWORD  cb;
    LPSTR  lpReserved;
    LPSTR  lpDesktop;
    LPSTR  lpTitle;
    DWORD  dwX;
    DWORD  dwY;
    DWORD  dwXSize;
    DWORD  dwYSize;
    DWORD  dwXCountChars;
    DWORD  dwYCountChars;
    DWORD  dwFillAttribute;
    DWORD  dwFlags;
    WORD   wShowWindow;
    WORD   cbReserved2;
    LPBYTE lpReserved2;
    HANDLE hStdInput;
    HANDLE hStdOutput;
    HANDLE hStdError;
} STARTUPINFO, *LPSTARTUPINFO;

void* GenerateStub(char* name);

WINAPI DWORD GetTickCount() {
    warnx("GetTickCount : %p", __builtin_return_address(0));
    return 342522;
}

WINAPI void GetSystemTimeAsFileTime(
        PFILETIME lpSystemTimeAsFileTime
) {
    warnx("GetSystemTimeAsFileTime : %p", __builtin_return_address(0));
    lpSystemTimeAsFileTime->dwLowDateTime = 2000;
    lpSystemTimeAsFileTime->dwHighDateTime = 2000;
}

WINAPI DWORD GetCurrentProcessId() {
    warnx("GetCurrentProcessId : %p", __builtin_return_address(0));
    return 4096;
}

WINAPI void GetStartupInfoW(LPSTARTUPINFO lpStartupInfo)
{
    warnx("GetStartupInfoW : %p", __builtin_return_address(0));
    memset(lpStartupInfo, 0, sizeof *lpStartupInfo);
    lpStartupInfo->cb = sizeof(STARTUPINFO);
    lpStartupInfo->lpDesktop = "YO!";
    lpStartupInfo->lpTitle = "YO";
    lpStartupInfo->lpReserved = "YO";
}

WINAPI DWORD GetCurrentThreadId()
{
    warnx("GetCurrentThreadId : %p", __builtin_return_address(0));
    return 0x1213;
}