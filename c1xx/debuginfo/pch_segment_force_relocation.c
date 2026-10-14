void __fastcall pch_segment_force_relocation(c1xx_pch_stream_reader *pch_stream_reader)

{
  c1_u32 cVar1;
  int iVar2;
  c1_u8 *pcVar3;
  SIZE_T dwSize;
  LPVOID lpAddress;
  
  if (pch_stream_reader->address == pch_stream_reader->base) {
    lpAddress = (LPVOID)0x0;
    dwSize = 0;
    if ((g_opt_Bm & 0x4000) != 0) {
      rand();
      cVar1 = pch_stream_reader->size;
      iVar2 = _ftol();
      dwSize = iVar2 + cVar1;
      lpAddress = VirtualAlloc((LPVOID)0x0,dwSize,0x2000,1);
    }
    pcVar3 = VirtualAlloc((LPVOID)0x0,pch_stream_reader->size,0x2000,4);
    if (pcVar3 != (c1_u8 *)0x0) {
      if (lpAddress != (LPVOID)0x0) {
        VirtualFree(lpAddress,dwSize,0x8000);
      }
      (*pch_stream_reader->vtbl->pch_segment_release)(pch_stream_reader);
      pch_stream_reader->address = pcVar3;
      pch_stream_reader->allocated = '\x01';
    }
  }
  return;
}

