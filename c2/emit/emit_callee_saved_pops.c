c2_tuple * __fastcall emit_callee_saved_pops(c2_function *fn,c2_tuple *after,uint32_t skip_mask)

{
  byte bVar1;
  uint uVar2;
  c2_symbol *reg;
  
  bVar1 = 8;
  reg = g_reg_symbols + 8;
  do {
    uVar2 = 1 << (bVar1 & 0x1f);
    if ((((g_callee_saved_mask & uVar2) != 0) && ((reg->flags5 & 0x10) != 0)) &&
       ((skip_mask & uVar2) == 0)) {
      after = emit_callee_save_pop(reg,after);
    }
    reg = reg + -1;
    bVar1 = bVar1 - 1;
  } while (0x107ac87f < (int)reg);
  return after;
}

