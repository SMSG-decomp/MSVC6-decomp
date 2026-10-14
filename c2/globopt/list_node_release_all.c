void __fastcall list_node_release_all(c2_list_cell **list_head)

{
  c2_list_cell *pcVar1;
  c2_list_cell *pcVar2;
  
  pcVar1 = *list_head;
  if (pcVar1 != (c2_list_cell *)0x0) {
    for (pcVar2 = pcVar1->next; pcVar2 != (c2_list_cell *)0x0; pcVar2 = pcVar2->next) {
      pcVar1 = pcVar2;
    }
    pcVar1->next = g_list_node_free;
    g_list_node_free = *list_head;
    *list_head = (c2_list_cell *)0x0;
  }
  return;
}

