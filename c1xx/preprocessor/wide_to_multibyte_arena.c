c1_u8 * __cdecl wide_to_multibyte_arena(wchar_t *wide)

{
  c1_u8 *lpMultiByteStr;
  size_t sVar1;
  
  sVar1 = wcslen(wide);
  lpMultiByteStr = g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + (sVar1 * 2 + 5 & 0xfffffffc);
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  *lpMultiByteStr = '\0';
  WideCharToMultiByte(0,0,wide,-1,(LPSTR)lpMultiByteStr,sVar1 * 2 + 2,(LPCSTR)0x0,(LPBOOL)0x0);
  return lpMultiByteStr;
}

