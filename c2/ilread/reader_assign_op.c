void __fastcall reader_assign_op(c2_reader_cell **stack,uint32_t op,c2_reader_op *rec)

{
  byte bVar1;
  c2_reader_cell *pcVar2;
  c2_reader_cell *pcVar3;
  uint32_t uVar4;
  uint16_t uVar5;
  c2_operand *pcVar6;
  c2_operand *local_c;
  c2_operand *local_8;
  uint32_t local_4;
  
  pcVar2 = *stack;
  pcVar3 = pcVar2->next;
  *stack = pcVar3;
  local_4 = op;
  pcVar6 = reader_duplicate_operand(pcVar3);
  reader_push(stack,(c2_node *)pcVar6);
  pcVar3 = *stack;
  bVar1 = pcVar3->next->flags;
  if ((bVar1 & 4) != 0) {
    pcVar3->flags = bVar1;
    pcVar6 = (pcVar3->next->u10).bitfield;
    if (pcVar6 != (c2_operand *)0x0) {
      pcVar6 = operand_list_clone(pcVar6);
      (pcVar3->u10).bitfield = pcVar6;
    }
  }
  reader_swap_top(stack);
  pcVar2->next = *stack;
  *stack = pcVar2;
  reader_swap_top(stack);
  uVar4 = rec->size;
  uVar5 = rec->type;
  reader_load_value(*stack,uVar5,uVar4,rec->qualifiers & 0x800);
  if ((uVar5 & 0xff00) == 0x8000) {
    g_reader_aggregate_size = uVar4;
  }
  local_c = reader_pop_operand(*stack);
  reader_swap_top(stack);
  local_8 = reader_pop_operand(*stack);
  uVar4 = local_4;
  if (((local_4 == 0x175) || (local_4 == 0x176)) || ((local_8->type & 0xf000) == 0x4000)) {
    uVar5 = usual_arithmetic_type(local_c->type,local_8->type);
    convert_operand(&local_c,uVar5,&(*stack)->next->tail);
    pcVar2 = *stack;
  }
  else {
    pcVar2 = *stack;
    uVar5 = local_c->type;
  }
  convert_operand(&local_8,uVar5,&pcVar2->tail);
  pcVar2 = (*stack)->next;
  tuple_splice_after(pcVar2->tail,(c2_tuple *)local_c);
  pcVar3 = *stack;
  pcVar2->tail = (c2_tuple *)local_c;
  tuple_splice_after(pcVar3->tail,(c2_tuple *)local_8);
  (*stack)->tail = (c2_tuple *)local_8;
  reader_binary_op(stack,uVar4);
  reader_emit_store(stack,rec);
  (*stack)->flags = (*stack)->flags | 0x40;
  return;
}

