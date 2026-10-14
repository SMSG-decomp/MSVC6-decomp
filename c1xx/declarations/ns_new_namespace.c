c1_symbol * __cdecl ns_new_namespace(fe_name *name,c1_u8 unnamed)

{
  byte *pbVar1;
  c1_symbol *pcVar2;
  c1_u8 *pcVar3;
  c1_symbol *pcVar4;
  c1_u8 *pcVar5;
  
  pcVar2 = sym_take_free_record(0x19,name,0);
  if (pcVar2 == (c1_symbol *)0x0) {
    pcVar2 = arena_alloc(g_arenas,g_symbol_size_table[0x19] + 3 & 0xfffffffc);
    if (pcVar2 == (c1_symbol *)0x0) {
      pcVar2 = (c1_symbol *)0x0;
    }
    else {
      pcVar2 = sym_init_kind(pcVar2,'\x19',name,0);
    }
  }
  pcVar5 = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 8;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  pcVar2->type = (c1_type *)pcVar5;
  pcVar5 = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 0x24;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  if (pcVar5 == (c1_u8 *)0x0) {
    pcVar5 = (c1_u8 *)0x0;
  }
  else {
    hash_scope_construct((c1xx_hash_scope *)pcVar5,0xff,'\0',(c1xx_scope *)0x0);
    *(c1_symbol **)(pcVar5 + 0x20) = pcVar2;
    *(undefined ***)pcVar5 = &PTR_hash_scope_has_entries_104cef40;
    pcVar3 = scope_pool_or_arena_alloc(*(int *)(pcVar5 + 0x18) * 4 + 4,0);
    *(c1_u8 **)(pcVar5 + 0x14) = pcVar3;
  }
  *(c1_u8 **)pcVar2->type = pcVar5;
  if (unnamed != '\0') {
    pbVar1 = (byte *)((int)&pcVar2->type->base + 2);
    *pbVar1 = *pbVar1 | 1;
  }
  pcVar2->flags2 = pcVar2->flags2 | 4;
  if ((g_current_scope->current != g_current_scope->global_scope) && (g_error_count == 0)) {
    pcVar4 = scope_current_namespace(g_current_scope);
    pcVar2->scope_index = *(c1_u16 *)&pcVar4->type->base;
  }
  scope_vector_add(pcVar2,'\x19');
  return pcVar2;
}

