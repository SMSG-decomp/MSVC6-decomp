void __fastcall cv_emit_udt_symbol(c2_fe_symbol *s)

{
  char cVar1;
  char *name;
  uint uVar2;
  int iVar3;
  uint8_t *out;
  char *pcVar4;
  uint16_t reclen;
  uint16_t rectyp;
  uint32_t typind;
  uint8_t name_buf [300];
  
  name = fe_symbol_name(s,0);
  uVar2 = 0xffffffff;
  pcVar4 = name;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  iVar3 = ~uVar2 - 1;
  if (0xff < iVar3) {
    iVar3 = 0xff;
  }
  iVar3 = (-(uint)(g_il_wide_type_index != 0) & 2) + 5 + iVar3;
  reclen = (uint16_t)iVar3;
  rectyp = (-(ushort)(g_il_wide_type_index != 0) & 0xfff) + 4;
  if (g_il_wide_type_index == 0) {
    typind = CONCAT22(typind._2_2_,(short)s->cv_type_index);
    out = (uint8_t *)((int)&typind + 2);
  }
  else {
    typind = s->cv_type_index;
    out = name_buf;
  }
  cv_put_name(out,name);
  (*g_hook_pad_section)(g_debug_symbols_section);
  (*g_writer_write_bytes_hook)(&reclen,iVar3 + 2);
  g_debug_symbols_section->offset = g_debug_symbols_section->offset + iVar3 + 2;
  return;
}

