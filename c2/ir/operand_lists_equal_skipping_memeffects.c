int __fastcall operand_lists_equal_skipping_memeffects(c2_operand *a,c2_operand *b)

{
  int iVar1;
  
  for (; a != (c2_operand *)0x0; a = a->next) {
    do {
      if (a->kind != '\v') break;
      a = a->next;
    } while (a != (c2_operand *)0x0);
    for (; (b != (c2_operand *)0x0 && (b->kind == '\v')); b = b->next) {
    }
    if (a == (c2_operand *)0x0) break;
    if ((b == (c2_operand *)0x0) || (iVar1 = operand_lists_equal(a,b), iVar1 == 0)) {
      return 0;
    }
    b = b->next;
  }
  for (; (b != (c2_operand *)0x0 && (b->kind == '\v')); b = b->next) {
  }
  return (uint)(b == (c2_operand *)0x0);
}

