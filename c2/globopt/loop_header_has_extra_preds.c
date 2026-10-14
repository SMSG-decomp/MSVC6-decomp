int __fastcall loop_header_has_extra_preds(c2_loop *loop)

{
  c2_edge *pcVar1;
  int iVar2;
  
  iVar2 = 0;
  pcVar1 = loop->first->preds;
  if (pcVar1 != (c2_edge *)0x0) {
    do {
      if ((pcVar1->from != loop->preheader) && (pcVar1->from != loop->last)) {
        return 1;
      }
      pcVar1 = pcVar1->next_pred;
      iVar2 = iVar2 + 1;
    } while (pcVar1 != (c2_edge *)0x0);
    if (iVar2 == 2) {
      return 0;
    }
  }
  return 1;
}

