c1_u8 * __cdecl asm_check_float_register(short reg,int st_index)

{
  uchar *puVar1;
  int iVar2;
  fe_name *pfVar3;
  c1_u8 *pcVar4;
  short sVar5;
  
  if ((g_asm_form_words[g_asm_form] & 0xc0) == 0x80) {
    if (reg != 0x1f) goto LAB_10650ff3;
    if (st_index < 8) {
      sVar5 = 0x1f;
      if (-1 < st_index) goto LAB_10650f97;
      goto LAB_10650f70;
    }
  }
  else {
LAB_10650f70:
    if (reg != 0x1f) {
LAB_10650ff3:
      iVar2 = asm_operand_description_id();
      diag_error(0x197,iVar2);
      pcVar4 = asm_check_register_1(reg);
      return pcVar4;
    }
  }
  iVar2 = asm_operand_description_id();
  pfVar3 = name_intern("ST");
  diag_error(0x194,pfVar3,iVar2);
  sVar5 = 0;
LAB_10650f97:
  g_asm_operand->expr->kind = '4';
  g_asm_operand->expr->base = (c1_u8)st_index;
  g_asm_operand->size_class = (&g_asm_register_size_class)[sVar5 * 2] & 0xf;
  puVar1 = g_arenas[3].cur;
  g_arenas[3].cur = g_arenas[3].cur + 0xc;
  if (g_arenas[3].end < g_arenas[3].cur) {
    arena_grow(g_arenas + 3);
  }
  puVar1[0] = '\x03';
  puVar1[1] = '\0';
  *(int *)(puVar1 + 8) = (int)sVar5;
  return puVar1;
}

