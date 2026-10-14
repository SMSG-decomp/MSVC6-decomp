void func_emit_global_helper_symbol(void)

{
  char *s;
  fe_name *pfVar1;
  c1_node *node;
  
  sym_ensure_global_helper_function();
  s = (char *)pdb_namemap_symbol_name(g_line_var_symbol);
  pfVar1 = name_intern(s);
  g_line_var_symbol->name = pfVar1;
  g_line_var_symbol = (c1_symbol *)decl_begin_initialized_definition(g_line_var_symbol);
  node = tree_new_int_constant(g_function_start_line);
  decl_finish_initialization(g_line_var_symbol,node);
  g_line_var_symbol->flags1 = g_line_var_symbol->flags1 & 0xfd;
  il_emit_global_symbol((int *)&g_line_var_symbol->name);
  g_line_var_symbol->name = g_name_LINE_Var;
  return;
}

