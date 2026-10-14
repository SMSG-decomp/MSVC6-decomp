void __fastcall factor_count_subtree(c2_node *n)

{
  byte bVar1;
  c2_factor_term *pcVar2;
  c2_factor_term *pcVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = n->rank_or_prev >> 8 & 0xf ^ n->rank_or_prev & 0xf;
  pcVar2 = g_factor_terms[uVar5];
  do {
    if (pcVar2 == (c2_factor_term *)0x0) {
LAB_1070c651:
      pcVar3 = arena_alloc(4,0x10);
      pcVar2 = g_factor_terms[uVar5];
      bVar1 = *(byte *)((int)&n->rank_or_prev + 2);
      g_factor_terms[uVar5] = pcVar3;
      pcVar3->tree = n;
      pcVar3->count = 1;
      pcVar3->x0c = bVar1 + 1;
      pcVar3->next = pcVar2;
      return;
    }
    iVar4 = compare_trees(n,pcVar2->tree);
    if (iVar4 == 0) {
      if (pcVar2 != (c2_factor_term *)0x0) {
        pcVar2->count = pcVar2->count + 1;
        return;
      }
      goto LAB_1070c651;
    }
    pcVar2 = pcVar2->next;
  } while( true );
}

