c2_operand * __fastcall find_mem_operand_using(c2_tuple *t,c2_operand *sub,c2_operand **list)

{
  c2_operand *pcVar1;
  
  pcVar1 = t->src;
  while( true ) {
    if (pcVar1 == (c2_operand *)0x0) {
      for (pcVar1 = t->dst;
          ((1 << (pcVar1->kind & 0x1f) & 0x60U) == 0 ||
          ((pcVar1->base != sub && (pcVar1->index != sub)))); pcVar1 = pcVar1->next) {
      }
      *list = t->dst;
      return pcVar1;
    }
    if (((1 << (pcVar1->kind & 0x1f) & 0x60U) != 0) &&
       ((pcVar1->base == sub || (pcVar1->index == sub)))) break;
    pcVar1 = pcVar1->next;
  }
  *list = t->src;
  return pcVar1;
}

