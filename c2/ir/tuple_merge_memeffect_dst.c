void __fastcall tuple_merge_memeffect_dst(c2_tuple *t,c2_operand *eff)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  
  pcVar1 = t->dst;
  if (t->dst != (c2_operand *)0x0) {
    do {
      pcVar2 = pcVar1;
      if ((pcVar2->kind == '\v') && (pcVar2->sym == eff->sym)) {
        if ((eff->flags & 0x10) != 0) {
          return;
        }
        node_free((c2_node *)eff);
        return;
      }
      pcVar1 = pcVar2->next;
    } while (pcVar2->next != (c2_operand *)0x0);
    if (pcVar2 != (c2_operand *)0x0) {
      pcVar2->next = (c2_operand *)0x0;
      return;
    }
  }
  t->dst = (c2_operand *)0x0;
  return;
}

