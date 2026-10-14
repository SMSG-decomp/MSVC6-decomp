wchar_t * __cdecl multibyte_to_wide_arena(char *text)

{
  char cVar1;
  c1_u8 *lpWideCharStr;
  uint uVar2;
  char *pcVar3;
  
  lpWideCharStr = g_arenas[5].cur;
  uVar2 = 0xffffffff;
  pcVar3 = text;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  g_arenas[5].cur = g_arenas[5].cur + (~uVar2 * 2 + 3 & 0xfffffffc);
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  lpWideCharStr[0] = '\0';
  lpWideCharStr[1] = '\0';
  MultiByteToWideChar(0,0,text,-1,(LPWSTR)lpWideCharStr,~uVar2);
  return (wchar_t *)lpWideCharStr;
}

