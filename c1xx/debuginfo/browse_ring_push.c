void __cdecl browse_ring_push(byte kind,int *sym)

{
  int iVar1;
  int iVar2;
  c1_u32 *ring_entry;
  c1_u32 *record_words;
  c1_u32 *record_words_3;
  c1_u32 *record_words_2;
  c1xx_browse_record local_18;
  
  if (g_browse_suspended == 0) {
    ring_entry = g_browse_record_zero;
    record_words_3 = (c1_u32 *)&local_18;
    for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
      *record_words_3 = *ring_entry;
      ring_entry = ring_entry + 1;
      record_words_3 = record_words_3 + 1;
    }
    local_18.kind = kind;
    browse_record_fill(&local_18,sym);
    iVar1 = g_browse_ring_head + g_browse_ring_count;
    if (0x1f < iVar1) {
      iVar1 = iVar1 + -0x20;
    }
    g_browse_ring_count = g_browse_ring_count + 1;
    record_words = (c1_u32 *)&local_18;
    record_words_2 = (c1_u32 *)(g_browse_ring + iVar1);
    for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
      *record_words_2 = *record_words;
      record_words = record_words + 1;
      record_words_2 = record_words_2 + 1;
    }
  }
  return;
}

