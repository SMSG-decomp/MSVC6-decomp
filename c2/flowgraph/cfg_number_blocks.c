void __fastcall cfg_number_blocks(c2_function *fn)

{
  c2_block *pcVar1;
  short sVar2;
  
  sVar2 = 0;
  pcVar1 = fn->cfg->first;
  if (pcVar1 != (c2_block *)0x0) {
    do {
      pcVar1->rpo = sVar2;
      pcVar1 = pcVar1->next;
      sVar2 = sVar2 + 1;
    } while (pcVar1 != (c2_block *)0x0);
    g_block_count = (int)sVar2;
    return;
  }
  g_block_count = 0;
  return;
}

