c1_u8 * __cdecl asm_check_register_1(short reg)

{
  c1_u8 *pcVar1;
  int iVar2;
  int iVar3;
  
  if (g_asm_in_brackets == 0) {
    iVar3 = (int)reg;
    if ((g_asm_registers[iVar3] & 0x80c0) == 0x80) {
      pcVar1 = asm_check_float_register(reg,0);
    }
    else {
      if ((((byte)g_asm_registers[iVar3] & 0xc0) == 0xc0) &&
         ((g_asm_instruction_code != 1 ||
          ((g_opt_G_cpu != 4 && (((reg == 0x31 || (reg == 0x32)) || (reg == 0x33)))))))) {
        iVar2 = asm_operand_description_id();
        diag_error(0x194,g_last_name,iVar2);
      }
      g_asm_current_operand->record->kind = '\x04';
      g_asm_current_operand->record->base = (c1_u8)reg;
      g_asm_current_operand->size_class = *(byte *)((int)g_asm_registers + iVar3 * 2 + 1) & 0xf;
      pcVar1 = g_arenas[5].cur;
      g_arenas[5].cur = g_arenas[5].cur + 0xc;
      if (g_arenas[5].end < g_arenas[5].cur) {
        arena_grow(g_arenas + 5);
      }
      pcVar1[0] = '\x03';
      pcVar1[1] = '\0';
      *(int *)(pcVar1 + 8) = iVar3;
    }
  }
  else {
    pcVar1 = asm_check_register_2(reg);
  }
  return pcVar1;
}

