byte * __cdecl browse_ring_pop_back(void)

{
  int iVar1;
  
  iVar1 = g_browse_ring_count + -1 + g_browse_ring_head;
  if (g_browse_ring_count != 0) {
    if (0x1f < iVar1) {
      iVar1 = iVar1 + -0x20;
    }
    g_browse_ring_count = g_browse_ring_count + -1;
    return &g_browse_ring[iVar1].kind;
  }
  return (byte *)0x0;
}

