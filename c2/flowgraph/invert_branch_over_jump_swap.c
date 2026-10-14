c2_block * __fastcall invert_branch_over_jump_swap(c2_block *from,c2_function *fn)

{
  c2_block *from_00;
  c2_tuple *br;
  c2_block *to;
  c2_tuple *label;
  c2_tuple *referrer;
  c2_edge *local_10;
  
  from_00 = from->next;
  br = from->end->prev;
  referrer = tuple_next_real_before_boundary(from_00->head);
  local_10 = from->succs;
  if (local_10->to == from_00) {
    local_10 = local_10->next_succ;
  }
  to = local_10->to;
  label = to->head->next;
  branch_invert_condition(br);
  tuple_retarget(br,*(c2_node **)((int)&referrer->src->sym->u30 + 2),0);
  tuple_retarget(referrer,(c2_node *)label,0);
  cfg_remove_edge(fn,local_10);
  cfg_add_edge(fn,from,from_00->succs->to);
  cfg_remove_edge(fn,from_00->succs);
  cfg_add_edge(fn,from_00,to);
  return to;
}

