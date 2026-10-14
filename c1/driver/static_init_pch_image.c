void * __cdecl static_init_pch_image(void)

{
  int iVar1;
  c1_pch_image *pcVar2;
  
  pcVar2 = &g_pch_image;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    pcVar2->count = 0;
    pcVar2 = (c1_pch_image *)&pcVar2->root;
  }
  return &g_pch_image;
}

