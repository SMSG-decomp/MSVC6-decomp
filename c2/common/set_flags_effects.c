void __fastcall set_flags_effects(c2_tuple *t)

{
  uint uVar1;
  byte bVar2;
  c2_operand *pcVar3;
  
  if ((t->flags & 1) == 0) {
    return;
  }
  bVar2 = x86_fixed_reg_class(t);
  if (bVar2 != 0) {
    pcVar3 = find_src_overlapping_reg(t,g_reg_symbols + 0x42);
    (pcVar3->u18).reg = g_reg_symbols + g_flags_subreg_by_cc[g_cond_to_x86_cc[bVar2]];
    return;
  }
  pcVar3 = find_dst_clobbering_reg(t,g_reg_symbols + 0x42);
  uVar1 = t->op;
  if (uVar1 < 0x31) {
    if (uVar1 != 0x30) {
      switch(uVar1) {
      case 6:
      case 8:
      case 0xe:
      case 0x1f:
      case 0x20:
      case 0x22:
      case 0x23:
      case 0x29:
      case 0x2a:
      case 0x2b:
      case 0x2d:
      case 0x2e:
        break;
      default:
        return;
      case 0x1e:
      case 0x21:
switchD_107137ce_caseD_1e:
        if (pcVar3 == (c2_operand *)0x0) {
          pcVar3 = operand_new_hardreg(0x43,0x8000);
          tuple_append_dst(t,pcVar3);
          return;
        }
        (pcVar3->u18).reg = g_reg_symbols + 0x43;
        return;
      case 0x27:
      case 0x28:
        pcVar3 = operand_new_hardreg(0x49,0x8000);
        tuple_append_dst(t,pcVar3);
        return;
      case 0x2c:
        goto switchD_107137ce_caseD_2c;
      }
    }
switchD_107137ce_caseD_6:
    if (pcVar3 != (c2_operand *)0x0) {
      return;
    }
LAB_10713824:
    pcVar3 = operand_new_hardreg(0x42,0x8000);
    tuple_append_dst(t,pcVar3);
  }
  else {
    if (uVar1 < 0xd0) {
      if (uVar1 < 200) {
        switch(uVar1) {
        case 0x31:
          goto switchD_107137ce_caseD_2c;
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x3a:
        case 0xa3:
        case 0xc1:
          break;
        default:
          goto switchD_107137ce_caseD_7;
        }
      }
      goto switchD_107137ce_caseD_6;
    }
    switch(uVar1) {
    case 0xd9:
    case 0xda:
    case 0x116:
    case 0x11a:
      goto switchD_107137ce_caseD_6;
    case 0x10f:
      find_src_overlapping_reg(t,g_reg_symbols + 0x42);
      return;
    case 0x118:
    case 0x119:
switchD_107137ce_caseD_2c:
      pcVar3 = find_src_overlapping_reg(t,g_reg_symbols + 0x42);
      (pcVar3->u18).reg = g_reg_symbols + 0x49;
      goto LAB_10713824;
    case 0x166:
      if ((t->src->u18).reg == (c2_symbol *)0x183) goto switchD_107137ce_caseD_1e;
    }
  }
switchD_107137ce_caseD_7:
  return;
}

