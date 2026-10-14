void __cdecl pch_write(void)

{
  char cVar1;
  bool bVar2;
  c1_u8 cVar3;
  int iVar4;
  uint uVar5;
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
  if (g_pch_needs_symbol == '\0') {
    if ((g_opt_Zi != '\0') && (g_pch_debug_in_object == '\0')) {
      iVar4 = -1;
      pcVar7 = g_opt_Yl_name;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      if (iVar4 != -2) goto LAB_1064136e;
    }
    bVar2 = false;
  }
  else {
LAB_1064136e:
    bVar2 = true;
    pch_stream_name(g_string_literal_cur,g_object_file_name,g_opt_Yl_name);
    uVar5 = 0xffffffff;
    pcVar7 = g_string_literal_cur;
    do {
      pcVar8 = pcVar7;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar8 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar8;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    pcVar7 = pcVar8 + -uVar5;
    pcVar8 = g_pch_symbol_name;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar8 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar8 = pcVar8 + 1;
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
    iVar4 = -1;
    pcVar7 = g_object_file_name;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    g_pch_saved_name_sizes[0] = ~(ushort)iVar4;
  }
  if (g_browse_file != (char *)0x0) {
    iVar4 = -1;
    pcVar7 = g_opt_Fr_browse;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    g_pch_saved_name_sizes[1] = ~(ushort)iVar4;
    if (g_pch_directive_mode == 0) {
      (*g_il_emitter->vtbl->pch_mark)();
    }
  }
  g_pch_header.flags._0_1_ =
       (byte)g_pch_header.flags ^ ((byte)g_pch_header.flags ^ g_opt_pch_types_in_pdb) & 1;
  tVar9 = time((time_t *)0x0);
  g_pch_header.time = (int)tVar9;
  if (((g_opt_pch_types_in_pdb != 0) && (g_opt_ZX == 0)) && (g_pdb.pdb != (PDB *)0x0)) {
    pdb_record_pch_contribution(&g_pdb,g_pch_file_name,g_pch_header.time);
  }
  pch_write_file();
  iVar4 = (*g_idb->vtbl->idb_pch_written)(g_idb,&g_ilstore_status);
  if (iVar4 != 0) {
    il_emitter_begin_region_at_top_level(g_ilstore_status == 5);
    if ((g_pch_directive_mode == 1) || (g_auto_pch_creating != 0)) {
      init_write_reloc_record(0xc,0,0);
      free_list_mark_block_end(g_pch_record_list);
      _g_io_result = fflush(g_pch_file);
      if (_g_io_result == -1) {
        diag_fatal_file_errno(0x58,0x158,g_pch_file_name);
      }
      iVar4 = ftell(g_pch_file);
      _g_io_result = iVar4;
      if (iVar4 == -1) {
        iVar4 = diag_fatal_file_errno(0x57,0x158,g_pch_file_name);
      }
      g_pch_header.records_offset = iVar4;
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
    if (bVar2) {
      sym_new_builtin_variable();
    }
    if ((cVar3 != '\0') && (g_debug_types_in_pdb == '\0')) {
      g_comment_record_kind = 7;
      g_comment_record_text = "\x03";
      il_emit_pragma_or_segment_record(0xb);
    }
    return;
  }
  diag_fatal(0x49,".\\pch.c",0x884);
}

