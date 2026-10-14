void __fastcall tuple_range_clear_line(c2_tuple *first,c2_tuple *end)

{
  for (; first != end; first = first->next) {
    first->line = 0;
  }
  return;
}

