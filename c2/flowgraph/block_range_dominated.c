uint32_t __fastcall block_range_dominated(c2_tuple *t,c2_tuple *t2)

{
  c2_tuple *pcVar1;
  c2_block *pcVar2;
  int iVar3;
  c2_block *pcVar4;
  
  pcVar1 = t;
  while( true ) {
    if (pcVar1 == (c2_tuple *)0x0) {
      return 0;
    }
    if (pcVar1->kind == '\x19') break;
    if (pcVar1 == t2) {
      return 1;
    }
    pcVar1 = pcVar1->next;
  }
  if ((pcVar1->u14).block == (c2_block *)0x0) {
    pcVar4 = tuple_get_block(t);
  }
  else {
    pcVar4 = ((pcVar1->u14).block)->prev;
  }
  pcVar2 = tuple_get_block(t2);
  iVar3 = bitvec_test(pcVar2->dominators,(int)pcVar4->rpo);
  if (iVar3 == 0) {
    return 0;
  }
  if (pcVar4 == pcVar2) {
    return 0;
  }
  return 1;
}

