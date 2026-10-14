c1_node * __cdecl
expr_member_offset_access
          (uint op,c1_node *node,c1_type *type,int offset,int slot,int offset2,c1_type *vbtable_type
          )

{
  c1_node *pcVar1;
  c1_node *pcVar2;
  c1_type *pcVar3;
  c1_node *pcVar4;
  
  pcVar1 = tree_new_offset(node,offset,type);
  pcVar2 = tree_copy_to_arena(pcVar1,0);
  pcVar2 = tree_new_unary('=',vbtable_type,pcVar2);
  pcVar2 = tree_new_offset(pcVar2,slot,vbtable_type);
  pcVar3 = type_int();
  pcVar2 = tree_new_unary('=',pcVar3,pcVar2);
  pcVar1 = tree_new_node('Q',pcVar1,pcVar2,type);
  pcVar1 = tree_new_offset(pcVar1,offset2,type);
  if (g_token_class[op & 0xff] != 'd') {
    return pcVar1;
  }
  pcVar3 = type;
  pcVar2 = tree_new_int_constant(0);
  pcVar4 = tree_copy_to_arena(node,0);
  pcVar2 = tree_new_node(';',pcVar4,pcVar2,pcVar3);
  pcVar4 = tree_new_int_constant(0);
  pcVar1 = tree_new_node('6',pcVar4,pcVar1,type);
  pcVar1 = tree_new_binary_typed_right('V',pcVar2,pcVar1);
  return pcVar1;
}

