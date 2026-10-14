void __fastcall
cv_emit_block32_symbol(c2_fe_symbol *fn_sym,uint32_t scope_start,uint32_t scope_length)

{
  uint16_t reclen;
  uint16_t rectyp;
  uint32_t parent;
  uint32_t end;
  uint32_t length;
  uint32_t offset;
  uint16_t segment;
  uint8_t name_len;
  
  length = scope_length;
  offset = scope_start - fn_sym->offset;
  reclen = 0x15;
  rectyp = 0x207;
  parent = 0;
  end = 0;
  segment = 0;
  name_len = '\0';
  (*g_hook_pad_section)(g_debug_symbols_section);
  (*g_writer_write_bytes_hook)(&reclen,0x17);
  (*g_hook_cv_secrel_section_relocs)(-7,fn_sym);
  g_debug_symbols_section->offset = g_debug_symbols_section->offset + 0x17;
  return;
}

