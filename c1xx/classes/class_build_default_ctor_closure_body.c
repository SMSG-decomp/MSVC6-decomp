void __cdecl class_build_default_ctor_closure_body(c1_symbol *cls)

{
  c1_node *obj;
  int args;
  char emit;
  char keep_vbase_flag;
  
  keep_vbase_flag = '\x01';
  emit = '\x01';
  args = 0;
  obj = expr_this_pointer((c1_symbol *)0x0);
  expr_build_constructor_call(cls,obj,args,emit,keep_vbase_flag);
  return;
}

