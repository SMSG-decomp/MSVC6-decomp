void __cdecl stmt_emit_intrinsic_call(int intrinsic,c1_node *args)

{
  c1_node *pcVar1;
  
  pcVar1 = tree_new_int_constant(intrinsic);
  pcVar1 = tree_new_binary('w',pcVar1,args);
  stmt_emit_expression(pcVar1);
  return;
}

