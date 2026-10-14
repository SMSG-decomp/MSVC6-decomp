c1_flow_state * __cdecl flow_state_alloc_from_free_list(byte size_class)

{
  c1_flow_state **ppcVar1;
  byte bVar2;
  c1_flow_state *pcVar3;
  c1_flow_state *pcVar4;
  
  pcVar4 = g_flow_state_free_list;
  pcVar3 = g_flow_state_free_list;
  if (g_flow_state_free_list != (c1_flow_state *)0x0) {
    while (pcVar4->flags >> 6 < size_class) {
      ppcVar1 = &pcVar4->prev;
      pcVar4 = *ppcVar1;
      if (*ppcVar1 == (c1_flow_state *)0x0) {
        return (c1_flow_state *)0x0;
      }
    }
    if (pcVar4 != (c1_flow_state *)0x0) {
      if (pcVar4->prev != (c1_flow_state *)0x0) {
        pcVar4->prev->next = pcVar4->next;
      }
      if (pcVar4->next == (c1_flow_state *)0x0) {
        g_flow_state_free_list = pcVar4->prev;
      }
      else {
        pcVar4->next->prev = pcVar4->prev;
      }
      bVar2 = pcVar4->flags;
      pcVar3 = g_flow_state_free_list;
      if (size_class < bVar2 >> 6) {
        pcVar3 = (c1_flow_state *)(pcVar4->more + (uint)size_class * 4 + -5);
        pcVar3->next = (c1_flow_state *)0x0;
        pcVar3->flags = ((bVar2 & 0xc0) + size_class * -0x40) - 1 ^ ~pcVar3->flags & 0x3f;
        pcVar3->prev = g_flow_state_free_list;
        if (g_flow_state_free_list != (c1_flow_state *)0x0) {
          g_flow_state_free_list->next = pcVar3;
        }
      }
    }
  }
  g_flow_state_free_list = pcVar3;
  return pcVar4;
}

