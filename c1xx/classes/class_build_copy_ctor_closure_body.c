void __cdecl class_build_copy_ctor_closure_body(c1_symbol *cls)

{
  c1_node *pcVar1;
  c1_node *obj;
  int flag;
  char emit;
  char keep_vbase_flag;
  
  keep_vbase_flag = '\x01';
  emit = '\x01';
  flag = 1;
  pcVar1 = expr_lookup_name_expression(PTR_104d164c);
  pcVar1 = tree_append_list_item((c1_node *)0x0,pcVar1,flag);
  obj = expr_this_pointer((c1_symbol *)0x0);
  expr_build_constructor_call(cls,obj,(int)pcVar1,emit,keep_vbase_flag);
  return;
}

