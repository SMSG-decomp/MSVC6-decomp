void __cdecl tree_list_arena_set(int arena)

{
  g_list_cell_arena_saved = g_list_cell_arena;
  g_list_cell_arena = arena;
  return;
}

