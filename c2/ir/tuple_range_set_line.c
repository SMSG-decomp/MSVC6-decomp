void __fastcall tuple_range_set_line(c2_tuple *first,c2_tuple *end)

{
  uint16_t uVar1;
  
  uVar1 = g_cur_line;
  for (; first != end; first = first->next) {
    first->line = uVar1;
  }
  return;
}

