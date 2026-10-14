int __fastcall op_has_side_effect_special(c2_tuple *t)

{
  uint uVar1;
  c2_operand *pcVar2;
  
  uVar1 = t->op;
  if (uVar1 < 0x176) {
    if (uVar1 == 0x175) {
      pcVar2 = t->src->next;
      if ((pcVar2->kind == '\a') && ((pcVar2->u18).reg != (c2_symbol *)0x0)) {
        return 0;
      }
    }
    else {
      if (uVar1 < 0x1f) {
        return 0;
      }
      if (0x20 < uVar1) {
        return 0;
      }
    }
  }
  else {
    if (uVar1 != 0x178) {
      return 0;
    }
    if ((t->src->kind == '\a') && ((t->src->flags11 & 0x40) == 0)) {
      return 0;
    }
  }
  return 1;
}

