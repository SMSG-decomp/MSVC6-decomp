c2_list_cell * __fastcall list_node_pop(c2_list_cell *list,void **out)

{
  c2_list_cell *pcVar1;
  
  if (list == (c2_list_cell *)0x0) {
    *out = (void *)0x0;
    return (c2_list_cell *)0x0;
  }
  pcVar1 = list->next;
  *out = (void *)list->u04;
  list->next = g_list_node_free;
  g_list_node_free = list;
  return pcVar1;
}

