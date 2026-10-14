int * __fastcall sched_new_mem_access_rec(int a,int b)

{
  c2_sched_mem_access **ppcVar1;
  c2_sched_mem_access *pcVar2;
  int *piVar3;
  
  pcVar2 = g_sched_mem_access_rec_free;
  if (g_sched_mem_access_rec_free != (c2_sched_mem_access *)0x0) {
    g_sched_mem_access_rec_free->mem = (c2_operand *)a;
    g_sched_mem_access_rec_free->node = (c2_sched_node *)b;
    ppcVar1 = &g_sched_mem_access_rec_free->next;
    g_sched_mem_access_rec_free = g_sched_mem_access_rec_free->next;
    *ppcVar1 = (c2_sched_mem_access *)0x0;
    return (int *)pcVar2;
  }
  piVar3 = arena_alloc(0,0xc);
  *piVar3 = a;
  piVar3[1] = b;
  piVar3[2] = 0;
  return piVar3;
}

