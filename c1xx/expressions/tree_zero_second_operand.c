int __cdecl tree_zero_second_operand(int node)

{
  int iVar1;
  c1_node *pcVar2;
  
  iVar1 = *(int *)(*(int *)(node + 0x10) + 0x14);
  pcVar2 = tree_new_int_constant(0);
  *(c1_node **)(iVar1 + 0x10) = pcVar2;
  return node;
}

