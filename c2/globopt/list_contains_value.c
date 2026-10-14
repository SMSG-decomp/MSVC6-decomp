int __fastcall list_contains_value(c2_list_cell *list,int v)

{
  while( true ) {
    if (list == (c2_list_cell *)0x0) {
      return 0;
    }
    if ((list->u04).tuple == (c2_tuple *)v) break;
    list = list->next;
  }
  return 1;
}

