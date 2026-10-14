void __cdecl pragma_warning_state_emit(c1_u8 kind)

{
  uchar uVar1;
  bool bVar2;
  uchar *puVar3;
  byte bVar4;
  int iVar5;
  short sVar6;
  uint uVar7;
  
  bVar2 = false;
  uVar7 = g_warning_state_emit_min;
  if (g_warning_state_emit_max < g_warning_state_emit_min) {
    return;
  }
  do {
    uVar1 = g_warning_state->state[uVar7];
    if (uVar1 != '\0') {
      if (!bVar2) {
        il_emit_byte_record('O');
        if (g_il_ex.bytes.pbStart + g_il_ex.bytes.cbAlloc < g_il_ex.bytes.pbEnd + 2) {
          iVar5 = il_buffer_grow(&g_il_ex.bytes,2);
          bVar4 = 0;
          if (iVar5 != 0) goto LAB_1063a7c2;
        }
        else {
LAB_1063a7c2:
          bVar4 = 1;
        }
        g_il_ex.open = g_il_ex.open & bVar4;
        if (g_il_ex.open != 0) {
          *g_il_ex.bytes.pbEnd = kind;
          g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
        }
        bVar2 = true;
      }
      sVar6 = (short)uVar7 + -700;
      if (g_il_ex.bytes.pbStart + g_il_ex.bytes.cbAlloc < g_il_ex.bytes.pbEnd + 4) {
        iVar5 = il_buffer_grow(&g_il_ex.bytes,4);
        bVar4 = 0;
        if (iVar5 != 0) goto LAB_1063a825;
      }
      else {
LAB_1063a825:
        bVar4 = 1;
      }
      g_il_ex.open = g_il_ex.open & bVar4;
      if ((g_il_ex.open != 0) &&
         (iVar5 = il_buffer_put_byte7(&g_il_ex,(int)sVar6), (char)iVar5 == '\0')) {
        *g_il_ex.bytes.pbEnd = 0x80;
        g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
        *(short *)g_il_ex.bytes.pbEnd = sVar6;
        g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 2;
      }
      if (g_il_ex.bytes.pbStart + g_il_ex.bytes.cbAlloc < g_il_ex.bytes.pbEnd + 2) {
        iVar5 = il_buffer_grow(&g_il_ex.bytes,2);
        bVar4 = 0;
        if (iVar5 != 0) goto LAB_1063a89c;
      }
      else {
LAB_1063a89c:
        bVar4 = 1;
      }
      g_il_ex.open = g_il_ex.open & bVar4;
      if (g_il_ex.open != 0) {
        *g_il_ex.bytes.pbEnd = uVar1;
        g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
      }
    }
    uVar7 = uVar7 + 1;
  } while (uVar7 <= g_warning_state_emit_max);
  if (!bVar2) {
    return;
  }
  if (g_il_ex.bytes.pbStart + g_il_ex.bytes.cbAlloc < g_il_ex.bytes.pbEnd + 4) {
    iVar5 = il_buffer_grow(&g_il_ex.bytes,4);
    bVar4 = 0;
    if (iVar5 == 0) goto LAB_1063a911;
  }
  bVar4 = 1;
LAB_1063a911:
  g_il_ex.open = g_il_ex.open & bVar4;
  if (g_il_ex.open != 0) {
    *g_il_ex.bytes.pbEnd = 0x80;
    g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
    puVar3 = g_il_ex.bytes.pbEnd + 1;
    g_il_ex.bytes.pbEnd[0] = 0xff;
    *puVar3 = 0xff;
    g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 2;
  }
  return;
}

