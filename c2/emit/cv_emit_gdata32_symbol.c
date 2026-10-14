void __fastcall cv_emit_gdata32_symbol(c2_fe_symbol *s,uint32_t offset)

{
  char cVar1;
  char *name;
  c2_fe_symbol *owner;
  c2_fe_symbol *pcVar2;
  uint uVar3;
  int iVar4;
  uint8_t *out;
  short sVar5;
  char *pcVar6;
  uint16_t reclen;
  short sStack_132;
  uint32_t uStack_130;
  uint32_t uStack_12c;
  uint8_t auStack_128 [296];
  
  sVar5 = (-(ushort)(g_il_wide_type_index != 0) & 0xe06) + 0x202;
  name = fe_symbol_name(s,0);
  pcVar2 = g_debug_symbols_section;
  uVar3 = 0xffffffff;
  pcVar6 = name;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  iVar4 = ~uVar3 - 1;
  if ((s->attrs & 0x20) != 0) {
    owner = fe_symbol_lookup_id(s->section_id);
    pcVar2 = coff_new_comdat_section_symbol(owner,pcVar2);
  }
  (*g_hook_pad_section)(pcVar2);
  if (0xff < iVar4) {
    iVar4 = 0xff;
  }
  iVar4 = (-(uint)(g_il_wide_type_index != 0) & 2) + 0xb + iVar4;
  reclen = (uint16_t)iVar4;
  if ((s->cls == '\x01') && ((s->attrs & 0x1000) != 0)) {
    sVar5 = (-(ushort)(g_il_wide_type_index != 0) & 0xe01) + 0x20e;
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
  sStack_132 = sVar5;
  cv_put_name(out,name);
  (*g_writer_write_bytes_hook)(&reclen,iVar4 + 2);
  (*g_hook_cv_secrel_section_relocs)(((-(uint)(g_il_wide_type_index != 0) & 4) - iVar4) + 2,s);
  pcVar2->offset = pcVar2->offset + iVar4 + 2;
  return;
}

