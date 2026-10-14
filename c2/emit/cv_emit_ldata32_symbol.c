void __fastcall cv_emit_ldata32_symbol(c2_fe_symbol *s,uint32_t offset)

{
  char cVar1;
  char *name;
  uint uVar2;
  int iVar3;
  uint8_t *out;
  short sVar4;
  char *pcVar5;
  uint16_t reclen;
  short sStack_132;
  uint32_t uStack_130;
  uint32_t uStack_12c;
  uint8_t auStack_128 [296];
  
  sVar4 = (-(ushort)(g_il_wide_type_index != 0) & 0xe06) + 0x201;
  name = fe_symbol_name(s,0);
  uVar2 = 0xffffffff;
  pcVar5 = name;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  iVar3 = ~uVar2 - 1;
  (*g_hook_pad_section)(g_debug_symbols_section);
  if (0xff < iVar3) {
    iVar3 = 0xff;
  }
  iVar3 = (-(uint)(g_il_wide_type_index != 0) & 2) + 0xb + iVar3;
  reclen = (uint16_t)iVar3;
  if ((s->cls == '\x01') && ((s->attrs & 0x1000) != 0)) {
    sVar4 = (-(ushort)(g_il_wide_type_index != 0) & 0xe01) + 0x20d;
  }
  if (g_il_wide_type_index == 0) {
    uStack_12c = (uint)(ushort)s->cv_type_index << 0x10;
    out = auStack_128;
    uStack_130 = offset;
  }
  else {
    uStack_130 = s->cv_type_index;
    auStack_128[0] = '\0';
    auStack_128[1] = '\0';
    out = auStack_128 + 2;
    uStack_12c = offset;
  }
  sStack_132 = sVar4;
  cv_put_name(out,name);
  (*g_writer_write_bytes_hook)(&reclen,iVar3 + 2);
  (*g_hook_cv_secrel_section_relocs)(((-(uint)(g_il_wide_type_index != 0) & 4) - iVar3) + 2,s);
  g_debug_symbols_section->offset = g_debug_symbols_section->offset + iVar3 + 2;
  return;
}

