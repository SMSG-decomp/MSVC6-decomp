c1_u8 * __cdecl asm_check_float_register(short reg,int st_index)

{
  int iVar1;
  void *pvVar2;
  c1_u8 *pcVar3;
  short sVar4;
  
  if ((g_asm_forms[g_asm_operand_form] & 0xc0) == 0x80) {
    if (reg != 0x1f) goto LAB_104bb6d2;
    if (st_index < 8) {
      sVar4 = 0x1f;
      if (-1 < st_index) goto LAB_104bb676;
      goto LAB_104bb64f;
    }
  }
  else {
LAB_104bb64f:
    if (reg != 0x1f) {
LAB_104bb6d2:
      iVar1 = asm_operand_description_id();
      diag_error(0x197,iVar1);
      pcVar3 = asm_check_register_1(reg);
      return pcVar3;
    }
  }
  iVar1 = asm_operand_description_id();
  pvVar2 = name_intern("ST");
  diag_error(0x194,pvVar2,iVar1);
  sVar4 = 0;
LAB_104bb676:
  g_asm_current_operand->record->kind = '4';
  g_asm_current_operand->record->base = (c1_u8)st_index;
  g_asm_current_operand->size_class = *(byte *)((int)g_asm_registers + sVar4 * 2 + 1) & 0xf;
  pcVar3 = g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 0xc;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  pcVar3[0] = '\x03';
  pcVar3[1] = '\0';
  *(int *)(pcVar3 + 8) = (int)sVar4;
  return pcVar3;
}

