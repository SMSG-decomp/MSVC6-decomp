void __fastcall sched_free_mem_access_list(c2_sched_mem_access *first,c2_sched_mem_access *last)

{
  c2_sched_mem_access *pcVar1;
  
  if (first != (c2_sched_mem_access *)0x0) {
    pcVar1 = first;
    last->next = g_sched_mem_access_rec_free;
    g_sched_mem_access_rec_free = pcVar1;
  }
  return;
}

