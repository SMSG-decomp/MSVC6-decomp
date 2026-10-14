void __fastcall coff_section_name_field(char *out,char *name)

{
  char cVar1;
  c2_coff_data *pcVar2;
  uint32_t uVar3;
  uint uVar4;
  size_t _Count;
  char *pcVar5;
  uint32_t radix;
  
  out[0] = '\0';
  out[1] = '\0';
  out[2] = '\0';
  out[3] = '\0';
  out[4] = '\0';
  pcVar2 = g_coff_string_table;
  out[5] = '\0';
  out[6] = '\0';
  out[7] = '\0';
  uVar4 = 0xffffffff;
  pcVar5 = name;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  _Count = ~uVar4 - 1;
  if ((int)_Count < 9) {
    strncpy(out,name,_Count);
    return;
  }
  radix = 10;
  *out = '/';
  uVar3 = coff_data_size(pcVar2);
  format_integer(uVar3 + 4,out + 1,radix);
  pcVar2 = g_coff_current_section_data;
  g_coff_current_section_data = g_coff_string_table;
  coff_write_bytes(name,~uVar4);
  g_coff_current_section_data = pcVar2;
  return;
}

