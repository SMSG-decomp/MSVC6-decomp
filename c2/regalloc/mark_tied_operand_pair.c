void __fastcall mark_tied_operand_pair(c2_tuple *t)

{
  uint uVar1;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  
  uVar1 = t->op;
  if ((uVar1 == 0x166) && ((t->src->u18).reg == (c2_symbol *)0x183)) {
    pcVar2 = t->src->next;
    t->dst->flags = t->dst->flags & 0xf2 | 2;
    pcVar2->flags = pcVar2->flags & 0xf2 | 2;
    return;
  }
  if (((uVar1 != 0) && (uVar1 < 0x144)) && ((g_x86_op_flags[uVar1] & 0x40) != 0)) {
    pcVar2 = t->src;
    if ((pcVar2->kind == '\x01') && (((pcVar2->u18).reg)->cls == '\x02')) {
      t->dst->flags = t->dst->flags & 0xf1 | 1;
      pcVar2->flags = pcVar2->flags & 0xf1 | 1;
    }
    if (((uVar1 == 9) || (uVar1 == 0xd9)) &&
       (pcVar2 = pcVar2->next, ((pcVar2->u18).reg)->cls == '\x02')) {
      pcVar3 = t->dst->next;
      pcVar3->flags = pcVar3->flags & 0xf2 | 2;
      pcVar2->flags = pcVar2->flags & 0xf2 | 2;
    }
  }
  return;
}

