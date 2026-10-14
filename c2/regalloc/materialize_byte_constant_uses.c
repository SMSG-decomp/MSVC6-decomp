void __fastcall materialize_byte_constant_uses(c2_live_range *range)

{
  c2_operand *old;
  uint32_t uVar1;
  c2_tuple *t;
  c2_block *pcVar2;
  
  pcVar2 = range->first_block;
  range->flags5 = range->flags5 & 0x7f;
  do {
    uVar1 = bitset_test(pcVar2->live,range->id);
    if (uVar1 != 0) {
      t = pcVar2->head;
      if (t != pcVar2->end) {
        do {
          if ((t->flags & 1) != 0) {
            for (old = t->src; old != (c2_operand *)0x0; old = old->next) {
              if (((old->kind == '\x01') && ((old->u18).reg == (c2_symbol *)range)) &&
                 ((old->type & 0xfff) == 1)) {
                old = tuple_replace_src_with_base_copy(t,old,old->sym);
                pcVar2->flags = pcVar2->flags | 0x40000;
              }
            }
          }
          t = t->next;
        } while (t != pcVar2->end);
      }
      if (pcVar2 == range->last_block) {
        return;
      }
    }
    pcVar2 = pcVar2->next;
  } while( true );
}

