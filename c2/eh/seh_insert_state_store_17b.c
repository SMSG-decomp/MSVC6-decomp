c2_tuple * __fastcall seh_insert_state_store_17b(int index,c2_tuple *anchor)

{
  c2_const_operand *src;
  c2_tuple *pcVar1;
  c2_insert_fn *insert_fn;
  
  insert_fn = tuple_insert_before;
  pcVar1 = anchor;
  src = operand_new_intconst(0x1004,index * 4,index * 4 >> 0x1f);
  pcVar1 = tuple_new_unary_temp(0x15a,0x1004,src,insert_fn,pcVar1);
  pcVar1 = tuple_new_intrinsic(400,0x1004,(c2_operand *)0x0,pcVar1->dst,(c2_operand *)0x0,
                               (c2_operand *)0x0,(c2_operand *)0x0,0x17b,tuple_insert_before,anchor)
  ;
  return pcVar1;
}

