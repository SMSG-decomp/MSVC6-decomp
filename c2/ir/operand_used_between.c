int __fastcall operand_used_between(c2_operand *b,c2_tuple *from,c2_tuple *stop,c2_symbol *base_reg)

{
  c2_tuple *pcVar1;
  c2_operand *a;
  int iVar2;
  
  pcVar1 = from->next;
  do {
    if (pcVar1 == stop) {
      return 0;
    }
    if ((pcVar1->flags & 1) != 0) {
      for (a = pcVar1->dst; a != (c2_operand *)0x0; a = a->next) {
        iVar2 = operands_may_alias(a,b);
        if ((iVar2 != 0) &&
           ((((base_reg == (c2_symbol *)0x0 || (a->kind != '\x06')) ||
             (a->base == (c2_operand *)0x0)) || ((a->base->u18).reg != base_reg)))) {
          return 1;
        }
      }
    }
    pcVar1 = pcVar1->next;
  } while( true );
}

