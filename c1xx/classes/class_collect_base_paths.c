c1_keyed_list * __cdecl class_collect_base_paths(c1_symbol *cls,c1_symbol *base)

{
  c1_keyed_cell *pcVar1;
  c1_keyed_list *pcVar2;
  c1_keyed_list *pcVar3;
  int *paths;
  c1_arena *a;
  fe_name **state;
  fe_name *local_14;
  uint state0;
  uint state1;
  c1_symtab *local_8;
  c1_vector *local_4;
  
  tree_list_arena_set(5);
  state0 = 0;
  local_14 = base->name;
  state1 = 0;
  local_8 = (c1_symtab *)0x0;
  local_4 = vector_new(1,5);
  state = &local_14;
  pcVar3 = tree_new_list_cell((c1_keyed_list *)0x0,0,cls);
  paths = class_find_base_paths(pcVar3,(int *)state);
  sym_list_remove_matching(paths,local_8);
  pcVar3 = (c1_keyed_list *)0x0;
  for (pcVar1 = (c1_keyed_cell *)*paths; pcVar1 != (c1_keyed_cell *)0x0; pcVar1 = pcVar1->next) {
    if (g_scope_vector->entries[(short)pcVar1->sym->key_ref] == base) {
      if (pcVar3 == (c1_keyed_list *)0x0) {
        a = g_arenas + g_list_cell_arena;
        pcVar3 = (c1_keyed_list *)a->cur;
        pcVar2 = (c1_keyed_list *)g_arenas[g_list_cell_arena].end;
        a->cur = (c1_u8 *)(pcVar3 + 1);
        if (pcVar2 < pcVar3 + 1) {
          arena_grow(a);
        }
        pcVar3->tail = pcVar1;
        pcVar3->head = pcVar1;
      }
      else {
        pcVar3->tail->next = pcVar1;
        pcVar3->tail = pcVar1;
      }
    }
  }
  tree_list_arena_restore();
  return pcVar3;
}

