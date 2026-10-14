void __cdecl arena_reset(int arena)

{
  uint uVar1;
  uint uVar2;
  c1_u8 *pcVar3;
  
  if (g_parse_context_depth == 0) {
    uVar1 = (int)g_arenas[arena].cur - (int)g_arenas[arena].base;
    pcVar3 = g_arenas[arena].base;
    for (uVar2 = uVar1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      pcVar3[0] = '\0';
      pcVar3[1] = '\0';
      pcVar3[2] = '\0';
      pcVar3[3] = '\0';
      pcVar3 = pcVar3 + 4;
    }
    for (uVar1 = uVar1 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
      *pcVar3 = '\0';
      pcVar3 = pcVar3 + 1;
    }
    g_arenas[arena].cur = g_arenas[arena].base;
  }
  return;
}

