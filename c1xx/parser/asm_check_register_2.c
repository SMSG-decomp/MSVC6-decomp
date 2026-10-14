c1_u8 * __cdecl asm_check_register_2(short reg)

{
  c1_u8 *pcVar1;
  c1_u8 cVar2;
  ushort uVar3;
  c1_asm_operand *pcVar4;
  c1_u8 *pcVar5;
  int iVar6;
  short n;
  
  pcVar5 = g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 0xc;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  pcVar5[0] = '\0';
  pcVar5[1] = '\0';
  pcVar5[4] = '\0';
  pcVar5[5] = '\0';
  pcVar5[6] = '\0';
  pcVar5[7] = '\0';
  pcVar4 = g_asm_current_operand->record;
  cVar2 = pcVar4->base;
  if ((cVar2 == '\0') || (pcVar4->index == '\0')) {
    uVar3 = g_asm_registers[reg];
    if (((uVar3 & 0xc0) == 0) && ((uVar3 & 0xf00) == 0x200)) {
      if (cVar2 == '\0') {
        pcVar4->base = (c1_u8)reg;
      }
      else {
        pcVar4->index = (c1_u8)reg;
      }
      pcVar1 = &g_asm_current_operand->record->kind;
      *pcVar1 = *pcVar1 & 0xef;
      pcVar1 = &g_asm_current_operand->record->kind;
      *pcVar1 = *pcVar1 | 0x16;
      pcVar5[0] = '\x01';
      pcVar5[1] = '\0';
      return pcVar5;
    }
    if ((uVar3 & 0x2000) == 0) {
      if ((uVar3 & 0x4000) == 0) {
        iVar6 = asm_operand_description_id();
        n = 0x193;
        goto LAB_104bb52d;
      }
    }
    else if (cVar2 != '\0') {
      iVar6 = asm_operand_description_id();
      n = 0x192;
      goto LAB_104bb52d;
    }
    if (((uVar3 & 0x4000) == 0) || (pcVar4->index == '\0')) {
      iVar6 = asm_operand_description_id();
      diag_error(0x1b0,iVar6);
      return pcVar5;
    }
    iVar6 = asm_operand_description_id();
    n = 0x191;
  }
  else {
    iVar6 = asm_operand_description_id();
    n = 0x194;
  }
LAB_104bb52d:
  diag_error(n,g_last_name,iVar6);
  return pcVar5;
}

