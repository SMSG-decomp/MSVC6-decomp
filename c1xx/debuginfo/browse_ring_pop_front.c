byte * __cdecl browse_ring_pop_front(void)

{
  c1xx_browse_record *pcVar1;
  int iVar2;
  
  if (g_browse_ring_count != 0) {
    iVar2 = g_browse_ring_head + 1;
    pcVar1 = g_browse_ring + g_browse_ring_head;
    g_browse_ring_count = g_browse_ring_count + -1;
    g_browse_ring_head = iVar2;
    if (0x1f < iVar2) {
      g_browse_ring_head = 0;
    }
    return &pcVar1->kind;
  }
  return (byte *)0x0;
}

