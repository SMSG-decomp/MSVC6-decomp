c2_operand * __fastcall operand_list_find_kind_b(c2_operand *op)

{
  for (; (op != (c2_operand *)0x0 && (op->kind != '\v')); op = op->next) {
  }
  return op;
}

