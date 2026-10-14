void __fastcall pch_segment_force_relocation(c1_pch_segment *segment)

{
  c1_u32 cVar1;
  int iVar2;
  c1_u8 *pcVar3;
  SIZE_T dwSize;
  LPVOID lpAddress;
  
  if (segment->address == segment->base) {
    lpAddress = (LPVOID)0x0;
    dwSize = 0;
    if ((g_opt_Bm & 0x4000) != 0) {
      rand();
      cVar1 = segment->size;
      iVar2 = _ftol();
      dwSize = iVar2 + cVar1;
      lpAddress = VirtualAlloc((LPVOID)0x0,dwSize,0x2000,1);
    }
    pcVar3 = VirtualAlloc((LPVOID)0x0,segment->size,0x2000,4);
    if (pcVar3 != (c1_u8 *)0x0) {
      if (lpAddress != (LPVOID)0x0) {
        VirtualFree(lpAddress,dwSize,0x8000);
      }
      (*segment->vtbl->pch_segment_release)(segment);
      segment->address = pcVar3;
      segment->allocated = '\x01';
    }
  }
  return;
}

