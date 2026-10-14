c2_tuple * __fastcall emit_sbb_mask(c2_tuple *anchor)

{
  c2_operand *pcVar1;
  c2_tuple *t;
  c2_const_operand *src2;
  c2_tuple *pcVar2;
  code *insert_fn_00;
  c2_insert_fn *insert_fn;
  
  insert_fn = tuple_insert_after;
  pcVar1 = operand_new_hardreg(0x42,0x8000);
  t = tuple_new_unary_temp(0x119,0x1004,pcVar1,insert_fn,anchor);
  pcVar1 = tuple_add_flags_result(t);
  insert_fn_00 = tuple_insert_after;
  pcVar2 = t;
  src2 = operand_new_intconst(0x1004,0xffffffff,-1);
  pcVar2 = tuple_new_binary_temp(0x31,0x1004,t->dst,src2,insert_fn_00,pcVar2);
  tuple_append_src(pcVar2,pcVar1);
  retie_register_chain(pcVar2->src,pcVar2->dst);
  return pcVar2;
}

