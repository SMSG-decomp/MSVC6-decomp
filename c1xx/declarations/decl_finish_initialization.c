void __cdecl decl_finish_initialization(c1_symbol *sym,c1_node *node)

{
  c1_symbol *pcVar1;
  
  init_simple_initializer(sym,node);
  g_init_symbol = (c1_symbol *)0x0;
  if ((g_compile_flags_cc & 0x800) != 0) {
    g_compile_flags_cc = g_compile_flags_cc & 0xfffff7ff;
    sym->flags4 = sym->flags4 & 0xfb;
  }
  if (((g_il_block_level != '\0') && (sym != (c1_symbol *)0x0)) &&
     (((byte)g_compile_flags_c4 & 0x20) == 0)) {
    pcVar1 = sym_class_needing_init(sym);
    if (pcVar1 == (c1_symbol *)0x0) {
      sym->key_ref = sym->key_ref & 0xfffffff8;
    }
  }
  return;
}

