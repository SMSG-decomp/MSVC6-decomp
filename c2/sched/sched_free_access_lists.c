void sched_free_access_lists(void)

{
  c2_sched_access *pcVar1;
  c2_sched_access *pcVar2;
  
  pcVar2 = g_sched_reg_use_list;
  while (pcVar2 != (c2_sched_access *)0x0) {
    pcVar1 = pcVar2->next;
    sched_free_access(pcVar2);
    pcVar2 = pcVar1;
  }
  g_sched_reg_use_list = (c2_sched_access *)0x0;
  pcVar2 = g_sched_reg_def_list;
  while (pcVar2 != (c2_sched_access *)0x0) {
    pcVar1 = pcVar2->next;
    sched_free_access(pcVar2);
    pcVar2 = pcVar1;
  }
  g_sched_reg_def_list = (c2_sched_access *)0x0;
  return;
}

