void __cdecl sym_global_helper_set_decorated_name_2(void)

{
  ushort uVar1;
  fe_name *pfVar2;
  
  uVar1 = g_block_scope_number;
  g_block_scope_number = 2;
  pfVar2 = name_intern_symbol_decorated(g_line_var_symbol);
  g_line_var_symbol->name = pfVar2;
  g_block_scope_number = uVar1;
  return;
}

