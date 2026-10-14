void __cdecl init_check_non_aggregate(c1_symbol *sym,c1_symbol *level_sym,int scalar_flag)

{
  byte bVar1;
  int iVar2;
  
  diag_error(0x228,level_sym);
  g_init_level->flags = g_init_level->flags | 0x20;
  iVar2 = sym_has_scalar_type(g_init_level->sym);
  if ((iVar2 != 0) || (scalar_flag != 0)) {
    g_init_level->flags = g_init_level->flags | 4;
  }
  if ((((g_block_depth == '\0') || (bVar1 = g_init_level->sym->storage & 7, bVar1 < 4)) ||
      (6 < bVar1)) && (g_init_pending_data_symbol = sym, g_browse_file != (char *)0x0)) {
    (*g_il_emitter->vtbl->begin_block)();
    (*g_il_emitter->vtbl->set_owner)((int)g_init_pending_data_symbol);
    g_compile_flags_cc = g_compile_flags_cc | 0x4000;
  }
  g_compile_flags_c4 = g_compile_flags_c4 & 0xfffbffff;
  return;
}

