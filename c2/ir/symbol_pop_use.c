c2_tuple * __fastcall symbol_pop_use(c2_symbol *s)

{
  c2_list_cell *pcVar1;
  c2_tuple *pcVar2;
  c2_list_cell *pcVar3;
  
  pcVar1 = s->uses;
  if (pcVar1 != (c2_list_cell *)0x0) {
    pcVar2 = (pcVar1->u04).tuple;
    pcVar3 = pcVar1->next;
    pcVar1->next = g_list_node_free;
    g_list_node_free = pcVar1;
    s->uses = pcVar3;
    return pcVar2;
  }
  s->uses = (c2_list_cell *)0x0;
  return (c2_tuple *)0x0;
}

