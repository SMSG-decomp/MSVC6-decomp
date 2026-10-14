void __fastcall cv_emit_label32_symbol(c2_fe_symbol *s)

{
  uint8_t uVar1;
  uint8_t *name;
  uint uVar2;
  int iVar3;
  uint8_t cv_flags;
  uint8_t *puVar4;
  uint16_t reclen;
  uint16_t rectyp;
  uint32_t rec_offset;
  uint16_t rec_segment;
  uint8_t rec_flags;
  uint8_t local_129 [297];
  
  cv_flags = '\0';
  if ((*(byte *)&s->u3e & 2) != 0) {
    cv_flags = '\x10';
  }
  if (s->role == '\0') {
    name = (uint8_t *)fe_symbol_name(s,0);
  }
  else {
    name = fe_symbol_external_name(s);
  }
  uVar2 = 0xffffffff;
  puVar4 = name;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    uVar1 = *puVar4;
    puVar4 = puVar4 + 1;
  } while (uVar1 != '\0');
  iVar3 = ~uVar2 - 1;
  if (0xff < iVar3) {
    iVar3 = 0xff;
  }
  reclen = (uint16_t)(iVar3 + 10);
  rectyp = 0x209;
  rec_offset = 0;
  rec_segment = 0;
  rec_flags = cv_flags;
  cv_put_name(local_129,(char *)name);
  (*g_hook_pad_section)(g_debug_symbols_section);
  (*g_writer_write_bytes_hook)(&reclen,iVar3 + 0xc);
  (*g_hook_cv_secrel_section_relocs)(2 - (iVar3 + 10),s);
  g_debug_symbols_section->offset = g_debug_symbols_section->offset + iVar3 + 0xc;
  return;
}

