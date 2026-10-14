c2_edge * __fastcall flow_edge_find(c2_block *block,c2_block *to)

{
  c2_edge *pcVar1;
  
  pcVar1 = block->succs;
  while( true ) {
    if (pcVar1 == (c2_edge *)0x0) {
      return (c2_edge *)0x0;
    }
    if (pcVar1->to == to) break;
    pcVar1 = pcVar1->next_succ;
  }
  return pcVar1;
}

