void __fastcall sched_link_to_next_barrier(c2_sched_node *from)

{
  c2_sched_node *to;
  
  to = from->next;
  while( true ) {
    if (to == (c2_sched_node *)0x0) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\dag.c",0x37c);
    }
    if ((to->sflags & 8) != 0) break;
    to = to->next;
  }
  sched_add_or_merge_edge(from,to,0x80000);
  return;
}

