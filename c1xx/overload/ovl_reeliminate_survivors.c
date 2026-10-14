c1_ovl_candidate * __fastcall ovl_reeliminate_survivors(c1_ovl_resolution *res)

{
  char cVar1;
  c1_ovl_candidate *pcVar2;
  
  for (pcVar2 = res->head; pcVar2 != (c1_ovl_candidate *)0x0; pcVar2 = pcVar2->next) {
    if (((pcVar2->flags & 0x80) != 0) &&
       (cVar1 = ovl_candidate_remove(res,pcVar2,(c1_node *)0x0), cVar1 != '\0')) {
      return (c1_ovl_candidate *)0x0;
    }
  }
  cVar1 = ovl_eliminate_worse_candidates(res,5,0);
  if (cVar1 == '\0') {
    return (c1_ovl_candidate *)0x0;
  }
  if (res->live != 1) {
    return (c1_ovl_candidate *)0x0;
  }
  pcVar2 = (c1_ovl_candidate *)ovl_first_live_candidate((int)res);
  return pcVar2;
}

