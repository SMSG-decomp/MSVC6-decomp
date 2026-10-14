void __fastcall list_clear_value(c2_list_cell *list,void *value)

{
  for (; list != (c2_list_cell *)0x0; list = list->next) {
    if ((list->u04).tuple == value) {
      (list->u04).tuple = (c2_tuple *)0x0;
    }
  }
  return;
}

