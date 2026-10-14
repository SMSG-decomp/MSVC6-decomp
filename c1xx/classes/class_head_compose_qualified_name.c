byte __fastcall class_head_compose_qualified_name(void *head,c1_u8 *unused_edx)

{
  byte bVar1;
  c1_arena *a;
  byte *token;
  c1_u8 *token_00;
  int iVar2;
  c1_u8 *extraout_EDX;
  c1_u8 *extraout_EDX_00;
  undefined4 *puVar3;
  c1_u8 *pcVar4;
  
  if (*(int *)((int)head + 4) != 0) {
    return 0;
  }
  if (*(int *)((int)head + 8) == 0) {
    token = lex_compose_qualified_name
                      ((char *)0x0,
                       CONCAT31((int3)((uint)head >> 8),
                                (*(ushort *)((int)head + 0xc) & 0xfff) == 0x802));
  }
  else {
    if (g_token_arena_index == 0) {
      if (g_pool_default_left < 0x30) {
        pool_reserve((c1xx_pool *)&g_pool_default,0x30);
        unused_edx = extraout_EDX;
      }
      g_pool_default_left = g_pool_default_left - 0x30;
      token_00 = g_pool_default;
      g_pool_default = g_pool_default + 0x30;
    }
    else {
      a = g_arenas + g_token_arena_index;
      token_00 = a->cur;
      unused_edx = g_arenas[g_token_arena_index].end;
      a->cur = token_00 + 0x30;
      if (unused_edx < token_00 + 0x30) {
        arena_grow(a);
        unused_edx = extraout_EDX_00;
      }
    }
    if (token_00 == (c1_u8 *)0x0) {
      token_00 = (c1_u8 *)0x0;
    }
    else {
      puVar3 = *(undefined4 **)((int)head + 8);
      pcVar4 = token_00;
      for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
        *(undefined4 *)pcVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        pcVar4 = pcVar4 + 4;
      }
    }
    token = lex_compose_qualified_name
                      ((char *)token_00,
                       CONCAT31((int3)((uint)unused_edx >> 8),
                                (*(ushort *)((int)head + 0xc) & 0xfff) == 0x802));
  }
  if (*token != 0x96) {
    bVar1 = class_head_take_name(head,token);
    return bVar1;
  }
  bVar1 = class_head_take_qualified_name(head,token);
  return bVar1;
}

