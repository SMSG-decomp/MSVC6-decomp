void __cdecl pch_read(void)

{
  c1_pack_cell *pcVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  c1_line_map_row *pcVar5;
  long _Offset;
  c1_u32 cVar6;
  long _Offset_00;
  fe_file_record *c;
  HANDLE pvVar7;
  BOOL BVar8;
  char *pcVar9;
  int iVar10;
  uint uVar11;
  c1_pch_option_block *pcVar12;
  uint *dst;
  int iVar13;
  byte bStack_23d;
  _FILETIME _Stack_230;
  char kind;
  byte file_rec_flags;
  char pair [16];
  char acStack_200 [256];
  byte abStack_100 [256];
  uint *bottom;
  char *note_newline_2;
  int note_id_2;
  char *note_newline_3;
  int note_id_3;
  char *note_newline;
  int note_id;
  
  if ((g_opt_Zi == '\0') ||
     ((g_pch_option_block_read.pch_debug_in_object == '\0' &&
      ((g_auto_pch_using == 0 || (g_debug_types_in_pdb != '\0')))))) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  pch_reload_il_streams(cVar3);
  uVar4 = (*g_idb->vtbl->idb_pch_read)(g_idb,&g_ilstore_status);
  if (uVar4 == 0) {
    diag_fatal(0x49,".\\pch.c",0x46f);
  }
  il_emitter_select(g_ilstore_status == 5);
  if (g_line_map_cached_row.position == g_token_position) {
    pcVar5 = &g_line_map_cached_row;
  }
  else {
    pcVar5 = pp_line_map_find_entry(&g_line_map,g_token_position);
  }
  iVar10 = (pcVar5->line - pcVar5->position) + g_token_position;
  g_token_position = 0;
  if ((g_pch_header.records_size != 0) &&
     (_g_io_result = fseek((FILE *)g_pch_file,
                           g_pch_header.records_offset + g_pch_header.records_size,0),
     _g_io_result != 0)) {
    diag_fatal_file_errno(0x56,0x158,g_pch_file_name);
  }
  fread(&g_pch_option_block_read,1,0x38c,(FILE *)g_pch_file);
  opt_unpack_optimize_flags(g_pch_option_block_read.function_option_word);
  if (g_pch_directive_mode == 2) {
    pcVar12 = &g_pch_option_block_read;
    dst = &g_pch_option_block;
    for (iVar13 = 0xe3; iVar13 != 0; iVar13 = iVar13 + -1) {
      *dst = pcVar12->opt_ZE;
      pcVar12 = (c1_pch_option_block *)&pcVar12->ms_extensions;
      dst = dst + 1;
    }
  }
  _Offset = ftell((FILE *)g_pch_file);
  uVar4 = g_pack_stack->top->packing;
  uVar11 = g_compile_flags_c4 >> 0xf;
  fread(&g_pending_special_members,1,0x8e4,(FILE *)g_pch_file);
  g_compile_flags_c4 = (uint)((byte)uVar11 & 1) << 0xf | g_compile_flags_c4 & 0xffff7fff;
  if (g_debug_types_in_pdb != '\0') {
    if (g_pdb.pdb == (c1xx_pdb *)0x0) {
      uVar11 = 0;
    }
    else {
      uVar11 = (*(g_pdb.pdb)->vtbl->query_age)();
    }
    if (g_pdb_age <= uVar11) {
      if (g_pdb.pdb == (c1xx_pdb *)0x0) {
        cVar6 = 0;
      }
      else {
        cVar6 = (*(g_pdb.pdb)->vtbl->query_signature)();
      }
      if (cVar6 == g_pch_option_block_read.pdb_signature) goto LAB_10449e05;
    }
    diag_error(0x35b,g_pdb_file_name);
  }
LAB_10449e05:
  if ((g_c9il_mode == '\0') && (g_split_pdbs != '\0')) {
    if (g_pdb_gi->pdb == (c1xx_pdb *)0x0) {
      uVar11 = 0;
    }
    else {
      uVar11 = (*g_pdb_gi->pdb->vtbl->query_age)();
    }
    if (g_pdb_gi_age <= uVar11) {
      if (g_pdb_gi->pdb == (c1xx_pdb *)0x0) {
        cVar6 = 0;
      }
      else {
        cVar6 = (*g_pdb_gi->pdb->vtbl->query_signature)();
      }
      if (cVar6 == g_pch_option_block_read.pdb_gi_signature) goto LAB_10449e12;
    }
    if (g_split_pdbs == '\0') {
      pcVar9 = g_pdb_file_name;
    }
    else {
      if (g_idb_file_name == '\0') {
        pdb_make_idb_name(&g_idb_file_name);
      }
      pcVar9 = &g_idb_file_name;
    }
    diag_error(0x35b,pcVar9);
  }
LAB_10449e12:
  if ((((g_pch_option_block_read.name_lengths.browse_name_length != 0) &&
       (fread(abStack_100,1,(uint)g_pch_option_block_read.name_lengths.browse_name_length,
              (FILE *)g_pch_file), g_browse_file != (char *)0x0)) && (g_pch_automatic == '\0')) &&
     (g_auto_pch_using == 0)) {
    (*g_il_emitter->vtbl->pch_name)((int)abStack_100);
  }
  if (g_pch_option_block_read.name_lengths.object_name_length != 0) {
    fread(abStack_100,1,(uint)g_pch_option_block_read.name_lengths & 0xffff,(FILE *)g_pch_file);
  }
  _Offset_00 = ftell((FILE *)g_pch_file);
  fread(g_builtin_operator_candidates,1,g_builtin_operator_candidate_count * 0x14,(FILE *)g_pch_file
       );
  uVar11 = ftell((FILE *)g_pch_file);
  bVar2 = pch_reload_arenas(g_pch_file_name,uVar11);
  if (bVar2 == 0) goto LAB_10449ed5;
  _kind = pair_init_zero_value((fe_name *)(pair + 4),g_opt_source_file);
  file_rec_flags = 0x15;
  line_map_set_cached_row((c1_line_map_state *)&g_lex_position,&kind);
  pvVar7 = (HANDLE)_get_osfhandle(g_pch_file->_file);
  BVar8 = GetFileTime(pvVar7,(LPFILETIME)0x0,(LPFILETIME)0x0,&_Stack_230);
  if ((BVar8 == 0) && (g_opt_nologo == '\0')) {
    note_newline = "\n";
    note_id = 0x38b;
    iVar13 = 0x100;
    pcVar9 = misc_string_get(0x386);
    format_snprintf(acStack_200,pcVar9,iVar13,note_id,note_newline);
    diag_write_stderr(acStack_200);
  }
  _g_io_result = fclose((FILE *)g_pch_file);
  if (_g_io_result == -1) {
    diag_fatal_file_errno(0x52,0x158,g_pch_file_name);
  }
  g_pch_file = (FILE *)fopen(g_pch_file_name,"rb+");
  if (g_pch_file == (FILE *)0x0) {
    if (g_opt_nologo == '\0') {
      note_newline_2 = "\n";
      note_id_2 = 0x38a;
      iVar13 = 0x100;
      pcVar9 = misc_string_get(0x386);
      format_snprintf(acStack_200,pcVar9,iVar13,note_id_2,note_newline_2);
LAB_10487019:
      diag_write_stderr(acStack_200);
    }
  }
  else {
    _g_io_result = fseek((FILE *)g_pch_file,_Offset,0);
    if (_g_io_result != 0) {
      diag_fatal_file_errno(0x52,0x158,g_pch_file_name);
    }
    _g_io_result = fwrite(&g_pending_special_members,1,0x8e4,(FILE *)g_pch_file);
    if (_g_io_result == 0xffffffff) {
      diag_fatal_file_errno(0x55,0x158,g_pch_file_name);
    }
    _g_io_result = fseek((FILE *)g_pch_file,_Offset_00,0);
    if (_g_io_result != 0) {
      diag_fatal_file_errno(0x52,0x158,g_pch_file_name);
    }
    _g_io_result = fwrite(g_builtin_operator_candidates,1,g_builtin_operator_candidate_count * 0x14,
                          (FILE *)g_pch_file);
    if (_g_io_result == 0xffffffff) {
      diag_fatal_file_errno(0x55,0x158,g_pch_file_name);
    }
    _g_io_result = fseek((FILE *)g_pch_file,uVar11,0);
    if (_g_io_result != 0) {
      diag_fatal_file_errno(0x52,0x158,g_pch_file_name);
    }
    pch_heap_write_file(&g_pch_image);
    _g_io_result = fflush((FILE *)g_pch_file);
    if (_g_io_result != 0) {
      diag_fatal_file_errno(0x58,0x158,g_pch_file_name);
    }
    if (BVar8 != 0) {
      pvVar7 = (HANDLE)_get_osfhandle(g_pch_file->_file);
      BVar8 = SetFileTime(pvVar7,(FILETIME *)0x0,(FILETIME *)0x0,&_Stack_230);
      if ((BVar8 == 0) && (g_opt_nologo == '\0')) {
        note_newline_3 = "\n";
        note_id_3 = 0x38b;
        iVar13 = 0x100;
        pcVar9 = misc_string_get(0x386);
        format_snprintf(acStack_200,pcVar9,iVar13,note_id_3,note_newline_3);
        goto LAB_10487019;
      }
    }
  }
  line_map_clear_cached_row((c1_line_map_state *)&g_lex_position);
LAB_10449ed5:
  pools_reset();
  c = file_record_lookup_or_new(g_current_scope,g_opt_source_file,0);
  g_lex_position = g_lex_position + 1;
  vector_push_triple((int *)&g_line_map,g_lex_position,iVar10,(int)c);
  g_token_position = g_lex_position;
  pch_rebind_include_stack_files();
  browse_resume_after_pch_read(g_il_emitter);
  il_emitter_begin_region_at_top_level(g_il_emitter,g_ilstore_status == 5);
  bStack_23d = g_pch_object_has_code;
  bVar2 = bStack_23d;
  if (g_opt_Zi != '\0') {
    if (g_pch_option_block_read.pch_debug_in_object == '\0') {
      if ((g_auto_pch_using == 0) || (g_debug_types_in_pdb != '\0')) {
        bVar2 = g_pch_object_has_code;
        if ((g_pch_option_block_read.opt_Zi != '\0') && (g_object_file_name != (char *)0x0)) {
          bVar2 = 1;
        }
        debug_begin_file((char *)abStack_100);
      }
      else {
        debug_begin('\x01');
        g_comment_record_kind = 7;
        g_comment_record_text = "\x03";
        il_emit_pragma_or_segment_record(0xb);
      }
      if (g_pch_automatic == '\0') {
        iVar10 = -1;
        pcVar9 = g_pch_option_block_read.pch_library_id;
        do {
          if (iVar10 == 0) break;
          iVar10 = iVar10 + -1;
          cVar3 = *pcVar9;
          pcVar9 = pcVar9 + 1;
        } while (cVar3 != '\0');
        if (iVar10 != -2) {
          bStack_23d = bStack_23d | 1;
        }
      }
    }
    else {
      debug_begin('\x01');
    }
  }
  if (((bVar2 != 0) && (g_opt_pch_types_in_pdb == '\0')) &&
     (cVar3 = file_name_equal((byte *)g_object_file_name,abStack_100), cVar3 != '\0')) {
    if (g_debug_types_in_pdb == '\0') {
      diag_warning(3,0x26e,g_object_file_name);
    }
    if (g_pch_object_has_code != 0) {
      diag_fatal(0x356,g_object_file_name);
    }
    iVar10 = -1;
    pcVar9 = g_pch_library_id;
    do {
      if (iVar10 == 0) break;
      iVar10 = iVar10 + -1;
      cVar3 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar3 != '\0');
    if (iVar10 != -2) {
      pch_declare_marker_variable();
    }
  }
  if ((bStack_23d != 0) && (g_pch_creating == 0)) {
    if (g_opt_pch_types_in_pdb == '\0') {
      pch_emit_pchsym_include_directive();
    }
    else {
      pch_declare_marker_variable();
    }
  }
  pch_check_defines();
  bottom = (uint *)g_pack_stack->top;
  for (pcVar1 = g_pack_stack->top->next; pcVar1 != (c1_pack_cell *)0x0; pcVar1 = pcVar1->next) {
    bottom = (uint *)pcVar1;
  }
  if (uVar4 != bottom[1]) {
    diag_warning(1,0x28d,0x196);
  }
  if (g_pch_creating == 0) {
    il_emit_end_of_globals();
    _g_io_result = fclose((FILE *)g_pch_file);
    if (_g_io_result == -1) {
      diag_fatal_file_errno(0x52,0x158,g_pch_file_name);
    }
  }
  g_pch_file_name = (char *)0x0;
  if ((g_minimal_rebuild != '\0') || (g_opt_FD != '\0')) {
    pdb_gi_restore_pch_blob(g_minimal_rebuild_tracker);
  }
  g_eh_declarations_injected = 1;
  return;
}

