void __cdecl browse_add_record(uint kind,int *sym)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  c1xx_browse_record *pcVar4;
  c1xx_browse_record *pcVar5;
  
  browse_ring_push((byte)kind,sym);
  pbVar2 = browse_ring_front();
  pbVar3 = browse_ring_second();
  pcVar4 = browse_ring_from_back(0);
  pcVar5 = browse_ring_from_back(1);
  if ((pbVar2 != (byte *)0x0) && (pbVar3 != (byte *)0x0)) {
    if (((*pbVar2 & 0xbf) == 4) && ((*pbVar3 & 0xbf) == 3)) {
      if ((pbVar3[1] & 1) != 0) {
        browse_ring_pop_front();
      }
    }
    else {
      bVar1 = pcVar5->kind & 0xbf;
      if ((bVar1 == 8) && ((pcVar4->kind & 0xbf) == 9)) {
        browse_ring_pop_back();
        browse_ring_pop_back();
        return;
      }
      if (((pcVar4->kind & 0xbf) == 8) && (bVar1 == 8)) {
        return;
      }
    }
    while (2 < g_browse_ring_count) {
      pcVar4 = (c1xx_browse_record *)browse_ring_pop_front();
      browse_record_type(pcVar4);
    }
  }
  return;
}

