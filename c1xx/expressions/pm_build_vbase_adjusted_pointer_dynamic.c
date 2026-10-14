c1_node * __cdecl
pm_build_vbase_adjusted_pointer_dynamic
          (c1_node *left,int node,c1_node *right,c1_node *src,c1_node *right2)

{
  c1_type *pcVar1;
  c1_node *pcVar2;
  c1_node *pcVar3;
  c1_type local_10;
  
  local_10.code = 0x83;
  local_10.debug_index = 0;
  local_10.flags = 0;
  local_10.base = type_int();
  local_10.extra.cls = (c1_symbol *)0x0;
  pcVar1 = type_intern(&local_10);
  local_10.debug_index = 0;
  local_10.code = 0x82;
  local_10.flags = decl_apply_default_calling_convention(0x82,0);
  local_10.extra.cls = (c1_symbol *)0x0;
  local_10.base = pcVar1;
  pcVar1 = type_intern(&local_10);
  pcVar2 = tree_copy_to_arena(src,0);
  pcVar2 = tree_new_node('Q',left,pcVar2,pcVar1);
  pcVar3 = tree_copy_to_arena(pcVar2,0);
  pcVar3 = tree_new_rvalue(pcVar3);
  pcVar3 = tree_new_binary_typed_right('Q',pcVar3,right2);
  pcVar3 = tree_new_rvalue(pcVar3);
  pcVar2 = tree_new_binary('Q',pcVar2,pcVar3);
  pcVar2 = tree_new_binary('Q',pcVar2,right);
  return pcVar2;
}

