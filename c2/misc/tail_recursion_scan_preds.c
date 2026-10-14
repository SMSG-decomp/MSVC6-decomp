uint __fastcall tail_recursion_scan_preds(c2_function *fn,c2_block *block)

{
  c2_block **ppcVar1;
  c2_edge *pcVar2;
  uint uVar3;
  uint uVar4;
  
  pcVar2 = block->preds;
  uVar4 = 0;
  while (pcVar2 != (c2_edge *)0x0) {
    ppcVar1 = &pcVar2->from;
    pcVar2 = pcVar2->next_pred;
    uVar3 = tail_recursion_try_block(fn,*ppcVar1);
    uVar4 = uVar4 | uVar3;
  }
  return uVar4 & 1;
}

