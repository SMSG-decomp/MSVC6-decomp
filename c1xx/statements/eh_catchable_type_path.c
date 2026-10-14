void __cdecl eh_catchable_type_path(int *value)

{
  char cVar1;
  ushort *puVar2;
  c1_keyed_list *pcVar3;
  
  tree_list_arena_set(5);
  if (*value != 0) {
    pcVar3 = tree_new_list_cell((c1_keyed_list *)0x0,**(int **)(*value + 0x24),(c1_symbol *)value[7]
                               );
    value[9] = (int)pcVar3;
    tree_list_arena_restore();
    return;
  }
  puVar2 = (ushort *)value[2];
  cVar1 = (char)*puVar2;
  while (cVar1 < '\0') {
    puVar2 = *(ushort **)(puVar2 + 2);
    cVar1 = (char)*puVar2;
  }
  if ((*puVar2 & 0x300) == 0) {
    pcVar3 = tree_new_list_cell((c1_keyed_list *)0x0,0,(c1_symbol *)0x0);
    value[9] = (int)pcVar3;
    tree_list_arena_restore();
    return;
  }
  pcVar3 = tree_new_list_cell((c1_keyed_list *)0x0,0,*(c1_symbol **)(puVar2 + 4));
  value[9] = (int)pcVar3;
  tree_list_arena_restore();
  return;
}

