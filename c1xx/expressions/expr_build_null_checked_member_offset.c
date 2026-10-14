c1_node * __cdecl expr_build_null_checked_member_offset(c1_node *adjusted,c1_node *orig)

{
  c1_node *pcVar1;
  c1_node *pcVar2;
  c1_type *type;
  
  type = g_type_int;
  pcVar1 = tree_new_int_constant(-1);
  pcVar1 = tree_new_node(';',orig,pcVar1,type);
  pcVar2 = expr_member_pointer_null_constant(adjusted->type);
  pcVar2 = tree_new_binary('6',pcVar2,adjusted);
  pcVar1 = tree_new_binary_typed_right('V',pcVar1,pcVar2);
  return pcVar1;
}

