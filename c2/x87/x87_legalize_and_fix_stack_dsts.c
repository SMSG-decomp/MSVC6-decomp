void __fastcall x87_legalize_and_fix_stack_dsts(c2_tuple *t)

{
  uint32_t uVar1;
  int iVar2;
  c2_operand *pcVar3;
  
  x87_add_implicit_stack_operands(t);
  iVar2 = x87_stack_effect(t);
  uVar1 = t->op;
  if (iVar2 < 0) {
    switch(uVar1) {
    case 0x4b:
    case 0x4c:
    case 0x4d:
    case 0x4e:
    case 0x4f:
    case 0x50:
      if (((t->dst->u18).reg)->id == 0x1f) {
        (t->dst->u18).reg = g_reg_symbols + ((t->src->u18).reg)->id;
      }
      break;
    case 0x5b:
      goto switchD_10721417_caseD_5b;
    case 0x86:
    case 0x91:
    case 0x92:
      if (((t->dst->u18).reg)->id == 0x1f) {
        (t->dst->u18).reg = g_reg_symbols + 0x20;
      }
    }
    pcVar3 = t->dst;
    while( true ) {
      if (pcVar3 == (c2_operand *)0x0) {
        pcVar3 = operand_new_reg(0x149,0x4008,g_reg_symbols + 0x1f,g_reg_symbols + 0x1f);
        tuple_append_dst(t,pcVar3);
        return;
      }
      if ((pcVar3->kind == '\x01') && ((pcVar3->u18).reg == g_reg_symbols + 0x1f)) break;
      pcVar3 = pcVar3->next;
    }
  }
  else if ((((uVar1 == 0x5c) || (uVar1 == 0x62)) &&
           (pcVar3 = t->dst->next, pcVar3 != (c2_operand *)0x0)) &&
          ((pcVar3->kind == '\x01' && (((pcVar3->u18).reg)->id == 0x1f)))) {
    tuple_detach_dst(t,pcVar3);
    node_free((c2_node *)pcVar3);
  }
switchD_10721417_caseD_5b:
  return;
}

