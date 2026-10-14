void __fastcall coff_write_directive_record(char *keyword,char *value,char *suffix,int quoted)

{
  char cVar1;
  uint uVar2;
  uint32_t cb;
  char *pcVar3;
  
  coff_pad_section_to_offset(g_drectve_section);
  uVar2 = 0xffffffff;
  pcVar3 = keyword;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  coff_write_bytes(keyword,~uVar2 - 1);
  g_drectve_section->offset = g_drectve_section->offset + (~uVar2 - 1);
  if (quoted == 0) {
    uVar2 = 0xffffffff;
    pcVar3 = value;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    cb = ~uVar2 - 1;
    coff_write_bytes(value,cb);
  }
  else {
    coff_write_byte_arg('\"');
    uVar2 = 0xffffffff;
    pcVar3 = value;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    coff_write_bytes(value,~uVar2 - 1);
    coff_write_byte_arg('\"');
    cb = ~uVar2 + 1;
  }
  g_drectve_section->offset = g_drectve_section->offset + cb;
  if (suffix != (char *)0x0) {
    uVar2 = 0xffffffff;
    pcVar3 = suffix;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    coff_write_bytes(suffix,~uVar2 - 1);
    g_drectve_section->offset = g_drectve_section->offset + (~uVar2 - 1);
  }
  coff_write_byte_arg(' ');
  g_drectve_section->offset = g_drectve_section->offset + 1;
  return;
}

