void __fastcall liveness_mark_copy_sources(c2_symbol *s)

{
  uint32_t uVar1;
  c2_copy_link *pcVar2;
  
  if (s->visit_stamp != g_tuple_visit_count) {
    s->visit_stamp = g_tuple_visit_count;
    if ((s->u18).expr != (c2_cse_expr *)0x0) {
      uVar1 = ((s->u18).expr)->op;
      if (uVar1 == 0x14c) {
        (s->u30).globopt.killed = '\0';
        return;
      }
      if (uVar1 == 0x15b) {
        return;
      }
      if (uVar1 == 0x165) {
        return;
      }
    }
    for (pcVar2 = (s->u34).source_links; pcVar2 != (c2_copy_link *)0x0;
        pcVar2 = pcVar2->next_of_source) {
      liveness_mark_copy_sources(pcVar2->copy);
    }
  }
  return;
}

