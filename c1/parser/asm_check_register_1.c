c1_u8 * __cdecl asm_check_register_1(short reg)

{
  uchar *puVar1;
  int iVar2;
  int iVar3;
  
  if (g_asm_in_brackets == 0) {
    iVar3 = (int)reg;
    if ((*(ushort *)(&g_asm_register_classes + iVar3 * 2) & 0x80c0) == 0x80) {
      puVar1 = asm_check_float_register(reg,0);
    }
    else {
      if ((((byte)*(ushort *)(&g_asm_register_classes + iVar3 * 2) & 0xc0) == 0xc0) &&
         ((g_asm_opcode != 1 ||
          ((g_opt_G_cpu != 4 && (((reg == 0x31 || (reg == 0x32)) || (reg == 0x33)))))))) {
        iVar2 = asm_operand_description_id();
        diag_error(0x194,g_last_name,iVar2);
      }
      g_asm_operand->expr->kind = '\x04';
      g_asm_operand->expr->base = (c1_u8)reg;
      g_asm_operand->size_class = (&g_asm_register_size_class)[iVar3 * 2] & 0xf;
      puVar1 = g_arenas[3].cur;
      g_arenas[3].cur = g_arenas[3].cur + 0xc;
      if (g_arenas[3].end < g_arenas[3].cur) {
        arena_grow(g_arenas + 3);
      }
      puVar1[0] = '\x03';
      puVar1[1] = '\0';
      *(int *)(puVar1 + 8) = iVar3;
    }
  }
  else {
    puVar1 = asm_check_register_2(reg);
  }
  return puVar1;
}

