void tmpl_check_declaration_context(void)

{
  byte *pbVar1;
  int iVar2;
  
  diag_error(0x3b7);
  if (g_linkage_stack[g_linkage_depth] == 2) {
    diag_error(0x37e);
  }
  iVar2 = g_paren_depth + 1;
  if (iVar2 < 0x3c) {
    pbVar1 = g_paren_level_flags + g_paren_depth + 1;
    g_paren_depth = iVar2;
    *pbVar1 = 0;
    *pbVar1 = *pbVar1 | 0x18;
    g_compile_flags_c8 = g_compile_flags_c8 | 0x10000000;
    g_block_depth = g_block_depth + '\x01';
    template_parameter_scope_push(g_current_scope,(c1_sym_list *)0x0);
    if (g_template_depth != 0x40) {
      g_template_parameter_index = 0;
      g_template_depth = g_template_depth + 1;
      return;
    }
    diag_fatal_simple(0x6e);
  }
  g_paren_depth = iVar2;
  diag_fatal_simple(0xd);
}

