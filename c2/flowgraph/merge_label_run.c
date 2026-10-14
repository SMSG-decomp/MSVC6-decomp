void __fastcall merge_label_run(c2_tuple *t,c2_tuple *t2,c2_tuple *t3)

{
  c2_tuple *pcVar1;
  c2_tuple *t_00;
  
  if (t == t3) {
    t = t->next;
  }
  else {
    if (t2 == t3) {
      t2 = t2->prev;
    }
    tuple_move_before(t,t3);
  }
  pcVar1 = t2->next;
  while (t_00 = t, t_00 != pcVar1) {
    t = t_00->next;
    if (t_00->kind == '\x1a') {
      label_redirect_and_delete(t_00,t3);
    }
  }
  return;
}

