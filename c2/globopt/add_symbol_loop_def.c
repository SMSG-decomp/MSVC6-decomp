void __fastcall add_symbol_loop_def(c2_symbol *sym,c2_tuple *t)

{
  c2_list_cell_u04 *pcVar1;
  c2_list_cell *pcVar2;
  c2_list_cell *pcVar3;
  
  pcVar2 = sym->defs;
  if (g_list_node_free == (c2_list_cell *)0x0) {
    refill_list_node_pool();
  }
  pcVar3 = g_list_node_free;
  pcVar1 = &g_list_node_free->u04;
  g_list_node_free = g_list_node_free->next;
  pcVar1->tuple = t;
  pcVar3->next = pcVar2;
  sym->defs = pcVar3;
  return;
}

