uint32_t prevobj_read_dword(void)

{
  uint32_t uVar1;
  
  uVar1 = *(uint32_t *)g_incr_info_buffer;
  g_incr_info_buffer = g_incr_info_buffer + 4;
  return uVar1;
}

