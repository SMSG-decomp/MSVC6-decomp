void pch_save_il(void)

{
  PB src;
  int iVar1;
  uint n;
  
  g_file_copy_buffer = mem_xmalloc(0x8000);
  il_buffer_flush(&g_il_sy);
  fflush(g_il_sy.file);
  rewind(g_il_sy.file);
  g_pch_header.sy_size = file_copy_contents(g_il_sy.file,g_pch_file,0x7fffffff);
  il_buffer_flush(&g_il_gl);
  fflush(g_il_gl.file);
  rewind(g_il_gl.file);
  g_pch_header.gl_size = file_copy_contents(g_il_gl.file,g_pch_file,0x7fffffff);
  src = g_il_pending_init.bytes.pbStart;
  n = (int)g_il_pending_init.bytes.pbEnd - (int)g_il_pending_init.bytes.pbStart;
  if (n != 0) {
    iVar1 = il_buffer_reserve(&g_il_in.bytes,n + 1);
    g_il_in.open = g_il_in.open & (byte)iVar1 & 1;
    if (g_il_in.open != 0) {
      il_buffer_put_bytes(&g_il_in,(uint *)src,n);
    }
    g_il_pending_init.bytes.pbEnd = g_il_pending_init.bytes.pbStart;
  }
  il_buffer_flush(&g_il_in);
  fflush(g_il_in.file);
  rewind(g_il_in.file);
  g_pch_header.in_size = file_copy_contents(g_il_in.file,g_pch_file,0x7fffffff);
  if ((g_opt_Zi != '\0') &&
     ((g_pch_debug_in_object != '\0' ||
      ((g_auto_pch_creating != 0 && (g_debug_types_in_pdb == '\0')))))) {
    il_buffer_flush(&g_il_db);
    fflush(g_il_db.file);
    rewind(g_il_db.file);
    g_pch_header.db_size = file_copy_contents(g_il_db.file,g_pch_file,0x7fffffff);
  }
  pch_write_finish();
  return;
}

