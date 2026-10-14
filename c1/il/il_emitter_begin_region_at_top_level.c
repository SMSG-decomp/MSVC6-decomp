void il_emitter_begin_region_at_top_level(char browse)

{
  fe_line_map_row *pfVar1;
  
  if (g_include_depth == 0) {
    if (g_line_map_cached_row.position == g_token_position) {
      pfVar1 = &g_line_map_cached_row;
    }
    else {
      pfVar1 = pp_line_map_find_entry(&g_line_map,g_token_position);
    }
    g_region_start_line = ((short)pfVar1->line - (short)pfVar1->position) + (short)g_token_position;
    if ((g_emitter_region_mode != 1) && (browse == '\0')) {
      g_il_emitter = il_emitter_get_default();
      (*g_il_emitter->vtbl->begin_region)();
      return;
    }
    g_il_emitter = il_emitter_get_preferred();
    (*g_il_emitter->vtbl->begin_region)();
  }
  return;
}

