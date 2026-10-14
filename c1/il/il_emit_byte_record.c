void __cdecl il_emit_byte_record(c1_u8 b)

{
  byte bVar1;
  int iVar2;
  
  il_emit_line_record();
  if (g_il_ex.bytes.pbStart + g_il_ex.bytes.cbAlloc < g_il_ex.bytes.pbEnd + 2) {
    iVar2 = il_buffer_grow(&g_il_ex.bytes,2);
    if (iVar2 == 0) {
      bVar1 = 0;
      goto LAB_10604981;
    }
  }
  bVar1 = 1;
LAB_10604981:
  g_il_ex.open = g_il_ex.open & bVar1;
  if (g_il_ex.open != 0) {
    *g_il_ex.bytes.pbEnd = b;
    g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
  }
  return;
}

