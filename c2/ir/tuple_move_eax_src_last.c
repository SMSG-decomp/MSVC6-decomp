void __fastcall tuple_move_eax_src_last(c2_tuple *t)

{
  c2_operand *op;
  c2_operand *pcVar1;
  
  pcVar1 = find_src_overlapping_reg(t,g_reg_symbols + 1);
  op = t->src;
  if (pcVar1 == op) {
    pcVar1 = op->next;
    tuple_append_src(t,op);
    node_free((c2_node *)t->src);
    t->src = pcVar1;
  }
  return;
}

