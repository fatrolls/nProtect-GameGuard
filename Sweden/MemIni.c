/* This file was generated by the Hex-Rays decompiler.
   Copyright (c) 2007-2020 Hex-Rays <info@hex-rays.com>

   Detected compiler: Visual C++
*/

#include <defs.h>


//-------------------------------------------------------------------------
// Function declarations

int __cdecl MemGetPrivateProfileInt(const char *a1, const char *a2, int a3, char *a4);
unsigned int __cdecl MemGetPrivateProfileString(const char *, const char *, const char *Source, char *Dest, size_t Count, char *); // idb
char *__cdecl GetLine(char *a1, _BYTE *a2);
int __cdecl MemGetPrivateProfileSectionNames(char *Dest, unsigned int a2, char *a3);
// int _sscanf(const char *const Buffer, const char *const Format, ...);
// int _sprintf(char *const Buffer, const char *const Format, ...);
// unsigned __int8 *__cdecl __mbsnbcpy(unsigned __int8 *Dest, const unsigned __int8 *Source, size_t Count);
// int __cdecl __mbsnbicmp(const unsigned __int8 *Str1, const unsigned __int8 *Str2, size_t MaxCount);
// unsigned __int8 *__cdecl __mbsnbcat(unsigned __int8 *Dest, const unsigned __int8 *Source, size_t Count);
// unsigned __int8 *__cdecl __mbsrchr(const unsigned __int8 *String, unsigned int C);


//----- (00000000) --------------------------------------------------------
int __cdecl MemGetPrivateProfileInt(const char *a1, const char *a2, int a3, char *a4)
{
  int v5; // [esp+0h] [ebp-84h] BYREF
  char Buffer[64]; // [esp+4h] [ebp-80h] BYREF
  char Dest[64]; // [esp+44h] [ebp-40h] BYREF

  _sprintf(Buffer, "%ld", a3);
  MemGetPrivateProfileString(a1, a2, Buffer, Dest, 0x40u, a4);
  v5 = 0;
  _sscanf(Dest, "%ld", &v5);
  return v5;
}

//----- (00000084) --------------------------------------------------------
unsigned int __cdecl MemGetPrivateProfileString(const char *a1, const char *a2, const char *Source, char *Dest, size_t Count, char *a6)
{
  void (*v6)(char *const, const char *const, ...); // esi
  size_t v7; // ebp
  unsigned int v8; // kr08_4
  char *v9; // eax
  int (__cdecl *v10)(const unsigned __int8 *, const unsigned __int8 *, size_t); // edi
  char *v11; // esi
  char *v12; // esi
  size_t v13; // esi
  const char *v14; // edx
  const unsigned __int8 *v16; // [esp-8h] [ebp-198h]
  size_t v17; // [esp-4h] [ebp-194h]
  char v18[64]; // [esp+10h] [ebp-180h] BYREF
  char Buffer[64]; // [esp+50h] [ebp-140h] BYREF
  unsigned __int8 Str2[256]; // [esp+90h] [ebp-100h] BYREF

  v6 = (void (*)(char *const, const char *const, ...))_sprintf;
  _sprintf(Buffer, "[%s]", a1);
  v6(v18, "%s=", a2);
  v7 = strlen(Buffer);
  v8 = strlen(v18) + 1;
  v9 = GetLine(a6, Str2);
  v10 = __mbsnbicmp;
  v11 = v9;
  if ( __mbsnbicmp((const unsigned __int8 *)Buffer, Str2, v7) )
  {
    while ( *v11 )
    {
      v11 = GetLine(v11, Str2);
      if ( !v10((const unsigned __int8 *)Buffer, Str2, v7) )
        goto LABEL_4;
    }
    v13 = Count;
    v14 = Source;
    v17 = Count;
    goto LABEL_11;
  }
LABEL_4:
  v12 = GetLine(v11, Str2);
  if ( Str2[0] != 91 )
  {
    while ( v10((const unsigned __int8 *)v18, Str2, v8 - 1) )
    {
      if ( *v12 )
      {
        v12 = GetLine(v12, Str2);
        if ( Str2[0] != 91 )
          continue;
      }
      goto LABEL_8;
    }
    v13 = Count;
    v17 = Count;
    v14 = (const char *)&Str2[strlen(v18)];
LABEL_11:
    v16 = (const unsigned __int8 *)v14;
    goto LABEL_12;
  }
LABEL_8:
  v13 = Count;
  v17 = Count;
  v16 = (const unsigned __int8 *)Source;
LABEL_12:
  __mbsnbcpy((unsigned __int8 *)Dest, v16, v17);
  Dest[v13 - 1] = 0;
  return strlen(Dest);
}

//----- (00000210) --------------------------------------------------------
char *__cdecl GetLine(char *a1, _BYTE *a2)
{
  char *result; // eax
  int v3; // edx
  char i; // cl

  result = a1;
  v3 = 0;
  for ( i = *a1; *result; i = *result )
  {
    if ( i == 13 )
      break;
    if ( i == 10 )
      break;
    *a2++ = i;
    ++result;
    if ( ++v3 >= 255 )
      break;
  }
  *a2 = 0;
  if ( *result == 13 )
    ++result;
  if ( *result == 10 )
    ++result;
  return result;
}

//----- (00000260) --------------------------------------------------------
int __cdecl MemGetPrivateProfileSectionNames(char *Dest, unsigned int a2, char *a3)
{
  unsigned __int8 *v4; // ebp
  unsigned __int8 *v5; // eax
  unsigned int v6; // kr04_4
  size_t v7; // esi
  unsigned __int8 *v8; // ebp
  int v9; // ebp
  int result; // eax
  unsigned __int8 String; // [esp+10h] [ebp-100h] BYREF
  unsigned __int8 Source[255]; // [esp+11h] [ebp-FFh] BYREF

  v4 = (unsigned __int8 *)Dest;
  *Dest = 0;
  do
  {
    a3 = GetLine(a3, &String);
    if ( String == 91 )
    {
      v5 = __mbsrchr(&String, 0x5Du);
      if ( v5 )
      {
        *v5 = 0;
        v6 = strlen((const char *)Source) + 1;
        v7 = v6 - 1;
        if ( a2 < v6 + 1 )
          v7 = a2 - 2;
        __mbsnbcat(v4, Source, v7);
        v8 = &v4[v7];
        *v8 = 0;
        a2 += -1 - v7;
        v4 = v8 + 1;
        if ( a2 <= 1 )
          break;
      }
    }
  }
  while ( *a3 );
  *v4 = 0;
  v9 = v4 - (unsigned __int8 *)Dest;
  result = v9;
  if ( v9 > 0 )
    result = v9 - 1;
  return result;
}

// nfuncs=10 queued=4 decompiled=4 lumina nreq=0 worse=0 better=0
// ALL OK, 4 function(s) have been successfully decompiled
