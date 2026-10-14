void __fastcall merge_label_range(c2_tuple *first,c2_tuple **end,c2_tuple *label,c2_function *fn)

{
  c2_tuple *pcVar1;
  c2_edge *pcVar2;
  c2_tuple *t2;
  c2_edge *edge;
  
  pcVar1 = *end;
  while (t2 = first, t2 != pcVar1) {
    first = t2->next;
    if ((t2->kind == '\x1a') && (t2 != label)) {
      edge = ((t2->u14).block)->preds;
      while (edge != (c2_edge *)0x0) {
        pcVar2 = edge->next_pred;
        redirect_branch_edge(edge,label,t2,fn);
        edge = pcVar2;
      }
      label_delete(t2);
    }
  }
  return;
}

