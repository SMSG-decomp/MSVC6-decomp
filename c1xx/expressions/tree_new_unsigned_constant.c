c1_node * __cdecl tree_new_unsigned_constant(int value)

{
  c1_node *pcVar1;
  
  pcVar1 = tree_new_int_constant(value);
  pcVar1->type = g_type_unsigned_int;
  return pcVar1;
}

