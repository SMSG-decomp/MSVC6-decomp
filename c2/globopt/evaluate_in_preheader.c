c2_operand * __fastcall evaluate_in_preheader(c2_operand *op,c2_loop *loop)

{
  c2_tuple *anchor;
  c2_tuple *t;
  c2_operand *pcVar1;
  
  anchor = tuple_new_block_boundary();
  t = tuple_new(0x15b,op->type,op,op,tuple_splice_after,anchor);
  g_cur_avail_set = loop->preheader->set50;
  cse_replace_operands(t);
  pcVar1 = (c2_operand *)node_clone((c2_node *)t->src);
  node_free((c2_node *)anchor);
  node_free((c2_node *)t);
  return pcVar1;
}

