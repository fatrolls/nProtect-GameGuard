/* This file was generated by the Hex-Rays decompiler.
   Copyright (c) 2007-2020 Hex-Rays <info@hex-rays.com>

   Detected compiler: Visual C++
*/

#include <windows.h>
#include <defs.h>


//-------------------------------------------------------------------------
// Function declarations

#define __thiscall __cdecl // Test compile in C mode

HCRYPTPROV *__thiscall CFileAuthClient::CFileAuthClient(HCRYPTPROV *phProv);
void __thiscall CFileAuthClient::~CFileAuthClient(CFileAuthClient *__hidden this); // idb
char __thiscall CFileAuthClient::Auth(HCRYPTPROV *phProv, LPCSTR lpFileName, bool a3);
char __thiscall CFileAuthClient::DecryptMem(CFileAuthClient *this, LPCSTR lpFileName, char *a3, unsigned int a4, BYTE *pbData);
char __thiscall CFileAuthClient::DecryptMem2(CFileAuthClient *this, LPCSTR lpFileName, char *a3, unsigned int a4, BYTE *pbData);
char __thiscall CFileAuthClient::DecryptRC4(CFileAuthClient *this, unsigned __int8 *a2, unsigned int a3);
// BOOL __stdcall CryptAcquireContextA(HCRYPTPROV *phProv, LPCSTR szContainer, LPCSTR szProvider, DWORD dwProvType, DWORD dwFlags);
// BOOL __stdcall CryptReleaseContext(HCRYPTPROV hProv, DWORD dwFlags);
// BOOL __stdcall CryptDestroyKey(HCRYPTKEY hKey);
// BOOL __stdcall CryptDestroyHash(HCRYPTHASH hHash);
// void __cdecl _free(void *Block);
// int __cdecl __strnicmp(const char *String1, const char *String2, size_t MaxCount);
// char *__cdecl _strrchr(const char *Str, int Ch);
// BOOL __stdcall CryptVerifySignatureA(HCRYPTHASH hHash, const BYTE *pbSignature, DWORD dwSigLen, HCRYPTKEY hPubKey, LPCSTR szDescription, DWORD dwFlags);
// BOOL __stdcall CryptHashData(HCRYPTHASH hHash, const BYTE *pbData, DWORD dwDataLen, DWORD dwFlags);
// BOOL __stdcall CryptCreateHash(HCRYPTPROV hProv, ALG_ID Algid, HCRYPTKEY hKey, DWORD dwFlags, HCRYPTHASH *phHash);
// DWORD __stdcall GetLastError();
// BOOL __stdcall CryptImportKey(HCRYPTPROV hProv, const BYTE *pbData, DWORD dwDataLen, HCRYPTKEY hPubKey, DWORD dwFlags, HCRYPTKEY *phKey);
// BOOL __stdcall ReadFile(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, LPDWORD lpNumberOfBytesRead, LPOVERLAPPED lpOverlapped);
// void *__cdecl _malloc(size_t Size);
// BOOL __stdcall CloseHandle(HANDLE hObject);
// DWORD __stdcall GetFileSize(HANDLE hFile, LPDWORD lpFileSizeHigh);
// HANDLE __stdcall CreateFileA(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile);
// BOOL __stdcall CryptDecrypt(HCRYPTKEY hKey, HCRYPTHASH hHash, BOOL Final, DWORD dwFlags, BYTE *pbData, DWORD *pdwDataLen);
// BOOL __stdcall CryptDeriveKey(HCRYPTPROV hProv, ALG_ID Algid, HCRYPTHASH hBaseData, DWORD dwFlags, HCRYPTKEY *phKey);
// void __cdecl RC4(struct rc4_key_st *, unsigned int, unsigned __int8 *, unsigned __int8 *); idb
// void __cdecl RC4_set_key(struct rc4_key_st *, int, unsigned __int8 *); idb
// BOOL __stdcall CryptGetHashParam(HCRYPTHASH hHash, DWORD dwParam, BYTE *pbData, DWORD *pdwDataLen, DWORD dwFlags);

//-------------------------------------------------------------------------
// Data declarations

BYTE pbPubKey = 6u; // idb
DWORD dwPubKeyLen = 84u; // idb


//----- (00000068) --------------------------------------------------------
HCRYPTPROV *__thiscall CFileAuthClient::CFileAuthClient(HCRYPTPROV *phProv)
{
  phProv[5] = 0;
  phProv[3] = 0;
  *phProv = 0;
  phProv[1] = 0;
  phProv[2] = 0;
  phProv[9] = 0;
  phProv[14] = 0;
  phProv[16] = 0;
  phProv[15] = 0;
  phProv[6] = 0;
  *((_BYTE *)phProv + 28) = 0;
  phProv[8] = 0;
  phProv[17] = 0;
  phProv[4] = 0;
  if ( !CryptAcquireContextA(phProv, 0, "Microsoft Base Cryptographic Provider v1.0", 1u, 0xF0000000) )
    *phProv = 0;
  return phProv;
}

//----- (000000E4) --------------------------------------------------------
void __thiscall CFileAuthClient::~CFileAuthClient(CFileAuthClient *this)
{
  void (__cdecl *v2)(void *); // edi
  HCRYPTHASH v3; // eax
  void (__stdcall *v4)(HCRYPTHASH); // ebx
  void (__stdcall *v5)(HCRYPTKEY); // edi
  HCRYPTPROV v6; // esi

  v2 = _free;
  if ( *((_DWORD *)this + 1) )
    _free(*((void **)this + 1));
  if ( *((_DWORD *)this + 5) )
    v2(*((void **)this + 5));
  v3 = *((_DWORD *)this + 3);
  v4 = (void (__stdcall *)(HCRYPTHASH))CryptDestroyHash;
  if ( v3 )
    CryptDestroyHash(v3);
  v5 = (void (__stdcall *)(HCRYPTKEY))CryptDestroyKey;
  if ( *((_DWORD *)this + 4) )
    CryptDestroyKey(*((_DWORD *)this + 4));
  if ( *((_DWORD *)this + 15) )
    v5(*((_DWORD *)this + 15));
  if ( *((_DWORD *)this + 16) )
    v4(*((_DWORD *)this + 16));
  v6 = *(_DWORD *)this;
  if ( v6 )
    CryptReleaseContext(v6, 0);
}

//----- (00000154) --------------------------------------------------------
char __thiscall CFileAuthClient::Auth(HCRYPTPROV *phProv, LPCSTR lpFileName, bool a3)
{
  char result; // al
  HANDLE v5; // eax
  void *v6; // esi
  DWORD v7; // eax
  void *v8; // eax
  HCRYPTPROV v9; // eax
  HCRYPTPROV *v10; // edx
  HCRYPTPROV v11; // ecx
  HCRYPTPROV v12; // edx
  int v13; // edx
  void *v14; // eax
  void *v15; // eax
  HCRYPTPROV *v16; // edi
  BOOL (__stdcall *v17)(HCRYPTPROV, const BYTE *, DWORD, HCRYPTKEY, DWORD, HCRYPTKEY *); // esi
  HCRYPTPROV *v18; // esi
  char *v19; // eax
  const char *v20; // eax
  DWORD NumberOfBytesRead; // [esp+10h] [ebp-4h] BYREF

  if ( !lpFileName )
  {
    phProv[17] = 1;
    return 0;
  }
  if ( !*lpFileName )
  {
    phProv[17] = 2;
    return 0;
  }
  v5 = CreateFileA(lpFileName, 0x80000000, 3u, 0, 3u, 0x80u, 0);
  v6 = v5;
  if ( v5 == (HANDLE)-1 )
  {
    phProv[17] = 3;
    return 0;
  }
  v7 = GetFileSize(v5, 0);
  phProv[9] = v7;
  if ( v7 == -1 )
  {
    CloseHandle(v6);
    phProv[17] = 33;
    return 0;
  }
  if ( phProv[1] )
  {
    _free((void *)phProv[1]);
    phProv[1] = 0;
  }
  v8 = _malloc(phProv[9]);
  phProv[1] = (HCRYPTPROV)v8;
  if ( !v8 )
  {
    CloseHandle(v6);
    phProv[17] = 4;
    return 0;
  }
  ReadFile(v6, v8, phProv[9], &NumberOfBytesRead, 0);
  v9 = phProv[9];
  if ( NumberOfBytesRead != v9 )
  {
    CloseHandle(v6);
    phProv[17] = 5;
    return 0;
  }
  v10 = (HCRYPTPROV *)(phProv[1] + v9 - 16);
  phProv[10] = *v10;
  phProv[11] = v10[1];
  phProv[12] = v10[2];
  phProv[13] = v10[3];
  if ( phProv[10] == 847324706 && phProv[13] == 847324705 )
  {
    v11 = phProv[11];
    v12 = phProv[12];
    *((_BYTE *)phProv + 28) = 1;
    v13 = v12 + v11 + 16;
    phProv[14] = v11;
    phProv[8] = v13;
    phProv[2] = v9 - v13;
  }
  else
  {
    phProv[10] = 0;
    phProv[11] = 0;
    phProv[12] = 0;
    phProv[13] = 0;
    v9 = phProv[9];
    *((_BYTE *)phProv + 28) = 0;
    phProv[8] = 0;
    phProv[2] = v9;
    phProv[14] = 0;
  }
  if ( v9 < phProv[8] )
  {
    *((_BYTE *)phProv + 28) = 0;
    phProv[8] = 0;
    phProv[9] = 0;
    phProv[2] = 0;
    phProv[14] = 0;
  }
  CloseHandle(v6);
  if ( !*((_BYTE *)phProv + 28) )
  {
    phProv[17] = 6;
    return 0;
  }
  v14 = (void *)phProv[5];
  phProv[6] = phProv[12];
  if ( v14 )
  {
    _free(v14);
    phProv[5] = 0;
  }
  v15 = _malloc(phProv[6]);
  phProv[5] = (HCRYPTPROV)v15;
  if ( !v15 )
  {
    phProv[17] = 7;
    return 0;
  }
  qmemcpy(v15, (const void *)(phProv[14] + phProv[1] + phProv[2]), phProv[6]);
  if ( !*phProv && !CryptAcquireContextA(phProv, 0, "Microsoft Base Cryptographic Provider v1.0", 1u, 0xF0000000) )
  {
    phProv[17] = 8;
    return 0;
  }
  v16 = phProv + 4;
  if ( phProv[4] )
  {
    CryptDestroyKey(phProv[4]);
    *v16 = 0;
  }
  v17 = CryptImportKey;
  if ( !CryptImportKey(*phProv, &pbPubKey, dwPubKeyLen, 0, 0, phProv + 4) )
  {
    if ( GetLastError() != 87 )
      goto LABEL_37;
    if ( !CryptAcquireContextA(phProv, 0, "Microsoft Base Cryptographic Provider v1.0", 1u, 0xF0000000) )
    {
      phProv[17] = 98;
      return 0;
    }
    if ( !v17(*phProv, &pbPubKey, dwPubKeyLen, 0, 0, phProv + 4) )
    {
LABEL_37:
      phProv[17] = 9;
      return 0;
    }
  }
  v18 = phProv + 3;
  if ( phProv[3] )
  {
    CryptDestroyHash(phProv[3]);
    *v18 = 0;
  }
  if ( !CryptCreateHash(*phProv, 0x8003u, 0, 0, phProv + 3) )
  {
    phProv[17] = 10;
    return 0;
  }
  if ( !CryptHashData(*v18, (const BYTE *)phProv[1], phProv[14] + phProv[2], 0) )
  {
    phProv[17] = 11;
    return 0;
  }
  if ( CryptVerifySignatureA(*v18, (const BYTE *)phProv[5], phProv[6], *v16, 0, 0) )
    goto LABEL_61;
  if ( GetLastError() != 87 )
    goto LABEL_49;
  if ( !CryptAcquireContextA(phProv, 0, "Microsoft Base Cryptographic Provider v1.0", 1u, 0xF0000000) )
  {
    phProv[17] = 128;
    return 0;
  }
  if ( CryptVerifySignatureA(*v18, (const BYTE *)phProv[5], phProv[6], *v16, 0, 0) )
  {
LABEL_61:
    if ( !a3
      || ((v19 = _strrchr(lpFileName, 92)) == 0 ? (v20 = lpFileName) : (v20 = v19 + 1),
          !__strnicmp(v20, (const char *)(phProv[1] + phProv[2]), phProv[14])) )
    {
      if ( phProv[1] )
      {
        _free((void *)phProv[1]);
        phProv[1] = 0;
      }
      result = 1;
    }
    else
    {
      phProv[17] = 13;
      result = 0;
    }
  }
  else
  {
LABEL_49:
    phProv[17] = 12;
    result = 0;
  }
  return result;
}

//----- (00000574) --------------------------------------------------------
char __thiscall CFileAuthClient::DecryptMem(CFileAuthClient *this, LPCSTR lpFileName, char *a3, unsigned int a4, BYTE *pbData)
{
  HANDLE v6; // eax
  void *v7; // esi
  char result; // al
  DWORD v9; // eax
  void *v10; // eax
  unsigned int v11; // eax
  _DWORD *v12; // edx
  int v13; // ecx
  int v14; // edx
  int v15; // edx
  HCRYPTHASH *v16; // ebx
  HCRYPTKEY *v17; // esi
  BYTE *v18; // ecx
  unsigned int v19; // eax
  char *v20; // edx
  DWORD NumberOfBytesRead; // [esp+10h] [ebp-4h] BYREF

  v6 = CreateFileA(lpFileName, 0x80000000, 3u, 0, 3u, 0x80u, 0);
  v7 = v6;
  if ( v6 == (HANDLE)-1 )
  {
    *((_DWORD *)this + 17) = 1;
    return 0;
  }
  v9 = GetFileSize(v6, 0);
  *((_DWORD *)this + 9) = v9;
  if ( v9 == -1 )
  {
    CloseHandle(v7);
    *((_DWORD *)this + 17) = 11;
    return 0;
  }
  if ( *((_DWORD *)this + 1) )
  {
    _free(*((void **)this + 1));
    *((_DWORD *)this + 1) = 0;
  }
  v10 = _malloc(*((_DWORD *)this + 9));
  *((_DWORD *)this + 1) = v10;
  if ( !v10 )
  {
    CloseHandle(v7);
    *((_DWORD *)this + 17) = 2;
    return 0;
  }
  ReadFile(v7, v10, *((_DWORD *)this + 9), &NumberOfBytesRead, 0);
  v11 = *((_DWORD *)this + 9);
  if ( NumberOfBytesRead != v11 )
  {
    CloseHandle(v7);
    *((_DWORD *)this + 17) = 3;
    return 0;
  }
  v12 = (_DWORD *)(*((_DWORD *)this + 1) + v11 - 16);
  *((_DWORD *)this + 10) = *v12;
  *((_DWORD *)this + 11) = v12[1];
  *((_DWORD *)this + 12) = v12[2];
  *((_DWORD *)this + 13) = v12[3];
  if ( *((_DWORD *)this + 10) == 847324706 && *((_DWORD *)this + 13) == 847324705 )
  {
    v13 = *((_DWORD *)this + 11);
    v14 = *((_DWORD *)this + 12);
    *((_BYTE *)this + 28) = 1;
    v15 = v14 + v13 + 16;
    *((_DWORD *)this + 14) = v13;
    *((_DWORD *)this + 8) = v15;
    *((_DWORD *)this + 2) = v11 - v15;
  }
  else
  {
    *((_DWORD *)this + 10) = 0;
    *((_DWORD *)this + 11) = 0;
    *((_DWORD *)this + 12) = 0;
    *((_DWORD *)this + 13) = 0;
    *((_BYTE *)this + 28) = 0;
    v11 = *((_DWORD *)this + 9);
    *((_DWORD *)this + 8) = 0;
    *((_DWORD *)this + 2) = v11;
    *((_DWORD *)this + 14) = 0;
  }
  if ( v11 < *((_DWORD *)this + 8) )
  {
    *((_BYTE *)this + 28) = 0;
    *((_DWORD *)this + 8) = 0;
    *((_DWORD *)this + 9) = 0;
    *((_DWORD *)this + 2) = 0;
    *((_DWORD *)this + 14) = 0;
  }
  CloseHandle(v7);
  if ( !*(_DWORD *)this
    && !CryptAcquireContextA((HCRYPTPROV *)this, 0, "Microsoft Base Cryptographic Provider v1.0", 1u, 0xF0000000) )
  {
    *((_DWORD *)this + 17) = 4;
    return 0;
  }
  v16 = (HCRYPTHASH *)((char *)this + 64);
  if ( *((_DWORD *)this + 16) )
  {
    CryptDestroyHash(*((_DWORD *)this + 16));
    *v16 = 0;
  }
  if ( !CryptCreateHash(*(_DWORD *)this, 0x8003u, 0, 0, (HCRYPTHASH *)this + 16) )
  {
    *((_DWORD *)this + 17) = 5;
    return 0;
  }
  if ( !CryptHashData(*v16, pbData, strlen((const char *)pbData), 0) )
  {
    *((_DWORD *)this + 17) = 6;
    return 0;
  }
  v17 = (HCRYPTKEY *)((char *)this + 60);
  if ( *((_DWORD *)this + 15) )
  {
    CryptDestroyKey(*((_DWORD *)this + 15));
    *v17 = 0;
  }
  if ( !CryptDeriveKey(*(_DWORD *)this, 0x6801u, *v16, 0, (HCRYPTKEY *)this + 15) )
  {
    *((_DWORD *)this + 17) = 7;
    return 0;
  }
  v18 = (BYTE *)*((_DWORD *)this + 1);
  lpFileName = (LPCSTR)*((_DWORD *)this + 2);
  if ( CryptDecrypt(*v17, 0, 1, 0, v18, (DWORD *)&lpFileName) )
    goto LABEL_35;
  if ( GetLastError() != -2146893808 )
  {
    *((_DWORD *)this + 17) = 8;
    return 0;
  }
  result = CFileAuthClient::DecryptRC4(this, *((unsigned __int8 **)this + 1), (unsigned int)lpFileName);
  if ( result )
  {
LABEL_35:
    v19 = a4;
    if ( a4 > *((_DWORD *)this + 2) )
      v19 = *((_DWORD *)this + 2);
    v20 = a3;
    qmemcpy(a3, *((const void **)this + 1), v19);
    v20[v19] = 0;
    if ( *((_DWORD *)this + 1) )
    {
      _free(*((void **)this + 1));
      *((_DWORD *)this + 1) = 0;
    }
    result = 1;
  }
  else
  {
    *((_DWORD *)this + 17) = 88;
  }
  return result;
}

//----- (00000874) --------------------------------------------------------
char __thiscall CFileAuthClient::DecryptMem2(CFileAuthClient *this, LPCSTR lpFileName, char *a3, unsigned int a4, BYTE *pbData)
{
  HANDLE v6; // eax
  void *v7; // esi
  char result; // al
  DWORD v9; // eax
  void *v10; // eax
  const CHAR *v11; // eax
  const CHAR *v12; // edx
  int v13; // ecx
  int v14; // edx
  int v15; // edx
  HCRYPTHASH *v16; // esi
  unsigned int v17; // eax
  char *v18; // edx

  v6 = CreateFileA(lpFileName, 0x80000000, 3u, 0, 3u, 0x80u, 0);
  v7 = v6;
  if ( v6 == (HANDLE)-1 )
  {
    *((_DWORD *)this + 17) = 1;
    result = 0;
  }
  else
  {
    v9 = GetFileSize(v6, 0);
    *((_DWORD *)this + 9) = v9;
    if ( v9 == -1 )
    {
      CloseHandle(v7);
      *((_DWORD *)this + 17) = 11;
      result = 0;
    }
    else
    {
      if ( *((_DWORD *)this + 1) )
      {
        _free(*((void **)this + 1));
        *((_DWORD *)this + 1) = 0;
      }
      v10 = _malloc(*((_DWORD *)this + 9));
      *((_DWORD *)this + 1) = v10;
      if ( v10 )
      {
        ReadFile(v7, v10, *((_DWORD *)this + 9), (LPDWORD)&lpFileName, 0);
        v11 = (const CHAR *)*((_DWORD *)this + 9);
        if ( lpFileName == v11 )
        {
          v12 = &v11[*((_DWORD *)this + 1) - 16];
          *((_DWORD *)this + 10) = *(_DWORD *)v12;
          *((_DWORD *)this + 11) = *((_DWORD *)v12 + 1);
          *((_DWORD *)this + 12) = *((_DWORD *)v12 + 2);
          *((_DWORD *)this + 13) = *((_DWORD *)v12 + 3);
          if ( *((_DWORD *)this + 10) == 847324706 && *((_DWORD *)this + 13) == 847324705 )
          {
            v13 = *((_DWORD *)this + 11);
            v14 = *((_DWORD *)this + 12);
            *((_BYTE *)this + 28) = 1;
            v15 = v14 + v13 + 16;
            *((_DWORD *)this + 14) = v13;
            *((_DWORD *)this + 8) = v15;
            *((_DWORD *)this + 2) = &v11[-v15];
          }
          else
          {
            *((_DWORD *)this + 10) = 0;
            *((_DWORD *)this + 11) = 0;
            *((_DWORD *)this + 12) = 0;
            *((_DWORD *)this + 13) = 0;
            v11 = (const CHAR *)*((_DWORD *)this + 9);
            *((_BYTE *)this + 28) = 0;
            *((_DWORD *)this + 8) = 0;
            *((_DWORD *)this + 2) = v11;
            *((_DWORD *)this + 14) = 0;
          }
          if ( (unsigned int)v11 < *((_DWORD *)this + 8) )
          {
            *((_BYTE *)this + 28) = 0;
            *((_DWORD *)this + 8) = 0;
            *((_DWORD *)this + 9) = 0;
            *((_DWORD *)this + 2) = 0;
            *((_DWORD *)this + 14) = 0;
          }
          CloseHandle(v7);
          if ( *(_DWORD *)this
            || CryptAcquireContextA((HCRYPTPROV *)this, 0, "Microsoft Base Cryptographic Provider v1.0", 1u, 0xF0000000) )
          {
            v16 = (HCRYPTHASH *)((char *)this + 64);
            if ( *((_DWORD *)this + 16) )
            {
              CryptDestroyHash(*((_DWORD *)this + 16));
              *v16 = 0;
            }
            if ( CryptCreateHash(*(_DWORD *)this, 0x8003u, 0, 0, (HCRYPTHASH *)this + 16) )
            {
              if ( CryptHashData(*v16, pbData, strlen((const char *)pbData), 0) )
              {
                if ( *((_DWORD *)this + 15) )
                {
                  CryptDestroyKey(*((_DWORD *)this + 15));
                  *((_DWORD *)this + 15) = 0;
                }
                if ( CryptDeriveKey(*(_DWORD *)this, 0x6801u, *v16, 0, (HCRYPTKEY *)this + 15) )
                {
                  result = CFileAuthClient::DecryptRC4(this, *((unsigned __int8 **)this + 1), *((_DWORD *)this + 2));
                  if ( result )
                  {
                    v17 = a4;
                    if ( a4 > *((_DWORD *)this + 2) )
                      v17 = *((_DWORD *)this + 2);
                    v18 = a3;
                    qmemcpy(a3, *((const void **)this + 1), v17);
                    v18[v17] = 0;
                    if ( *((_DWORD *)this + 1) )
                    {
                      _free(*((void **)this + 1));
                      *((_DWORD *)this + 1) = 0;
                    }
                    result = 1;
                  }
                  else
                  {
                    *((_DWORD *)this + 17) = 88;
                  }
                }
                else
                {
                  *((_DWORD *)this + 17) = 7;
                  result = 0;
                }
              }
              else
              {
                *((_DWORD *)this + 17) = 6;
                result = 0;
              }
            }
            else
            {
              *((_DWORD *)this + 17) = 5;
              result = 0;
            }
          }
          else
          {
            *((_DWORD *)this + 17) = 4;
            result = 0;
          }
        }
        else
        {
          CloseHandle(v7);
          *((_DWORD *)this + 17) = 3;
          result = 0;
        }
      }
      else
      {
        CloseHandle(v7);
        *((_DWORD *)this + 17) = 2;
        result = 0;
      }
    }
  }
  return result;
}

//----- (00000B24) --------------------------------------------------------
char __thiscall CFileAuthClient::DecryptRC4(CFileAuthClient *this, unsigned __int8 *a2, unsigned int a3)
{
  HCRYPTHASH v4; // [esp-14h] [ebp-430h]
  DWORD pdwDataLen; // [esp+0h] [ebp-41Ch] BYREF
  BYTE pbData[5]; // [esp+4h] [ebp-418h] BYREF
  int v7; // [esp+9h] [ebp-413h]
  int v8; // [esp+Dh] [ebp-40Fh]
  __int16 v9; // [esp+11h] [ebp-40Bh]
  char v10; // [esp+13h] [ebp-409h]
  char v11[1032]; // [esp+14h] [ebp-408h] BYREF

  v4 = *((_DWORD *)this + 16);
  pdwDataLen = 16;
  if ( !CryptGetHashParam(v4, 2u, pbData, &pdwDataLen, 0) )
    return 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  RC4_set_key((struct rc4_key_st *)v11, 16, pbData);
  RC4((struct rc4_key_st *)v11, a3, a2, a2);
  return 1;
}

// nfuncs=28 queued=6 decompiled=6 lumina nreq=0 worse=0 better=0
// ALL OK, 6 function(s) have been successfully decompiled
