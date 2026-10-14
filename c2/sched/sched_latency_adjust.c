int __fastcall sched_latency_adjust(c2_sched_node *n)

{
  c2_tuple *pcVar1;
  c2_operand *pcVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  
  pcVar1 = n->tuple;
  iVar4 = 0;
  uVar5 = pcVar1->op;
  if (0x34 < uVar5) {
    switch(uVar5) {
    case 0x62:
    case 99:
    case 0xd9:
    case 0x11c:
    case 0x11d:
    case 0x11e:
    case 0x11f:
    case 0x120:
    case 0x121:
    case 0x122:
    case 0x123:
    case 0x124:
    case 0x125:
    case 0x126:
    case 0x127:
    case 0x128:
    case 0x129:
    case 0x12a:
    case 299:
      if ((n->sflags & 2) == 0) {
        return 0;
      }
      return 1;
    default:
      return 0;
    case 0xb9:
    case 0xba:
      goto switchD_1073acd5_caseD_c;
    case 0xcc:
      if ((n->sflags & 2) == 0) {
        return 0;
      }
      if (pcVar1->src->next->kind != '\x01') {
        return 0;
      }
      return 5;
    case 0xcd:
    case 0xce:
    case 0xcf:
      uVar5 = (uint)((n->sflags & 2) != 0);
      if (pcVar1->src->next->kind != '\x01') {
        return uVar5;
      }
      return uVar5 + 5;
    }
  }
  if (uVar5 < 0x2c) {
    switch(uVar5) {
    case 0xc:
    case 0xd:
    case 0x1e:
    case 0x21:
    case 0x23:
    case 0x24:
      goto switchD_1073acd5_caseD_c;
    case 0x1f:
    case 0x20:
      uVar3 = pcVar1->dst->type & 0xfff;
      if (uVar3 == 1) {
        return 0;
      }
      if (uVar3 != 2) {
        return 0x18;
      }
      return 8;
    case 0x25:
    case 0x26:
      if ((n->sflags & 2) != 0) {
        iVar4 = 2;
      }
      pcVar2 = pcVar1->src->next;
      if (pcVar2->kind == '\x01') {
        return iVar4 + 6;
      }
      if (((pcVar2->u18).reg != (c2_symbol *)0x1) || (pcVar2->tag != 0)) {
        return iVar4 + 7;
      }
      break;
    case 0x27:
    case 0x28:
    case 0x29:
    case 0x2a:
    case 0x2b:
      if (pcVar1->src->next->kind == '\x01') {
        return 3;
      }
      if ((n->sflags & 2) != 0) {
        return 2;
      }
    }
  }
  else {
switchD_1073acd5_caseD_c:
    if ((n->sflags & 2) != 0) {
      return 2;
    }
    if ((n->sflags & 1) != 0) {
      return 1;
    }
  }
  return iVar4;
}

