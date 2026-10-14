void __cdecl stmt_emit_intrinsic_call(int value,c1_node *right)

{
  c1_node *pcVar1;
  
  pcVar1 = tree_new_int_constant(value);
  pcVar1 = tree_new_binary('w',pcVar1,right);
  stmt_emit_expression(pcVar1);
  return;
}

