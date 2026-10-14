c1_symbol * __cdecl decl_new_compiler_formal(void *name,c1_type *type)

{
  byte bVar1;
  c1_decl_record *pcVar2;
  c1_symbol *pcVar3;
  int iVar4;
  c1_declarator *d;
  c1_u32 *spec_word;
  c1_u32 *spec_word_2;
  c1_u32 *spec_dst;
  c1_u32 local_18 [6];
  
  d = (c1_declarator *)g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 0x58;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  if (d == (c1_declarator *)0x0) {
    d = (c1_declarator *)0x0;
  }
  else {
    d->name = name;
    *(c1_u8 *)((int)d + 0x28) = '\0';
    *(c1_u8 *)((int)d + 0x29) = '\0';
    *(c1_u8 *)((int)d + 0x2a) = '\0';
    *(c1_u8 *)((int)d + 0x2b) = '\0';
    *(c1_u8 *)((int)d + 0x30) = '\x01';
    *(c1_u8 *)((int)d + 0x4c) = '\x05';
    *(c1_u8 *)((int)d + 0x4d) = '\0';
    *(c1_u8 *)((int)d + 0x4e) = '\0';
    *(c1_u8 *)((int)d + 0x4f) = '\0';
    pcVar2 = arena_alloc(g_arenas + 5,0x4c);
    if (pcVar2 == (c1_decl_record *)0x0) {
      *(c1_u8 *)((int)d + 4) = '\0';
      *(c1_u8 *)((int)d + 5) = '\0';
      *(c1_u8 *)((int)d + 6) = '\0';
      *(c1_u8 *)((int)d + 7) = '\0';
      *(int *)((int)d + 0x24) = g_token_position;
    }
    else {
      pcVar2 = decl_record_init_default(pcVar2,d->name,*(c1_overload_set **)((int)d + 0x28));
      *(c1_decl_record **)((int)d + 4) = pcVar2;
      *(int *)((int)d + 0x24) = g_token_position;
    }
  }
  local_18[0]._0_1_ = (byte)local_18[0] & 0xfd | 5;
  spec_word_2 = local_18;
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    *spec_word_2 = 0;
    spec_word_2 = spec_word_2 + 1;
  }
  bVar1 = d->flags54;
  local_18[0]._0_1_ = (byte)local_18[0] ^ ((byte)local_18[0] ^ 5) & 7;
  spec_word = local_18;
  spec_dst = (c1_u32 *)d->spec;
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    *spec_dst = *spec_word;
    spec_word = spec_word + 1;
    spec_dst = spec_dst + 1;
  }
  d->flags54 = bVar1 | 0x20;
  d->flags57 = d->flags57 | 0x20;
  d->type = type;
  decl_process_declaration(d);
  pcVar3 = sym_new_from_declarator(d,4);
  return pcVar3;
}

