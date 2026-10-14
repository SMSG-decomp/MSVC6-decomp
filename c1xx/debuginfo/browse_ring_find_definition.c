byte * __cdecl browse_ring_find_definition(int sym)

{
  c1xx_browse_record *pcVar1;
  int n;
  
  n = 0;
  pcVar1 = browse_ring_from_back(0);
  while( true ) {
    if (pcVar1 == (c1xx_browse_record *)0x0) {
      return (byte *)0x0;
    }
    if ((pcVar1->kind & 0xbf) == 3) break;
    n = n + 1;
    pcVar1 = browse_ring_from_back(n);
  }
  return (byte *)((uint)pcVar1 & (pcVar1->name_record != (fe_name *)sym) - 1);
}

