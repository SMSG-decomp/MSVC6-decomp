void __cdecl pch_creation_point(void)

{
  char cVar1;
  int iVar2;
  c1_u8 cVar3;
  char *pcVar4;
  char *fmt;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint *src;
  uint *dst;
  time_t tVar8;
  char *pcVar9;
  char acStack_100 [168];
  void *return_address;
  char cVar10;
  int line;
  
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
      return;
    }
    if ((g_pch_file_time_changed == '\0') && (*g_pch_record_cursor == 0xc)) {
      src = (uint *)&g_pch_header_read;
      dst = (uint *)&g_pch_header;
      for (iVar5 = 0x1a; iVar5 != 0; iVar5 = iVar5 + -1) {
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
        line = 0x15e;
        iVar5 = 0x100;
        pcVar4 = misc_string_get(0x386);
        format_snprintf(acStack_100,pcVar4,iVar5,line,pcVar9);
        diag_write_stderr(acStack_100);
      }
      return;
    }
    if (g_pch_header_read.include_key_alt == 0) {
      g_pch_header_read.include_key_alt = g_pch_header_read.include_key;
    }
    if (g_pch_auto_never_recreate == '\0') {
      if (((g_pch_include_count[1] == 0) ||
          ((g_pch_header_read.include_key << 7) / (int)(uint)(ushort)g_pch_include_count[1] < 100))
         || ((g_pch_header_read.include_key_alt << 7) / (int)(uint)(ushort)g_pch_include_count[1] <
             0x50)) {
        iVar5 = 0;
        iVar2 = *g_pch_record_cursor;
        while (iVar2 != 0xc) {
          if (iVar2 == 2) {
            iVar5 = iVar5 + 1;
          }
          g_pch_record_cursor = (int *)((int)g_pch_record_cursor + g_pch_record_cursor[1] + 0xc);
          iVar2 = *g_pch_record_cursor;
        }
        iVar5 = g_pch_include_count[0] + iVar5;
        if ((iVar5 == 0) || ((g_pch_include_count[0] * 100) / iVar5 < 0x46)) {
          g_pch_include_count[0] = -1;
        }
      }
    }
    else {
      g_pch_include_count[0] = -1;
    }
    if (g_opt_nologo == '\0') {
      if (g_pch_include_count[0] < 1) {
        pcVar4 = (char *)0x160;
        iVar5 = 0x100;
        pcVar9 = g_pch_file_name;
        fmt = misc_string_get(0x386);
      }
      else {
        pcVar9 = (char *)(int)g_pch_include_count[0];
        iVar5 = 0x100;
        pcVar4 = g_pch_file_name;
        fmt = misc_string_get(0x387);
      }
      format_snprintf(acStack_100,fmt,iVar5,pcVar4,pcVar9);
      uVar6 = 0xffffffff;
      pcVar4 = acStack_100;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar10 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar10 != '\0');
      g_pch_auto_note = mem_xmalloc(~uVar6);
      uVar6 = 0xffffffff;
      pcVar4 = acStack_100;
      do {
        pcVar9 = pcVar4;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar9 = pcVar4 + 1;
        cVar10 = *pcVar4;
        pcVar4 = pcVar9;
      } while (cVar10 != '\0');
      uVar6 = ~uVar6;
      pcVar4 = pcVar9 + -uVar6;
      pcVar9 = g_pch_auto_note;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar9 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar9 = pcVar9 + 1;
      }
    }
    pp_line_output_reset();
    pch_auto_start_recording();
    g_forced_include_index._0_2_ = 0;
    g_forced_include_files = g_forced_include_list;
    return;
  }
  if (-1 < g_pp_cond_depth) {
    diag_error(0x358);
  }
  if ((uint)(1 < g_warnings_as_errors) + g_error_count != 0) {
    if (g_c9il_mode != '\0') {
      return;
    }
    pch_finish_il();
    return;
  }
  if (g_pch_needs_symbol == '\0') {
    if ((g_opt_Zi != '\0') && (g_pch_debug_in_object == '\0')) {
      iVar5 = -1;
      pcVar4 = g_opt_Yl_name;
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        cVar10 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar10 != '\0');
      if (iVar5 != -2) goto LAB_1064136e;
    }
    cVar10 = '\0';
  }
  else {
LAB_1064136e:
    cVar10 = '\x01';
    pch_stream_name(g_string_literal_cur,g_object_file_name,g_opt_Yl_name);
    uVar6 = 0xffffffff;
    pcVar4 = g_string_literal_cur;
    do {
      pcVar9 = pcVar4;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar9 = pcVar4 + 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar9;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    pcVar4 = pcVar9 + -uVar6;
    pcVar9 = g_pch_symbol_name;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar9 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar9 = pcVar9 + 1;
    }
  }
  cVar3 = g_pch_precomp_types;
  if (g_pch_precomp_types != '\0') {
    pch_write_end_precomp_types();
  }
  PTR_1065d414 = vector_copy(g_include_path_list,0,str_dup_arena);
  PTR_1065d410 = vector_copy(g_define_list,0,str_dup_arena);
  if ((g_minimal_rebuild != '\0') || (g_opt_FD != '\0')) {
    pdb_gi_read_blob_for_pch();
  }
  if (g_object_file_name != (char *)0x0) {
    iVar5 = -1;
    pcVar4 = g_object_file_name;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    g_pch_saved_name_sizes[0] = ~(ushort)iVar5;
  }
  if (g_browse_file != (char *)0x0) {
    iVar5 = -1;
    pcVar4 = g_opt_Fr_browse;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    g_pch_saved_name_sizes[1] = ~(ushort)iVar5;
    if (g_pch_directive_mode == 0) {
      (*g_il_emitter->vtbl->pch_mark)();
    }
  }
  g_pch_header.flags._0_1_ =
       (byte)g_pch_header.flags ^ ((byte)g_pch_header.flags ^ g_opt_pch_types_in_pdb) & 1;
  tVar8 = time((time_t *)0x0);
  g_pch_header.time = (int)tVar8;
  if (((g_opt_pch_types_in_pdb != 0) && (g_opt_ZX == 0)) && (g_pdb.pdb != (PDB *)0x0)) {
    pdb_record_pch_contribution(&g_pdb,g_pch_file_name,g_pch_header.time);
  }
  pch_write_file();
  iVar5 = (*g_idb->vtbl->idb_pch_written)(g_idb,&g_ilstore_status);
  if (iVar5 != 0) {
    il_emitter_begin_region_at_top_level(g_ilstore_status == 5);
    if ((g_pch_directive_mode == 1) || (g_auto_pch_creating != 0)) {
      init_write_reloc_record(0xc,0,0);
      free_list_mark_block_end(g_pch_record_list);
      _g_io_result = fflush(g_pch_file);
      if (_g_io_result == -1) {
        diag_fatal_file_errno(0x58,0x158,g_pch_file_name);
      }
      iVar5 = ftell(g_pch_file);
      _g_io_result = iVar5;
      if (iVar5 == -1) {
        iVar5 = diag_fatal_file_errno(0x57,0x158,g_pch_file_name);
      }
      g_pch_header.records_offset = iVar5;
      g_pch_header.records_size =
           pch_write_blocks(g_pch_record_list,g_pch_file,(c1_byte_block_list *)0x0);
    }
    g_pch_optimize_word = il_function_option_word();
    _g_io_result = fwrite(&g_pch_option_block,1,900,g_pch_file);
    if (_g_io_result == 0xffffffff) {
      diag_fatal_file_errno(0x55,0x158,g_pch_file_name);
    }
    fwrite(&g_pch_saved_globals,1,0x764,g_pch_file);
    fwrite(g_browse_file,1,(uint)g_pch_saved_name_sizes >> 0x10,g_pch_file);
    fwrite(g_object_file_name,1,(uint)g_pch_saved_name_sizes & 0xffff,g_pch_file);
    g_pch_header.arenas_offset = ftell(g_pch_file);
    pch_write_arenas(g_pch_file_name,g_pch_header.arenas_offset);
    return_address = (void *)0x10641286;
    rewind(g_pch_file);
    _g_io_result = fwrite(&g_pch_header,0x68,1,g_pch_file);
    if (_g_io_result == 0xffffffff) {
      diag_fatal_file_errno(0x55,0x158,g_pch_file_name);
    }
    if (g_create_pch_header_name != (char *)0x0) {
      strncpy(g_pch_option_block_read.header_file_name,g_create_pch_header_name,0x104);
      g_pch_option_block_read.header_file_name[0x103] = '\0';
    }
    fwrite(&g_pch_option_block_read,1,900,g_pch_file);
    g_pch_written = '\x01';
    _g_io_result = fclose(g_pch_file);
    if (_g_io_result == -1) {
      diag_fatal_file_errno(0x52,0x158,g_pch_file_name);
    }
    g_pch_file_unfinished = '\0';
    if (cVar10 != '\0') {
      sym_new_builtin_variable();
    }
    if ((cVar3 != '\0') && (g_debug_types_in_pdb == '\0')) {
      g_comment_record_kind = 7;
      g_comment_record_text = "\x03";
      il_emit_pragma_or_segment_record(0xb);
    }
    return;
  }
  diag_fatal(0x49);
}

