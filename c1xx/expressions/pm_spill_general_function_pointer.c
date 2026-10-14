c1_node * __cdecl
pm_spill_general_function_pointer
          (c1_type *type,c1_node *right,c1_node *right2,int value,c1_node *right3)

{
  char cVar1;
  char cVar2;
  uint entity;
  c1_type *type_00;
  c1_type *pcVar3;
  c1_node *pcVar4;
  c1_node *pcVar5;
  c1_node *pcVar6;
  c1_node *pcVar7;
  c1_node *pcVar8;
  c1_node *left;
  c1_type local_10;
  
  entity = sym_new_local_key();
  local_10.code = 0x86;
  local_10.base = type->base;
  local_10.debug_index = 0;
  local_10.extra.cls = (c1_symbol *)0x0;
  local_10.flags = (byte)(local_10.base)->flags & 0x1f;
  type_00 = type_intern(&local_10);
  pcVar3 = type_int();
  cVar1 = (char)pcVar3->code;
  while (cVar1 < '\0') {
    pcVar3 = pcVar3->base;
    cVar1 = (char)pcVar3->code;
  }
  cVar1 = (&g_type_rank_table)[(byte)pcVar3->code & 0xf];
  pcVar3 = type_int();
  cVar2 = (char)pcVar3->code;
  while (cVar2 < '\0') {
    pcVar3 = pcVar3->base;
    cVar2 = (char)pcVar3->code;
  }
  cVar2 = (&g_type_rank_table)[(byte)pcVar3->code & 0xf];
  pcVar4 = tree_new_leaf_9c(entity,type);
  pcVar5 = tree_new_int_constant(0);
  pcVar6 = tree_copy_to_arena(pcVar4,0);
  pcVar5 = tree_new_node('S',pcVar6,pcVar5,type_00);
  pcVar5 = tree_new_binary('4',pcVar5,right);
  pcVar3 = type_int();
  pcVar6 = tree_new_int_constant(4);
  pcVar7 = tree_copy_to_arena(pcVar4,0);
  pcVar6 = tree_new_node('S',pcVar7,pcVar6,pcVar3);
  pcVar6 = tree_new_binary('4',pcVar6,right2);
  pcVar3 = type_int();
  pcVar7 = tree_new_int_constant(cVar1 + 4);
  pcVar8 = tree_copy_to_arena(pcVar4,0);
  pcVar7 = tree_new_node('S',pcVar8,pcVar7,pcVar3);
  pcVar8 = tree_new_int_constant(value);
  pcVar7 = tree_new_binary('4',pcVar7,pcVar8);
  pcVar3 = type_int();
  pcVar8 = tree_new_int_constant((int)cVar2 + cVar1 + 4);
  left = tree_copy_to_arena(pcVar4,0);
  pcVar8 = tree_new_node('S',left,pcVar8,pcVar3);
  pcVar8 = tree_new_binary('4',pcVar8,right3);
  pcVar5 = tree_new_binary_typed_right('7',pcVar5,pcVar6);
  pcVar5 = tree_new_binary_typed_right('7',pcVar5,pcVar7);
  pcVar5 = tree_new_binary_typed_right('7',pcVar5,pcVar8);
  pcVar4 = tree_new_rvalue(pcVar4);
  pcVar4 = tree_new_binary_typed_right('7',pcVar5,pcVar4);
  return pcVar4;
}

