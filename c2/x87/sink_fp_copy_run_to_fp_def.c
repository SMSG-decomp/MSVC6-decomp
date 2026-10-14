void __fastcall sink_fp_copy_run_to_fp_def(c2_tuple *pos)

{
  c2_tuple *last;
  c2_operand *pcVar1;
  c2_tuple *pcVar2;
  
  last = pos->prev;
  pcVar2 = last;
  if (last->op == 99) {
    while (((pcVar2->src->kind == '\x01' && (((pcVar2->src->u18).reg)->cls == '\x02')) &&
           (pcVar2->dst->kind == '\x01'))) {
      if ((pcVar2->dst->sym->cls != '\x01') || (pcVar2 = pcVar2->prev, pcVar2->op != 99)) break;
    }
  }
  if (pcVar2->next != pos) {
    do {
      pos = pos->next;
      pcVar1 = pos->dst;
      if (((pcVar1 != (c2_operand *)0x0) && ((pcVar1->type & 0xf000) == 0x4000)) &&
         ((pcVar1->kind == '\x01' && (((pcVar1->u18).reg)->cls == '\x02')))) break;
    } while (((pos->flags13 != '\0') || (pos->op == 0x163)) || (pos->op == 0x164));
    if ((pos->dst == (c2_operand *)0x0) || ((pos->dst->type & 0xf000) != 0x4000)) {
      pos = pos->next;
    }
    tuple_move_range(pos,pcVar2->next,last);
  }
  return;
}

