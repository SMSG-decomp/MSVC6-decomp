void __fastcall
sched_record_memory_access
          (c2_sched_mem_access **list,c2_sched_mem_access **tail,c2_operand *mem,c2_sched_node *n)

{
  c2_sched_mem_access *pcVar1;
  c2_sched_mem_access *pcVar2;
  
  pcVar2 = (c2_sched_mem_access *)sched_new_mem_access_rec((int)mem,(int)n);
  pcVar1 = *list;
  *list = pcVar2;
  pcVar2->next = pcVar1;
  if (*tail == (c2_sched_mem_access *)0x0) {
    *tail = pcVar2;
  }
  return;
}

