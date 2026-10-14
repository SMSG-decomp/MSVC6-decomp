void __fastcall sched_link_to_previous_barrier(c2_sched_node *n)

{
  c2_sched_node *from;
  
  from = n->prev;
  while( true ) {
    if (from == (c2_sched_node *)0x0) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\dag.c",0x36b);
    }
    if ((from->sflags & 8) != 0) break;
    from = from->prev;
  }
  sched_add_or_merge_edge(from,n,0x80000);
  return;
}

