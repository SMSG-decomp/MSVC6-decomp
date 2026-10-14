void __cdecl il_begin_function_body(int generated)

{
  c1_u8 *src;
  int iVar1;
  uint n;
  
  src = g_il_pending_init.bytes.start;
  g_compile_flags_cc = g_compile_flags_cc | 0x1000;
  if (g_c9il_mode == '\0') {
    if ((g_compile_flags_c4 & 0x20) == 0) {
      n = (int)g_il_pending_init.bytes.cur - (int)g_il_pending_init.bytes.start;
      if (n != 0) {
        iVar1 = il_buffer_reserve(&g_il_in.bytes,n + 1);
        g_il_in.open = g_il_in.open & (byte)iVar1 & 1;
        if (g_il_in.open != 0) {
          il_buffer_put_bytes(&g_il_in,(uint *)src,n);
        }
        g_il_pending_init.bytes.cur = g_il_pending_init.bytes.start;
      }
      if (g_il_in.ilstore_stream == (c1xx_pdb_stream *)0x0) {
        il_buffer_flush(&g_il_in);
      }
      else {
        ilstore_flush(&g_il_in);
      }
    }
  }
  else {
    il_buffer_flush(&g_il_ex);
    g_function_ex_offset = ftell((FILE *)g_il_ex.file);
    il_buffer_flush(&g_il_sy);
    g_function_sy_offset = ftell((FILE *)g_il_sy.file);
  }
  g_function_tuple_count = 0;
  if (g_ilstore_status != 4) {
    il_emit_pragma_or_segment_record(0x1f);
    if (g_inline_level != 0) {
      il_emit_pragma_or_segment_record(0x20);
    }
    if (generated == 0) {
      il_emit_pragma_or_segment_record(2);
      il_emit_pragma_or_segment_record(0x24);
      il_emit_pragma_or_segment_record(0x23);
      return;
    }
    g_il_block_level = g_il_block_level + '\x01';
    il_emit_symbol(6,(c1_symbol *)0x0);
    g_il_block_level = g_il_block_level + 0xff;
  }
  return;
}

