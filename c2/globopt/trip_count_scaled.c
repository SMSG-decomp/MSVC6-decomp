c2_operand * __fastcall trip_count_scaled(c2_loop *loop,c2_function *fn,uint32_t lo,uint32_t hi)

{
  c2_operand *pcVar1;
  uint32_t lo_00;
  c2_const_operand *pcVar2;
  c2_tuple *pcVar3;
  longlong lVar4;
  code *insert_fn_00;
  c2_insert_fn *insert_fn;
  
  pcVar1 = loop->trip_count;
  if (pcVar1->kind == '\a') {
    lVar4 = __allmul((pcVar1->u18).lo,pcVar1->tag,lo,hi);
    pcVar2 = operand_new_intconst(0x2004,(uint32_t)lVar4,(int32_t)((ulonglong)lVar4 >> 0x20));
    return pcVar2;
  }
  pcVar1 = trip_count_as_type(loop,0x2004,fn);
  if ((-1 < (int)hi) &&
     (((0 < (int)hi || (lo != 0)) && ((lo - 1 & lo) == 0 && (hi - (lo == 0) & hi) == 0)))) {
    lo_00 = log2_floor(lo);
    insert_fn = tuple_insert_before;
    pcVar3 = g_preheader_insert_point;
    pcVar2 = operand_new_intconst(0x2004,lo_00,(int)lo_00 >> 0x1f);
    pcVar3 = tuple_new_binary_temp(0x171,0x2004,pcVar1,pcVar2,insert_fn,pcVar3);
    return pcVar3->dst;
  }
  insert_fn_00 = tuple_insert_before;
  pcVar3 = g_preheader_insert_point;
  pcVar2 = operand_new_intconst(0x2004,lo,hi);
  pcVar3 = tuple_new_binary_temp(0x16f,0x2004,pcVar1,pcVar2,insert_fn_00,pcVar3);
  return pcVar3->dst;
}

