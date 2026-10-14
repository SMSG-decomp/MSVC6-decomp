void __fastcall sched_free_access(c2_sched_access *rec)

{
  c2_sched_access *pcVar1;
  
  pcVar1 = rec;
  rec->next = g_sched_access_rec_free;
  g_sched_access_rec_free = pcVar1;
  return;
}

