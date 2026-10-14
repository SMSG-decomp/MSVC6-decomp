void __fastcall sched_memory_deps_on_stores(c2_operand *opnd,c2_sched_node *n,uint32_t type)

{
  c2_sched_mem_access **ppcVar1;
  int iVar2;
  c2_sched_mem_access *pcVar3;
  
  pcVar3 = g_sched_store_list;
  if (g_sched_store_list != (c2_sched_mem_access *)0x0) {
    while ((opnd->kind != '\x02' || (iVar2 = operands_same_location(pcVar3->mem,opnd), iVar2 == 0)))
    {
      iVar2 = operands_may_alias(pcVar3->mem,opnd);
      if (iVar2 != 0) {
        sched_add_or_merge_edge(pcVar3->node,n,type);
      }
      ppcVar1 = &pcVar3->next;
      pcVar3 = *ppcVar1;
      if (*ppcVar1 == (c2_sched_mem_access *)0x0) {
        return;
      }
    }
    sched_add_or_merge_edge(pcVar3->node,n,type);
  }
  return;
}

