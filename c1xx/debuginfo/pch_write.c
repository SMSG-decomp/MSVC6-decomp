void __cdecl pch_write(void)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  time_t tVar9;
  
  if ((g_pch_directive_mode == 0) && (-1 < g_pp_cond_depth)) {
    diag_error(0x358);
  }
  if ((uint)(1 < g_warnings_as_errors) + g_error_count != 0) {
    if (g_c9il_mode != '\0') {
      return;
    }
    pch_finish_il();
    return;
  }
  if (((byte)g_compile_flags_c4 & 0x20) != 0) {
    func_definition_end('\x01');
  }
  if (g_parse_context_depth != 0) {
    diag_fatal(1,".\\pch.c",0x826);
  }
  if (g_pch_create_explicit == 0) {
    tu_end_flush();
  }
  if (g_pch_object_has_code == 0) {
    if ((g_opt_Zi != '\0') && (g_pch_debug_in_object == '\0')) {
      iVar5 = -1;
      pcVar7 = g_pch_library_id;
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        cVar3 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar3 != '\0');
      if (iVar5 != -2) goto LAB_10487d96;
    }
    bVar1 = false;
  }
  else {
LAB_10487d96:
    bVar1 = true;
    pch_stream_name(g_string_literal_cur,g_object_file_name,g_pch_library_id);
    uVar4 = 0xffffffff;
    pcVar7 = g_string_literal_cur;
    do {
      pcVar8 = pcVar7;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar8 = pcVar7 + 1;
      cVar3 = *pcVar7;
      pcVar7 = pcVar8;
    } while (cVar3 != '\0');
    uVar4 = ~uVar4;
    pcVar7 = pcVar8 + -uVar4;
    pcVar8 = g_pch_symbol_name;
    for (uVar6 = uVar4 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar8 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar8 = pcVar8 + 1;
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
    iVar5 = -1;
    pcVar7 = g_object_file_name;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      cVar3 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar3 != '\0');
    g_pch_name_lengths.object_name_length = ~(ushort)iVar5;
  }
  if (g_browse_file != (char *)0x0) {
    iVar5 = -1;
    pcVar7 = g_opt_Fr_browse;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      cVar3 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar3 != '\0');
    g_pch_name_lengths.browse_name_length = ~(ushort)iVar5;
    if (g_pch_directive_mode == 0) {
      (*g_il_emitter->vtbl->pch_mark)();
    }
  }
  g_pch_header.flags._0_1_ =
       (byte)g_pch_header.flags ^ ((byte)g_pch_header.flags ^ g_opt_pch_types_in_pdb) & 1;
  tVar9 = time((time_t *)0x0);
  g_pch_header.time = (int)tVar9;
  if (((g_opt_pch_types_in_pdb != 0) && (g_opt_ZX == 0)) && (g_pdb.pdb != (c1xx_pdb *)0x0)) {
    pdb_record_pch_contribution(&g_pdb,g_pch_file_name,g_pch_header.time);
  }
  pch_write_file();
  uVar4 = (*g_idb->vtbl->idb_pch_written)(g_idb,&g_ilstore_status);
  if (uVar4 != 0) {
    il_emitter_begin_region_at_top_level(g_il_emitter,g_ilstore_status == 5);
    g_builtin_operator_candidate_count = builtin_operator_candidate_count();
    if ((g_pch_directive_mode == 1) || (g_auto_pch_creating != 0)) {
      init_write_reloc_record(0xc,0,0);
      free_list_mark_block_end(g_pch_record_list);
      _g_io_result = fflush((FILE *)g_pch_file);
      if (_g_io_result == -1) {
        diag_fatal_file_errno(0x58,0x158,g_pch_file_name);
      }
      iVar5 = ftell((FILE *)g_pch_file);
      _g_io_result = iVar5;
      if (iVar5 == -1) {
        iVar5 = diag_fatal_file_errno(0x57,0x158,g_pch_file_name);
      }
      g_pch_header.records_offset = iVar5;
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
    _g_io_result = fclose((FILE *)g_pch_file);
    if (_g_io_result == -1) {
      diag_fatal_file_errno(0x52,0x158,g_pch_file_name);
    }
    g_pch_file_unfinished = 0;
    if (bVar1) {
      pch_declare_marker_variable();
    }
    if ((bVar2 != 0) && (g_debug_types_in_pdb == '\0')) {
      g_comment_record_kind = 7;
      g_comment_record_text = "\x03";
      il_emit_pragma_or_segment_record(0xb);
    }
    return;
  }
  diag_fatal(0x49,".\\pch.c",0x884);
}

