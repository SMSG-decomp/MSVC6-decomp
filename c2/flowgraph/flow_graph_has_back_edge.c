uint32_t __fastcall flow_graph_has_back_edge(c2_function *fn)

{
  c2_block *pcVar1;
  c2_edge *pcVar2;
  
  pcVar1 = fn->cfg->first;
  do {
    if (pcVar1 == (c2_block *)0x0) {
      return 0;
    }
    pcVar2 = pcVar1->preds;
    if (pcVar2 != (c2_edge *)0x0) {
      do {
        if (pcVar1->rpo <= pcVar2->from->rpo) {
          return 1;
        }
        pcVar2 = pcVar2->next_pred;
      } while (pcVar2 != (c2_edge *)0x0);
    }
    pcVar1 = pcVar1->next;
  } while( true );
}

