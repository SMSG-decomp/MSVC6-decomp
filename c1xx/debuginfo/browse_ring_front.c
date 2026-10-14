byte * __cdecl browse_ring_front(void)

{
  if (0 < g_browse_ring_count) {
    return &g_browse_ring[g_browse_ring_head].kind;
  }
  return (byte *)0x0;
}

