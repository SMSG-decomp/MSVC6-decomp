void __cdecl lookup_check_symbol_kinds_reversed(int *list)

{
  int *list_00;
  
  list_00 = (int *)*list;
  if (list_00 != (int *)0x0) {
    lookup_check_symbol_kinds_reversed(list_00);
  }
  lookup_check_symbol_kind(g_current_scope,(byte *)list[2],0,list_00 == (int *)0x0);
  return;
}

