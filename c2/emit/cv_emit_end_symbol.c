void cv_emit_end_symbol(void)

{
  uint16_t reclen;
  uint16_t rectyp;
  
  reclen = 2;
  rectyp = 6;
  (*g_hook_pad_section)(g_debug_symbols_section);
  (*g_writer_write_bytes_hook)(&reclen,4);
  g_debug_symbols_section->offset = g_debug_symbols_section->offset + 4;
  return;
}

