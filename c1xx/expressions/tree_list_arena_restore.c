void __cdecl tree_list_arena_restore(void)

{
  g_list_cell_arena = g_list_cell_arena_saved;
  g_list_cell_arena_saved = -1;
  return;
}

