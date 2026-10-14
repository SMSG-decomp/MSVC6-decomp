int __cdecl c1_reset_data_section(void)

{
  int iVar1;
  c1_static_initializer *ppcVar2;
  uint *puVar3;
  uint *puVar4;
  uint *bss_dst;
  void *local_14;
  undefined *puStack_10;
  sehtable_entry *psStack_c;
  int try_level;
  
  try_level = -1;
  psStack_c = &g_reset_data_section_scope_table;
  puStack_10 = &_except_handler3;
  local_14 = ExceptionList;
  if (g_first_compiler_pass == 0) {
    puVar3 = g_data_section_copy;
    puVar4 = &g_data_section_begin;
    ExceptionList = &local_14;
    for (iVar1 = 0x561; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(char *)puVar4 = (char)*puVar3;
      puVar3 = (uint *)((int)puVar3 + 1);
      puVar4 = (uint *)((int)puVar4 + 1);
    }
    bss_dst = &g_bss_section_begin;
    for (iVar1 = 0x4159; iVar1 != 0; iVar1 = iVar1 + -1) {
      *bss_dst = 0;
      bss_dst = bss_dst + 1;
    }
    for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(undefined1 *)bss_dst = 0;
      bss_dst = (uint *)((int)bss_dst + 1);
    }
    g_batch_continuing = g_last_in_batch == '\0';
  }
  else {
    ExceptionList = &local_14;
    g_data_section_copy = mem_xmalloc(0x1584);
    puVar3 = &g_data_section_begin;
    puVar4 = g_data_section_copy;
    for (iVar1 = 0x561; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(char *)puVar4 = (char)*puVar3;
      puVar3 = (uint *)((int)puVar3 + 1);
      puVar4 = (uint *)((int)puVar4 + 1);
    }
    g_batch_continuing = '\0';
  }
  g_first_compiler_pass = 0;
  ppcVar2 = g_static_initializer_table;
  while (ppcVar2 < &g_static_initializer_table_end) {
    if (*ppcVar2 == (c1_static_initializer)0x0) {
      ppcVar2 = ppcVar2 + 1;
    }
    else {
      try_level = 0;
      (**ppcVar2)();
      ppcVar2 = ppcVar2 + 1;
    }
  }
  ExceptionList = local_14;
  return 0;
}

