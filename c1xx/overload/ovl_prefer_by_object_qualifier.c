c1_ovl_candidate * __fastcall ovl_prefer_by_object_qualifier(c1_ovl_resolution *res)

{
  c1_ovl_candidate *cand;
  c1_ovl_candidate *pcVar1;
  c1_ovl_candidate *pcVar2;
  bool bVar3;
  
  pcVar2 = (c1_ovl_candidate *)0x0;
  cand = res->head;
  pcVar1 = cand;
  while( true ) {
    if (pcVar1 == (c1_ovl_candidate *)0x0) {
      for (; cand != (c1_ovl_candidate *)0x0; cand = cand->next) {
        if (((cand->flags & 4) == 0) && ((*(byte *)((int)&cand->function->tail + 9) & 0xc0) != 0)) {
          ovl_candidate_remove(res,cand,(c1_node *)0x0);
        }
      }
      return pcVar2;
    }
    if ((((pcVar1->flags & 4) != 0) || ((*(byte *)((int)&pcVar1->function->tail + 9) & 0xc0) == 0))
       && (bVar3 = pcVar2 != (c1_ovl_candidate *)0x0, pcVar2 = pcVar1, bVar3)) break;
    pcVar1 = pcVar1->next;
  }
  return (c1_ovl_candidate *)0x0;
}

