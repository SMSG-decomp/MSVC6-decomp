void * __fastcall symbol_add_use_unique(c2_symbol *s,void *v)

{
  c2_list_cell_u04 *pcVar1;
  c2_list_cell *pcVar2;
  c2_list_cell *pcVar3;
  
  pcVar2 = s->uses;
  pcVar3 = pcVar2;
  while( true ) {
    if (pcVar3 == (c2_list_cell *)0x0) {
      if (g_list_node_free == (c2_list_cell *)0x0) {
        refill_list_node_pool();
      }
      pcVar3 = g_list_node_free;
      pcVar1 = &g_list_node_free->u04;
      g_list_node_free = g_list_node_free->next;
      pcVar1->tuple = v;
      pcVar3->next = pcVar2;
      s->uses = pcVar3;
      return pcVar3;
    }
    if ((pcVar3->u04).tuple == v) break;
    pcVar3 = pcVar3->next;
  }
  s->uses = pcVar2;
  return pcVar2;
}

