uint32_t __fastcall is_induction_variable_operand(c2_operand *opnd)

{
  uint32_t uVar1;
  
  if ((1 << (opnd->kind & 0x1f) & 6U) != 0) {
    uVar1 = bitset_test(g_iv_syms,opnd->sym->id);
    if (uVar1 != 0) {
      return 1;
    }
  }
  return 0;
}

