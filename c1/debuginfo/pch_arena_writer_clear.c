c1_pch_image * __fastcall pch_arena_writer_clear(c1_pch_image *image)

{
  int iVar1;
  c1_pch_image *pcVar2;
  
  pcVar2 = image;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    pcVar2->count = 0;
    pcVar2 = (c1_pch_image *)&pcVar2->root;
  }
  return image;
}

