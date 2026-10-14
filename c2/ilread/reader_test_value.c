uint8_t __fastcall reader_test_value(c2_reader_cell **stack)

{
  c2_reader_cell *cell;
  c2_symbol *pcVar1;
  c2_tuple *pcVar2;
  c2_operand *pcVar3;
  c2_const_operand *first;
  uint uVar4;
  
  cell = *stack;
  if ((cell->flags & 0x40) == 0) {
    pcVar2 = cell->tail;
    uVar4 = 1 << (pcVar2->kind & 0x1f);
    if ((((uVar4 & 0xffe) != 0) &&
        ((((uVar4 & 6) == 0 || (((pcVar2->u14).expr)->cls != '\x03')) && (pcVar2->kind != 6)))) &&
       (pcVar2->prev != (c2_tuple *)0x0)) {
      pcVar2 = pcVar2->prev;
    }
    if ((((pcVar2->flags & 1) != 0) && (pcVar2->op == 0x15b)) &&
       ((pcVar2->dst->kind != '\x01' ||
        ((pcVar1 = pcVar2->dst->sym, pcVar1->cls != '\x03' || (pcVar1->def == (c2_tuple *)0x0))))))
    {
      warning(4,0x2c2);
    }
  }
  pcVar3 = (c2_operand *)cell->tail;
  if ((pcVar3->flags9 & 1) != 0) {
    pcVar3 = (c2_operand *)pcVar3->tag;
  }
  if (((pcVar3 != (c2_operand *)0x0) && ((1 << (pcVar3->kind & 0x1f) & 0xffeU) != 0)) &&
     (pcVar3->type == 0x8000)) {
    return pcVar3->flags11 >> 4;
  }
  pcVar3 = reader_pop_operand(cell);
  if ((pcVar3->type & 0xf000) == 0x4000) {
    first = operand_new_fconst(pcVar3->type,&g_ld_const_zero);
  }
  else {
    first = operand_new_intconst(0x1004,0,0);
  }
  tuple_splice_after(cell->tail,(c2_tuple *)pcVar3);
  cell->tail = (c2_tuple *)pcVar3;
  reader_push(stack,(c2_node *)first);
  reader_binary_op(stack,0x17d);
  pcVar3 = (*stack)->tail->dst;
  pcVar3->flags11 = pcVar3->flags11 & 0xf | 0x10;
  return '\x01';
}

