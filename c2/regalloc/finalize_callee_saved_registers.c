void __fastcall finalize_callee_saved_registers(c2_function *fn)

{
  uint32_t *puVar1;
  uint32_t uVar2;
  uint32_t *puVar3;
  
  if (((fn->fsym->attrs & 0x1000) == 0) && ((fn->flags & 0x10000) == 0)) {
    puVar3 = g_int_register_order;
    do {
      uVar2 = *puVar3;
      if (g_reg_symbols[uVar2].u34.refs < 3) {
        remove_register_uses(fn,g_reg_symbols + uVar2);
        g_reg_symbols[g_reg_symbols[uVar2].id].flags5 =
             g_reg_symbols[g_reg_symbols[uVar2].id].flags5 & 0xef;
      }
      puVar1 = puVar3 + 1;
      puVar3 = puVar3 + 1;
    } while (*puVar1 != 0);
  }
  if (((g_ebp_allocatable != 0) && ((g_reg_symbols[6].flags5 & 0x10) != 0)) &&
     (g_opt_favor_speed == 0)) {
    if ((g_reg_symbols[4].flags5 & 0x10) == 0) {
      retarget_frame_register_operands(fn,g_reg_symbols + 4);
      g_reg_symbols[4].flags5 = g_reg_symbols[4].flags5 | 0x10;
      g_reg_symbols[6].flags5 = g_reg_symbols[6].flags5 & 0xef;
      return;
    }
    if ((g_reg_symbols[7].flags5 & 0x10) == 0) {
      retarget_frame_register_operands(fn,g_reg_symbols + 7);
      g_reg_symbols[7].flags5 = g_reg_symbols[7].flags5 | 0x10;
      g_reg_symbols[6].flags5 = g_reg_symbols[6].flags5 & 0xef;
      return;
    }
    if ((g_reg_symbols[8].flags5 & 0x10) == 0) {
      retarget_frame_register_operands(fn,g_reg_symbols + 8);
      g_reg_symbols[8].flags5 = g_reg_symbols[8].flags5 | 0x10;
      g_reg_symbols[6].flags5 = g_reg_symbols[6].flags5 & 0xef;
    }
  }
  return;
}

