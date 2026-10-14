int __fastcall operand_is_partial_alias_iv(c2_operand *op)

{
  uint32_t uVar1;
  
  if ((1 << (op->kind & 0x1f) & 6U) != 0) {
    uVar1 = bitset_test(g_iv_partial_alias_syms,op->sym->id);
    if (uVar1 != 0) {
      return 1;
    }
  }
  return 0;
}

