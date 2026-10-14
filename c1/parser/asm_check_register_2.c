c1_u8 * __cdecl asm_check_register_2(short reg)

{
  c1_u8 *pcVar1;
  c1_u8 cVar2;
  ushort uVar3;
  c1_asm_expr *pcVar4;
  uchar *puVar5;
  int iVar6;
  short n;
  
  puVar5 = g_arenas[3].cur;
  g_arenas[3].cur = g_arenas[3].cur + 0xc;
  if (g_arenas[3].end < g_arenas[3].cur) {
    arena_grow(g_arenas + 3);
  }
  puVar5[0] = '\0';
  puVar5[1] = '\0';
  puVar5[4] = '\0';
  puVar5[5] = '\0';
  puVar5[6] = '\0';
  puVar5[7] = '\0';
  pcVar4 = g_asm_operand->expr;
  cVar2 = pcVar4->base;
  if ((cVar2 == '\0') || (pcVar4->index == '\0')) {
    uVar3 = *(ushort *)(&g_asm_register_classes + reg * 2);
    if (((uVar3 & 0xc0) == 0) && ((uVar3 & 0xf00) == 0x200)) {
      if (cVar2 == '\0') {
        pcVar4->base = (c1_u8)reg;
      }
      else {
        pcVar4->index = (c1_u8)reg;
      }
      pcVar1 = &g_asm_operand->expr->kind;
      *pcVar1 = *pcVar1 & 0xef;
      pcVar1 = &g_asm_operand->expr->kind;
      *pcVar1 = *pcVar1 | 0x16;
      puVar5[0] = '\x01';
      puVar5[1] = '\0';
      return puVar5;
    }
    if ((uVar3 & 0x2000) == 0) {
      if ((uVar3 & 0x4000) == 0) {
        iVar6 = asm_operand_description_id();
        n = 0x193;
        goto LAB_10650e4e;
      }
    }
    else if (cVar2 != '\0') {
      iVar6 = asm_operand_description_id();
      n = 0x192;
      goto LAB_10650e4e;
    }
    if (((uVar3 & 0x4000) == 0) || (pcVar4->index == '\0')) {
      iVar6 = asm_operand_description_id();
      diag_error(0x1b0,iVar6);
      return puVar5;
    }
    iVar6 = asm_operand_description_id();
    n = 0x191;
  }
  else {
    iVar6 = asm_operand_description_id();
    n = 0x194;
  }
LAB_10650e4e:
  diag_error(n,g_last_name,iVar6);
  return puVar5;
}

