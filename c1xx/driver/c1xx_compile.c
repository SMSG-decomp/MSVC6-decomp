int __cdecl c1xx_compile(void)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  c1_node *n;
  char *pdb_error_text;
  uint word_count;
  uint word_count_2;
  c1_u32 *pcVar4;
  uint *src;
  c1_u32 *il_in_dst;
  uint *dst;
  char text [260];
  
  c1xx_compile_begin();
  g_command_line_option_word = il_function_option_word();
  g_compile_phase = 3;
  g_pch_debug_in_object = g_pch_debug_in_object & g_debug_types_in_pdb == '\0';
  if (g_opt_E_preprocess == 0) {
    if (g_c9il_mode != '\0') {
      emit_version_string_literal();
    }
    if (g_use_pch == '\0') {
      g_pch_function_option_word = il_function_option_word();
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
      src = &g_pch_option_block;
      dst = (uint *)&g_pch_option_block_read;
      for (iVar2 = 0xe3; iVar2 != 0; iVar2 = iVar2 + -1) {
        *dst = *src;
        src = src + 1;
        dst = dst + 1;
      }
    }
    else {
      if (g_auto_pch_saved_use_pch != '\0') {
        pch_use(g_auto_pch_saved_yu_header,'\0');
      }
      pch_use(g_opt_Yu_header,'\x01');
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
      tu_end_flush();
      tu_end_emit_global_scope(g_current_scope);
      if (g_c9il_mode != '\0') {
        if (g_file_scope_decl_since_body != 0) {
          il_emit_tuple(0x53,(node *)0x0);
          n = tree_new_int_constant(0);
          il_emit_tuple(0x54,n);
        }
        il_emit_tuple(0x4d,(node *)0x0);
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
       (iVar2 = (*g_idb->vtbl->idb_commit)(g_idb), iVar2 == 0)) {
      pdb_error_text = (char *)(*g_pdb_gi->pdb->vtbl->query_pdb_name)(text);
      diag_error(0x1d7,pdb_error_text);
    }
    uVar3 = (*g_idb->vtbl->idb_release)(g_idb);
    if (uVar3 == 0) {
      diag_fatal(0x49,".\\main.c",0x80d);
    }
    g_idb = (c1xx_idb *)0x0;
    if (g_opt_Zg == '\0') {
      if ((g_minimal_rebuild != '\0') || (g_opt_FD != '\0')) {
        pdb_gi_end_unit(g_minimal_rebuild_tracker,
                        (uint)(1 < g_warnings_as_errors) + g_error_count == 0);
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
        pcVar4 = (c1_u32 *)g_il_pending_init.bytes.start;
        uVar3 = (int)g_il_pending_init.bytes.cur - (int)g_il_pending_init.bytes.start;
        if (uVar3 != 0) {
          iVar2 = uVar3 + 1;
          if (iVar2 < 0) {
            bVar1 = 0;
          }
          else if ((g_il_in.bytes.start + g_il_in.bytes.size < g_il_in.bytes.cur + iVar2) &&
                  (iVar2 = il_buffer_grow(&g_il_in.bytes,iVar2), iVar2 == 0)) {
            bVar1 = 0;
          }
          else {
            bVar1 = 1;
          }
          g_il_in.open = g_il_in.open & bVar1;
          if (g_il_in.open != 0) {
            il_in_dst = (c1_u32 *)g_il_in.bytes.cur;
            for (word_count = uVar3 >> 2; word_count != 0; word_count = word_count - 1) {
              *il_in_dst = *pcVar4;
              pcVar4 = pcVar4 + 1;
              il_in_dst = il_in_dst + 1;
            }
            for (word_count_2 = uVar3 & 3; word_count_2 != 0; word_count_2 = word_count_2 - 1) {
              *(c1_u8 *)il_in_dst = (c1_u8)*pcVar4;
              pcVar4 = (c1_u32 *)((int)pcVar4 + 1);
              il_in_dst = (c1_u32 *)((int)il_in_dst + 1);
            }
            g_il_in.bytes.cur = g_il_in.bytes.cur + uVar3;
          }
          g_il_pending_init.bytes.cur = g_il_pending_init.bytes.start;
        }
        il_buffer_close(&g_il_in);
        if (g_opt_Zi != '\0') {
          il_buffer_close(&g_il_db);
        }
      }
      pdb_close(g_pdb_gi);
    }
    (**(code **)(*g_source_tracker + 0x10))();
    g_source_tracker = (int *)0x0;
  }
  else {
    pp_run_preprocess_only();
    if (g_opt_FD != '\0') {
      pdb_gi_end_unit(g_minimal_rebuild_tracker,
                      (uint)(1 < g_warnings_as_errors) + g_error_count == 0);
      pdb_close(g_pdb_gi);
    }
    g_compile_phase = 5;
  }
  if ((g_opt_Fi_output != (char *)0x0) && (iVar2 = fclose_if_open(g_fi_output_file), iVar2 != 0)) {
    diag_fatal_file_errno(0x55,0x154,g_opt_Fi_output);
  }
  iVar2 = fflush((FILE *)(_iob_exref + 0x20));
  if (iVar2 != 0) {
    diag_fatal_file_errno(0x55,0x154,(char *)0x0);
  }
  pch_finish_files();
  c1xx_cleanup();
  g_compile_phase = 8;
  if (g_abort_requested != 0) {
    c1xx_abort_if_running();
  }
  return (uint)(1 < g_warnings_as_errors) + g_error_count;
}

