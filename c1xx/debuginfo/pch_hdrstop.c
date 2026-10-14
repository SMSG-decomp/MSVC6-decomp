void __cdecl pch_hdrstop(void)

{
  c1_line_map_row *pcVar1;
  fe_input_file *pfVar2;
  int iVar3;
  
  if (g_pch_directive_mode == 0) {
    if ((((g_pch_create != '\0') && (g_create_pch_header_name == (char *)0x0)) &&
        (g_pch_written == 0)) && (g_include_depth < 1)) {
      (*g_il_emitter->vtbl->flush)();
      pch_set_name(g_opt_source_file);
      pch_write();
      (*g_il_emitter->vtbl->flush)();
    }
  }
  else if (g_include_depth == 0) {
    pch_read_options();
  }
  if (g_opt_BMOVE != '\0') {
    if (-1 < g_include_depth) {
      iVar3 = g_include_depth + 1;
      pfVar2 = g_input_file;
      do {
        if (g_line_map_cached_row.position == g_token_position) {
          pcVar1 = &g_line_map_cached_row;
        }
        else {
          pcVar1 = pp_line_map_find_entry(&g_line_map,g_token_position);
        }
        iVar3 = iVar3 + -1;
        pfVar2->file = pcVar1->file;
        pfVar2 = pfVar2->next;
      } while (iVar3 != 0);
    }
    return;
  }
  return;
}

