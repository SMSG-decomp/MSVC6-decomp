void __thiscall il_emitter_begin_region_at_top_level(c1xx_il_emitter *this,char use_preferred)

{
  c1_line_map_row *pcVar1;
  int iVar2;
  
  if (g_include_depth == 0) {
    if (g_use_instantiation_position == '\0') {
      if (g_line_map_cached_row.position == g_token_position) {
        pcVar1 = &g_line_map_cached_row;
        iVar2 = g_token_position;
      }
      else {
        pcVar1 = pp_line_map_find_entry(&g_line_map,g_token_position);
        iVar2 = g_token_position;
      }
    }
    else if (g_line_map_cached_row.position == g_region_source_position) {
      pcVar1 = &g_line_map_cached_row;
      iVar2 = g_region_source_position;
    }
    else {
      pcVar1 = pp_line_map_find_entry(&g_line_map,g_region_source_position);
      iVar2 = g_region_source_position;
    }
    g_region_start_line = ((short)pcVar1->line - (short)pcVar1->position) + (short)iVar2;
    if ((g_emitter_region_mode != 1) && (use_preferred == '\0')) {
      g_il_emitter = il_emitter_get_default();
      (*g_il_emitter->vtbl->begin_region)();
      return;
    }
    g_il_emitter = il_emitter_get_preferred();
    (*g_il_emitter->vtbl->begin_region)();
  }
  return;
}

