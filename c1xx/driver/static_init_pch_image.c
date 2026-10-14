void * __cdecl static_init_pch_image(void)

{
  int iVar1;
  uint *cursor;
  
  cursor = (uint *)&g_pch_image;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *cursor = 0;
    cursor = cursor + 1;
  }
  return &g_pch_image;
}

