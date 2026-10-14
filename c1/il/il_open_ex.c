void il_open_ex(void)

{
  byte bVar1;
  c1_node *node;
  size_t sVar2;
  int iVar3;
  
  if ((g_pch_create == '\0') ||
     (((g_create_pch_header_name == (char *)0x0 && (g_pch_file_name == (char *)0x0)) ||
      (g_use_pch != '\0')))) {
    il_file_open(&g_il_ex,(byte *)g_opt_il_prefix,"ex","w+b");
  }
  else {
    pch_set_name(g_create_pch_header_name);
    il_file_open(&g_il_ex,(byte *)g_pch_file_name,"","wb");
    g_pch_in_ex_file = '\x01';
  }
  if (g_use_pch != '\0') {
    return;
  }
  node = tree_new_int_constant(0x3ec);
  il_emit_tuple(0x5b,node);
  il_buffer_flush(&g_il_ex);
  fflush(g_il_ex.file);
  _g_io_result = fseek(g_il_ex.file,0x3eb,0);
  if (_g_io_result != 0) {
    diag_fatal_file_errno(0x56,0x153,(char *)0x0);
  }
  if ((g_il_ex.bytes.pbStart + g_il_ex.bytes.cbAlloc < g_il_ex.bytes.pbEnd + 2) &&
     (iVar3 = il_buffer_grow(&g_il_ex.bytes,2), iVar3 == 0)) {
    bVar1 = 0;
  }
  else {
    bVar1 = 1;
  }
  g_il_ex.open = g_il_ex.open & bVar1;
  if (g_il_ex.open != 0) {
    *g_il_ex.bytes.pbEnd = '\0';
    g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
  }
  if ((int)g_il_ex.bytes.pbEnd - (int)g_il_ex.bytes.pbStart != 0) {
    if ((((uint)(1 < g_warnings_as_errors) + g_error_count == 0) && (g_opt_E_preprocess == 0)) &&
       ((g_opt_Zg == '\0' &&
        ((g_il_ex.open == '\0' ||
         (sVar2 = fwrite(g_il_ex.bytes.pbStart,1,
                         (int)g_il_ex.bytes.pbEnd - (int)g_il_ex.bytes.pbStart,g_il_ex.file),
         (int)g_il_ex.bytes.pbEnd - (int)g_il_ex.bytes.pbStart != sVar2)))))) {
      diag_fatal_file_errno(0x58,0x153,g_il_ex.name);
    }
    g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbStart;
    return;
  }
  return;
}

