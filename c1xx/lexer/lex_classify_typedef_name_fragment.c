c1_u8 * __cdecl lex_classify_typedef_name_fragment(uint flags_c8,c1_symbol *sym)

{
  fe_name *name;
  c1_u8 *pcVar1;
  c1_arena *pcVar2;
  c1_type *pcVar3;
  c1_symbol *pcVar4;
  c1_u8 *pcVar5;
  int iVar6;
  uint *puVar7;
  uint *puVar8;
  
  if (((((flags_c8 & 0x20000000) == 0) && ((sym->kind & 0x1f) == 10)) && ((sym->storage & 7) == 7))
     && ((sym->type->code & 0x300) != 0)) {
    pcVar4 = (sym->type->extra).cls;
    if ((pcVar4->scope_index != 0) &&
       ((g_scope_vector->entries[(short)pcVar4->scope_index]->kind & 0x1f) == 4)) {
      tree_list_arena_set(5);
      pcVar3 = tree_new_scope_chain_list((int)pcVar4);
      tree_list_arena_restore();
      name = pcVar4->name;
      pcVar4 = arena_alloc(g_arenas + 5,g_symbol_size_table[0x12] + 3 & 0xfffffffc);
      if (pcVar4 == (c1_symbol *)0x0) {
        pcVar4 = (c1_symbol *)0x0;
      }
      else {
        pcVar4 = sym_init_kind(pcVar4,'\x12',name,5);
      }
      pcVar4->type = pcVar3;
      pcVar5 = g_arenas[4].cur;
      g_arenas[4].cur = g_arenas[4].cur + 8;
      if (g_arenas[4].end < g_arenas[4].cur) {
        arena_grow(g_arenas + 4);
      }
      if (pcVar5 == (c1_u8 *)0x0) {
        g_yylval = 0;
      }
      else {
        *(c1_symbol **)pcVar5 = pcVar4;
        pcVar5[4] = '\0';
        pcVar5[5] = '\0';
        pcVar5[6] = '\0';
        pcVar5[7] = '\0';
        g_yylval = (uint)pcVar5;
      }
      if (g_token_arena_index == 0) {
        if (g_pool_default_left < 0x30) {
          pool_reserve((c1xx_pool *)&g_pool_default,0x30);
        }
        g_pool_default_left = g_pool_default_left - 0x30;
        pcVar5 = g_pool_default;
        g_pool_default = g_pool_default + 0x30;
      }
      else {
        pcVar2 = g_arenas + g_token_arena_index;
        pcVar5 = pcVar2->cur;
        pcVar1 = g_arenas[g_token_arena_index].end;
        pcVar2->cur = pcVar5 + 0x30;
        if (pcVar1 < pcVar5 + 0x30) {
          arena_grow(pcVar2);
        }
      }
      if (pcVar5 == (c1_u8 *)0x0) {
        return (c1_u8 *)0x0;
      }
      *pcVar5 = 0x96;
      puVar7 = &g_yylval;
      puVar8 = (uint *)(pcVar5 + 8);
      for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      return pcVar5;
    }
  }
  g_yylval = (uint)sym;
  if (g_token_arena_index == 0) {
    if (g_pool_default_left < 0x30) {
      pool_reserve((c1xx_pool *)&g_pool_default,0x30);
    }
    g_pool_default_left = g_pool_default_left - 0x30;
    pcVar5 = g_pool_default;
    g_pool_default = g_pool_default + 0x30;
  }
  else {
    pcVar2 = g_arenas + g_token_arena_index;
    pcVar5 = pcVar2->cur;
    pcVar1 = g_arenas[g_token_arena_index].end;
    pcVar2->cur = pcVar5 + 0x30;
    if (pcVar1 < pcVar5 + 0x30) {
      arena_grow(pcVar2);
    }
  }
  if (pcVar5 == (c1_u8 *)0x0) {
    return (c1_u8 *)0x0;
  }
  *pcVar5 = '\x1e';
  puVar7 = &g_yylval;
  puVar8 = (uint *)(pcVar5 + 8);
  for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar8 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
  }
  return pcVar5;
}

