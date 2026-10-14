void __fastcall encode_modrm(c2_tuple *t,c2_operand *opnd,uint32_t reg_field)

{
  c2_symbol *pcVar1;
  c2_operand *pcVar2;
  bool bVar3;
  uint32_t uVar4;
  byte bVar5;
  byte bVar6;
  
  bVar6 = (byte)((reg_field & 7) << 3);
  switch(opnd->op) {
  case 0x149:
    *g_encode_cursor = (byte)(((opnd->u18).reg)->u28).frame_home | bVar6 | 0xc0;
    g_encode_cursor = g_encode_cursor + 1;
    return;
  case 0x14a:
    if (((g_esp_adjust_locals == 0) || (opnd->sym->cls == '\x05')) &&
       ((g_esp_adjust_params == 0 || (opnd->sym->cls != '\x05')))) {
      uVar4 = modrm_mod_for_operand(opnd,(int *)&reg_field);
      bVar5 = (byte)uVar4 | (undefined1)g_reg_symbols[6].u28.hw_reg;
LAB_1073630d:
      *g_encode_cursor = bVar5 | bVar6;
      goto LAB_10736316;
    }
    break;
  case 0x14b:
    *g_encode_cursor = bVar6 | 5;
    g_encode_cursor = g_encode_cursor + 1;
    reg_field = 4;
    encode_imm_or_disp(opnd,4,0);
    return;
  case 0x14c:
    if (((opnd->base->u18).reg)->id != 5) {
      uVar4 = modrm_mod_for_operand(opnd,(int *)&reg_field);
      bVar5 = (byte)uVar4 | *(byte *)&((opnd->base->u18).reg)->u28;
      goto LAB_1073630d;
    }
    break;
  case 0x14d:
    if (((opnd->index->u18).reg)->id == 5) {
      pcVar2 = opnd->base;
      opnd->base = opnd->index;
      opnd->index = pcVar2;
    }
    uVar4 = modrm_mod_for_operand(opnd,(int *)&reg_field);
    pcVar2 = opnd->index;
    *g_encode_cursor = (byte)uVar4 | bVar6 | 4;
    g_encode_cursor = g_encode_cursor + 1;
    *g_encode_cursor =
         (*(byte *)&((pcVar2->u18).reg)->u28 & 7 | opnd->flags << 3) << 3 |
         *(byte *)&((opnd->base->u18).reg)->u28 & 7;
    goto LAB_10736316;
  case 0x14e:
    if (((g_esp_adjust_params == 0) || (opnd->base_sym->cls != '\x05')) &&
       ((g_esp_adjust_locals == 0 || (opnd->base_sym->cls == '\x05')))) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    uVar4 = modrm_mod_for_operand(opnd,(int *)&reg_field);
    *g_encode_cursor = (byte)uVar4 | bVar6 | 4;
    bVar6 = (byte)g_reg_symbols[5].u28.frame_home;
    g_encode_cursor = g_encode_cursor + 1;
    if (!bVar3) {
      bVar6 = (byte)g_reg_symbols[6].u28.frame_home;
    }
    *g_encode_cursor =
         (*(byte *)&((opnd->index->u18).reg)->u28 & 7 | opnd->flags << 3) << 3 | bVar6 & 7;
    goto LAB_10736316;
  case 0x14f:
    pcVar1 = (opnd->index->u18).reg;
    *g_encode_cursor = bVar6 | 4;
    g_encode_cursor[1] = (*(byte *)&pcVar1->u28 & 7 | opnd->flags << 3) << 3 | 5;
    g_encode_cursor = g_encode_cursor + 2;
    reg_field = 4;
    encode_imm_or_disp(opnd,4,0);
    return;
  }
  uVar4 = modrm_mod_for_operand(opnd,(int *)&reg_field);
  *g_encode_cursor = (byte)uVar4 | bVar6 | 4;
  g_encode_cursor = g_encode_cursor + 1;
  *g_encode_cursor =
       ((undefined1)g_reg_symbols[5].u28.hw_reg & 7) << 3 |
       (undefined1)g_reg_symbols[5].u28.hw_reg & 7;
LAB_10736316:
  g_encode_cursor = g_encode_cursor + 1;
  encode_imm_or_disp(opnd,reg_field,0);
  return;
}

