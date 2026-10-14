c2_tuple * __fastcall label_after_or_create(c2_tuple *pos)

{
  uint8_t uVar1;
  c2_fe_symbol *label_sym;
  c2_tuple *t;
  
  t = pos;
  if ((pos->flags & 1) != 0) {
    t = pos->next;
  }
  uVar1 = t->kind;
  while (uVar1 == '\x19') {
    t = t->next;
    uVar1 = t->kind;
  }
  if (t->kind != '\x1a') {
    label_sym = label_symbol_new();
    t = tuple_new_label(label_sym);
    tuple_insert_after(pos,t);
  }
  return t;
}

