void __cdecl browse_add_record(byte kind,c1_symbol *sym)

{
  fe_line_map_row *pfVar1;
  c1_browse_record local_18;
  
  if (g_browse_suspended == 0) {
    local_18.kind = kind;
    if (g_line_map_cached_row.position == g_token_position) {
      pfVar1 = &g_line_map_cached_row;
    }
    else {
      pfVar1 = pp_line_map_find_entry(&g_line_map,g_token_position);
    }
    local_18.line = (pfVar1->line - pfVar1->position) + g_token_position;
    local_18.name = (char *)0x0;
    local_18.name_record = (void *)0x0;
    local_18.attributes = 0;
    local_18.sub_kind = '\0';
    local_18.id = 0;
    browse_record_fill(&local_18,sym);
    browse_record_type(&local_18);
  }
  return;
}

