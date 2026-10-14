int __cdecl expr_build_operator_delete_call_not_found(c1_node *p)

{
  c1_node *args;
  c1_node *callee;
  int iVar1;
  
  args = tree_append_list_item((c1_node *)0x0,p,2);
  callee = tree_new_symbol_ref((c1_symbol *)0x0,'\0');
  iVar1 = expr_build_call(callee,args);
  return iVar1;
}

