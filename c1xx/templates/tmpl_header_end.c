void * __cdecl tmpl_header_end(void *parameter_table)

{
  byte bVar1;
  c1_u8 *pcVar2;
  c1_u8 cVar3;
  int iVar4;
  byte *token;
  int *piVar5;
  
  iVar4 = g_paren_depth;
  g_block_depth = g_block_depth + 0xff;
  g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xef;
  pcVar2 = g_arenas[0].end;
  if (0 < iVar4) {
    iVar4 = iVar4 + -1;
    g_paren_depth = iVar4;
  }
  g_paren_level_flags[iVar4] = g_paren_level_flags[iVar4] & 0xf7;
  piVar5 = (int *)g_arenas[0].cur;
  g_context_arena_index = 0;
  g_compile_flags_c8 = g_compile_flags_c8 & 0xefffffff | 0x2000000;
  g_expr_arena_index = 0;
  g_arenas[0].cur = g_arenas[0].cur + 8;
  if (pcVar2 < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    *piVar5 = g_token_arena_index;
    *(int **)((int)piVar5 + 4) = g_token_arena_stack;
  }
  g_token_arena_index = 0;
  g_token_arena_stack = piVar5;
  token = token_next((c1_token_reader *)&g_token_position);
  bVar1 = *token;
  while (bVar1 == 0xf4) {
    token = token_next((c1_token_reader *)&g_token_position);
    bVar1 = *token;
  }
  (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)token);
  bVar1 = *token;
  if ((bVar1 != 0x1a) &&
     (((bVar1 < 0x1c || (0x1d < bVar1)) &&
      (cVar3 = lex_check_end_of_file_2(parameter_table), cVar3 == '\0')))) {
    return (void *)0x0;
  }
  g_token_arena_index = *g_token_arena_stack;
  g_token_arena_stack = (int *)g_token_arena_stack[1];
  return parameter_table;
}

