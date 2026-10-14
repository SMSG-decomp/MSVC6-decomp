uint32_t __fastcall sched_unit_class(c2_tuple *t)

{
  if (t->op < 0x144) {
    return g_sched_latency_table[t->op].unit_pairing & 0xff;
  }
  return 0;
}

