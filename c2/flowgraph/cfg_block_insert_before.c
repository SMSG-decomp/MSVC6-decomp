c2_block * __fastcall cfg_block_insert_before(c2_cfg *cfg,c2_block *block)

{
  c2_block *pcVar1;
  c2_block *pcVar2;
  c2_block *pcVar3;
  
  if (block != (c2_block *)0x0) {
    pcVar3 = cfg_block_alloc(cfg);
    pcVar1 = block->prev;
    pcVar3->next = block;
    pcVar3->prev = pcVar1;
    if (pcVar1 != (c2_block *)0x0) {
      block->prev = pcVar3;
      pcVar1->next = pcVar3;
      return pcVar3;
    }
    cfg->first = pcVar3;
    block->prev = pcVar3;
    return pcVar3;
  }
  pcVar2 = cfg_block_alloc(cfg);
  pcVar1 = cfg->first;
  pcVar3 = cfg->last;
  pcVar2->prev = pcVar3;
  if (pcVar1 != (c2_block *)0x0) {
    cfg->last = pcVar2;
    pcVar3->next = pcVar2;
    return pcVar2;
  }
  cfg->first = pcVar2;
  cfg->last = pcVar2;
  return pcVar2;
}

