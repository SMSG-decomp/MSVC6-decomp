c2_bitset * __fastcall x87_live_at(c2_tuple *t,c2_bitset *ranges)

{
  c2_tuple *pcVar1;
  c2_operand *pcVar2;
  c2_live_range *pcVar3;
  c2_bitset *dst;
  c2_block *pcVar4;
  
  dst = bitset_clone(ranges);
  if (t->kind == '\x19') {
    bitset_and(dst,((t->u14).block)->live_in);
    return dst;
  }
  pcVar4 = tuple_get_block_nonnull(t);
  bitset_and(dst,pcVar4->live_in);
  for (pcVar1 = pcVar4->head; pcVar1 != t; pcVar1 = pcVar1->next) {
    if (((pcVar1->flags & 1) != 0) && ((pcVar1->type & 0xf000) == 0x4000)) {
      for (pcVar2 = pcVar1->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
        if ((((pcVar2->kind == '\x01') && ((pcVar2->flags11 & 0x10) != 0)) &&
            (pcVar3 = (pcVar2->u18).range, pcVar3->kind == '\x02')) &&
           (pcVar3->colour != (c2_register_descriptor *)0x0)) {
          bitset_clear(dst,pcVar3->id);
        }
      }
      for (pcVar2 = pcVar1->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
        if (((pcVar2->kind == '\x01') && (pcVar3 = (pcVar2->u18).range, pcVar3->kind == '\x02')) &&
           (pcVar3->colour != (c2_register_descriptor *)0x0)) {
          bitset_set(dst,pcVar3->id);
        }
      }
    }
  }
  return dst;
}

