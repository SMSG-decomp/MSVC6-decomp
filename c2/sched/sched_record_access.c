void __fastcall sched_record_access(c2_sched_access **list,c2_symbol *sym,c2_sched_node *n)

{
  c2_sched_access *pcVar1;
  c2_sched_access *pcVar2;
  
  pcVar2 = (c2_sched_access *)sched_new_access_rec((int)sym,(int)n);
  pcVar1 = *list;
  *list = pcVar2;
  pcVar2->next = pcVar1;
  return;
}

