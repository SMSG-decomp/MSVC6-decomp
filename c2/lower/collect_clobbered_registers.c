void __fastcall collect_clobbered_registers(c2_tuple *list,c2_bitset *set)

{
  uint uVar1;
  c2_operand *pcVar2;
  uint32_t uVar3;
  
  if (list != (c2_tuple *)0x0) {
    do {
      if ((list->flags & 1) == 0) goto LAB_10774165;
      uVar1 = list->op;
      if ((g_x86_op_flags[uVar1] & 2) != 0) {
        bitset_set(set,0x42);
      }
      if (uVar1 < 0xa0) {
        if (uVar1 == 0x9f) goto switchD_107741c0_caseD_df;
        switch(uVar1) {
        case 6:
        case 0x1f:
        case 0x20:
        case 0x22:
          goto switchD_107740aa_caseD_6;
        default:
          goto switchD_107740aa_caseD_7;
        case 10:
        case 0x95:
        case 0x96:
        case 0x97:
        case 0x98:
        case 0x99:
          goto switchD_107740aa_caseD_a;
        case 0xc:
        case 0xd:
          goto switchD_107740aa_caseD_c;
        case 0xe:
          goto switchD_107740aa_caseD_e;
        case 0x10:
          goto switchD_107740aa_caseD_10;
        case 0x17:
        case 0x18:
        case 0x19:
          goto switchD_107740aa_caseD_17;
        case 0x35:
        case 0x38:
          bitset_set(set,7);
        case 0x36:
        case 0x3a:
        case 0x3b:
          uVar3 = 8;
          break;
        case 0x37:
          bitset_set(set,1);
        case 0x39:
          uVar3 = 7;
          break;
        case 0x6c:
        case 0x6e:
          bitset_set(set,1);
          uVar3 = 0x4a;
        }
        goto LAB_107740bf;
      }
      switch(uVar1) {
      case 0xa0:
      case 0xa1:
      case 0xa6:
      case 0xde:
switchD_107740aa_caseD_a:
        uVar3 = 1;
        break;
      default:
        goto switchD_107740aa_caseD_7;
      case 0xaa:
        bitset_set(set,1);
        bitset_set(set,3);
        bitset_set(set,2);
        bitset_set(set,7);
        bitset_set(set,8);
        bitset_set(set,4);
      case 0xab:
      case 0xac:
      case 0xad:
switchD_107740aa_caseD_c:
        uVar3 = 5;
        break;
      case 0xb5:
      case 0xb7:
      case 0xb8:
switchD_107740aa_caseD_17:
        uVar3 = 2;
        break;
      case 0xc6:
      case 199:
      case 0x114:
      case 0x115:
switchD_107740aa_caseD_10:
        if ((list->src->kind == '\x04') && (list->src->sym->cls == '\x04')) {
          bitset_set(set,1);
          bitset_set(set,3);
          goto switchD_107740aa_caseD_17;
        }
        goto switchD_107740aa_caseD_7;
      case 0xdf:
        goto switchD_107741c0_caseD_df;
      case 0xfd:
      case 0xff:
      case 0x101:
      case 0x102:
switchD_107740aa_caseD_6:
        uVar3 = 1;
        goto LAB_1077428f;
      case 0xfe:
        bitset_set(set,1);
        bitset_set(set,4);
        uVar3 = 2;
LAB_1077428f:
        bitset_set(set,uVar3);
switchD_107741c0_caseD_df:
        uVar3 = 3;
        break;
      case 0x116:
switchD_107740aa_caseD_e:
        bitset_set(set,1);
        bitset_set(set,3);
        bitset_set(set,2);
        bitset_set(set,5);
        uVar3 = 0x42;
      }
LAB_107740bf:
      bitset_set(set,uVar3);
switchD_107740aa_caseD_7:
      if (((g_x86_op_flags[uVar1] & 1) != 0) || (list->kind == '\x0e')) {
        bitset_set(set,0x1f);
        bitset_set(set,0x20);
        bitset_set(set,0x21);
        bitset_set(set,0x22);
        bitset_set(set,0x23);
        bitset_set(set,0x24);
        bitset_set(set,0x25);
        bitset_set(set,0x26);
      }
      for (pcVar2 = list->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
        if ((((pcVar2->kind == '\x01') && (uVar1 = ((pcVar2->u18).reg)->storage->id, uVar1 != 0)) &&
            (uVar1 < 9)) && (uVar1 != 5)) {
          bitset_set(set,uVar1);
        }
      }
LAB_10774165:
      list = list->next;
    } while (list != (c2_tuple *)0x0);
  }
  bitset_clear(set,6);
  return;
}

