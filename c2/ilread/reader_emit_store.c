void __fastcall reader_emit_store(c2_reader_cell **stack,c2_reader_op *op)

{
  undefined4 in_EAX;
  c2_operand *src;
  c2_tuple *pcVar1;
  c2_const_operand *pcVar2;
  uint16_t type;
  c2_tuple **anchor;
  c2_reader_cell *pcVar3;
  c2_operand *target;
  c2_operand *value;
  uint32_t type_class;
  uint32_t store_type;
  
  store_type = CONCAT22((short)((uint)in_EAX >> 0x10),op->type);
  type_class = op->type & 0xf000;
  if (((short)type_class == 0x5000) &&
     (g_reader_aggregate_size = op->size, 0xfff < g_reader_aggregate_size)) {
    reader_struct_copy(stack,op);
    (*stack)->flags = (*stack)->flags & 0xbf;
    return;
  }
  pcVar3 = *stack;
  src = reader_pop_operand(pcVar3);
  if ((src->kind == '\x06') && ((short)type_class == 0x5000)) {
    if (((g_reader_aggregate_size == 0) || (8 < g_reader_aggregate_size)) ||
       ((g_reader_aggregate_size & g_reader_aggregate_size - 1U) != 0)) {
      target = operand_new_temp_sym(src->type);
    }
    else {
      target = operand_new_temp(src->type);
    }
    pcVar2 = operand_new_intconst(0x1004,g_reader_aggregate_size,g_reader_aggregate_size >> 0x1f);
    src = (c2_operand *)
          tuple_new_blockop(0x16b,src->type,target,src,pcVar2,tuple_splice_after,pcVar3->tail);
    *(c2_operand **)(*(int *)(src->tag + 0x14) + 0x14) = src;
  }
  else {
    if ((src->flags & 0x10) != 0) {
      src = (c2_operand *)node_clone((c2_node *)src);
    }
    tuple_splice_after(pcVar3->tail,(c2_tuple *)src);
  }
  pcVar3->tail = (c2_tuple *)src;
  reader_swap_top(stack);
  if (((*stack)->flags & 4) == 0) {
    type = (uint16_t)store_type;
    reader_load_value(*stack,type,op->size,op->qualifiers & 0x800);
    reader_pop_two_merge(stack,&value,&target,0);
    if ((short)type_class == 0x5000) {
      pcVar2 = operand_new_intconst(0x1004,g_reader_aggregate_size,g_reader_aggregate_size >> 0x1f);
      pcVar3 = *stack;
      anchor = &pcVar3->tail;
      pcVar1 = tuple_new_blockop(0x16b,target->type,target,value,pcVar2,tuple_splice_after,
                                 pcVar3->tail);
    }
    else {
      pcVar3 = *stack;
      anchor = &pcVar3->tail;
      convert_operand(&value,type,anchor);
      pcVar1 = tuple_new(0x15b,target->type,target,value,tuple_splice_after,*anchor);
    }
    *anchor = pcVar1;
    if (((target->kind != 2) && ((1 << (target->kind & 0x1f) & 0x380U) == 0)) &&
       ((((value->kind == 2 &&
          ((value->sym->def == (c2_tuple *)0x0 && ((value->sym->flags7 & 1) == 0)))) &&
         ((value->flags & 0x40) == 0)) || ((1 << (value->kind & 0x1f) & 0x380U) != 0)))) {
      value = (c2_operand *)node_clone((c2_node *)value);
      tuple_splice_after(*anchor,(c2_tuple *)value);
      *anchor = (c2_tuple *)value;
    }
    pcVar3->flags = pcVar3->flags & 0xbf;
    return;
  }
  reader_store_bitfield(stack,op);
  (*stack)->flags = (*stack)->flags & 0xbf;
  return;
}

