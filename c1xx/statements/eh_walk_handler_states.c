c1_node * __cdecl eh_walk_handler_states(c1_node *left,c1_flow_state *rec,int mode,c1_node *flag)

{
  if (rec->kind == 0xd) {
    do {
      if ((mode == 2) && ((rec->flags & 1) != 0)) {
        left = eh_build_exit_state_change(left,(int)rec->subject,rec,flag);
      }
      rec = rec->prev;
    } while (rec->kind == 0xd);
    return left;
  }
  return left;
}

