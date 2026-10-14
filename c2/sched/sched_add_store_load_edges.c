void __fastcall sched_add_store_load_edges(c2_operand *mem,c2_sched_node *n)

{
  c2_sched_mem_access *pcVar1;
  int iVar2;
  
  for (pcVar1 = g_sched_load_list; pcVar1 != (c2_sched_mem_access *)0x0; pcVar1 = pcVar1->next) {
    iVar2 = operands_may_alias(pcVar1->mem,mem);
    if (iVar2 != 0) {
      sched_add_or_merge_edge(pcVar1->node,n,0x40);
    }
  }
  return;
}

