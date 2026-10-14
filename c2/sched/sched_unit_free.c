int __fastcall sched_unit_free(int unit)

{
  return (uint)(g_sched_units[unit].busy < (int)g_sched_units[unit].capacity);
}

