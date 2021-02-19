/* This file was generated by the Hex-Rays decompiler.
   Copyright (c) 2007-2020 Hex-Rays <info@hex-rays.com>

   Detected compiler: Visual C++
*/

#include <windows.h>
#include <defs.h>


//-------------------------------------------------------------------------
// Function declarations

#define __thiscall __cdecl // Test compile in C mode

void *__thiscall CCommPipe::GetChildReadHandle(CCommPipe *__hidden this); // idb
void *__thiscall CCommPipe::GetChildWriteHandle(CCommPipe *__hidden this); // idb
const char *__thiscall CCommPipe::GetUserInfo(CCommPipe *__hidden this); // idb
unsigned int *__thiscall CCommPipe::GetCSAuth2(CCommPipe *__hidden this); // idb
bool __thiscall CCommPipe::InternalSendCommPipe(CCommPipe *__hidden this, unsigned int, unsigned int, unsigned int); // idb
bool __thiscall CCommPipe::SendCommPipe(CCommPipe *__hidden this, unsigned int, unsigned int, unsigned int); // idb
CCommPipe *__thiscall CCommPipe::CCommPipe(CCommPipe *__hidden this); // idb
char __thiscall CCommPipe::InitCommPipe(CCommPipe *this);
HANDLE __thiscall CCommPipe::ConnectCommPipe(CCommPipe *this);
HANDLE __thiscall CCommPipe::ConnectCommPipe(CCommPipe *this, void *a2, void *a3);
HANDLE __thiscall CCommPipe::CreateEventAndThread(CCommPipe *this);
HANDLE __thiscall CCommPipe::RunCommPipe(CCommPipe *this);
char __thiscall CCommPipe::CloseCommPipe(CCommPipe *this);
DWORD __stdcall CommPipeThread(LPVOID lpThreadParameter); // idb
// DWORD __stdcall GetLastError();
// BOOL __stdcall WriteFile(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped);
// int __stdcall lstrlenA(LPCSTR lpString);
// void __stdcall GetLocalTime(LPSYSTEMTIME lpSystemTime);
// BOOL __stdcall CloseHandle(HANDLE hObject);
// BOOL __stdcall DuplicateHandle(HANDLE hSourceProcessHandle, HANDLE hSourceHandle, HANDLE hTargetProcessHandle, LPHANDLE lpTargetHandle, DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwOptions);
// HANDLE __stdcall GetCurrentProcess();
// BOOL __stdcall SetStdHandle(DWORD nStdHandle, HANDLE hHandle);
// BOOL __stdcall CreatePipe(PHANDLE hReadPipe, PHANDLE hWritePipe, LPSECURITY_ATTRIBUTES lpPipeAttributes, DWORD nSize);
// HANDLE __stdcall GetStdHandle(DWORD nStdHandle);
// HANDLE __stdcall CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId);
// HANDLE __stdcall CreateEventA(LPSECURITY_ATTRIBUTES lpEventAttributes, BOOL bManualReset, BOOL bInitialState, LPCSTR lpName);
// BOOL __stdcall TerminateThread(HANDLE hThread, DWORD dwExitCode);
// DWORD __stdcall WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds);
// BOOL __stdcall SetEvent(HANDLE hEvent);
// bool __stdcall CommPipeCallback(struct CCommPipe *, unsigned int, unsigned int); idb
// BOOL __stdcall PeekNamedPipe(HANDLE hNamedPipe, LPVOID lpBuffer, DWORD nBufferSize, LPDWORD lpBytesRead, LPDWORD lpTotalBytesAvail, LPDWORD lpBytesLeftThisMessage);
// BOOL __stdcall ReadFile(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, LPDWORD lpNumberOfBytesRead, LPOVERLAPPED lpOverlapped);

//-------------------------------------------------------------------------
// Data declarations

_SCOPETABLE_ENTRY _T20326 = { -1, &_L20321, &_L20322 }; // weak
// extern _UNKNOWN _except_list; weak
// extern _UNKNOWN _except_handler3; weak


//----- (00000000) --------------------------------------------------------
void *__thiscall CCommPipe::GetChildReadHandle(CCommPipe *this)
{
  return (void *)*((_DWORD *)this + 78);
}

//----- (00000010) --------------------------------------------------------
void *__thiscall CCommPipe::GetChildWriteHandle(CCommPipe *this)
{
  return (void *)*((_DWORD *)this + 81);
}

//----- (00000020) --------------------------------------------------------
const char *__thiscall CCommPipe::GetUserInfo(CCommPipe *this)
{
  return (char *)this + 44;
}

//----- (00000030) --------------------------------------------------------
unsigned int *__thiscall CCommPipe::GetCSAuth2(CCommPipe *this)
{
  return (unsigned int *)((char *)this + 24);
}

//----- (00000040) --------------------------------------------------------
bool __thiscall CCommPipe::InternalSendCommPipe(CCommPipe *this, unsigned int a2, unsigned int a3, unsigned int lpString)
{
  void *v5; // ebx
  bool result; // al
  int v7; // edi
  unsigned int v8; // eax
  BOOL v9; // eax
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  int v13; // ecx
  DWORD v14; // eax
  unsigned int *v15; // [esp-18h] [ebp-168h]
  DWORD v16; // [esp-14h] [ebp-164h]
  DWORD NumberOfBytesWritten; // [esp+8h] [ebp-148h] BYREF
  unsigned int Buffer; // [esp+Ch] [ebp-144h] BYREF
  int v19; // [esp+10h] [ebp-140h]
  unsigned int v20; // [esp+14h] [ebp-13Ch]
  unsigned int v21; // [esp+18h] [ebp-138h]
  int v22[8]; // [esp+1Ch] [ebp-134h] BYREF
  int v23[4]; // [esp+3Ch] [ebp-114h] BYREF
  char v24[260]; // [esp+4Ch] [ebp-104h] BYREF

  v5 = (void *)*((_DWORD *)this + 1);
  if ( v5 == (void *)-1 )
    return 0;
  v7 = *((_DWORD *)this + 3);
  Buffer = a2;
  v20 = a3;
  v19 = v7;
  v21 = lpString;
  if ( a3 == 1555 )
  {
    v8 = lstrlenA((LPCSTR)lpString) + 1;
    v21 = v8;
    if ( v8 > 0x104 )
    {
      v8 = 260;
      *(_BYTE *)(lpString + 259) = 0;
      v21 = 260;
    }
    v23[0] = Buffer;
    v23[2] = v20;
    v23[1] = v19;
    v23[3] = v8;
    qmemcpy(v24, (const void *)lpString, v8);
    v9 = WriteFile(*((HANDLE *)this + 1), v23, v8 + 16, &NumberOfBytesWritten, 0);
  }
  else
  {
    if ( a3 == 1561 )
    {
      v22[2] = 1561;
      v10 = *(_DWORD *)(lpString + 4);
      v21 = 16;
      v22[0] = a2;
      v11 = *(_DWORD *)lpString;
      v22[3] = 16;
      v12 = *(_DWORD *)(lpString + 8);
      v22[5] = v10;
      v22[4] = v11;
      v13 = *(_DWORD *)(lpString + 12);
      v22[6] = v12;
      v16 = 32;
      v22[1] = v7;
      v22[7] = v13;
      v15 = (unsigned int *)v22;
    }
    else
    {
      v16 = 16;
      v15 = &Buffer;
    }
    v9 = WriteFile(v5, v15, v16, &NumberOfBytesWritten, 0);
  }
  result = 1;
  if ( !v9 )
  {
    v14 = GetLastError();
    if ( v14 == 109 || v14 == 232 || v14 == 6 )
      result = 0;
  }
  return result;
}

//----- (000001A0) --------------------------------------------------------
bool __thiscall CCommPipe::SendCommPipe(CCommPipe *this, unsigned int a2, unsigned int a3, unsigned int a4)
{
  int v4; // eax
  unsigned int v5; // eax

  v4 = *((_DWORD *)this + 83);
  if ( v4 != 1561 )
  {
    if ( *((_DWORD *)this + 82) == a2 && v4 == a3 && *((_DWORD *)this + 84) == a4 )
    {
      v5 = *((_DWORD *)this + 85) + 1;
      *((_DWORD *)this + 85) = v5;
      if ( v5 > 2 )
        return 1;
    }
    else
    {
      *((_DWORD *)this + 85) = 0;
    }
    *((_DWORD *)this + 82) = a2;
    *((_DWORD *)this + 83) = a3;
    *((_DWORD *)this + 84) = a4;
  }
  return CCommPipe::InternalSendCommPipe(this, a2, a3, a4);
}

//----- (00000220) --------------------------------------------------------
CCommPipe *__thiscall CCommPipe::CCommPipe(CCommPipe *this)
{
  int v2; // ecx
  struct _SYSTEMTIME SystemTime; // [esp+4h] [ebp-10h] BYREF

  GetLocalTime(&SystemTime);
  v2 = (SystemTime.wYear * SystemTime.wMonth * SystemTime.wDay) ^ 0xDAD53A;
  *((_DWORD *)this + 1) = -1;
  *((_DWORD *)this + 2) = -1;
  *((_DWORD *)this + 3) = v2;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 4) = 0;
  *((_BYTE *)this + 20) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_BYTE *)this + 44) = 0;
  return this;
}

//----- (00000290) --------------------------------------------------------
char __thiscall CCommPipe::InitCommPipe(CCommPipe *this)
{
  HANDLE (__stdcall *v3)(DWORD); // ebp
  HANDLE *v4; // edi
  HANDLE (__stdcall *v5)(); // ebx
  HANDLE v6; // eax
  HANDLE *v7; // edi
  HANDLE *v8; // esi
  HANDLE v9; // eax
  HANDLE v10; // [esp-18h] [ebp-38h]
  HANDLE v11; // [esp-18h] [ebp-38h]
  HANDLE v12; // [esp-14h] [ebp-34h]
  HANDLE v13; // [esp-14h] [ebp-34h]
  HANDLE *lpTargetHandle; // [esp+10h] [ebp-10h]
  struct _SECURITY_ATTRIBUTES PipeAttributes; // [esp+14h] [ebp-Ch] BYREF

  lpTargetHandle = (HANDLE *)((char *)this + 4);
  if ( *((_DWORD *)this + 1) != -1 )
    return 0;
  v3 = GetStdHandle;
  PipeAttributes.nLength = 12;
  PipeAttributes.bInheritHandle = 1;
  PipeAttributes.lpSecurityDescriptor = 0;
  *((_DWORD *)this + 77) = GetStdHandle(0xFFFFFFF5);
  v4 = (HANDLE *)((char *)this + 320);
  if ( !CreatePipe((PHANDLE)this + 80, (PHANDLE)this + 81, &PipeAttributes, 0) )
    return 0;
  if ( !SetStdHandle(0xFFFFFFF5, *((HANDLE *)this + 81)) )
    return 0;
  v5 = GetCurrentProcess;
  v12 = GetCurrentProcess();
  v10 = *v4;
  v6 = v5();
  if ( !DuplicateHandle(v6, v10, v12, (LPHANDLE)this + 2, 0, 0, 2u) )
    return 0;
  CloseHandle(*v4);
  *((_DWORD *)this + 76) = v3(0xFFFFFFF6);
  v7 = (HANDLE *)((char *)this + 316);
  v8 = (HANDLE *)((char *)this + 312);
  if ( !CreatePipe(v8, v7, &PipeAttributes, 0) )
    return 0;
  if ( !SetStdHandle(0xFFFFFFF6, *v8) )
    return 0;
  v13 = v5();
  v11 = *v7;
  v9 = v5();
  if ( !DuplicateHandle(v9, v11, v13, lpTargetHandle, 0, 0, 2u) )
    return 0;
  CloseHandle(*v7);
  return 1;
}

//----- (000003E0) --------------------------------------------------------
HANDLE __thiscall CCommPipe::ConnectCommPipe(CCommPipe *this)
{
  HANDLE (__stdcall *v2)(DWORD); // edi
  HANDLE v3; // eax
  int v4; // ecx

  if ( *((_DWORD *)this + 1) == -1 )
  {
    v2 = GetStdHandle;
    *((_DWORD *)this + 1) = GetStdHandle(0xFFFFFFF5);
    v3 = v2(0xFFFFFFF6);
    v4 = *((_DWORD *)this + 1);
    *((_DWORD *)this + 2) = v3;
    if ( v4 != -1 && v3 != (HANDLE)-1 )
      return CCommPipe::CreateEventAndThread(this);
    GetLastError();
  }
  return 0;
}

//----- (00000420) --------------------------------------------------------
HANDLE __thiscall CCommPipe::ConnectCommPipe(CCommPipe *this, void *a2, void *a3)
{
  *((_DWORD *)this + 1) = a3;
  *((_DWORD *)this + 2) = a2;
  if ( a3 != (void *)-1 && a2 != (void *)-1 )
    return CCommPipe::CreateEventAndThread(this);
  GetLastError();
  return 0;
}

//----- (00000450) --------------------------------------------------------
HANDLE __thiscall CCommPipe::CreateEventAndThread(CCommPipe *this)
{
  HANDLE result; // eax
  DWORD ThreadId; // [esp+4h] [ebp-4h] BYREF

  result = CreateEventA(0, 1, 0, 0);
  *((_DWORD *)this + 4) = result;
  if ( result )
  {
    result = CreateThread(0, 0, CommPipeThread, this, 0, &ThreadId);
    *(_DWORD *)this = result;
    if ( result )
    {
      result = (HANDLE)ThreadId;
      *((_BYTE *)this + 20) = 1;
    }
  }
  return result;
}

//----- (000004A0) --------------------------------------------------------
HANDLE __thiscall CCommPipe::RunCommPipe(CCommPipe *this)
{
  HANDLE result; // eax
  BOOL (__stdcall *v3)(DWORD, HANDLE); // edi
  HANDLE v4; // eax
  DWORD v5; // ecx
  DWORD ThreadId; // [esp+8h] [ebp-4h] BYREF

  if ( *((_DWORD *)this + 1) == -1 )
    return 0;
  v3 = SetStdHandle;
  result = (HANDLE)SetStdHandle(0xFFFFFFF6, *((HANDLE *)this + 76));
  if ( result )
  {
    result = (HANDLE)v3(0xFFFFFFF5, *((HANDLE *)this + 77));
    if ( result )
    {
      result = CreateEventA(0, 1, 0, 0);
      *((_DWORD *)this + 4) = result;
      if ( result )
      {
        v4 = CreateThread(0, 0, CommPipeThread, this, 0, &ThreadId);
        v5 = ThreadId;
        *(_DWORD *)this = v4;
        result = (HANDLE)(v4 != 0 ? v5 : 0);
      }
    }
  }
  return result;
}

//----- (00000520) --------------------------------------------------------
char __thiscall CCommPipe::CloseCommPipe(CCommPipe *this)
{
  void (__stdcall *v3)(HANDLE); // edi

  if ( *((_DWORD *)this + 1) == -1 )
    return 0;
  if ( *((_DWORD *)this + 4) )
    SetEvent(*((HANDLE *)this + 4));
  v3 = (void (__stdcall *)(HANDLE))CloseHandle;
  if ( *(_DWORD *)this )
  {
    if ( WaitForSingleObject(*(HANDLE *)this, 0x64u) == 258 )
      TerminateThread(*(HANDLE *)this, 0);
    v3(*(HANDLE *)this);
    *(_DWORD *)this = 0;
  }
  if ( *((_DWORD *)this + 1) != -1 )
  {
    v3(*((HANDLE *)this + 1));
    *((_DWORD *)this + 1) = -1;
  }
  if ( *((_DWORD *)this + 2) != -1 )
  {
    v3(*((HANDLE *)this + 2));
    *((_DWORD *)this + 2) = -1;
  }
  return 1;
}

//----- (000005A0) --------------------------------------------------------
DWORD __stdcall CommPipeThread(LPVOID lpThreadParameter)
{
  BOOL (__stdcall *v1)(HANDLE, LPVOID, DWORD, LPDWORD, LPOVERLAPPED); // edi
  unsigned int v2; // eax
  DWORD result; // eax
  int v4; // [esp-Ch] [ebp-4Ch] BYREF
  int v5; // [esp+0h] [ebp-40h]
  int Buffer[2]; // [esp+4h] [ebp-3Ch] BYREF
  unsigned int v7; // [esp+Ch] [ebp-34h]
  DWORD nNumberOfBytesToRead; // [esp+10h] [ebp-30h]
  unsigned int v9; // [esp+14h] [ebp-2Ch]
  DWORD TotalBytesAvail; // [esp+20h] [ebp-20h] BYREF
  DWORD NumberOfBytesRead[2]; // [esp+24h] [ebp-1Ch] BYREF
  unsigned int v12[4]; // [esp+30h] [ebp-10h] BYREF

  v12[2] = (unsigned int)&_T20326;
  v12[1] = (unsigned int)&_except_handler3;
  v12[0] = __readfsdword((unsigned int)&_except_list);
  __writefsdword((unsigned int)&_except_list, (unsigned int)v12);
  NumberOfBytesRead[1] = (DWORD)&v4;
  TotalBytesAvail = 0;
  v5 = 0;
  v9 = 0;
  v12[3] = 0;
  v1 = ReadFile;
  do
  {
    while ( 1 )
    {
      while ( 1 )
      {
        do
        {
          while ( !TotalBytesAvail )
          {
            if ( !PeekNamedPipe(*((HANDLE *)lpThreadParameter + 2), 0, 0, 0, &TotalBytesAvail, 0)
              && !CommPipeCallback((struct CCommPipe *)lpThreadParameter, 0x60Fu, 0) )
            {
              goto LABEL_56;
            }
            if ( TotalBytesAvail )
              break;
            if ( WaitForSingleObject(*((HANDLE *)lpThreadParameter + 4), 0x32u) )
            {
              if ( (int)++v9 < 200
                || (CCommPipe::InternalSendCommPipe((CCommPipe *)lpThreadParameter, 0x8B1u, 0x60Eu, 0)
                 || CommPipeCallback((struct CCommPipe *)lpThreadParameter, 0x60Fu, 0))
                && ((int)v9 < 800 || CommPipeCallback((struct CCommPipe *)lpThreadParameter, 0x618u, v9)) )
              {
                if ( !*((_BYTE *)lpThreadParameter + 20) )
                  continue;
                if ( ++v5 < 80 )
                  continue;
                v5 = 0;
                *((_BYTE *)lpThreadParameter + 20) = 0;
                if ( CCommPipe::InternalSendCommPipe((CCommPipe *)lpThreadParameter, 0x8B0u, 0, 0)
                  || CommPipeCallback((struct CCommPipe *)lpThreadParameter, 0x60Fu, 0) )
                {
                  continue;
                }
              }
            }
            goto LABEL_56;
          }
          v9 = 0;
          if ( (!v1(*((HANDLE *)lpThreadParameter + 2), Buffer, 0x10u, NumberOfBytesRead, 0) || !NumberOfBytesRead[0])
            && !CommPipeCallback((struct CCommPipe *)lpThreadParameter, 0x60Fu, 0) )
          {
            goto LABEL_56;
          }
          TotalBytesAvail -= NumberOfBytesRead[0];
          v2 = v7;
        }
        while ( v7 == 1550 );
        if ( Buffer[0] == 2225 )
          break;
LABEL_35:
        switch ( Buffer[0] )
        {
          case 2226:
            if ( v7 )
            {
              if ( v7 == 1552 && !CommPipeCallback((struct CCommPipe *)lpThreadParameter, 0x610u, 0) )
                goto LABEL_56;
            }
            else
            {
              *((_BYTE *)lpThreadParameter + 20) = 0;
              ++*((_DWORD *)lpThreadParameter + 3);
            }
            break;
          case 2224:
            if ( *((_DWORD *)lpThreadParameter + 3) == Buffer[1] )
            {
              if ( !CCommPipe::InternalSendCommPipe((CCommPipe *)lpThreadParameter, 0x8B2u, v7, 0)
                && !CommPipeCallback((struct CCommPipe *)lpThreadParameter, 0x60Fu, 0) )
              {
                goto LABEL_56;
              }
              *((_BYTE *)lpThreadParameter + 20) = 1;
              ++*((_DWORD *)lpThreadParameter + 3);
            }
            else
            {
              if ( !CommPipeCallback((struct CCommPipe *)lpThreadParameter, 0x60Fu, 0) )
                goto LABEL_56;
              *((_BYTE *)lpThreadParameter + 20) = 1;
              ++*((_DWORD *)lpThreadParameter + 3);
            }
            break;
          case 2225:
            if ( v7 == 1552 )
            {
              if ( !CommPipeCallback((struct CCommPipe *)lpThreadParameter, 0x610u, 0) )
                goto LABEL_56;
              v2 = v7;
            }
            if ( CCommPipe::InternalSendCommPipe((CCommPipe *)lpThreadParameter, 0x8B2u, v2, nNumberOfBytesToRead) )
            {
              if ( !CommPipeCallback((struct CCommPipe *)lpThreadParameter, v7, nNumberOfBytesToRead) )
                goto LABEL_56;
            }
            else if ( !CommPipeCallback((struct CCommPipe *)lpThreadParameter, 0x60Fu, 0) )
            {
              goto LABEL_56;
            }
            break;
        }
      }
      if ( v7 != 1555 )
        break;
      if ( nNumberOfBytesToRead > 0x104
        || (!v1(
               *((HANDLE *)lpThreadParameter + 2),
               (char *)lpThreadParameter + 44,
               nNumberOfBytesToRead,
               NumberOfBytesRead,
               0)
         || !NumberOfBytesRead[0])
        && !CommPipeCallback((struct CCommPipe *)lpThreadParameter, 0x60Fu, 0) )
      {
        goto LABEL_56;
      }
      TotalBytesAvail -= NumberOfBytesRead[0];
    }
    if ( v7 != 1561 )
      goto LABEL_35;
    if ( nNumberOfBytesToRead > 0x10
      || (!v1(
             *((HANDLE *)lpThreadParameter + 2),
             (char *)lpThreadParameter + 24,
             nNumberOfBytesToRead,
             NumberOfBytesRead,
             0)
       || !NumberOfBytesRead[0])
      && !CommPipeCallback((struct CCommPipe *)lpThreadParameter, 0x60Fu, 0) )
    {
      break;
    }
    TotalBytesAvail -= NumberOfBytesRead[0];
  }
  while ( CommPipeCallback((struct CCommPipe *)lpThreadParameter, v7, nNumberOfBytesToRead) );
LABEL_56:
  if ( *((_DWORD *)lpThreadParameter + 2) != -1 )
  {
    CloseHandle(*((HANDLE *)lpThreadParameter + 2));
    *((_DWORD *)lpThreadParameter + 2) = -1;
  }
  if ( !WaitForSingleObject(*((HANDLE *)lpThreadParameter + 4), 0x7530u) && v7 != 1552 && v7 != 1551 )
    CCommPipe::InternalSendCommPipe((CCommPipe *)lpThreadParameter, 0x8B1u, 0x610u, 0);
  result = 0;
  __writefsdword((unsigned int)&_except_list, v12[0]);
  return result;
}
// 950: using guessed type _SCOPETABLE_ENTRY _T20326;

// nfuncs=35 queued=14 decompiled=14 lumina nreq=0 worse=0 better=0
// ALL OK, 14 function(s) have been successfully decompiled
