int __fastcall count_successors(c2_block *block)

{
  c2_edge *pcVar1;
  int iVar2;
  
  iVar2 = 0;
  for (pcVar1 = block->succs; pcVar1 != (c2_edge *)0x0; pcVar1 = pcVar1->next_succ) {
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}

