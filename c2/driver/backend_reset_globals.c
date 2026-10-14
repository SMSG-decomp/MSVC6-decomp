int backend_reset_globals(void)

{
  int iVar1;
  uint32_t *src;
  uint32_t *dst;
  int32_t *bss_cursor;
  
  if (g_first_invocation != 0) {
    g_databe_snapshot = malloc(0x246c);
    src = (uint32_t *)&g_databe_begin;
    dst = g_databe_snapshot;
    for (iVar1 = 0x91b; iVar1 != 0; iVar1 = iVar1 + -1) {
      *dst = *src;
      src = src + 1;
      dst = dst + 1;
    }
    for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(char *)dst = (char)*src;
      src = (uint32_t *)((int)src + 1);
      dst = (uint32_t *)((int)dst + 1);
    }
    g_first_invocation = 0;
    return 0;
  }
  src = g_databe_snapshot;
  dst = (uint32_t *)&g_databe_begin;
  for (iVar1 = 0x91b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *dst = *src;
    src = src + 1;
    dst = dst + 1;
  }
  for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(char *)dst = (char)*src;
    src = (uint32_t *)((int)src + 1);
    dst = (uint32_t *)((int)dst + 1);
  }
  g_first_invocation = 0;
  bss_cursor = &g_bssbe_begin;
  for (iVar1 = 0x19b4; iVar1 != 0; iVar1 = iVar1 + -1) {
    *bss_cursor = 0;
    bss_cursor = bss_cursor + 1;
  }
  for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined1 *)bss_cursor = 0;
    bss_cursor = (int32_t *)((int)bss_cursor + 1);
  }
  return 0;
}

