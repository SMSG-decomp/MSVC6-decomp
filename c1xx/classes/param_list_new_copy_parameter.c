c1_u8 * __cdecl param_list_new_copy_parameter(c1_symbol *tag,c1_u16 cv)

{
  c1_decl_record *pcVar1;
  c1_type *pcVar2;
  c1_symbol *sym;
  int iVar3;
  c1_declarator *d;
  c1_u32 *spec_word;
  c1_u32 *spec_word_2;
  c1_u8 *pcVar4;
  c1_type local_28;
  c1_u32 local_18 [6];
  undefined2 type_code;
  
  d = (c1_declarator *)g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 0x58;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  if (d == (c1_declarator *)0x0) {
    d = (c1_declarator *)0x0;
  }
  else {
    *(c1_symbol **)d = PTR_104d164c;
    *(c1_u8 *)((int)d + 0x28) = '\0';
    *(c1_u8 *)((int)d + 0x29) = '\0';
    *(c1_u8 *)((int)d + 0x2a) = '\0';
    *(c1_u8 *)((int)d + 0x2b) = '\0';
    *(c1_u8 *)((int)d + 0x30) = '\x01';
    *(c1_u8 *)((int)d + 0x4c) = '\x05';
    *(c1_u8 *)((int)d + 0x4d) = '\0';
    *(c1_u8 *)((int)d + 0x4e) = '\0';
    *(c1_u8 *)((int)d + 0x4f) = '\0';
    pcVar1 = arena_alloc(g_arenas + 5,0x4c);
    if (pcVar1 == (c1_decl_record *)0x0) {
      *(c1_u8 *)((int)d + 4) = '\0';
      *(c1_u8 *)((int)d + 5) = '\0';
      *(c1_u8 *)((int)d + 6) = '\0';
      *(c1_u8 *)((int)d + 7) = '\0';
      *(int *)((int)d + 0x24) = g_token_position;
    }
    else {
      pcVar1 = decl_record_init_default(pcVar1,d->name,*(c1_overload_set **)((int)d + 0x28));
      *(c1_decl_record **)((int)d + 4) = pcVar1;
      *(int *)((int)d + 0x24) = g_token_position;
    }
  }
  d->flags57 = d->flags57 | 0x20;
  local_18[0]._0_1_ = (byte)local_18[0] & 0xfd | 5;
  spec_word_2 = local_18;
  for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
    *spec_word_2 = 0;
    spec_word_2 = spec_word_2 + 1;
  }
  local_18[0]._0_1_ = (byte)local_18[0] ^ ((byte)local_18[0] ^ 5) & 7;
  pcVar2 = tag->type;
  if ((cv != 0) && (pcVar2->flags != cv)) {
    type_code = pcVar2->code;
    local_28.flags = cv;
    local_28.code = type_code;
    local_28.base = pcVar2->base;
    local_28.extra = pcVar2->extra;
    local_28.debug_index = pcVar2->debug_index;
    pcVar2 = type_intern(&local_28);
  }
  pcVar1 = d->decl;
  pcVar1->spec_type = pcVar2;
  local_28._0_4_ = local_28._0_4_ & 0xffff0000;
  local_28.base = (c1_type *)0x0;
  decl_add_reference_modifier(pcVar1,&local_28.code);
  decl_finish_declarator(pcVar1);
  spec_word = local_18;
  pcVar4 = d->spec;
  for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(c1_u32 *)pcVar4 = *spec_word;
    spec_word = spec_word + 1;
    pcVar4 = pcVar4 + 4;
  }
  decl_process_declaration(d);
  sym = sym_new_from_declarator(d,4);
  sym_mark_referenced(sym);
  pcVar4 = g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 0x1c;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  if (pcVar4 != (c1_u8 *)0x0) {
    pcVar4[0x10] = '\x03';
    pcVar4[0x11] = '\0';
    pcVar4[0x12] = '\0';
    pcVar4[0x13] = '\0';
    pcVar4[0x14] = '\0';
    pcVar4[0] = '\0';
    pcVar4[1] = '\0';
    pcVar4[2] = '\0';
    pcVar4[3] = '\0';
    sym_list_append(pcVar4,sym);
    return pcVar4;
  }
  sym_list_append((void *)0x0,sym);
  return (c1_u8 *)0x0;
}

