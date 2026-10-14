c2_operand * __fastcall derive_iv_from_chain(c2_operand *a,c2_operand *b,c2_operand *base)

{
  uint8_t *puVar1;
  uint16_t type;
  c2_cse_expr *pcVar2;
  int iVar3;
  c2_operand *a_00;
  uint32_t lo;
  c2_operand *pcVar4;
  uint32_t uVar5;
  
  iVar3 = operand_compare(a,b);
  if (iVar3 == 0) {
    return a;
  }
  pcVar2 = (b->sym->u18).expr;
  a_00 = derive_iv_from_chain(a,pcVar2->operands,base);
  iVar3 = operand_compare(base,pcVar2->operands->next);
  if (iVar3 != 0) {
    uVar5 = pcVar2->op;
    type = pcVar2->type;
    if ((base->kind == '\x03') && (pcVar4 = pcVar2->operands->next, pcVar4->kind == '\x03')) {
      lo = pcVar4->sym->offset - base->sym->offset;
      pcVar4 = operand_new_intconst(type,lo,(int)lo >> 0x1f);
    }
    else {
      iVar3 = operand_reaches_via_copies(pcVar2->operands->next,base);
      if (iVar3 == 0) {
        pcVar4 = pcVar2->operands->next;
      }
      else {
        pcVar4 = operand_new_cse_sym(0x16e,type,pcVar2->operands->next,base);
        puVar1 = &(pcVar4->sym->u30).sizeopt.width_facts;
        *puVar1 = *puVar1 | 2;
        bitset_set(g_invariant_expr_syms,pcVar4->sym->id);
      }
    }
    uVar5 = map_iv_update_opcode(uVar5);
    a_00 = get_derived_iv(type,uVar5,a_00,pcVar4);
  }
  return a_00;
}

