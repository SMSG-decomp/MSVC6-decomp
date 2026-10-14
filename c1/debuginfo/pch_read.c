void __cdecl pch_read(void)

{
  PDB *pPVar1;
  fe_pack_cell *pfVar2;
  fe_pack_cell *pfVar3;
  c1_u8 cVar4;
  byte bVar5;
  char cVar6;
  uint uVar7;
  fe_line_map_row *pfVar8;
  long _Offset;
  SIG SVar9;
  char *pcVar10;
  HANDLE pvVar11;
  BOOL BVar12;
  int *c;
  int iVar13;
  int iVar14;
  c1_u8 cVar15;
  uint *src;
  uint *cursor;
  int iVar16;
  char *pcVar17;
  byte bStack_23d;
  _FILETIME _Stack_230;
  uint *puStack_228;
  c1_u8 record_kind;
  uint file_pair [4];
  char acStack_200 [256];
  byte abStack_100 [256];
  int line;
  int line_2;
  int line_3;
  
  if ((g_opt_Zi == '\0') ||
     ((g_pch_option_block_read.pch_debug_in_object == '\0' &&
      ((g_auto_pch_using == 0 || (g_debug_types_in_pdb != '\0')))))) {
    cVar6 = '\0';
  }
  else {
    cVar6 = '\x01';
  }
  pch_reload_il_streams(cVar6);
  uVar7 = (*g_idb->vtbl->idb_pch_read)(g_idb,&g_ilstore_status);
  if (uVar7 == 0) {
    diag_fatal(0x49,".\\pch.c",0x46f);
  }
  il_emitter_select(g_ilstore_status == 5);
  if (g_line_map_cached_row.position == g_token_position) {
    pfVar8 = &g_line_map_cached_row;
  }
  else {
    pfVar8 = pp_line_map_find_entry(&g_line_map,g_token_position);
  }
  iVar14 = (pfVar8->line - pfVar8->position) + g_token_position;
  g_token_position = 0;
  if ((g_pch_header.records_size != 0) &&
     (_g_io_result = fseek(g_pch_file,g_pch_header.records_offset + g_pch_header.records_size,0),
     _g_io_result != 0)) {
    diag_fatal_file_errno(0x56,0x158,g_pch_file_name);
  }
  fread(&g_pch_option_block_read,1,900,g_pch_file);
  opt_unpack_optimize_flags(g_pch_option_block_read.optimize_word);
  if (g_pch_directive_mode == 2) {
    src = (uint *)&g_pch_option_block_read;
    cursor = &g_pch_option_block;
    for (iVar13 = 0xe1; iVar13 != 0; iVar13 = iVar13 + -1) {
      *cursor = *src;
      src = src + 1;
      cursor = cursor + 1;
    }
  }
  _Offset = ftell(g_pch_file);
  iVar13 = g_pack_stack->top->packing;
  uVar7 = g_compile_flags_c4 >> 0xf;
  fread(&g_pch_saved_globals,1,0x764,g_pch_file);
  g_compile_flags_c4 = (uint)((byte)uVar7 & 1) << 0xf | g_compile_flags_c4 & 0xffff7fff;
  if (g_debug_types_in_pdb != '\0') {
    if (g_pdb.pdb == (PDB *)0x0) {
      uVar7 = 0;
    }
    else {
      uVar7 = (*(g_pdb.pdb)->vtbl->QueryAge)(g_pdb.pdb);
    }
    if (g_pdb_age <= uVar7) {
      if (g_pdb.pdb == (PDB *)0x0) {
        SVar9 = 0;
      }
      else {
        SVar9 = (*(g_pdb.pdb)->vtbl->QuerySignature)(g_pdb.pdb);
      }
      if (SVar9 == g_pch_option_block_read.pdb_signature) goto LAB_1063fb25;
    }
    diag_error(0x35b,&g_pdb_file_name);
  }
LAB_1063fb25:
  if ((g_c9il_mode == '\0') && (g_split_pdbs != '\0')) {
    pPVar1 = g_pdb_gi->pdb;
    if (pPVar1 == (PDB *)0x0) {
      uVar7 = 0;
    }
    else {
      uVar7 = (*pPVar1->vtbl->QueryAge)(pPVar1);
    }
    if (g_pdb_gi_age <= uVar7) {
      pPVar1 = g_pdb_gi->pdb;
      if (pPVar1 == (PDB *)0x0) {
        SVar9 = 0;
      }
      else {
        SVar9 = (*pPVar1->vtbl->QuerySignature)(pPVar1);
      }
      if (SVar9 == g_pch_option_block_read.idb_signature) goto LAB_1063fba6;
    }
    if (g_split_pdbs == '\0') {
      pcVar10 = &g_pdb_file_name;
    }
    else {
      if (g_idb_file_name == '\0') {
        pdb_make_idb_name(&g_idb_file_name);
      }
      pcVar10 = &g_idb_file_name;
    }
    diag_error(0x35b,pcVar10);
  }
LAB_1063fba6:
  if ((((g_pch_option_block_read.name_sizes[1] != 0) &&
       (fread(abStack_100,1,(uint)g_pch_option_block_read.name_sizes[1],g_pch_file),
       g_browse_file != (char *)0x0)) && (g_pch_automatic == '\0')) && (g_auto_pch_using == 0)) {
    (*g_il_emitter->vtbl->pch_name)(abStack_100);
  }
  if (g_pch_option_block_read.name_sizes[0] != 0) {
    fread(abStack_100,1,(uint)g_pch_option_block_read.name_sizes & 0xffff,g_pch_file);
  }
  uVar7 = ftell(g_pch_file);
  bVar5 = pch_reload_arenas(g_pch_file_name,uVar7);
  if (bVar5 == 0) goto LAB_1063fd6f;
  puStack_228 = pair_init_zero_value(file_pair,(int)g_opt_source_file);
  record_kind = '\x15';
  line_map_set_cached_row((c1_lex_position_record *)&g_lex_position,&puStack_228);
  pvVar11 = (HANDLE)_get_osfhandle(g_pch_file->_file);
  BVar12 = GetFileTime(pvVar11,(LPFILETIME)0x0,(LPFILETIME)0x0,&_Stack_230);
  if ((BVar12 == 0) && (g_opt_nologo == '\0')) {
    pcVar17 = "\n";
    line = 0x38b;
    iVar16 = 0x100;
    pcVar10 = misc_string_get(0x386);
    format_snprintf(acStack_200,pcVar10,iVar16,line,pcVar17);
    diag_write_stderr(acStack_200);
  }
  _g_io_result = fclose(g_pch_file);
  if (_g_io_result == -1) {
    diag_fatal_file_errno(0x52,0x158,g_pch_file_name);
  }
  g_pch_file = fopen(g_pch_file_name,"rb+");
  if (g_pch_file == (FILE *)0x0) {
    if (g_opt_nologo == '\0') {
      pcVar17 = "\n";
      line_2 = 0x38a;
      iVar16 = 0x100;
      pcVar10 = misc_string_get(0x386);
      format_snprintf(acStack_200,pcVar10,iVar16,line_2,pcVar17);
LAB_1063fd5d:
      diag_write_stderr(acStack_200);
    }
  }
  else {
    _g_io_result = fseek(g_pch_file,_Offset,0);
    if (_g_io_result != 0) {
      diag_fatal_file_errno(0x52,0x158,g_pch_file_name);
    }
    _g_io_result = fwrite(&g_pch_saved_globals,1,0x764,g_pch_file);
    if (_g_io_result == 0xffffffff) {
      diag_fatal_file_errno(0x55,0x158,g_pch_file_name);
    }
    _g_io_result = fseek(g_pch_file,uVar7,0);
    if (_g_io_result != 0) {
      diag_fatal_file_errno(0x52,0x158,g_pch_file_name);
    }
    pch_heap_write_file(&g_pch_image);
    _g_io_result = fflush(g_pch_file);
    if (_g_io_result != 0) {
      diag_fatal_file_errno(0x58,0x158,g_pch_file_name);
    }
    if (BVar12 != 0) {
      pvVar11 = (HANDLE)_get_osfhandle(g_pch_file->_file);
      BVar12 = SetFileTime(pvVar11,(FILETIME *)0x0,(FILETIME *)0x0,&_Stack_230);
      if ((BVar12 == 0) && (g_opt_nologo == '\0')) {
        pcVar17 = "\n";
        line_3 = 0x38b;
        iVar16 = 0x100;
        pcVar10 = misc_string_get(0x386);
        format_snprintf(acStack_200,pcVar10,iVar16,line_3,pcVar17);
        goto LAB_1063fd5d;
      }
    }
  }
  line_map_clear_cached_row((c1_lex_position_record *)&g_lex_position);
LAB_1063fd6f:
  pools_reset();
  c = file_record_lookup_or_new(g_current_scope,g_opt_source_file,0);
  g_lex_position = g_lex_position + 1;
  vector_push_triple((int *)&g_line_map,g_lex_position,iVar14,(int)c);
  g_token_position = g_lex_position;
  pch_rebind_include_stack_files();
  browse_restart_region_after_pch();
  il_emitter_begin_region_at_top_level(g_ilstore_status == 5);
  cVar4 = g_pch_needs_symbol;
  bStack_23d = g_pch_needs_symbol;
  cVar15 = cVar4;
  if (g_opt_Zi != '\0') {
    if (g_pch_option_block_read.pch_debug_in_object == '\0') {
      if ((g_auto_pch_using == 0) || (g_debug_types_in_pdb != '\0')) {
        cVar15 = g_pch_needs_symbol;
        if ((g_pch_option_block_read.opt_Zi != '\0') && (g_object_file_name != (char *)0x0)) {
          cVar15 = '\x01';
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
        iVar14 = -1;
        pcVar10 = g_pch_option_block_read.yl_name;
        do {
          if (iVar14 == 0) break;
          iVar14 = iVar14 + -1;
          cVar6 = *pcVar10;
          pcVar10 = pcVar10 + 1;
        } while (cVar6 != '\0');
        if (iVar14 != -2) {
          bStack_23d = cVar4 | 1;
        }
      }
    }
    else {
      debug_begin('\x01');
    }
  }
  if (((cVar15 != '\0') && (g_opt_pch_types_in_pdb == '\0')) &&
     (cVar6 = file_name_equal((byte *)g_object_file_name,abStack_100), cVar6 != '\0')) {
    if (g_debug_types_in_pdb == '\0') {
      diag_warning(3,0x26e,g_object_file_name);
    }
    if (g_pch_needs_symbol != '\0') {
      diag_fatal(0x356,g_object_file_name);
    }
    iVar14 = -1;
    pcVar10 = g_opt_Yl_name;
    do {
      if (iVar14 == 0) break;
      iVar14 = iVar14 + -1;
      cVar6 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar6 != '\0');
    if (iVar14 != -2) {
      sym_new_builtin_variable();
    }
  }
  if ((bStack_23d != 0) && (g_pch_creating == 0)) {
    if (g_opt_pch_types_in_pdb == '\0') {
      pch_emit_pchsym_include_directive();
    }
    else {
      sym_new_builtin_variable();
    }
  }
  pch_check_defines();
  pfVar2 = g_pack_stack->top;
  for (pfVar3 = g_pack_stack->top->next; pfVar3 != (fe_pack_cell *)0x0; pfVar3 = pfVar3->next) {
    pfVar2 = pfVar3;
  }
  if (iVar13 != pfVar2->packing) {
    diag_warning(1,0x28d,0x196);
  }
  if (g_pch_creating == 0) {
    il_emit_end_of_globals();
    _g_io_result = fclose(g_pch_file);
    if (_g_io_result == -1) {
      diag_fatal_file_errno(0x52,0x158,g_pch_file_name);
    }
  }
  g_pch_file_name = (char *)0x0;
  if ((g_minimal_rebuild != '\0') || (g_opt_FD != '\0')) {
    pdb_gi_restore_pch_blob();
  }
  g_eh_declarations_injected = 1;
  return;
}

