uint32_t __fastcall operand_live_out_of_preheader(c2_operand *op)

{
  uint32_t uVar1;
  
  if ((1 << (op->kind & 0x1f) & 6U) != 0) {
    uVar1 = bitset_test(g_preheader_live_out,op->sym->id);
    return uVar1;
  }
  return 0;
}

