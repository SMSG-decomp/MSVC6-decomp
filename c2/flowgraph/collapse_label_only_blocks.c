int __fastcall collapse_label_only_blocks(c2_block *b,c2_function *fn)

{
  c2_tuple *pcVar1;
  c2_block *pcVar2;
  bool bVar3;
  c2_block **ppcVar4;
  uint32_t uVar5;
  c2_block *pcVar6;
  c2_block *pcVar7;
  c2_block *pcVar8;
  
  bVar3 = false;
  pcVar6 = b;
  pcVar7 = b;
  pcVar8 = b;
  if (b == (c2_block *)0x0) {
    return 0;
  }
  do {
    pcVar1 = pcVar7->head->next;
    if (((pcVar1->kind != '\x1a') ||
        ((pcVar7->loop != (c2_loop *)0x0 && (pcVar7->loop->first == pcVar7)))) ||
       ((pcVar2 = pcVar7->next, pcVar2 != (c2_block *)0x0 &&
        ((pcVar2->loop != (c2_loop *)0x0 && (pcVar2->loop->first == pcVar2)))))) goto LAB_10705536;
    uVar5 = label_is_removable(pcVar1);
    if (uVar5 != 0) {
      if (bVar3) {
LAB_10705536:
        if (pcVar6 == b) {
          return 0;
        }
        merge_label_range(b->head->next,&pcVar6->head->next->next,pcVar8->head->next,fn);
        return 1;
      }
      bVar3 = true;
      pcVar8 = pcVar7;
    }
    for (pcVar1 = pcVar1->next; pcVar6 = pcVar7, pcVar1 != pcVar7->end; pcVar1 = pcVar1->next) {
      if (pcVar1->kind != '\x16') goto LAB_10705536;
    }
    ppcVar4 = &pcVar7->next;
    pcVar7 = *ppcVar4;
    if (*ppcVar4 == (c2_block *)0x0) goto LAB_10705536;
  } while( true );
}

