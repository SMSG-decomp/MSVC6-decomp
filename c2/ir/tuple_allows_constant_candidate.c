int __fastcall tuple_allows_constant_candidate(c2_tuple *t)

{
  uint uVar1;
  c2_operand *pcVar2;
  c2_register_descriptor *pcVar3;
  int allowed;
  
  uVar1 = t->op;
  allowed = 1;
  if (0x2f < uVar1) {
    if (uVar1 < 0xcc) {
      if (uVar1 < 0xca) {
        if (uVar1 == 0x32) goto switchD_1071c2de_caseD_2d;
        if ((uVar1 != 0xa3) && (uVar1 != 0xc1)) {
          return allowed;
        }
      }
    }
    else if (((uVar1 != 0x11a) && (uVar1 != 0x166)) && (uVar1 != 0x178)) {
      return 1;
    }
    goto switchD_1071c2de_caseD_4;
  }
  if (uVar1 == 0x2f) {
    pcVar2 = t->src;
    if (pcVar2->next->kind != '\a') {
      return 1;
    }
    if ((pcVar2->next->u18).reg != (c2_symbol *)0x0) {
      return 1;
    }
    if (pcVar2->kind != '\x01') {
      return 1;
    }
    if (((pcVar2->u18).reg)->cls == '\x02') {
      return 1;
    }
    return 0;
  }
  switch(uVar1) {
  case 1:
    if (((t->src->kind == '\a') && ((t->src->u18).reg == (c2_symbol *)0x0)) &&
       ((t->dst->kind == '\x01' && (((t->dst->u18).reg)->cls != '\x02')))) {
      return 0;
    }
    break;
  case 0x2d:
switchD_1071c2de_caseD_2d:
    if (t->dst->kind != '\x01') {
      return 1;
    }
    pcVar3 = (t->dst->u18).reg;
    if (pcVar3 != g_reg_symbols + 6) {
      if (pcVar3 != g_reg_symbols + 5) {
        return 1;
      }
      return 0;
    }
  case 4:
  case 6:
  case 8:
  case 10:
  case 0xb:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
switchD_1071c2de_caseD_4:
    allowed = 0;
  }
  return allowed;
}

