void __cdecl class_build_local_vftable_ctor_closure_body(c1_symbol *cls)

{
  c1_node *pcVar1;
  int args;
  char emit;
  char keep_vbase_flag;
  
  keep_vbase_flag = '\x01';
  emit = '\x01';
  args = 0;
  pcVar1 = expr_this_pointer((c1_symbol *)0x0);
  expr_build_constructor_call(cls,pcVar1,args,emit,keep_vbase_flag);
  pcVar1 = expr_this_pointer((c1_symbol *)0x0);
  pcVar1 = class_build_vptr_stores(pcVar1,cls);
  stmt_emit_expression(pcVar1);
  return;
}

