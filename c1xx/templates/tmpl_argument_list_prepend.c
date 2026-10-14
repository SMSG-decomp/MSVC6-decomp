void __thiscall tmpl_argument_list_prepend(c1_arg_list *list,c1_arg_item *item)

{
  item->next = list->first;
  list->first->prev = item;
  list->first = item;
  if ((item->kind & 8) != 0) {
    list->flags = list->flags | 1;
  }
  return;
}

