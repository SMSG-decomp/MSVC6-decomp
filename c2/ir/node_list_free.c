void __fastcall node_list_free(c2_node *list)

{
  c2_node *pcVar1;
  
  while (list != (c2_node *)0x0) {
    pcVar1 = list->next;
    node_free(list);
    list = pcVar1;
  }
  return;
}

