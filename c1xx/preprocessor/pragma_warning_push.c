void __cdecl pragma_warning_push(void)

{
  c1_u32 cVar1;
  c1xx_warning_state *pcVar2;
  c1_warning_record *pcVar3;
  
  pcVar3 = (c1_warning_record *)g_arenas[0].cur;
  pcVar2 = g_warning_state;
  if (g_warning_record_free_list == (c1_warning_record *)0x0) {
    g_arenas[0].cur = g_arenas[0].cur + 8;
    if (g_arenas[0].end < g_arenas[0].cur) {
      arena_grow(g_arenas);
    }
  }
  else {
    pcVar3 = g_warning_record_free_list;
    g_warning_record_free_list =
         (c1_warning_record *)(g_warning_record_free_list->next & 0xfffffffe);
  }
  if (pcVar3 == (c1_warning_record *)0x0) {
    pcVar2->saved = (c1_warning_record *)0x0;
    return;
  }
  cVar1 = pcVar2->level;
  pcVar3->next = (c1_u32)pcVar2->saved;
  pcVar3->value = cVar1;
  pcVar2->saved = pcVar3;
  return;
}

