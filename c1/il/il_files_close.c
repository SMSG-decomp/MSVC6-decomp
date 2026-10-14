void __cdecl il_files_close(char keep_db)

{
  PB src;
  byte bVar1;
  int iVar2;
  uint n;
  
  if (g_opt_E_preprocess != 0) {
    return;
  }
  if (g_opt_Zg != '\0') {
    return;
  }
  ilstore_release_module();
  if (g_il_gl.ilstore_stream == (Stream *)0x0) {
    il_buffer_close(&g_il_gl);
  }
  else {
    ilstore_close(&g_il_gl);
  }
  src = g_il_pending_init.bytes.pbStart;
  n = (int)g_il_pending_init.bytes.pbEnd - (int)g_il_pending_init.bytes.pbStart;
  if (n != 0) {
    iVar2 = il_buffer_reserve(&g_il_in.bytes,n + 1);
    g_il_in.open = g_il_in.open & (byte)iVar2 & 1;
    if (g_il_in.open != 0) {
      il_buffer_put_bytes(&g_il_in,(uint *)src,n);
    }
    g_il_pending_init.bytes.pbEnd = g_il_pending_init.bytes.pbStart;
  }
  if (g_il_in.bytes.pbStart + g_il_in.bytes.cbAlloc < g_il_in.bytes.pbEnd + 2) {
    iVar2 = il_buffer_grow(&g_il_in.bytes,2);
    bVar1 = 0;
    if (iVar2 == 0) goto LAB_10644e06;
  }
  bVar1 = 1;
LAB_10644e06:
  g_il_in.open = g_il_in.open & bVar1;
  if (g_il_in.open != 0) {
    *g_il_in.bytes.pbEnd = '\x0f';
    g_il_in.bytes.pbEnd = g_il_in.bytes.pbEnd + 1;
  }
  if (g_il_in.ilstore_stream == (Stream *)0x0) {
    il_buffer_close(&g_il_in);
  }
  else {
    ilstore_close(&g_il_in);
  }
  if (g_opt_Zi != '\0') {
    if (g_il_db.file == (FILE *)0x0) {
      ilstore_close(&g_il_db);
    }
    else if (keep_db == '\0') {
      il_buffer_close(&g_il_db);
      g_compile_flags_cc = g_compile_flags_cc & 0xffffdfff;
      return;
    }
  }
  g_compile_flags_cc = g_compile_flags_cc & 0xffffdfff;
  return;
}

