void __cdecl il_emit_byte_record(c1_u8 b)

{
  byte bVar1;
  int iVar2;
  
  il_emit_line_record();
  if (g_il_ex.bytes.start + g_il_ex.bytes.size < g_il_ex.bytes.cur + 2) {
    iVar2 = il_buffer_grow(&g_il_ex.bytes,2);
    if (iVar2 == 0) {
      bVar1 = 0;
      goto LAB_1040d8be;
    }
  }
  bVar1 = 1;
LAB_1040d8be:
  g_il_ex.open = g_il_ex.open & bVar1;
  if (g_il_ex.open != 0) {
    *g_il_ex.bytes.cur = b;
    g_il_ex.bytes.cur = g_il_ex.bytes.cur + 1;
  }
  return;
}

