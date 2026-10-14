void __cdecl func_emit_return_this(int is_ctor)

{
  c1_node *node;
  
  if (is_ctor != 0) {
    eh_flush_pending_state_c2();
    eh_check_try_with_unwinding();
    node = expr_this_pointer((c1_symbol *)0x0);
    il_emit_expression_tree(node);
    il_emit_tuple(0x41,node);
  }
  return;
}

