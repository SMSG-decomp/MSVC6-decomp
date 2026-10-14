void __fastcall reader_pop_convert_append(c2_reader_cell *cell,uint16_t type)

{
  c2_tuple *pcVar1;
  c2_tuple **anchor;
  c2_operand *local_4;
  
  local_4 = (c2_operand *)cell;
  local_4 = reader_pop_operand(cell);
  anchor = &cell->tail;
  pcVar1 = convert_operand(&local_4,type,anchor);
  if ((pcVar1 == (c2_tuple *)0x0) && ((local_4->flags & 0x10) == 0)) {
    tuple_splice_after(*anchor,(c2_tuple *)local_4);
    *anchor = (c2_tuple *)local_4;
  }
  return;
}

