void __fastcall remove_duplicate_edges(c2_function *fn)

{
  c2_block *pcVar1;
  c2_edge *pcVar2;
  c2_edge *edge;
  c2_edge *pcVar3;
  
  pcVar1 = fn->cfg->first;
  do {
    if (pcVar1 == (c2_block *)0x0) {
      return;
    }
    pcVar2 = pcVar1->succs;
joined_r0x1071a64a:
    edge = pcVar2;
    if (edge != (c2_edge *)0x0) {
      pcVar2 = edge->next_succ;
      if (pcVar2 != (c2_edge *)0x0) {
        pcVar3 = pcVar2;
        do {
          if (pcVar3->to == edge->to) {
            cfg_remove_edge(fn,edge);
            break;
          }
          pcVar3 = pcVar3->next_succ;
        } while (pcVar3 != (c2_edge *)0x0);
      }
      goto joined_r0x1071a64a;
    }
    pcVar1 = pcVar1->next;
  } while( true );
}

