int __fastcall is_lea_base_operand(c2_tuple *t,c2_operand *op)

{
  if (((op->flags & 0x20) != 0) && (t->op == 0x12)) {
    return 1;
  }
  return 0;
}

