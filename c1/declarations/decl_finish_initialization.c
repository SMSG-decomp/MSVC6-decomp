void __cdecl decl_finish_initialization(c1_symbol *sym,c1_node *node)

{
  init_check_aggregate_or_constant(sym,node);
  g_init_symbol = (c1_symbol *)0x0;
  if ((g_compile_flags_cc & 0x800) != 0) {
    g_compile_flags_cc = g_compile_flags_cc & 0xfffff7ff;
    sym->flags3 = sym->flags3 & 0xfb;
  }
  if ((g_il_block_level != '\0') && (sym != (c1_symbol *)0x0)) {
    sym->key_ref = sym->key_ref & 0xfffffff8;
  }
  return;
}

