c2_operand * __fastcall operand_list_find_constant(c2_operand *op)

{
  while( true ) {
    if (op == (c2_operand *)0x0) {
      return (c2_operand *)0x0;
    }
    if (op->kind == '\a') break;
    if (op->kind == '\t') {
      return op;
    }
    op = op->next;
  }
  return op;
}

