c2_tuple * __fastcall label_insert_in_block(c2_fe_symbol *label_sym,c2_block *to)

{
  c2_tuple *t;
  
  t = tuple_new_label(label_sym);
  tuple_insert_after(to->head,t);
  (t->u14).block = to;
  return t;
}

