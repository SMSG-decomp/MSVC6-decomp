void __cdecl il_emit_in_marker(void)

{
  byte bVar1;
  int iVar2;
  
  if ((g_compile_flags_cc & 0x800) == 0) {
    if ((g_il_in.bytes.start + g_il_in.bytes.size < g_il_in.bytes.cur + 2) &&
       (iVar2 = il_buffer_grow(&g_il_in.bytes,2), iVar2 == 0)) {
      bVar1 = 0;
    }
    else {
      bVar1 = 1;
    }
    g_il_in.open = g_il_in.open & bVar1;
    if (g_il_in.open != 0) {
      *g_il_in.bytes.cur = '\a';
      g_il_in.bytes.cur = g_il_in.bytes.cur + 1;
    }
    return;
  }
  return;
}

