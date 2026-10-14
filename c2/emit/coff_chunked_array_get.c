void * __fastcall coff_chunked_array_get(c2_coff_list *list,uint32_t n)

{
  c2_coff_list_chunk *pcVar1;
  uint uVar2;
  uint uVar3;
  
  if (list->count < n) {
    return (void *)0x0;
  }
  uVar3 = (uint)list->capacity;
  pcVar1 = list->first;
  uVar2 = uVar3;
  while( true ) {
    if (n <= uVar2) {
      return *(void **)((int)pcVar1 + ((uVar3 - uVar2) + n) * 4);
    }
    if (pcVar1 == (c2_coff_list_chunk *)0x0) break;
    pcVar1 = pcVar1->next;
    uVar2 = uVar2 + uVar3;
  }
  ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0xf27);
}

