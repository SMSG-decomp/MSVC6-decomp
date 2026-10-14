c2_block * __fastcall cfg_block_append(c2_cfg *cfg)

{
  c2_block *pcVar1;
  c2_block *pcVar2;
  c2_block *pcVar3;
  
  pcVar3 = cfg_block_alloc(cfg);
  pcVar1 = cfg->first;
  pcVar2 = cfg->last;
  pcVar3->prev = pcVar2;
  if (pcVar1 != (c2_block *)0x0) {
    cfg->last = pcVar3;
    pcVar2->next = pcVar3;
    return pcVar3;
  }
  cfg->first = pcVar3;
  cfg->last = pcVar3;
  return pcVar3;
}

