void __fastcall loop_mark_eh_entry(c2_loop *loop)

{
  c2_block *pcVar1;
  c2_tuple *pcVar2;
  c2_block *pcVar3;
  
  pcVar3 = loop->first;
  pcVar1 = loop->last->next;
  if (pcVar3 != pcVar1) {
    while (pcVar3->eh_state == 0) {
      if (g_opt_basic != 0) {
        for (pcVar2 = pcVar3->head; pcVar2 != pcVar3->end; pcVar2 = pcVar2->next) {
          if ((pcVar2->op == 0x18b) || (pcVar2->op == 0x19c)) goto LAB_10791bd7;
        }
      }
      pcVar3 = pcVar3->next;
      if (pcVar3 == pcVar1) {
        return;
      }
    }
LAB_10791bd7:
    loop->flags = loop->flags | 9;
  }
  return;
}

