int operand_lists_equal_case_2(c2_operand *a,c2_operand *b)

{
  if (a->sym == b->sym) {
    return 1;
  }
  return 0;
}

