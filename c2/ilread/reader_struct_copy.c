void __fastcall reader_struct_copy(c2_reader_cell **stack,c2_reader_op *op)

{
  ushort uVar1;
  c2_reader_cell *pcVar2;
  c2_operand *first;
  c2_operand *pcVar3;
  c2_tuple *pcVar4;
  c2_const_operand *src;
  c2_operand *local_8;
  c2_operand *local_4;
  
  reader_swap_top(stack);
  pcVar2 = *stack;
  first = reader_duplicate_operand(pcVar2);
  pcVar3 = reader_pop_operand(pcVar2);
  pcVar4 = tuple_new_unary_temp(0x15a,pcVar3->type,pcVar3,tuple_splice_after,pcVar2->tail);
  pcVar2->tail = pcVar4;
  reader_swap_top(stack);
  pcVar2 = *stack;
  reader_address_of_top(pcVar2,g_ptr_type);
  pcVar3 = reader_pop_operand(pcVar2);
  pcVar4 = tuple_new_unary_temp(0x15a,pcVar3->type,pcVar3,tuple_splice_after,pcVar2->tail);
  pcVar2->tail = pcVar4;
  reader_pop_two_merge(stack,&local_4,&local_8,0);
  src = operand_new_intconst(0x1004,g_reader_aggregate_size,g_reader_aggregate_size >> 0x1f);
  pcVar2 = *stack;
  pcVar4 = tuple_new_unary_temp(0x15a,0x1004,src,tuple_splice_after,pcVar2->tail);
  pcVar3 = pcVar4->dst;
  pcVar2->tail = pcVar4;
  pcVar4 = tuple_new_intrinsic(400,g_ptr_type,(c2_operand *)0x0,local_4,local_8,pcVar3,
                               (c2_operand *)0x0,0xac,tuple_splice_after,pcVar4);
  pcVar4 = reader_lower_intrinsic_call(g_reading_function,pcVar4);
  pcVar2->tail = pcVar4;
  reader_push_pending_list(pcVar2);
  tuple_splice_after(pcVar2->tail,(c2_tuple *)first);
  pcVar4 = (c2_tuple *)list_last((c2_link *)first);
  uVar1 = op->qualifiers;
  pcVar2->tail = pcVar4;
  reader_load_value(pcVar2,op->type,g_reader_aggregate_size,uVar1 & 0x800);
  return;
}

