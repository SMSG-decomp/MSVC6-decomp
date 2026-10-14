void __fastcall reader_store_bitfield(c2_reader_cell **stack,c2_reader_op *op)

{
  c2_tuple **anchor;
  c2_operand_u18 *pcVar1;
  uint16_t type;
  c2_reader_cell *pcVar2;
  c2_operand *pcVar3;
  c2_operand *pcVar4;
  c2_tuple *anchor_00;
  c2_const_operand *pcVar5;
  uint8_t count;
  uint hi;
  int64_t iVar6;
  uint64_t uVar7;
  longlong lVar8;
  code *insert_fn_00;
  c2_operand *value;
  c2_operand *field_bits;
  c2_operand *word;
  int value_is_zero;
  c2_reader_op *op_saved;
  int32_t width;
  c2_operand *bitfield;
  c2_tuple **tail_slot;
  c2_operand *target;
  int mask_shift;
  uint64_t field_mask;
  uint32_t value_lo;
  uint32_t value_hi;
  c2_insert_fn *insert_fn;
  int32_t shift;
  
  type = op->type;
  value_is_zero = 0;
  op_saved = op;
  reader_swap_top(stack);
  reader_spill_eh_calls((*stack)->tail,*stack);
  reader_swap_top(stack);
  pcVar2 = *stack;
  bitfield = (pcVar2->u10).bitfield;
  (pcVar2->u10).bitfield = (c2_operand *)0x0;
  width = (bitfield->u18).lo;
  shift = (bitfield->next->u18).lo;
  target = reader_duplicate_operand(pcVar2);
  pcVar2->flags = pcVar2->flags & 0xfb;
  reader_load_value(pcVar2,type,0,op_saved->qualifiers & 0x800);
  reader_pop_two_merge(stack,&value,&word,0);
  anchor = &(*stack)->tail;
  tail_slot = anchor;
  convert_operand(&value,type,anchor);
  anchor_00 = *anchor;
  mask_shift = 0x40 - width;
  field_mask = aullshr((uint8_t)mask_shift,0xffffffff,0xffffffff);
  hi = (uint)(field_mask >> 0x20);
  count = (uint8_t)shift;
  if (value->kind == '\a') {
    iVar6 = allshl(count,value->tag & hi,(value->u18).lo & (uint)field_mask);
    uVar7 = const_normalize(type,(uint32_t)iVar6,(int32_t)((ulonglong)iVar6 >> 0x20));
    value->u18 = (c2_operand_u18)(int)uVar7;
    value->tag = (int)(uVar7 >> 0x20);
    field_bits = value;
    value_lo = (value->u18).lo;
    value_hi = value->tag;
    if (value_lo == 0 && value_hi == 0) {
      value_is_zero = 1;
      goto LAB_1074c079;
    }
    iVar6 = allshl(count,field_mask._4_4_,(uint)field_mask);
    if (iVar6 != CONCAT44(value_hi,value_lo)) goto LAB_1074c079;
  }
  else {
    insert_fn = tuple_splice_after;
    pcVar5 = operand_new_intconst(type,(uint)field_mask,hi);
    anchor_00 = tuple_new_binary_temp(0x172,type,value,pcVar5,insert_fn,anchor_00);
    field_bits = anchor_00->dst;
    if (shift != 0) {
      insert_fn_00 = tuple_splice_after;
      pcVar5 = operand_new_intconst(0x1001,shift,shift >> 0x1f);
      anchor_00 = tuple_new_binary_temp(0x171,type,field_bits,pcVar5,insert_fn_00,anchor_00);
      field_bits = anchor_00->dst;
    }
LAB_1074c079:
    insert_fn = tuple_splice_after;
    iVar6 = allshl(count,field_mask._4_4_,(uint)field_mask);
    pcVar5 = operand_new_intconst(type,~(uint)iVar6,~(uint)((ulonglong)iVar6 >> 0x20));
    anchor_00 = tuple_new_binary_temp(0x172,type,word,pcVar5,insert_fn,anchor_00);
    word = anchor_00->dst;
    if (value_is_zero != 0) goto LAB_1074bfc7;
  }
  anchor_00 = tuple_new_binary_temp(0x173,type,word,field_bits,tuple_splice_after,anchor_00);
LAB_1074bfc7:
  *tail_slot = anchor_00;
  reader_push(stack,(c2_node *)target);
  reader_swap_top(stack);
  reader_emit_store(stack,op_saved);
  if (value->kind == '\a') {
    if ((value->flags & 0x10) != 0) {
      value = (c2_operand *)node_clone((c2_node *)value);
    }
    pcVar3 = value;
    pcVar1 = &value->u18;
    if ((type & 0xf000) == 0x1000) {
      iVar6 = allshl(('@' - count) - (char)width,value->tag,pcVar1->lo);
      pcVar4 = value;
      pcVar3->u18 = (c2_operand_u18)(int)iVar6;
      pcVar3->tag = (int)((ulonglong)iVar6 >> 0x20);
      pcVar1 = &value->u18;
      lVar8 = allshr((value->u18).lo,value->tag,(uint8_t)mask_shift);
      pcVar1->lo = (uint32_t)lVar8;
      pcVar4->tag = (int)(uint32_t)lVar8 >> 0x1f;
    }
    else {
      lVar8 = allshr(pcVar1->lo,value->tag,count);
      pcVar1->lo = (uint32_t)lVar8;
      pcVar3->tag = 0;
    }
    pcVar2 = *stack;
    tuple_splice_after(pcVar2->tail,(c2_tuple *)value);
    pcVar3 = bitfield;
    pcVar2->tail = (c2_tuple *)value;
    node_free((c2_node *)bitfield->next);
    node_free((c2_node *)pcVar3);
    pcVar2->flags = pcVar2->flags & 0xfb;
    (pcVar2->u10).bitfield = (c2_operand *)0x0;
    return;
  }
  pcVar2 = *stack;
  pcVar2->flags = pcVar2->flags | 4;
  (pcVar2->u10).bitfield = bitfield;
  return;
}

