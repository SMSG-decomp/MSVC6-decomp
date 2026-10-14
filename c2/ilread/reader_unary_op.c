void __fastcall reader_unary_op(c2_reader_cell **stack,uint32_t op)

{
  c2_reader_cell *cell;
  uint16_t type;
  c2_tuple *pcVar1;
  c2_operand *local_4;
  
  cell = *stack;
  local_4 = (c2_operand *)stack;
  local_4 = reader_pop_operand(cell);
  if (g_opt_basic == 0) {
    type = usual_arithmetic_type(local_4->type,0x1004);
    convert_operand(&local_4,type,&cell->tail);
  }
  pcVar1 = tuple_new_unary_temp(op,local_4->type,local_4,tuple_splice_after,cell->tail);
  cell->tail = pcVar1;
  return;
}

