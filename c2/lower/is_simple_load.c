uint32_t __fastcall is_simple_load(c2_tuple *t)

{
  c2_operand *pcVar1;
  
  if (((t->op == 1) && (t->dst->next == (c2_operand *)0x0)) &&
     ((pcVar1 = t->src->next, pcVar1 == (c2_operand *)0x0 || ((pcVar1->flags & 0x20) != 0)))) {
    return 1;
  }
  return 0;
}

