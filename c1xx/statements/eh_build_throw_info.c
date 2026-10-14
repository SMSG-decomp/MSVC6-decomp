void __cdecl eh_build_throw_info(uint *list,int by_number)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  c1_u8 local_24 [4];
  uint local_20 [3];
  uint entry_word;
  int local_c;
  int local_8;
  
  if ((g_flow_state_abandoned == '\0') && (list != (uint *)0x0)) {
    local_24[0] = '\r';
    local_24[1] = '\0';
    local_24[2] = '\0';
    local_24[3] = '\0';
    puVar3 = local_20;
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    eh_build_throw_info((uint *)*list,by_number);
    piVar1 = (int *)list[1];
    local_20[0]._0_1_ = (byte)local_20[0] & 0xfc;
    if ((char)by_number == '\0') {
      local_c = *(int *)(piVar1[1] + 0x10);
    }
    else {
      local_c = eh_state_find_by_source_number(*(int *)(piVar1[1] + 0x10));
    }
    piVar1 = (int *)*piVar1;
    if ((char)by_number == '\0') {
      local_8 = *(int *)(piVar1[1] + 0x10);
    }
    else {
      local_8 = eh_state_find_by_source_number(*(int *)(piVar1[1] + 0x10));
    }
    entry_word = *(uint *)(*piVar1 + 4);
    func_check_flow_state_complexity(local_24,0x24);
  }
  return;
}

