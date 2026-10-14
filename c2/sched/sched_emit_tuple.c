void __fastcall sched_emit_tuple(c2_tuple *t)

{
  t->prev = g_sched_emit_tail;
  g_sched_emit_tail->next = t;
  if (t->line < g_sched_emit_tail->line) {
    t->line = g_sched_emit_tail->line;
  }
  g_sched_emit_tail = t;
  g_sched_emitted_count = g_sched_emitted_count + 1;
  return;
}

