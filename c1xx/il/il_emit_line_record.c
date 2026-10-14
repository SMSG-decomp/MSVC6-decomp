void __cdecl il_emit_line_record(void)

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
  if (g_il_ex.bytes.start + g_il_ex.bytes.size < g_il_ex.bytes.cur + 2) {
    iVar3 = il_buffer_grow(&g_il_ex.bytes,2);
    bVar2 = 0;
    if (iVar3 != 0) goto LAB_1047e2a9;
  }
  else {
LAB_1047e2a9:
    bVar2 = 1;
  }
  g_il_ex.open = g_il_ex.open & bVar2;
  if (g_il_ex.open != 0) {
    *g_il_ex.bytes.cur = 'O';
    g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
  }
  if (g_il_ex.bytes.start + g_il_ex.bytes.size < g_il_ex.bytes.cur + 2) {
    iVar3 = il_buffer_grow(&g_il_ex.bytes,2);
    bVar2 = 0;
    if (iVar3 != 0) goto LAB_1047e2fd;
  }
  else {
LAB_1047e2fd:
    bVar2 = 1;
  }
  g_il_ex.open = g_il_ex.open & bVar2;
  if (g_il_ex.open != 0) {
    *g_il_ex.bytes.cur = '$';
    g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
  }
  uVar1 = g_il_line_offset;
  if (g_il_ex.bytes.start + g_il_ex.bytes.size < g_il_ex.bytes.cur + 4) {
    iVar3 = il_buffer_grow(&g_il_ex.bytes,4);
    bVar2 = 0;
    if (iVar3 == 0) goto LAB_1047e35d;
  }
  bVar2 = 1;
LAB_1047e35d:
  g_il_ex.open = g_il_ex.open & bVar2;
  if (g_il_ex.open != 0) {
    if ((uVar1 & 0xff80) == 0) {
      *g_il_ex.bytes.cur = (c1_u8)uVar1;
      g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
      return;
    }
    *g_il_ex.bytes.cur = 0x80;
    g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
    *(short *)g_il_ex.bytes.cur = (short)uVar1;
    g_il_ex.bytes.cur = g_il_ex.bytes.cur + 2;
  }
  return;
}

