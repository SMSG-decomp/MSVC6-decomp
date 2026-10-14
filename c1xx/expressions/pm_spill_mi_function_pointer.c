c1_node * __cdecl pm_spill_mi_function_pointer(c1_type *type,c1_node *right,c1_node *right2)

{
  uint entity;
  c1_type *type_00;
  c1_node *pcVar1;
  c1_node *pcVar2;
  c1_node *pcVar3;
  c1_type *pcVar4;
  c1_node *left;
  c1_type local_10;
  
  entity = sym_new_local_key();
  local_10.debug_index = 0;
  local_10.base = type->base;
  local_10.code = 0x86;
  local_10.extra.cls = (c1_symbol *)0x0;
  local_10.flags = (byte)(local_10.base)->flags & 0x1f;
  type_00 = type_intern(&local_10);
  pcVar1 = tree_new_leaf_9c(entity,type);
  pcVar4 = type_00;
  pcVar2 = tree_new_int_constant(0);
  pcVar3 = tree_copy_to_arena(pcVar1,0);
  pcVar2 = tree_new_node('S',pcVar3,pcVar2,pcVar4);
  pcVar2 = tree_new_node('4',pcVar2,right,type_00);
  pcVar4 = type_int();
  pcVar3 = tree_new_int_constant(4);
  left = tree_copy_to_arena(pcVar1,0);
  pcVar3 = tree_new_node('S',left,pcVar3,pcVar4);
  pcVar4 = type_int();
  pcVar3 = tree_new_node('4',pcVar3,right2,pcVar4);
  pcVar2 = tree_new_binary_typed_right('7',pcVar2,pcVar3);
  pcVar1 = tree_new_rvalue(pcVar1);
  pcVar1 = tree_new_binary_typed_right('7',pcVar2,pcVar1);
  return pcVar1;
}

