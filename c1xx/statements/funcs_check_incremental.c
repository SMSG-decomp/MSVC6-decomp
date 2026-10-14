void funcs_check_incremental(void)

{
  bool bVar1;
  int iVar2;
  c1_line_map_row *pcVar3;
  uint uVar4;
  byte *member_name;
  int iVar5;
  c1_u32 class_ni;
  int local_8;
  int local_4;
  
  local_8 = g_ilstore_status;
  if ((g_ilstore_status == 4) || (bVar1 = false, (g_token_source->stream->flags & 1) != 0)) {
    bVar1 = true;
  }
  if (g_current_function != (c1_symbol *)0x0) {
    iVar2 = local_4;
    if (bVar1) {
      class_ni = 0;
      if ((g_current_function->kind & 0x1f) == 8) {
        class_ni = ((g_scope_vector->entries[(short)g_current_function->scope_index]->detail).cls)->
                   gm_name_index;
      }
      iVar2 = (*g_idb->vtbl->idb_helper_called)(g_idb);
      if ((iVar2 == 0) && (g_function_uses_line_helper == '\0')) {
        iVar2 = 0;
      }
      else {
        iVar2 = 1;
      }
      if (g_line_map_cached_row.position == g_token_position) {
        pcVar3 = &g_line_map_cached_row;
      }
      else {
        pcVar3 = pp_line_map_find_entry(&g_line_map,g_token_position);
      }
      uVar4 = (*g_idb->vtbl->idb_function_end)
                        (g_idb,class_ni,
                         CONCAT22((short)((uint)g_macro_expansion_depth >> 0x10),
                                  (short)pcVar3->line - (short)pcVar3->position) + g_token_position,
                         g_macro_expansion_depth,&local_8,&local_4);
      if (uVar4 == 0) {
        diag_fatal(0x49,".\\funcs.c",0x82e);
      }
      if ((g_minimal_rebuild != '\0') && (local_4 != 0)) {
        member_name = mre_member_name_text
                                (g_current_function->name,
                                 (int)g_scope_vector->entries
                                      [(short)g_current_function->scope_index]);
        iVar5 = (*g_idb->vtbl->idb_tracker_note)(g_idb,class_ni,(char *)member_name);
        if (iVar5 == 0) {
          diag_fatal(0x49,".\\funcs.c",0x833);
        }
      }
    }
    func_emit_end(g_current_function->flags3 & 1);
    if ((bVar1) && (il_emitter_begin_region_at_top_level(g_il_emitter,local_8 == 5), iVar2 != 0)) {
      sym_init_global_helper_name();
    }
  }
  sym_clear_global_helper_key();
  func_flow_state_reset();
  g_static_guard_record.guard = (c1_symbol *)0x0;
  g_static_guard_record.mask = '\0';
  g_static_guard_record.pad05[0] = '\0';
  g_static_guard_record.pad05[1] = '\0';
  g_static_guard_record.pad05[2] = '\0';
  g_static_guard_count = 0;
  decl_state_restore(g_current_scope,'\0');
  decl_state_pop(g_current_scope);
  g_pending_parameter_scope = (c1_sym_list *)0x0;
  g_compile_flags_c4 = g_compile_flags_c4 & 0xfffdfeff;
  g_function_parameter_scope = (c1_sym_list *)0x0;
  g_pending_function_word = 0;
  g_function_context_word = 0;
  g_current_function = (c1_symbol *)0x0;
  func_clear_local_side_tables();
  eh_flush_function_data();
  g_ilstore_status = local_8;
  return;
}

