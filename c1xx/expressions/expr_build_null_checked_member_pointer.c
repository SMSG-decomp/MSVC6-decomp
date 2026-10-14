c1_node * __cdecl
expr_build_null_checked_member_pointer(c1_node *adjusted,c1_node *orig,c1_type *type)

{
  c1_node *pcVar1;
  c1_node *pcVar2;
  
  pcVar1 = tree_new_null_data_member_pointer(type);
  pcVar1 = tree_new_node(';',orig,pcVar1,g_type_int);
  pcVar2 = expr_member_pointer_null_constant(adjusted->type);
  pcVar2 = tree_new_binary('6',pcVar2,adjusted);
  pcVar1 = tree_new_binary_typed_right('V',pcVar1,pcVar2);
  return pcVar1;
}

