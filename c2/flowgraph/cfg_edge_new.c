c2_edge * __fastcall cfg_edge_new(c2_cfg *cfg,c2_block *block,c2_block *to)

{
  c2_edge *pcVar1;
  c2_edge *pcVar2;
  
  pcVar2 = cfg->free_edges;
  if (pcVar2 == (c2_edge *)0x0) {
    pcVar2 = arena_alloc(cfg->arena,cfg->edge_size);
  }
  else {
    cfg->free_edges = pcVar2->next_succ;
  }
  pcVar1 = block->succs;
  pcVar2->from = block;
  pcVar2->next_succ = pcVar1;
  block->succs = pcVar2;
  pcVar2->to = to;
  pcVar1 = to->preds;
  to->preds = pcVar2;
  pcVar2->next_pred = pcVar1;
  return pcVar2;
}

