int c1xx_reset_data_section(void)

{
  int iVar1;
  uint *src_2;
  void **ppvVar2;
  uint *src;
  uint *dst_2;
  int *piVar3;
  uint *dst;
  void *local_14;
  void *seh_handler;
  c1_seh_scope *seh_scope_table;
  int seh_try_level;
  
  seh_try_level = -1;
  seh_scope_table = &g_reset_data_section_scope_table;
  seh_handler = &_except_handler3;
  local_14 = ExceptionList;
  if (g_first_compiler_pass == 0) {
    src_2 = g_data_section_copy;
    dst_2 = (uint *)&g_data_section_begin;
    ExceptionList = &local_14;
    for (iVar1 = 0x745; iVar1 != 0; iVar1 = iVar1 + -1) {
      *dst_2 = *src_2;
      src_2 = src_2 + 1;
      dst_2 = dst_2 + 1;
    }
    for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(char *)dst_2 = (char)*src_2;
      src_2 = (uint *)((int)src_2 + 1);
      dst_2 = (uint *)((int)dst_2 + 1);
    }
    piVar3 = &g_bss_section_begin;
    for (iVar1 = 0x4d74; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar3 = 0;
      piVar3 = piVar3 + 1;
    }
    for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(undefined1 *)piVar3 = 0;
      piVar3 = (int *)((int)piVar3 + 1);
    }
    g_batch_continuing = g_last_in_batch == '\0';
  }
  else {
    ExceptionList = &local_14;
    g_data_section_copy = mem_xmalloc(0x1d14);
    src = (uint *)&g_data_section_begin;
    dst = g_data_section_copy;
    for (iVar1 = 0x745; iVar1 != 0; iVar1 = iVar1 + -1) {
      *dst = *src;
      src = src + 1;
      dst = dst + 1;
    }
    for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(char *)dst = (char)*src;
      src = (uint *)((int)src + 1);
      dst = (uint *)((int)dst + 1);
    }
    g_batch_continuing = '\0';
  }
  g_first_compiler_pass = 0;
  ppvVar2 = g_static_initializer_table;
  while (ppvVar2 < &g_static_initializer_table_end) {
    if (*ppvVar2 == (code *)0x0) {
      ppvVar2 = ppvVar2 + 1;
    }
    else {
      seh_try_level = 0;
      (**ppvVar2)();
      ppvVar2 = ppvVar2 + 1;
    }
  }
  ExceptionList = local_14;
  return 0;
}

