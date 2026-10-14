c2_tuple * __fastcall find_tuple_of_kind(c2_tuple *t,char kind)

{
  c2_tuple *pcVar1;
  
  for (pcVar1 = t->next; (pcVar1 != (c2_tuple *)0x0 && (pcVar1->kind != kind));
      pcVar1 = pcVar1->next) {
  }
  return pcVar1;
}

