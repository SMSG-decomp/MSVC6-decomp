int c1_compile(void)

{
  byte bVar1;
  uint uVar2;
  c1_node *node;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  uint *option_word;
  uint *puVar6;
  c1_pch_options *pcVar7;
  uint *il_dst;
  char acStack_104 [260];
  
  c1_compile_begin();
  g_command_line_option_word = il_function_option_word();
  g_compile_phase = 3;
  g_pch_debug_in_object = g_pch_debug_in_object & g_debug_types_in_pdb == '\0';
  if (g_opt_E_preprocess == 0) {
    if (g_c9il_mode != '\0') {
      emit_version_string_literal();
    }
    if (g_use_pch == '\0') {
      g_pch_optimize_word = il_function_option_word();
      if (g_pch_automatic == '\0') {
        g_pch_directive_mode = 0;
        if ((((g_c9il_mode != '\0') && (g_opt_E_preprocess == 0)) && (g_opt_Zg == '\0')) &&
           (g_opt_Zi != '\0')) {
          debug_begin('\0');
        }
      }
      else {
        g_pch_debug_in_object = g_debug_types_in_pdb == '\0';
        pch_auto_begin();
      }
      option_word = &g_pch_option_block;
      pcVar7 = &g_pch_option_block_read;
      for (iVar4 = 0xe1; iVar4 != 0; iVar4 = iVar4 + -1) {
        uVar2 = *option_word;
        pcVar7->opt_ZE = (char)uVar2;
        pcVar7->pad01[0] = (char)(uVar2 >> 8);
        pcVar7->pad01[1] = (char)(uVar2 >> 0x10);
        pcVar7->pad01[2] = (char)(uVar2 >> 0x18);
        option_word = option_word + 1;
        pcVar7 = (c1_pch_options *)&pcVar7->ms_extensions;
      }
    }
    else {
      if (g_auto_pch_saved_use_pch != '\0') {
        pch_use((byte *)g_auto_pch_saved_header,'\0');
      }
      pch_use((byte *)g_use_pch_header_name,'\x01');
    }
    if ((g_c9il_mode == '\0') && (g_pch_automatic == '\0')) {
      if (g_pch_creating == 0) {
        il_files_open();
        il_emit_end_of_globals();
      }
      else {
        ilstore_open_for_gi();
      }
    }
    parse_translation_unit();
    if (g_opt_Zg == '\0') {
      tu_end_emit_global_scope((int *)g_current_scope);
      if (g_c9il_mode != '\0') {
        if (g_file_scope_decl_since_body != 0) {
          il_emit_tuple(0x53,(c1_node *)0x0);
          node = tree_new_int_constant(0);
          il_emit_tuple(0x54,node);
        }
        il_emit_tuple(0x4d,(c1_node *)0x0);
      }
      il_globals_rewind();
    }
    g_compile_phase = 5;
    if ((uint)(1 < g_warnings_as_errors) + g_error_count != 0) {
      g_last_in_batch = 1;
    }
    g_il_emitter = il_emitter_get_preferred();
    (*g_il_emitter->vtbl->finish)();
    il_emitters_free();
    if (((uint)(1 < g_warnings_as_errors) + g_error_count == 0) &&
       (iVar4 = (*g_idb->vtbl->idb_commit)(g_idb), iVar4 == 0)) {
      pcVar3 = (*g_pdb_gi->pdb->vtbl->QueryPDBName)(g_pdb_gi->pdb,acStack_104);
      diag_error(0x1d7,pcVar3);
    }
    uVar2 = (*g_idb->vtbl->idb_release)(g_idb);
    if (uVar2 == 0) {
      diag_fatal(0x49,".\\main.c",0x80d);
    }
    g_idb = (c1_idb_state *)0x0;
    if (g_opt_Zg == '\0') {
      if ((g_minimal_rebuild != '\0') || (g_opt_FD != '\0')) {
        pdb_gi_end_unit(g_pdb_file_stack,
                        CONCAT31((int3)((uint)g_error_count >> 8),
                                 (uint)(1 < g_warnings_as_errors) + g_error_count == 0));
      }
      if ((g_opt_E_preprocess == 0) && ((g_opt_Zi != '\0' || (g_debug_types_in_pdb != '\0')))) {
        debug_finish();
      }
      if (g_c9il_mode == '\0') {
        il_files_close('\0');
        ilstore_release();
      }
      else {
        il_buffer_close(&g_il_ex);
        il_buffer_close(&g_il_sy);
        il_buffer_close(&g_il_gl);
        puVar6 = (uint *)g_il_pending_init.bytes.pbStart;
        uVar2 = (int)g_il_pending_init.bytes.pbEnd - (int)g_il_pending_init.bytes.pbStart;
        if (uVar2 != 0) {
          iVar4 = uVar2 + 1;
          if (iVar4 < 0) {
            bVar1 = 0;
          }
          else if ((g_il_in.bytes.pbStart + g_il_in.bytes.cbAlloc < g_il_in.bytes.pbEnd + iVar4) &&
                  (iVar4 = il_buffer_grow(&g_il_in.bytes,iVar4), iVar4 == 0)) {
            bVar1 = 0;
          }
          else {
            bVar1 = 1;
          }
          g_il_in.open = g_il_in.open & bVar1;
          if (g_il_in.open != 0) {
            il_dst = (uint *)g_il_in.bytes.pbEnd;
            for (uVar5 = uVar2 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
              *il_dst = *puVar6;
              puVar6 = puVar6 + 1;
              il_dst = il_dst + 1;
            }
            for (uVar5 = uVar2 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
              *(uchar *)il_dst = (uchar)*puVar6;
              puVar6 = (uint *)((int)puVar6 + 1);
              il_dst = (uint *)((int)il_dst + 1);
            }
            g_il_in.bytes.pbEnd = g_il_in.bytes.pbEnd + uVar2;
          }
          g_il_pending_init.bytes.pbEnd = g_il_pending_init.bytes.pbStart;
        }
        il_buffer_close(&g_il_in);
        if (g_opt_Zi != '\0') {
          il_buffer_close(&g_il_db);
        }
      }
      pdb_close(g_pdb_gi);
    }
    (*g_source_tracker->vtbl->source_tracker_delete)(g_source_tracker);
    g_source_tracker = (c1_source_tracker *)0x0;
  }
  else {
    pp_run_preprocess_only();
    if (g_opt_FD != '\0') {
      pdb_gi_end_unit(g_pdb_file_stack,
                      CONCAT31((int3)((uint)g_error_count >> 8),
                               (uint)(1 < g_warnings_as_errors) + g_error_count == 0));
      pdb_close(g_pdb_gi);
    }
    g_compile_phase = 5;
  }
  if ((g_opt_Fi_file != (char *)0x0) &&
     (iVar4 = fclose_if_open(g_preprocess_output_file), iVar4 != 0)) {
    diag_fatal_file_errno(0x55,0x154,g_opt_Fi_file);
  }
  iVar4 = fflush((FILE *)(_iob_exref + 0x20));
  if (iVar4 != 0) {
    diag_fatal_file_errno(0x55,0x154,(char *)0x0);
  }
  pch_finish_files();
  c1_cleanup();
  g_compile_phase = 8;
  if (g_abort_requested != 0) {
    c1_abort_if_running();
  }
  return (uint)(1 < g_warnings_as_errors) + g_error_count;
}

