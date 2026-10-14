c1_node * __cdecl expr_report_function_operand(c1_u8 op,c1_node *node)

{
  c1_node *pcVar1;
  c1_symbol *sym;
  uint local_4;
  
  pcVar1 = expr_strip_to_function_ref(node,&local_4);
  if (pcVar1 == (c1_node *)0x0) {
    diag_error(0x12a,op);
    return (c1_node *)0x0;
  }
  diag_begin_global(g_token_position);
  diag_error(0x238,op);
  sym = pcVar1->left;
  if ((sym->kind & 0x1f) == 0x12) {
    sym = *(c1_symbol **)(*(int *)sym->type + 8);
  }
  node = (c1_node *)CONCAT31(node._1_3_,1);
  diag_note_candidates(sym,(char *)&node);
  diag_end_global();
  return pcVar1;
}

