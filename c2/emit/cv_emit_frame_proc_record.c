void __fastcall cv_emit_frame_proc_record(c2_fe_symbol *s)

{
  c2_fe_symbol *sym;
  byte local_24;
  uint16_t reclen;
  uint16_t rectyp;
  uint32_t local_1c;
  uint32_t local_18;
  int local_14;
  int local_10;
  uint32_t off_ex_hdlr;
  uint16_t sect_ex_hdlr;
  byte local_6;
  uint8_t flags_b1;
  uint8_t flags_b2;
  uint8_t flags_b3;
  
  local_24 = 0;
  local_1c = s->frame_size;
  local_18 = (s->u3e).label_flags;
  local_14 = local_1c - local_18;
  if ((g_cur_function->flags & 0x18000) != 0) {
    local_24 = 0x10;
  }
  reclen = 0x1c;
  rectyp = 0x1012;
  local_10 = g_cur_function->callee_save_pushes << 2;
  off_ex_hdlr = 0;
  sect_ex_hdlr = 0;
  flags_b1 = '\0';
  flags_b2 = '\0';
  flags_b3 = '\0';
  local_6 = ((byte)(g_cur_function->flags >> 6) & 1 | ((byte)g_cur_function->flags & 1) << 2) << 1 |
            -((s->fn_flags & 0x2080) != 0) & 0x20U | (byte)(g_cur_function->fsym->attrs >> 6) & 0x40
            | (byte)(g_cur_function->flags >> 7) & 1 | local_24;
  (*g_hook_pad_section)(g_debug_symbols_section);
  (*g_writer_write_bytes_hook)(&reclen,0x1e);
  if ((g_cur_function->flags & 0x18000) == 0) {
    if ((g_cur_function->fsym->attrs & 0x1000) == 0) goto LAB_1077da6d;
    sym = (c2_fe_symbol *)get_seh_scopetable_symbol();
  }
  else {
    sym = get_ehhandler_symbol();
  }
  (*g_hook_cv_secrel_section_relocs)(-10,sym);
LAB_1077da6d:
  g_debug_symbols_section->offset = g_debug_symbols_section->offset + 0x1e;
  return;
}

