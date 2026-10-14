c1_node * __cdecl
pm_spill_vi_function_pointer(c1_type *type,c1_node *right,c1_node *right2,c1_node *right3)

{
  char cVar1;
  uint entity;
  c1_type *type_00;
  c1_type *pcVar2;
  c1_node *pcVar3;
  c1_node *pcVar4;
  c1_node *pcVar5;
  c1_node *pcVar6;
  c1_node *left;
  c1_type local_10;
  
  entity = sym_new_local_key();
  local_10.base = type->base;
  local_10.debug_index = 0;
  local_10.code = 0x86;
  local_10.flags = (byte)(local_10.base)->flags & 0x1f;
  local_10.extra.cls = (c1_symbol *)0x0;
  type_00 = type_intern(&local_10);
  pcVar2 = type_int();
  cVar1 = (char)pcVar2->code;
  while (cVar1 < '\0') {
    pcVar2 = pcVar2->base;
    cVar1 = (char)pcVar2->code;
  }
  cVar1 = (&g_type_rank_table)[(byte)pcVar2->code & 0xf];
  pcVar3 = tree_new_leaf_9c(entity,type);
  pcVar4 = tree_new_int_constant(0);
  pcVar5 = tree_copy_to_arena(pcVar3,0);
  pcVar4 = tree_new_node('S',pcVar5,pcVar4,type_00);
  pcVar4 = tree_new_binary('4',pcVar4,right);
  pcVar2 = type_int();
  pcVar5 = tree_new_int_constant(4);
  pcVar6 = tree_copy_to_arena(pcVar3,0);
  pcVar5 = tree_new_node('S',pcVar6,pcVar5,pcVar2);
  pcVar5 = tree_new_binary('4',pcVar5,right2);
  pcVar2 = type_int();
  pcVar6 = tree_new_int_constant(cVar1 + 4);
  left = tree_copy_to_arena(pcVar3,0);
  pcVar6 = tree_new_node('S',left,pcVar6,pcVar2);
  pcVar6 = tree_new_binary('4',pcVar6,right3);
  pcVar4 = tree_new_binary_typed_right('7',pcVar4,pcVar5);
  pcVar4 = tree_new_binary_typed_right('7',pcVar4,pcVar6);
  pcVar3 = tree_new_rvalue(pcVar3);
  pcVar3 = tree_new_binary_typed_right('7',pcVar4,pcVar3);
  return pcVar3;
}

