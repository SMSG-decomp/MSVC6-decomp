int __fastcall operand_is_not_first_dst(c2_tuple *t,c2_operand *op)

{
  if (op == t->dst) {
    return 0;
  }
  if (((t->op == 0xd9) || (t->op == 9)) && (op == t->dst->next)) {
    return 0;
  }
  return 1;
}

