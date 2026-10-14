c2_tuple * __fastcall get_latch_exit_compare(c2_block *latch,c2_tuple **branch)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  c2_tuple *pcVar3;
  int iVar4;
  
  pcVar2 = tuple_prev_real_before_boundary(latch->end);
  if (pcVar2->kind == '\x11') {
    pcVar1 = (pcVar2->u20).default_label;
    iVar4 = 0;
    pcVar3 = pcVar1;
    if (pcVar1 != (c2_tuple *)0x0) {
      do {
        pcVar3 = pcVar3->next;
        iVar4 = iVar4 + 1;
      } while (pcVar3 != (c2_tuple *)0x0);
      if (iVar4 == 1) {
        pcVar1 = pcVar1->prev;
        if ((pcVar1->op == 0x17d) && ((1 << (byte)(pcVar1->type >> 0xc) & 0xeU) != 0)) {
          *branch = pcVar2;
          return pcVar1;
        }
      }
    }
  }
  return (c2_tuple *)0x0;
}

