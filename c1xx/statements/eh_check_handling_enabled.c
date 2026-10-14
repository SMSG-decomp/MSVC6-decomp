void eh_check_handling_enabled(void)

{
  c1_u8 *item;
  c1_line_map_row *pcVar1;
  c1_vector *pcVar2;
  c1_node *pcVar3;
  
  if ((g_current_function->flags5 & 1) != 0) {
    diag_error(0x2c9);
  }
  if (g_opt_eh == '\0') {
    diag_warning(1,0x212);
  }
  *(byte *)((int)&g_current_function->tail + 10) =
       *(byte *)((int)&g_current_function->tail + 10) | 4;
  item = g_arenas[4].cur;
  g_arenas[4].cur = g_arenas[4].cur + 0x18;
  if (g_arenas[4].end < g_arenas[4].cur) {
    arena_grow(g_arenas + 4);
  }
  if (g_line_map_cached_row.position == g_token_position) {
    pcVar1 = &g_line_map_cached_row;
  }
  else {
    pcVar1 = pp_line_map_find_entry(&g_line_map,g_token_position);
  }
  *(int *)item = (pcVar1->line - pcVar1->position) + g_token_position;
  pcVar2 = vector_new(0,4);
  *(c1_vector **)(item + 0xc) = pcVar2;
  pcVar3 = label_new(0x48);
  *(c1_node **)(item + 0x10) = pcVar3;
  item[0x14] = '\0';
  if (PTR_104d2cb8 == (c1_vector *)0x0) {
    PTR_104d2cb8 = vector_new(0,4);
  }
  vector_push(PTR_104d2cb8,item);
  il_emit_eh_try();
  return;
}

