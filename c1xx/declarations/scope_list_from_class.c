c1_keyed_cell * __cdecl scope_list_from_class(c1_vtable_record *rec,c1_symbol *cls)

{
  c1_symbol *sym;
  c1_keyed_list *pcVar1;
  
  tree_list_arena_set(5);
  pcVar1 = tree_new_list_cell((c1_keyed_list *)0x0,0,cls);
  sym = rec->via_base;
  while (sym != (c1_symbol *)0x0) {
    pcVar1 = tree_new_list_cell((c1_keyed_list *)0x0,(int)pcVar1->head,sym);
    rec = rec->outer;
    sym = rec->via_base;
  }
  tree_list_arena_restore();
  return pcVar1->head;
}

