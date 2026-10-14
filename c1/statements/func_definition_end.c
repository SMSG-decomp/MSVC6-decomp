void func_definition_end(void)

{
  bool bVar1;
  int iVar2;
  fe_line_map_row *pfVar3;
  uint uVar4;
  int local_8;
  int local_4;
  
  local_8 = g_ilstore_status;
  if ((g_ilstore_status == 4) || ((g_token_source->stream->flags & 1) != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (g_current_function != (c1_symbol *)0x0) {
    iVar2 = local_4;
    if (bVar1) {
      iVar2 = (*g_idb->vtbl->idb_helper_called)(g_idb);
      if ((iVar2 == 0) && (g_function_uses_line_helper == '\0')) {
        iVar2 = 0;
      }
      else {
        iVar2 = 1;
      }
      if (g_line_map_cached_row.position == g_token_position) {
        pfVar3 = &g_line_map_cached_row;
      }
      else {
        pfVar3 = pp_line_map_find_entry(&g_line_map,g_token_position);
      }
      uVar4 = (*g_idb->vtbl->idb_function_end)
                        (g_idb,0,CONCAT22((short)((uint)g_macro_expansion_depth >> 0x10),
                                          (short)pfVar3->line - (short)pfVar3->position) +
                                 g_token_position,g_macro_expansion_depth,&local_8,&local_4);
      if (uVar4 == 0) {
        diag_fatal(0x49,".\\funcs.c",0x82e);
      }
    }
    func_emit_body_end_il((g_current_function->flags1 & 0x40) >> 6);
    if ((bVar1) && (il_emitter_begin_region_at_top_level(local_8 == 5), iVar2 != 0)) {
      func_emit_global_helper_symbol();
    }
  }
  func_reset_helper_key();
  g_pending_parameter_scope = (c1_scope_symbol_list *)0x0;
  g_compile_flags_c4 = g_compile_flags_c4 & 0xfffdffff;
  g_function_parameter_scope = (c1_scope_symbol_list *)0x0;
  g_pending_function_word = 0;
  g_function_context_word = 0;
  g_current_function = (c1_symbol *)0x0;
  implicit_function_table_clear();
  g_ilstore_status = local_8;
  return;
}

