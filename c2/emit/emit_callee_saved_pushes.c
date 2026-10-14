c2_tuple * __fastcall
emit_callee_saved_pushes(c2_function *fn,c2_tuple *after,uint32_t shrink_wrapped_mask)

{
  byte bVar1;
  uint uVar2;
  c2_symbol *reg;
  
  bVar1 = 4;
  reg = g_reg_symbols + 4;
  do {
    uVar2 = 1 << (bVar1 & 0x1f);
    if ((((g_callee_saved_mask & uVar2) != 0) && ((reg->flags5 & 0x10) != 0)) &&
       ((shrink_wrapped_mask & uVar2) == 0)) {
      after = emit_callee_save_push(fn,reg,after);
    }
    reg = reg + 1;
    bVar1 = bVar1 + 1;
  } while ((int)reg < 0x107ac9d1);
  return after;
}

