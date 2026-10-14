c2_tuple * __fastcall tuple_find_prev_of_kind(c2_tuple *t,char kind)

{
  c2_tuple *pcVar1;
  
  for (pcVar1 = t->prev; (pcVar1 != (c2_tuple *)0x0 && (pcVar1->kind != kind));
      pcVar1 = pcVar1->prev) {
  }
  return pcVar1;
}

