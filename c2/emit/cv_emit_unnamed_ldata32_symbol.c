void __fastcall cv_emit_unnamed_ldata32_symbol(c2_fe_symbol *s)

{
  uint8_t *name_len;
  uint uVar1;
  uint16_t reclen;
  uint16_t rectyp;
  uint32_t field_04;
  uint32_t field_08;
  uint16_t name_or_segment;
  uint8_t name_tail [38];
  
  (*g_hook_pad_section)(g_debug_symbols_section);
  uVar1 = -(uint)(g_il_wide_type_index != 0) & 2;
  reclen = (uint16_t)(uVar1 + 0xb);
  rectyp = (-(ushort)(g_il_wide_type_index != 0) & 0xe06) + 0x201;
  field_04 = 0;
  if (g_il_wide_type_index == 0) {
    name_len = (uint8_t *)&name_or_segment;
  }
  else {
    name_or_segment = 0;
    name_len = name_tail;
  }
  field_08 = 0;
  *name_len = '\0';
  (*g_writer_write_bytes_hook)(&reclen,uVar1 + 0xd);
  (*g_hook_cv_secrel_section_relocs)
            (((-(uint)(g_il_wide_type_index != 0) & 4) - (uVar1 + 0xb)) + 2,s);
  g_debug_symbols_section->offset = g_debug_symbols_section->offset + uVar1 + 0xd;
  return;
}

