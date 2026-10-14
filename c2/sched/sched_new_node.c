c2_sched_node * __fastcall sched_new_node(c2_tuple *from)

{
  c2_node_hook_fn *pcVar1;
  c2_sched_node *node;
  int iVar2;
  uint32_t uVar3;
  byte bVar4;
  
  node = (c2_sched_node *)cfg_block_append((c2_cfg *)g_sched_dag);
  node->index = (int16_t)g_sched_node_seq;
  g_sched_node_seq = g_sched_node_seq + 1;
  node->tuple = from;
  if ((from == (c2_tuple *)0x0) || ((from->flags & 1) == 0)) {
    node->latency = '\0';
  }
  else {
    iVar2 = tuple_reads_memory(from);
    bVar4 = (node->sflags ^ (byte)iVar2) & 1 ^ node->sflags;
    node->sflags = bVar4;
    iVar2 = tuple_writes_memory(from);
    node->sflags = ((byte)iVar2 & 1) << 1 | bVar4 & 0xfd;
    uVar3 = sched_unit_class(from);
    node->pipe = (node->pipe ^ (byte)uVar3) & 7 ^ node->pipe;
    iVar2 = sched_node_latency(node);
    node->latency = (int8_t)iVar2;
    node->sflags = node->sflags & 0xfb;
  }
  pcVar1 = g_sched_node_hook;
  node->nsucc = 0;
  node->npred = 0;
  node->soft_preds = 0;
  if (pcVar1 != (c2_node_hook_fn *)0x0) {
    (*pcVar1)(node);
  }
  g_sched_node_count = g_sched_node_count + 1;
  return node;
}

