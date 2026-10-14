void sym_init_global_helper_name(void)

{
  char *s;
  fe_name *pfVar1;
  c1_node *node;
  
  sym_ensure_global_helper_function();
  s = (char *)pdb_namemap_symbol_name(PTR_104d1b38);
  pfVar1 = name_intern(s);
  PTR_104d1b38->name = pfVar1;
  init_set_target_symbol(PTR_104d1b38);
  PTR_104d1b38 = (c1_symbol *)decl_begin_initialized_definition(PTR_104d1b38);
  node = tree_new_int_constant(g_function_start_line);
  decl_finish_initialization(PTR_104d1b38,node);
  type_check_destructible_2(PTR_104d1b38);
  PTR_104d1b38->flags2 = PTR_104d1b38->flags2 & 0xf7;
  il_emit_global_symbol((int *)&PTR_104d1b38->name);
  PTR_104d1b38->name = g_name_line_var;
  return;
}

