uint8_t prevobj_read_byte(void)

{
  uint8_t uVar1;
  
  uVar1 = *g_incr_info_buffer;
  g_incr_info_buffer = g_incr_info_buffer + 1;
  return uVar1;
}

