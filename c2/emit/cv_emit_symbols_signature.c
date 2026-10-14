void cv_emit_symbols_signature(void)

{
  int local_8 [2];
  
  local_8[0] = (g_il_wide_type_index != 0) + 1;
  (*g_hook_pad_section)(g_debug_symbols_section);
  (*g_writer_write_bytes_hook)(local_8,4);
  g_debug_symbols_section->offset = g_debug_symbols_section->offset + 4;
  return;
}

