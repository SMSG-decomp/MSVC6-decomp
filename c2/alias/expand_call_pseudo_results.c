void __fastcall expand_call_pseudo_results(c2_function *fn)

{
  c2_tuple *pcVar1;
  c2_tuple *t2;
  c2_tuple *first;
  c2_tuple *pos;
  
  first = tuple_new_pseudo(0x145,0x1004);
  for (pcVar1 = fn->cfg->first->head; pcVar1 != (c2_tuple *)0x0; pcVar1 = pcVar1->next) {
    if (pcVar1->op == 0x1ab) {
      t2 = pcVar1->prev;
      pos = (c2_tuple *)list_last((c2_link *)(pcVar1->u20).cond_cells);
      tuple_splice_after(pos,first);
      move_expression_tree_before(first,t2);
      tuple_unlink(first);
    }
  }
  node_free((c2_node *)first);
  return;
}

