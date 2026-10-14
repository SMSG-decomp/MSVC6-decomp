void __cdecl expr_make_reusable(c1_node **copy,c1_node **expr)

{
  c1_node *pcVar1;
  
  pcVar1 = *expr;
  if (pcVar1->op == '=') {
    pcVar1 = tree_copy_to_arena(pcVar1,g_expr_arena_index);
    *copy = pcVar1;
    return;
  }
  *copy = pcVar1;
  pcVar1 = expr_spill_to_temporary(copy);
  *expr = pcVar1;
  return;
}

