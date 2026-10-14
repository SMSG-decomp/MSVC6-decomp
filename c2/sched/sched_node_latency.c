int __fastcall sched_node_latency(c2_sched_node *n)

{
  c2_tuple *pcVar1;
  uint uVar2;
  int iVar3;
  
  pcVar1 = n->tuple;
  if (pcVar1 == (c2_tuple *)0x0) {
    return 0;
  }
  iVar3 = sched_latency_adjust(n);
  uVar2 = pcVar1->op;
  if (uVar2 < 0x144) {
    return iVar3 + g_sched_latency_table[uVar2].latency;
  }
  return iVar3;
}

