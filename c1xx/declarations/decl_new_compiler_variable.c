c1_symbol * __cdecl decl_new_compiler_variable(byte storage,c1_type *type)

{
  c1_u8 *pcVar1;
  void *pvVar2;
  c1_decl_record *pcVar3;
  c1_symbol *pcVar4;
  int iVar5;
  byte bVar6;
  c1_declarator *d;
  uint *spec_cursor;
  uint *spec_cursor_3;
  uint *spec_cursor_2;
  c1_u8 spec [24];
  c1_decl_record local_4c;
  
  pcVar1 = g_arenas[5].cur;
  if (((storage == 3) && (g_current_function != (c1_symbol *)0x0)) &&
     ((g_current_function->flags21 & 1) != 0)) {
    pcVar4 = decl_new_compiler_variable_inline_block
                       (g_current_function,(c1_declarator *)0x0,spec[0],3,type);
    return pcVar4;
  }
  g_arenas[5].cur = g_arenas[5].cur + 0x58;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  d = (c1_declarator *)0x0;
  if (pcVar1 != (c1_u8 *)0x0) {
    pvVar2 = name_new_S();
    *(void **)pcVar1 = pvVar2;
    pcVar1[0x28] = '\0';
    pcVar1[0x29] = '\0';
    pcVar1[0x2a] = '\0';
    pcVar1[0x2b] = '\0';
    pcVar1[0x30] = '\x01';
    pcVar1[0x4c] = '\0';
    pcVar1[0x4d] = '\0';
    pcVar1[0x4e] = '\0';
    pcVar1[0x4f] = '\0';
    pcVar3 = arena_alloc(g_arenas + 5,0x4c);
    if (pcVar3 == (c1_decl_record *)0x0) {
      pcVar3 = (c1_decl_record *)0x0;
    }
    else {
      pcVar3 = decl_record_init_default
                         (pcVar3,*(void **)pcVar1,*(c1_overload_set **)(pcVar1 + 0x28));
    }
    *(c1_decl_record **)(pcVar1 + 4) = pcVar3;
    *(int *)(pcVar1 + 0x24) = g_token_position;
    d = (c1_declarator *)pcVar1;
  }
  d->flags54 = d->flags54 | 0x20;
  if ((((byte)g_compile_flags_c4 & 0x20) != 0) && (storage != 3)) {
    storage = 3;
  }
  spec[0] = spec[0] ^ (spec[0] ^ storage) & 7;
  bVar6 = spec[0] & 7;
  spec_cursor_3 = (uint *)spec;
  for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
    *spec_cursor_3 = 0;
    spec_cursor_3 = spec_cursor_3 + 1;
  }
  spec[0] = spec[0] ^ (spec[0] ^ bVar6) & 7;
  decl_record_init(&local_4c,type,g_default_decl_specifiers);
  decl_finish_declarator(&local_4c);
  d->decl = &local_4c;
  spec_cursor = (uint *)spec;
  spec_cursor_2 = (uint *)d->spec;
  for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
    *spec_cursor_2 = *spec_cursor;
    spec_cursor = spec_cursor + 1;
    spec_cursor_2 = spec_cursor_2 + 1;
  }
  pcVar4 = decl_declare_and_check(d,spec);
  return pcVar4;
}

