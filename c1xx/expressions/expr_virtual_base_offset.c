c1_node * __cdecl
expr_virtual_base_offset(c1_node *left,int vbptr_offset,int slot,c1_type *vbtable_type)

{
  c1_node *pcVar1;
  c1_type *type;
  
  pcVar1 = tree_new_offset(left,vbptr_offset,left->type);
  pcVar1 = tree_new_unary('=',vbtable_type,pcVar1);
  pcVar1 = tree_new_offset(pcVar1,slot,vbtable_type);
  type = type_int();
  pcVar1 = tree_new_unary('=',type,pcVar1);
  return pcVar1;
}

