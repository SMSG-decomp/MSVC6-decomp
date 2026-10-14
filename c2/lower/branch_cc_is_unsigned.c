int __fastcall branch_cc_is_unsigned(void *t)

{
  void *local_4;
  
  if (*(char *)((int)t + 8) == '\x10') {
    local_4 = (void *)(uint)*(byte *)((int)t + 0x20);
  }
  else {
    local_4 = t;
    if (*(char *)((int)t + 8) == '\x11') {
      local_4 = (void *)(uint)*(byte *)((int)t + 10);
    }
  }
  return (uint)((byte)local_4 == g_unsigned_cc[(uint)local_4 & 0xff]);
}

