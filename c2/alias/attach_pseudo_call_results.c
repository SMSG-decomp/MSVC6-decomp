void __fastcall attach_pseudo_call_results(c2_function *fn)

{
  c2_tuple *t;
  c2_tuple *t2;
  
  for (t = fn->cfg->first->head; t != (c2_tuple *)0x0; t = t->next) {
    if (t->op == 0x1ab) {
      for (t2 = (c2_tuple *)list_last((c2_link *)(t->u20).cond_cells);
          (t2 != (c2_tuple *)0x0 && (t2->op != 0x1ac)); t2 = t2->prev) {
      }
      move_expression_tree_before(t,t2);
    }
  }
  return;
}

