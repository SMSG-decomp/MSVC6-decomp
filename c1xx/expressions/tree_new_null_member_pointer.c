c1_node * __cdecl tree_new_null_member_pointer(c1_type *type)

{
  c1_node *pcVar1;
  c1_type *pcVar2;
  
  pcVar1 = tree_new_int_constant(0);
  pcVar2 = type_member_pointer_to(type);
  pcVar1->type = pcVar2;
  return pcVar1;
}

