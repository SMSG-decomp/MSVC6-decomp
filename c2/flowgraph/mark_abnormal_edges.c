void __fastcall mark_abnormal_edges(c2_tuple *t,c2_block *block)

{
  c2_edge *pcVar1;
  
  if (t != (c2_tuple *)0x0) {
    if (((t->flags & 8) != 0) && ((t->op == 0x18b || (t->op == 0x18c)))) {
      pcVar1 = flow_edge_find(block,*(c2_block **)(*(int *)((int)&t->src->sym->u30 + 2) + 0x14));
      pcVar1->flags = pcVar1->flags | 0x40;
      return;
    }
    if (t->op == 0x18e) {
      for (pcVar1 = block->succs; pcVar1 != (c2_edge *)0x0; pcVar1 = pcVar1->next_succ) {
        pcVar1->flags = pcVar1->flags | 0x40;
      }
    }
  }
  return;
}

