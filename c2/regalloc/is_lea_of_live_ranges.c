int __fastcall is_lea_of_live_ranges(c2_tuple *t)

{
  c2_operand *pcVar1;
  
  if (t->dst->next != (c2_operand *)0x0) {
    return 0;
  }
  if (t->op != 0x12) {
    return 0;
  }
  pcVar1 = t->src;
  if (pcVar1->kind == '\x05') {
    if ((pcVar1->base != (c2_operand *)0x0) && (((pcVar1->base->u18).reg)->cls != '\x02')) {
      return 0;
    }
    if ((pcVar1->index != (c2_operand *)0x0) && (((pcVar1->index->u18).reg)->cls != '\x02')) {
      return 0;
    }
  }
  return 1;
}

