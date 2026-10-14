c2_operand * __fastcall trip_count_is_nonzero(c2_operand *a,c2_operand *b,uint8_t cc)

{
  uint16_t type;
  c2_tuple *pcVar1;
  c2_const_operand *c;
  c2_const_operand *b_00;
  c2_operand *pcVar2;
  code *insert_fn_00;
  c2_tuple *anchor;
  c2_insert_fn *insert_fn;
  
  free_pending_tuple_list();
  anchor = g_iv_scratch_tail;
  insert_fn = tuple_insert_before;
  pcVar1 = g_iv_scratch_tail;
  type = usual_arithmetic_type(a->type,b->type);
  pcVar1 = tuple_new_compare(0x17d,type,a,b,insert_fn,pcVar1);
  insert_fn_00 = tuple_insert_before;
  c = operand_new_intconst(0x1004,1,0);
  b_00 = operand_new_intconst(0x1004,0,0);
  tuple_new_ternary_temp(399,0x1004,pcVar1->dst,b_00,c,cc,insert_fn_00,anchor);
  simplify_tuple(pcVar1,(c2_block *)0x0,(c2_function *)0x0);
  if (g_iv_scratch_tail->prev->op == 0x15b) {
    pcVar2 = (c2_operand *)node_clone((c2_node *)g_iv_scratch_tail->prev->src);
    return pcVar2;
  }
  return (c2_operand *)0x0;
}

