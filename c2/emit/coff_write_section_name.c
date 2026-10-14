void __fastcall coff_write_section_name(char *out,char *name,int resolve_now)

{
  char cVar1;
  c2_coff_data *pcVar2;
  uint32_t uVar3;
  char *pcVar4;
  uint uVar5;
  size_t _Count;
  uint uVar6;
  
  pcVar2 = g_coff_string_table;
  uVar5 = 0xffffffff;
  pcVar4 = name;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  _Count = uVar5 - 1;
  if ((int)_Count < 9) {
    strncpy(out,name,_Count);
    pcVar4 = out + _Count;
    for (uVar5 = 8 - _Count >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      pcVar4[0] = '\0';
      pcVar4[1] = '\0';
      pcVar4[2] = '\0';
      pcVar4[3] = '\0';
      pcVar4 = pcVar4 + 4;
    }
    for (uVar5 = 8 - _Count & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar4 = '\0';
      pcVar4 = pcVar4 + 1;
    }
    return;
  }
  if ((resolve_now == 0) &&
     (((g_coff_incremental_update != 0 || (g_opt_edit_and_continue != 0)) || (g_opt_ZX != 0)))) {
    out[0] = '\0';
    out[1] = '\0';
    out[2] = '\0';
    out[3] = '\0';
    pcVar4 = (*g_coff_alloc_fn)(uVar5);
    *(char **)(out + 4) = pcVar4;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar4 = *(undefined4 *)name;
      name = name + 4;
      pcVar4 = pcVar4 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar4 = *name;
      name = name + 1;
      pcVar4 = pcVar4 + 1;
    }
    return;
  }
  out[0] = '\0';
  out[1] = '\0';
  out[2] = '\0';
  out[3] = '\0';
  uVar3 = coff_data_size(pcVar2);
  *(uint32_t *)(out + 4) = uVar3 + 4;
  pcVar2 = g_coff_current_section_data;
  g_coff_current_section_data = g_coff_string_table;
  coff_write_bytes(name,uVar5);
  g_coff_current_section_data = pcVar2;
  return;
}

