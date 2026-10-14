void __thiscall list_append_tail(c1_arg_list *list,c1_arg_item *item)

{
  list->last->next = item;
  item->prev = list->last;
  list->last = item;
  if ((item->kind & 8) != 0) {
    list->flags = list->flags | 1;
  }
  return;
}

