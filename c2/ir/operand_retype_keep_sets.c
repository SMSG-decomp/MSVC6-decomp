void __fastcall operand_retype_keep_sets(c2_operand *op,uint16_t type)

{
  uint8_t *puVar1;
  uint32_t n;
  uint32_t uVar2;
  uint32_t uVar3;
  byte bVar4;
  c2_symbol *pcVar5;
  
  pcVar5 = (c2_symbol *)0x0;
  bVar4 = 0;
  if ((1 << (op->kind & 0x1f) & 6U) != 0) {
    pcVar5 = op->sym;
    bVar4 = (pcVar5->u30).sizeopt.width_facts >> 1 & 1;
  }
  operand_set_type(op,type);
  if ((bVar4 != 0) && ((1 << (op->kind & 0x1f) & 6U) != 0)) {
    puVar1 = &(op->sym->u30).sizeopt.width_facts;
    *puVar1 = *puVar1 | 2;
  }
  if ((pcVar5 != (c2_symbol *)0x0) && (pcVar5 != op->sym)) {
    uVar3 = pcVar5->id;
    n = op->sym->id;
    uVar2 = bitset_test(g_invariant_expr_syms,uVar3);
    if (uVar2 != 0) {
      bitset_set(g_invariant_expr_syms,n);
    }
    uVar2 = bitset_test(g_loop_kill_set,uVar3);
    if (uVar2 != 0) {
      bitset_set(g_loop_kill_set,n);
    }
    uVar2 = bitset_test(g_preheader_avail_exprs,uVar3);
    if (uVar2 != 0) {
      bitset_set(g_preheader_avail_exprs,n);
    }
    uVar2 = bitset_test(g_hoisted_exprs,uVar3);
    if (uVar2 != 0) {
      bitset_set(g_hoisted_exprs,n);
    }
    uVar2 = bitset_test(g_loop_live_out_syms,uVar3);
    if (uVar2 != 0) {
      bitset_set(g_loop_live_out_syms,n);
    }
    uVar3 = bitset_test(g_preheader_live_out,uVar3);
    if (uVar3 != 0) {
      bitset_set(g_preheader_live_out,n);
    }
  }
  return;
}

