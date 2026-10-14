void __fastcall check_loop_optimizable(c2_loop *loop)

{
  c2_edge *pcVar1;
  c2_tuple *pcVar2;
  
  if ((loop->flags & 1) == 0) {
    pcVar1 = flow_edge_find(loop->last,loop->first);
    if (pcVar1 == (c2_edge *)0x0) {
      loop->flags = loop->flags | 1;
    }
    pcVar2 = loop->preheader->head;
    if (pcVar2 != (c2_tuple *)0x0) {
      while (pcVar2->kind != '\x1a') {
        if ((pcVar2->flags & 1) != 0) {
          if (pcVar2->kind != '\x11') {
            return;
          }
          if ((pcVar2->u20).cond_cells != (c2_cond_cell *)0x0) {
            return;
          }
          if (pcVar2->op == 0x18b) {
            return;
          }
          loop->flags = loop->flags | 1;
          return;
        }
        pcVar2 = pcVar2->prev;
        if (pcVar2 == (c2_tuple *)0x0) {
          return;
        }
      }
    }
  }
  return;
}

