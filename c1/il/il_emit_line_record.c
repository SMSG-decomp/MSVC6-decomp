void il_emit_line_record(void)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  
  if (g_il_line_offset == 0) {
    return;
  }
  if (g_il_line_offset == g_il_last_line_offset) {
    return;
  }
  g_il_last_line_offset = g_il_line_offset;
  if (g_il_ex.bytes.pbStart + g_il_ex.bytes.cbAlloc < g_il_ex.bytes.pbEnd + 2) {
    iVar3 = il_buffer_grow(&g_il_ex.bytes,2);
    bVar2 = 0;
    if (iVar3 != 0) goto LAB_1063a2ea;
  }
  else {
LAB_1063a2ea:
    bVar2 = 1;
  }
  g_il_ex.open = g_il_ex.open & bVar2;
  if (g_il_ex.open != 0) {
    *g_il_ex.bytes.pbEnd = 'O';
    g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
  }
  if (g_il_ex.bytes.pbStart + g_il_ex.bytes.cbAlloc < g_il_ex.bytes.pbEnd + 2) {
    iVar3 = il_buffer_grow(&g_il_ex.bytes,2);
    bVar2 = 0;
    if (iVar3 != 0) goto LAB_1063a33e;
  }
  else {
LAB_1063a33e:
    bVar2 = 1;
  }
  g_il_ex.open = g_il_ex.open & bVar2;
  if (g_il_ex.open != 0) {
    *g_il_ex.bytes.pbEnd = '$';
    g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
  }
  uVar1 = g_il_line_offset;
  if (g_il_ex.bytes.pbStart + g_il_ex.bytes.cbAlloc < g_il_ex.bytes.pbEnd + 4) {
    iVar3 = il_buffer_grow(&g_il_ex.bytes,4);
    bVar2 = 0;
    if (iVar3 == 0) goto LAB_1063a39e;
  }
  bVar2 = 1;
LAB_1063a39e:
  g_il_ex.open = g_il_ex.open & bVar2;
  if (g_il_ex.open != 0) {
    if ((uVar1 & 0xff80) == 0) {
      *g_il_ex.bytes.pbEnd = (uchar)uVar1;
      g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
      return;
    }
    *g_il_ex.bytes.pbEnd = 0x80;
    g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
    *(short *)g_il_ex.bytes.pbEnd = (short)uVar1;
    g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 2;
  }
  return;
}

