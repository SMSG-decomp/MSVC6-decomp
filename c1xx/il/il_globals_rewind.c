void __cdecl il_globals_rewind(void)

{
  il_buffer_flush(&g_il_gl);
  fflush((FILE *)g_il_gl.file);
  rewind((FILE *)g_il_gl.file);
  g_il_block_level = '\0';
  il_emit_symbol(0x11,(c1_symbol *)0x0);
  return;
}

