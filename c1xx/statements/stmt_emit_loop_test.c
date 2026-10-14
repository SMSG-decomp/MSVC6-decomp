void __cdecl stmt_emit_loop_test(c1_node *cond)

{
  stmt_emit_condition(cond,*(c1_node **)((int)g_break_label_stack + 4),0);
  return;
}

