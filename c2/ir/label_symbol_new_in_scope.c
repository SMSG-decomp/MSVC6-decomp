c2_fe_symbol * __fastcall label_symbol_new_in_scope(c2_function *fn)

{
  c2_scope_table *pcVar1;
  c2_fe_symbol *pcVar2;
  
  pcVar1 = g_cur_scope;
  g_cur_scope = fn->scope;
  pcVar2 = label_symbol_new();
  g_cur_scope = pcVar1;
  return pcVar2;
}

