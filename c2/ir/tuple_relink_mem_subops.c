void __fastcall tuple_relink_mem_subops(c2_tuple *t)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  
  for (pcVar2 = t->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
    if ((1 << (pcVar2->kind & 0x1f) & 0x60U) != 0) {
      pcVar2->flags11 = pcVar2->flags11 & 0xdf;
    }
  }
  for (pcVar2 = t->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
    if ((1 << (pcVar2->kind & 0x1f) & 0x60U) != 0) {
      pcVar2->flags11 = pcVar2->flags11 & 0xdf;
    }
  }
  for (pcVar2 = t->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
    if (((1 << (pcVar2->kind & 0x1f) & 0x60U) != 0) && ((pcVar2->flags11 & 0x20) == 0)) {
      pcVar1 = pcVar2->base;
      if (pcVar1 != (c2_operand *)0x0) {
        pcVar1->flags = pcVar1->flags & 0xef;
        tuple_append_src(t,pcVar1);
      }
      pcVar1 = pcVar2->index;
      if (pcVar1 != (c2_operand *)0x0) {
        pcVar1->flags = pcVar1->flags & 0xef;
        tuple_append_src(t,pcVar1);
      }
    }
  }
  for (pcVar2 = t->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
    if (((1 << (pcVar2->kind & 0x1f) & 0x60U) != 0) && ((pcVar2->flags11 & 0x20) == 0)) {
      pcVar1 = pcVar2->base;
      if (pcVar1 != (c2_operand *)0x0) {
        pcVar1->flags = pcVar1->flags & 0xef;
        tuple_append_src(t,pcVar1);
      }
      pcVar1 = pcVar2->index;
      if (pcVar1 != (c2_operand *)0x0) {
        pcVar1->flags = pcVar1->flags & 0xef;
        tuple_append_src(t,pcVar1);
      }
    }
  }
  return;
}

