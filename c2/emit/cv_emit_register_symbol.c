void __fastcall cv_emit_register_symbol(c2_fe_symbol *s)

{
  char cVar1;
  uint16_t uVar2;
  char *name;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  uint16_t *reg_field;
  uint16_t reclen;
  uint16_t rectyp;
  uint32_t typind;
  uint16_t reg_and_name [150];
  
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
  iVar4 = (-(uint)(g_il_wide_type_index != 0) & 2) + 7 + iVar4;
  reclen = (uint16_t)iVar4;
  rectyp = (-(ushort)(g_il_wide_type_index != 0) & 0xfff) + 2;
  if (g_il_wide_type_index == 0) {
    reg_field = (uint16_t *)((int)&typind + 2);
    typind = CONCAT22(typind._2_2_,(short)s->cv_type_index);
  }
  else {
    typind = s->cv_type_index;
    reg_field = reg_and_name;
  }
  uVar2 = cv_register_number(s);
  *reg_field = uVar2;
  cv_put_name((uint8_t *)(reg_field + 1),name);
  (*g_writer_write_bytes_hook)(&reclen,iVar4 + 2);
  g_debug_symbols_section->offset = g_debug_symbols_section->offset + iVar4 + 2;
  return;
}

