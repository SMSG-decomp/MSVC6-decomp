void __fastcall number_tuples_in_range(c2_tuple *first,c2_tuple **end)

{
  c2_tuple *pcVar1;
  short sVar2;
  
  pcVar1 = *end;
  sVar2 = 0;
  for (; first != pcVar1; first = first->next) {
    if (((first->flags & 1) != 0) || (first->kind == '\x1a')) {
      sVar2 = sVar2 + 1;
      *(short *)&first->flags12 = sVar2;
    }
  }
  return;
}

