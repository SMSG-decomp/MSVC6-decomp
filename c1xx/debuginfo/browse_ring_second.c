byte * __cdecl browse_ring_second(void)

{
  int iVar1;
  
  if (1 < g_browse_ring_count) {
    iVar1 = g_browse_ring_head + 1;
    if (0x1f < iVar1) {
      iVar1 = g_browse_ring_head + -0x1f;
    }
    return &g_browse_ring[iVar1].kind;
  }
  return (byte *)0x0;
}

