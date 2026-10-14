c1xx_browse_record * __cdecl browse_ring_from_back(int n)

{
  int iVar1;
  
  iVar1 = (g_browse_ring_count - n) + -1 + g_browse_ring_head;
  if (n + 1 <= g_browse_ring_count) {
    if (0x1f < iVar1) {
      iVar1 = iVar1 + -0x20;
    }
    return g_browse_ring + iVar1;
  }
  return (c1xx_browse_record *)0x0;
}

