int __fastcall is_redundant_zero_move(c2_tuple *t)

{
  uint32_t uVar1;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  
  uVar1 = t->op;
  if (uVar1 != 1) {
    if ((uVar1 != 0x34) && (uVar1 != 0x32)) {
      return 0;
    }
    if (uVar1 != 1) {
      if ((uVar1 != 0x34) && (uVar1 != 0x32)) {
        return 0;
      }
      pcVar2 = t->src;
      if (pcVar2->kind != '\x01') {
        return 0;
      }
      if (pcVar2->next->kind != '\x01') {
        return 0;
      }
      if (((pcVar2->u18).reg)->id != ((pcVar2->next->u18).reg)->id) {
        return 0;
      }
      return 1;
    }
  }
  pcVar2 = t->src;
  if ((pcVar2->kind == '\a') && ((pcVar2->u18).reg == (c2_symbol *)0x0)) {
    return 1;
  }
  if ((((t->dst->kind == '\x01') && (pcVar2->kind == '\x01')) && (pcVar2->sym->cls == '\r')) &&
     (((pcVar3 = (pcVar2->sym->u28).const_operand, pcVar3->kind == '\a' &&
       ((pcVar3->u18).reg == (c2_symbol *)0x0 && pcVar3->tag == 0)) &&
      ((t->dst->u18).reg != (pcVar2->u18).reg)))) {
    return 1;
  }
  return 0;
}

