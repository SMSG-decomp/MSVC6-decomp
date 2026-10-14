c1_arg_item * __fastcall decl_finish_declarator_record(c1_declarator *d)

{
  byte bVar1;
  int iVar2;
  c1_arg_item *pcVar3;
  
  decl_check_conversion_return_type(d->decl,(c1xx_decl_specifiers *)&stack0x00000004);
  decl_finish_declarator(d->decl);
  pcVar3 = (c1_arg_item *)g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 0x14;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  if (pcVar3 == (c1_arg_item *)0x0) {
    pcVar3 = (c1_arg_item *)0x0;
  }
  else {
    bVar1 = *(byte *)((int)pcVar3 + 0xc);
    *(c1_type **)((int)pcVar3 + 0x10) = d->decl->type;
    *(c1_u8 *)((int)pcVar3 + 4) = '\0';
    *(c1_u8 *)((int)pcVar3 + 5) = '\0';
    *(c1_u8 *)((int)pcVar3 + 6) = '\0';
    *(c1_u8 *)((int)pcVar3 + 7) = '\0';
    *(c1_u8 *)((int)pcVar3 + 8) = '\0';
    *(c1_u8 *)((int)pcVar3 + 9) = '\0';
    *(c1_u8 *)((int)pcVar3 + 10) = '\0';
    *(c1_u8 *)((int)pcVar3 + 0xb) = '\0';
    *(byte *)((int)pcVar3 + 0xc) = bVar1 & 0xfc | 4;
    pcVar3->vtbl = &PTR_pch_fixup_list_object_104c4c3c;
  }
  iVar2 = g_paren_depth;
  g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffc;
  g_declarator_paren_base = g_declarator_paren_base + -1;
  g_pending_access_check[g_paren_depth] = (c1_symbol *)0x0;
  g_paren_level_flags[iVar2] = g_paren_level_flags[iVar2] & 0xfc | 0x2c;
  return pcVar3;
}

