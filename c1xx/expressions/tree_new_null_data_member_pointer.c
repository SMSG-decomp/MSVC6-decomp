c1_node * __cdecl tree_new_null_data_member_pointer(c1_type *type)

{
  uint uVar1;
  c1_node *pcVar2;
  
  uVar1 = type_member_pointer_class_has_vfptr(type);
  pcVar2 = tree_new_int_constant_raw(((char)uVar1 != '\0') - 1);
  pcVar2->type = type;
  return pcVar2;
}

