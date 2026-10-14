uint32_t __fastcall redirect_branch_edge(c2_edge *edge,c2_tuple *label,c2_tuple *t2,c2_function *fn)

{
  c2_tuple *referrer;
  
  referrer = branch_targets_label(edge->from->end->prev,t2);
  if (referrer != (c2_tuple *)0x0) {
    cfg_edge_redirect(edge,(label->u14).block,fn);
    tuple_retarget(referrer,(c2_node *)label,0);
    return 1;
  }
  return 0;
}

