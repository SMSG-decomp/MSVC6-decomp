void __fastcall tuple_merge_memeffect_src(c2_tuple *t,c2_operand *eff)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  
  pcVar1 = (c2_operand *)0x0;
  for (pcVar2 = t->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
    if ((pcVar2->kind == '\v') && (pcVar2->sym == eff->sym)) {
      if ((eff->flags & 0x10) != 0) {
        return;
      }
      node_free((c2_node *)eff);
      return;
    }
    pcVar1 = pcVar2;
  }
  if ((1 << (eff->kind & 0x1f) & 0xffeU) != 0) {
    if ((eff->flags & 0x10) != 0) {
      eff = (c2_operand *)node_clone((c2_node *)eff);
    }
    eff->flags = eff->flags | 0x10;
  }
  if (pcVar1 == (c2_operand *)0x0) {
    t->src = eff;
    return;
  }
  pcVar1->next = eff;
  return;
}

