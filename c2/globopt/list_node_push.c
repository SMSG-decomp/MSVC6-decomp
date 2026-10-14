c2_list_cell * __fastcall list_node_push(c2_list_cell *head,void *value)

{
  c2_list_cell **ppcVar1;
  c2_list_cell *pcVar2;
  
  if (g_list_node_free == (c2_list_cell *)0x0) {
    refill_list_node_pool();
  }
  pcVar2 = g_list_node_free;
  ppcVar1 = &g_list_node_free->next;
  g_list_node_free = g_list_node_free->next;
  *ppcVar1 = head;
  (pcVar2->u04).tuple = value;
  return pcVar2;
}

