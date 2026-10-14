c1_node * __cdecl
expr_member_access_via_vbase_spilled
          (uint op,c1_node *object,c1_type *type,int vbptr_offset,int vbase_slot,int member_offset,
          c1_type *vbtable_type)

{
  uint entity;
  c1_node *pcVar1;
  c1_node *left;
  c1_type *type_00;
  
  type_00 = type;
  entity = sym_new_local_key();
  pcVar1 = tree_new_leaf_9c(entity,type_00);
  left = tree_new_binary('4',pcVar1,object);
  pcVar1 = tree_copy_to_arena(pcVar1,0);
  pcVar1 = tree_new_rvalue(pcVar1);
  pcVar1 = expr_member_offset_access
                     (op,pcVar1,type,vbptr_offset,vbase_slot,member_offset,vbtable_type);
  pcVar1 = expr_build_builtin_binary('7',left,pcVar1);
  return pcVar1;
}

