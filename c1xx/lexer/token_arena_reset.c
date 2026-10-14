void __cdecl token_arena_reset(void)

{
  g_token_arena_stack = (int *)0x0;
  g_token_arena_index = 4;
  return;
}

