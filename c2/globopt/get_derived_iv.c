c2_operand * __fastcall get_derived_iv(uint16_t type,uint32_t op,c2_operand *a,c2_operand *b)

{
  uint8_t *puVar1;
  c2_symbol *b_00;
  c2_symbol *pcVar2;
  short sVar3;
  uint32_t uVar4;
  c2_operand *pcVar5;
  int iVar6;
  
  uVar4 = map_iv_update_opcode(op);
  pcVar5 = operand_new_cse_sym(uVar4,type,a,b);
  b_00 = pcVar5->sym;
  if (((b_00->u30).sizeopt.width_facts & 3) == 0) {
    pcVar2 = b_00;
    if (g_derived_iv_head != (c2_symbol *)0xffffffff) {
      g_derived_iv_tail->order_next = b_00;
      pcVar2 = g_derived_iv_head;
    }
    g_derived_iv_head = pcVar2;
    g_derived_iv_tail = b_00;
    b_00->order_next = (c2_symbol *)0xffffffff;
    uVar4 = is_loop_invariant_operand(a);
    if ((uVar4 == 0) ||
       ((b != (c2_operand *)0x0 && (uVar4 = is_loop_invariant_operand(b), uVar4 == 0)))) {
      uVar4 = b_00->id;
      puVar1 = &(b_00->u30).sizeopt.width_facts;
      *puVar1 = *puVar1 | 1;
      bitset_set(g_iv_syms,uVar4);
      bitset_set(g_loop_kill_set,uVar4);
      b_00->flags7 = b_00->flags7 | 2;
    }
    else {
      puVar1 = &(b_00->u30).sizeopt.width_facts;
      *puVar1 = *puVar1 | 2;
      iVar6 = iv_operand_is_variable(a);
      if ((iVar6 == 0) &&
         ((b == (c2_operand *)0x0 || (iVar6 = iv_operand_is_variable(b), iVar6 == 0)))) {
        sVar3 = 0;
      }
      else {
        sVar3 = 1;
      }
      uVar4 = b_00->id;
      (b_00->u30).globopt.marks = sVar3 << 2 | (b_00->u30).globopt.marks & 0xfffb;
      bitset_set(g_invariant_expr_syms,uVar4);
    }
    if ((1 << (a->kind & 0x1f) & 6U) != 0) {
      cse_add_copy_link(a->sym,b_00);
    }
    if ((b != (c2_operand *)0x0) && ((1 << (b->kind & 0x1f) & 6U) != 0)) {
      cse_add_copy_link(b->sym,b_00);
    }
  }
  return pcVar5;
}

