void __fastcall cfg_init(c2_cfg *cfg,int arena,uint32_t block_size,uint32_t edge_size)

{
  cfg->arena = arena;
  cfg->block_size = block_size;
  cfg->edge_size = edge_size;
  cfg->first = (c2_block *)0x0;
  cfg->last = (c2_block *)0x0;
  cfg->rpo_last = (c2_block *)0x0;
  cfg->rpo_first = (c2_block *)0x0;
  cfg->free_blocks = (c2_block *)0x0;
  cfg->free_edges = (c2_edge *)0x0;
  return;
}

