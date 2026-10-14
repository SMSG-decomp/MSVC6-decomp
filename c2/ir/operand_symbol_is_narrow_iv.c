int __fastcall operand_symbol_is_narrow_iv(c2_operand *op)

{
  uint32_t uVar1;
  
  uVar1 = bitset_test(g_narrow_iv_syms,op->sym->id);
  return (uint)(uVar1 != 0);
}

