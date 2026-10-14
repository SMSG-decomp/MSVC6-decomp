uint16_t prevobj_read_word(void)

{
  uint16_t uVar1;
  
  uVar1 = *(uint16_t *)g_incr_info_buffer;
  g_incr_info_buffer = g_incr_info_buffer + 2;
  return uVar1;
}

