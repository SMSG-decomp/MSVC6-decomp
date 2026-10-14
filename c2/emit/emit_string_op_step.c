c2_tuple * __fastcall
emit_string_op_step(uint32_t op,uint16_t type,c2_operand **a,c2_operand **b,c2_tuple *at,int both)

{
  c2_symbol *pcVar1;
  c2_operand *dst;
  c2_tuple *t;
  c2_operand *pcVar2;
  c2_operand *src2;
  
  pcVar2 = *a;
  if (b == (c2_operand **)0x0) {
    src2 = (c2_operand *)0x0;
  }
  else {
    src2 = *b;
  }
  dst = operand_new_temp_in_reg(((pcVar2->u18).reg)->id,type);
  *a = dst;
  if (src2 == (c2_operand *)0x0) {
    t = tuple_new(op,type,dst,pcVar2,tuple_insert_after,at);
  }
  else {
    t = tuple_new_binary(op,type,dst,pcVar2,src2,tuple_insert_after,at);
  }
  pcVar1 = dst->sym;
  if (pcVar1->storage->part_next == (c2_symbol *)0x0) {
    pcVar1->def = t;
  }
  else {
    symbol_mark_overlapping_parts(pcVar1,t);
  }
  if (both == 2) {
    pcVar2 = operand_new_temp_in_reg((((*b)->u18).reg)->id,0x1004);
    *b = pcVar2;
    tuple_append_dst(t,pcVar2);
    pcVar1 = pcVar2->sym;
    if (pcVar1->storage->part_next == (c2_symbol *)0x0) {
      pcVar1->def = t;
      return t;
    }
    symbol_mark_overlapping_parts(pcVar1,t);
  }
  return t;
}

