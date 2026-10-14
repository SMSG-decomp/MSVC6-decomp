c1_symbol * decl_check_definition_dllimport(c1_symbol *sym,c1_declarator *d)

{
  int iVar1;
  c1_symbol *pcVar2;
  
  if ((g_compile_flags_c4 & 0x200) == 0) {
    if (sym == (c1_symbol *)0x0) {
      sym = sym_new_from_declarator(d,5);
    }
    diag_error(0x1eb,sym,0x176);
  }
  if (g_code_seg_name != (void *)0x0) {
    sym_set_segment_checked(d->sym,g_code_seg_name);
  }
  g_current_function = func_body_begin(d->sym);
  g_function_context_word = g_pending_function_word;
  g_function_parameter_scope = g_pending_parameter_scope;
  if (((byte)g_function_return_type->code >> 6 & 1) == 0) {
    iVar1 = type_size(g_function_return_type);
    if (iVar1 == 0) {
      if ((g_function_return_type->code & 0x200) == 0) {
        pcVar2 = (c1_symbol *)0x0;
      }
      else {
        pcVar2 = (g_function_return_type->extra).cls;
      }
      diag_error(0x4f,g_current_function,g_function_return_type,pcVar2);
    }
  }
  return g_current_function;
}

