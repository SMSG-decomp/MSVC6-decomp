int __cdecl pch_creation_point(void)

{
  int iVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *fmt;
  int extraout_EAX;
  int extraout_EAX_00;
  int extraout_EAX_01;
  uint uVar7;
  uint *src;
  uint *dst;
  time_t tVar8;
  char *pcVar9;
  char acStack_100 [168];
  undefined4 uStack_58;
  char cVar10;
  int msg_number;
  
  if (g_pch_directive_mode != 0) {
    free_list_mark_block_end(g_pch_directive_text_blocks);
    if (g_pch_directive_mode == 1) {
      (*g_il_emitter->vtbl->flush)();
      pch_write();
      g_pch_directive_mode = 0;
      if (g_pch_auto_note != (char *)0x0) {
        diag_write_stderr(g_pch_auto_note);
        mem_free(g_pch_auto_note);
        g_pch_auto_note = (char *)0x0;
      }
      return 4;
    }
    if ((g_pch_file_time_changed == 0) && (*g_pch_record_cursor == 0xc)) {
      src = (uint *)&g_pch_header_read;
      dst = (uint *)&g_pch_header;
      for (iVar4 = 0x1a; iVar4 != 0; iVar4 = iVar4 + -1) {
        *dst = *src;
        src = src + 1;
        dst = dst + 1;
      }
      pch_read();
      mem_free(g_pch_records_buffer);
      g_pch_record_cursor = (int *)0x0;
      g_pch_records_buffer = (int *)0x0;
      if (g_opt_Zi != '\0') {
        debug_begin('\x01');
      }
      g_pch_directive_mode = 0;
      if (g_opt_nologo == '\0') {
        pcVar9 = "\n";
        msg_number = 0x15e;
        iVar4 = 0x100;
        pcVar6 = misc_string_get(0x386);
        format_snprintf(acStack_100,pcVar6,iVar4,msg_number,pcVar9);
        diag_write_stderr(acStack_100);
      }
      return 3;
    }
    if (g_pch_header_read.include_key_alt == 0) {
      g_pch_header_read.include_key_alt = g_pch_header_read.include_key;
    }
    if (g_pch_auto_never_recreate == 0) {
      if (((g_pch_include_count.last_key == 0) ||
          ((g_pch_header_read.include_key << 7) / (int)(uint)(ushort)g_pch_include_count.last_key <
           100)) ||
         ((g_pch_header_read.include_key_alt << 7) / (int)(uint)(ushort)g_pch_include_count.last_key
          < 0x50)) {
        iVar4 = 0;
        iVar1 = *g_pch_record_cursor;
        while (iVar1 != 0xc) {
          if (iVar1 == 2) {
            iVar4 = iVar4 + 1;
          }
          g_pch_record_cursor = (int *)((int)g_pch_record_cursor + g_pch_record_cursor[1] + 0xc);
          iVar1 = *g_pch_record_cursor;
        }
        iVar4 = g_pch_include_count.count + iVar4;
        if ((iVar4 == 0) || ((g_pch_include_count.count * 100) / iVar4 < 0x46)) {
          g_pch_include_count.count = -1;
        }
      }
    }
    else {
      g_pch_include_count.count = -1;
    }
    if (g_opt_nologo == '\0') {
      if (g_pch_include_count.count < 1) {
        pcVar6 = (char *)0x160;
        iVar4 = 0x100;
        pcVar9 = g_pch_file_name;
        fmt = misc_string_get(0x386);
      }
      else {
        pcVar9 = (char *)(int)g_pch_include_count.count;
        iVar4 = 0x100;
        pcVar6 = g_pch_file_name;
        fmt = misc_string_get(0x387);
      }
      format_snprintf(acStack_100,fmt,iVar4,pcVar6,pcVar9);
      uVar5 = 0xffffffff;
      pcVar6 = acStack_100;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar10 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar10 != '\0');
      g_pch_auto_note = mem_xmalloc(~uVar5);
      uVar5 = 0xffffffff;
      pcVar6 = acStack_100;
      do {
        pcVar9 = pcVar6;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar9 = pcVar6 + 1;
        cVar10 = *pcVar6;
        pcVar6 = pcVar9;
      } while (cVar10 != '\0');
      uVar5 = ~uVar5;
      pcVar6 = pcVar9 + -uVar5;
      pcVar9 = g_pch_auto_note;
      for (uVar7 = uVar5 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar9 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar9 = pcVar9 + 1;
      }
    }
    pp_line_output_reset();
    pch_auto_start_recording();
    g_forced_include_index._0_2_ = 0;
    g_forced_include_files = g_forced_include_list;
    return 1;
  }
  if (-1 < g_pp_cond_depth) {
    diag_error(0x358);
  }
  iVar4 = (uint)(1 < g_warnings_as_errors) + g_error_count;
  if (iVar4 != 0) {
    if (g_c9il_mode != '\0') {
      return CONCAT31((int3)((uint)iVar4 >> 8),g_c9il_mode);
    }
    pch_finish_il();
    return extraout_EAX;
  }
  if (((byte)g_compile_flags_c4 & 0x20) != 0) {
    func_definition_end('\x01');
  }
  if (g_parse_context_depth != 0) {
    diag_fatal(1);
  }
  if (g_pch_create_explicit == 0) {
    tu_end_flush();
  }
  if (g_pch_object_has_code == 0) {
    if ((g_opt_Zi != '\0') && (g_pch_debug_in_object == '\0')) {
      iVar4 = -1;
      pcVar6 = g_pch_library_id;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        cVar10 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar10 != '\0');
      if (iVar4 != -2) goto LAB_10487d96;
    }
    cVar10 = '\0';
  }
  else {
LAB_10487d96:
    cVar10 = '\x01';
    pch_stream_name(g_string_literal_cur,g_object_file_name,g_pch_library_id);
    uVar5 = 0xffffffff;
    pcVar6 = g_string_literal_cur;
    do {
      pcVar9 = pcVar6;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar9 = pcVar6 + 1;
      cVar3 = *pcVar6;
      pcVar6 = pcVar9;
    } while (cVar3 != '\0');
    uVar5 = ~uVar5;
    pcVar6 = pcVar9 + -uVar5;
    pcVar9 = g_pch_symbol_name;
    for (uVar7 = uVar5 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar9 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    }
  }
  bVar2 = g_pch_precomp_types;
  if (g_pch_precomp_types != 0) {
    tu_end_scope();
  }
  PTR_104d144c = vector_copy(g_include_path_list,0,str_dup_arena);
  PTR_104d1448 = vector_copy(g_define_list,0,str_dup_arena);
  if ((g_minimal_rebuild != '\0') || (g_opt_FD != '\0')) {
    pdb_gi_read_blob_for_pch();
  }
  if (g_object_file_name != (char *)0x0) {
    iVar4 = -1;
    pcVar6 = g_object_file_name;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      cVar3 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar3 != '\0');
    g_pch_name_lengths.object_name_length = ~(ushort)iVar4;
  }
  if (g_browse_file != (char *)0x0) {
    iVar4 = -1;
    pcVar6 = g_opt_Fr_browse;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      cVar3 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar3 != '\0');
    g_pch_name_lengths.browse_name_length = ~(ushort)iVar4;
    if (g_pch_directive_mode == 0) {
      (*g_il_emitter->vtbl->pch_mark)();
    }
  }
  g_pch_header.flags._0_1_ =
       (byte)g_pch_header.flags ^ ((byte)g_pch_header.flags ^ g_opt_pch_types_in_pdb) & 1;
  tVar8 = time((time_t *)0x0);
  g_pch_header.time = (int)tVar8;
  if (((g_opt_pch_types_in_pdb != 0) && (g_opt_ZX == 0)) && (g_pdb.pdb != (c1xx_pdb *)0x0)) {
    pdb_record_pch_contribution(&g_pdb,g_pch_file_name,g_pch_header.time);
  }
  pch_write_file();
  uVar5 = (*g_idb->vtbl->idb_pch_written)(g_idb,&g_ilstore_status);
  if (uVar5 != 0) {
    il_emitter_begin_region_at_top_level(g_il_emitter,g_ilstore_status == 5);
    g_builtin_operator_candidate_count = builtin_operator_candidate_count();
    if ((g_pch_directive_mode == 1) || (g_auto_pch_creating != 0)) {
      init_write_reloc_record(0xc,0,0);
      free_list_mark_block_end(g_pch_record_list);
      _g_io_result = fflush((FILE *)g_pch_file);
      if (_g_io_result == -1) {
        diag_fatal_file_errno(0x58,0x158,g_pch_file_name);
      }
      iVar4 = ftell((FILE *)g_pch_file);
      _g_io_result = iVar4;
      if (iVar4 == -1) {
        iVar4 = diag_fatal_file_errno(0x57,0x158,g_pch_file_name);
      }
      g_pch_header.records_offset = iVar4;
      g_pch_header.records_size = pch_write_blocks(g_pch_record_list,g_pch_file,0);
    }
    g_pch_function_option_word = il_function_option_word();
    _g_io_result = fwrite(&g_pch_option_block,1,0x38c,(FILE *)g_pch_file);
    if (_g_io_result == 0xffffffff) {
      diag_fatal_file_errno(0x55,0x158,g_pch_file_name);
    }
    fwrite(&g_pending_special_members,1,0x8e4,(FILE *)g_pch_file);
    fwrite(g_browse_file,1,(uint)g_pch_name_lengths >> 0x10,(FILE *)g_pch_file);
    fwrite(g_object_file_name,1,(uint)g_pch_name_lengths & 0xffff,(FILE *)g_pch_file);
    uStack_58 = 0x10454002;
    fwrite(g_builtin_operator_candidates,1,g_builtin_operator_candidate_count * 0x14,
           (FILE *)g_pch_file);
    g_pch_header.arenas_offset = ftell((FILE *)g_pch_file);
    pch_write_arenas(g_pch_file_name,g_pch_header.arenas_offset);
    if ((g_tmpl_definition_table == (c1_symtab *)0x0) && (PTR_104d1600 == (c1_symtab *)0x0)) {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x01';
    }
    g_pch_header.flags._0_1_ = cVar3 << 1 | (byte)g_pch_header.flags & 0xfd;
    rewind((FILE *)g_pch_file);
    _g_io_result = fwrite(&g_pch_header,0x68,1,(FILE *)g_pch_file);
    if (_g_io_result == 0xffffffff) {
      diag_fatal_file_errno(0x55,0x158,g_pch_file_name);
    }
    if (g_create_pch_header_name != (char *)0x0) {
      strncpy(g_pch_option_block_read.header_name,g_create_pch_header_name,0x104);
      g_pch_option_block_read.header_name[0x103] = '\0';
    }
    fwrite(&g_pch_option_block_read,1,0x38c,(FILE *)g_pch_file);
    g_pch_written = 1;
    iVar4 = fclose((FILE *)g_pch_file);
    _g_io_result = iVar4;
    if (iVar4 == -1) {
      iVar4 = diag_fatal_file_errno(0x52,0x158,g_pch_file_name);
    }
    iVar4 = CONCAT31((int3)((uint)iVar4 >> 8),cVar10);
    g_pch_file_unfinished = 0;
    if (cVar10 != '\0') {
      pch_declare_marker_variable();
      iVar4 = extraout_EAX_00;
    }
    if ((bVar2 != 0) &&
       (iVar4 = CONCAT31((int3)((uint)iVar4 >> 8),g_debug_types_in_pdb),
       g_debug_types_in_pdb == '\0')) {
      g_comment_record_kind = 7;
      g_comment_record_text = "\x03";
      il_emit_pragma_or_segment_record(0xb);
      iVar4 = extraout_EAX_01;
    }
    return iVar4;
  }
  diag_fatal(0x49);
}

