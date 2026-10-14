uint __fastcall can_use_memory_operand(c2_tuple *t,c2_operand *op)

{
  uint uVar1;
  c2_operand *pcVar2;
  byte bVar3;
  c2_operand *pcVar4;
  
  if (op->sym->cls == '\r') {
    return 1;
  }
  if ((op->flags & 0x20) != 0) {
    return 0;
  }
  uVar1 = t->op;
  if (0xc5 < uVar1) {
    switch(uVar1) {
    case 0xca:
    case 0xcb:
switchD_10714d4b_caseD_33:
      pcVar4 = t->src->next;
      if (((op != pcVar4) && (bVar3 = pcVar4->kind, bVar3 != 2)) &&
         ((1 << (bVar3 & 0x1f) & 0x60U) == 0)) {
        return 1;
      }
      break;
    default:
switchD_10714d4b_caseD_7:
      if ((g_x86_op_flags[uVar1] & 0x800) == 0) {
        pcVar4 = t->src;
        pcVar2 = pcVar4->next;
        if (op != pcVar2) {
          if (pcVar2 == (c2_operand *)0x0) {
            if (pcVar4->kind != '\x01') {
              return 1;
            }
          }
          else {
            if (pcVar2->kind == 2) {
              return 0;
            }
            if ((1 << (pcVar2->kind & 0x1f) & 0x60U) != 0) {
              return 0;
            }
          }
          bVar3 = pcVar4->flags & 0xf;
          if (bVar3 != 0) {
            pcVar2 = tuple_nth_dst(t,bVar3);
            pcVar4 = t->src;
            if (pcVar2->sym != pcVar4->sym) {
              return 0;
            }
          }
          pcVar4 = pcVar4->next;
          if (pcVar4 != (c2_operand *)0x0) {
            if (pcVar4->kind != '\x01') {
              return 1;
            }
            if (((pcVar4->u18).reg)->cls == '\x02') {
              if (pcVar4->sym->cls != '\r') {
                pcVar4->flags11 = pcVar4->flags11 | 0x80;
                return 1;
              }
              return 1;
            }
            return 1;
          }
          return 1;
        }
        if (pcVar4->kind == 2) {
          return 0;
        }
        if ((1 << (pcVar4->kind & 0x1f) & 0x60U) != 0) {
          return 0;
        }
        bVar3 = pcVar2->flags & 0xf;
        if (bVar3 != 0) {
          pcVar2 = tuple_nth_dst(t,bVar3);
          pcVar4 = t->src;
          if (pcVar2->sym != pcVar4->next->sym) {
            return 0;
          }
        }
        if (((pcVar4->kind == '\x01') && (((pcVar4->u18).reg)->cls == '\x02')) &&
           (pcVar4->sym->cls != '\r')) {
          pcVar4->flags11 = pcVar4->flags11 | 0x80;
        }
switchD_10714d4b_caseD_6:
        return 1;
      }
      pcVar4 = t->dst;
      if (op != pcVar4) {
        bVar3 = pcVar4->kind;
        if (bVar3 == 2) {
          return 0;
        }
        if ((1 << (bVar3 & 0x1f) & 0x60U) != 0) {
          return 0;
        }
        if (op == t->src->next) {
          return 0;
        }
        if (bVar3 != 1) {
          return 1;
        }
        if (((pcVar4->u18).reg)->cls != '\x02') {
          return 1;
        }
        pcVar4->flags11 = pcVar4->flags11 | 0x80;
        return 1;
      }
      pcVar4 = t->src;
      bVar3 = pcVar4->kind;
      if ((bVar3 != 2) && ((1 << (bVar3 & 0x1f) & 0x60U) == 0)) {
        if (bVar3 != 1) {
          return 1;
        }
        if (((pcVar4->u18).reg)->cls != '\x02') {
          return 1;
        }
        if (pcVar4->sym->cls == '\r') {
          return 1;
        }
        pcVar4->flags11 = pcVar4->flags11 | 0x80;
        return 1;
      }
      break;
    case 0x118:
    case 0x119:
    case 0x11a:
    case 0x166:
    case 0x178:
    case 0x18d:
    case 0x19e:
      break;
    }
    return 0;
  }
  if (0xc1 < uVar1) {
switchD_10714d4b_caseD_a3:
    return (uint)(op != t->dst);
  }
  switch(uVar1) {
  case 6:
    goto switchD_10714d4b_caseD_6;
  default:
    goto switchD_10714d4b_caseD_7;
  case 0xe:
    return (uint)(op == t->src);
  case 0x12:
    return 0;
  case 0x33:
    goto switchD_10714d4b_caseD_33;
  case 0xa3:
    goto switchD_10714d4b_caseD_a3;
  case 0xc1:
    if (op == t->dst) {
      return 0;
    }
    if (op != t->src) {
      return 1;
    }
    return 0;
  }
}

