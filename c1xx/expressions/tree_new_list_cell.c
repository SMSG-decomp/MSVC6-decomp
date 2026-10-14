c1_keyed_list * __cdecl tree_new_list_cell(c1_keyed_list *list,int key,c1_symbol *sym)

{
  c1_keyed_list *pcVar1;
  c1_keyed_cell *pcVar2;
  c1_keyed_cell *pcVar3;
  c1_arena *pcVar4;
  
  if (list == (c1_keyed_list *)0x0) {
    pcVar4 = g_arenas + g_list_cell_arena;
    list = (c1_keyed_list *)pcVar4->cur;
    pcVar1 = (c1_keyed_list *)g_arenas[g_list_cell_arena].end;
    pcVar4->cur = (c1_u8 *)(list + 1);
    if (pcVar1 < list + 1) {
      arena_grow(pcVar4);
    }
  }
  pcVar4 = g_arenas + g_list_cell_arena;
  pcVar2 = (c1_keyed_cell *)pcVar4->cur;
  pcVar3 = (c1_keyed_cell *)g_arenas[g_list_cell_arena].end;
  pcVar4->cur = (c1_u8 *)(pcVar2 + 1);
  if (pcVar3 < pcVar2 + 1) {
    arena_grow(pcVar4);
  }
  pcVar2->sym = sym;
  pcVar2->key = (c1_keyed_cell *)key;
  if (list->head == (c1_keyed_cell *)0x0) {
    list->head = pcVar2;
    list->tail = pcVar2;
    return list;
  }
  list->tail->next = pcVar2;
  list->tail = pcVar2;
  return list;
}

