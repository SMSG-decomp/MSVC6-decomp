void __fastcall cv_emit_proc_record(c2_fe_symbol *s)

{
  char cVar1;
  char *name;
  uint32_t *tail_cursor;
  uint32_t *puVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  byte bVar6;
  uint16_t reclen;
  uint16_t rectyp;
  uint32_t parent_offset;
  uint32_t end_offset;
  uint32_t next_offset;
  uint32_t proc_length;
  uint32_t debug_start;
  uint32_t debug_end;
  uint32_t typind_or_offset;
  uint32_t offset_or_segment;
  
  name = fe_symbol_name(s,0);
  uVar3 = 0xffffffff;
  pcVar5 = name;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  iVar4 = ~uVar3 - 1;
  (*g_hook_pad_section)(g_debug_symbols_section);
  if (0xff < iVar4) {
    iVar4 = 0xff;
  }
  iVar4 = (-(uint)(g_il_wide_type_index != 0) & 2) + 0x24 + iVar4;
  reclen = (uint16_t)iVar4;
  if (((byte)s->storage & 0xf0) == 0x50) {
    rectyp = (-(ushort)(g_il_wide_type_index != 0) & 0xe06) + 0x205;
  }
  else {
    rectyp = (-(ushort)(g_il_wide_type_index != 0) & 0xe06) + 0x204;
  }
  proc_length = s->code_size;
  debug_start = s->dbg_start;
  debug_end = s->dbg_end;
  parent_offset = 0;
  end_offset = 0;
  next_offset = 0;
  tail_cursor = &typind_or_offset;
  if (g_il_wide_type_index != 0) {
    typind_or_offset = s->cv_type_index;
    tail_cursor = &offset_or_segment;
  }
  *tail_cursor = 0;
  *(undefined2 *)(tail_cursor + 1) = 0;
  puVar2 = (uint32_t *)((int)tail_cursor + 6);
  if (g_il_wide_type_index == 0) {
    *(short *)puVar2 = (short)s->cv_type_index;
    puVar2 = tail_cursor + 2;
  }
  bVar6 = (g_cur_function->flags & 0x100) == 0;
  if ((s->attrs & 0x80) != 0) {
    bVar6 = bVar6 | 8;
  }
  *(byte *)puVar2 = bVar6;
  cv_put_name((byte *)((int)puVar2 + 1),name);
  (*g_writer_write_bytes_hook)(&reclen,iVar4 + 2);
  (*g_hook_cv_secrel_section_relocs)(((-(uint)(g_il_wide_type_index != 0) & 4) - iVar4) + 0x1a,s);
  g_debug_symbols_section->offset = g_debug_symbols_section->offset + iVar4 + 2;
  return;
}

