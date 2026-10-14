void __cdecl opt_parse_command_line(int argc,char **argv)

{
  c1_warning_default *pcVar1;
  fe_warning_state *pfVar2;
  char cVar3;
  byte *pbVar4;
  char *pcVar5;
  FILE *_File;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  uchar *puVar9;
  char *pcVar10;
  uchar *puVar11;
  fe_warning_record *record;
  code *pcVar12;
  int iVar13;
  c1_warning_default *local_a10;
  char local_a0c;
  char acStack_a08 [518];
  char acStack_802 [2050];
  
  if (g_include_alias_table == (c1_include_alias **)0x0) {
    include_alias_table_new();
  }
  crc16_tables_init();
  setlocale(2,"");
  lex_mark_mbcs_lead_bytes();
  file_name_case_table_init();
  if (1 < argc) {
    pcVar5 = argv[1];
    if (*pcVar5 == '@') {
      _File = fopen(pcVar5 + 1,"rt");
      if (_File == (FILE *)0x0) {
        diag_fatal_file_errno(0x54,0x151,argv[1] + 1);
        c1_raise_exit(1);
      }
      pcVar5 = fgets(acStack_802 + 2,0x800,_File);
      while (pcVar5 != (char *)0x0) {
        pcVar5 = acStack_802 + 2;
        if (acStack_802[2] != ';') {
          uVar6 = 0xffffffff;
          pcVar8 = acStack_802 + 2;
          do {
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            cVar3 = *pcVar8;
            pcVar8 = pcVar8 + 1;
          } while (cVar3 != '\0');
          if (acStack_802[~uVar6] == '\n') {
            acStack_802[~uVar6] = '\0';
          }
          if (((acStack_802[2] == 'P') && (acStack_802[3] == '1')) && (acStack_802[4] == ':')) {
            pcVar5 = acStack_802 + 5;
          }
          pbVar4 = str_dup_arena(pcVar5,1);
          opt_parse_switch_string(pbVar4);
        }
        pcVar5 = fgets(acStack_802 + 2,0x800,_File);
      }
      fclose(_File);
    }
  }
  pbVar4 = (byte *)getenv("MSC_CMD_FLAGS");
  opt_parse_switch_string(pbVar4);
  puVar11 = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 0x3f4;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  if (puVar11 == (uchar *)0x0) {
    g_warning_state = (fe_warning_state *)0x0;
  }
  else {
    puVar11[1000] = '\x01';
    puVar11[0x3e9] = '\0';
    puVar11[0x3ea] = '\0';
    puVar11[0x3eb] = '\0';
    puVar11[0x3ec] = '\0';
    puVar11[0x3ed] = '\0';
    puVar11[0x3ee] = '\0';
    puVar11[0x3ef] = '\0';
    puVar11[0x3f0] = '\0';
    puVar11[0x3f1] = '\0';
    puVar11[0x3f2] = '\0';
    puVar11[0x3f3] = '\0';
    g_warning_state = (fe_warning_state *)puVar11;
  }
  local_a10 = g_warning_defaults;
  do {
    pfVar2 = g_warning_state;
    uVar6 = local_a10->number;
    uVar7 = local_a10->state;
    if (g_warning_state->saved != (fe_warning_record *)0x0) {
      if (g_warning_record_free_list == (fe_warning_record *)0x0) {
        record = arena_alloc(g_arenas,8);
      }
      else {
        record = g_warning_record_free_list;
        g_warning_record_free_list =
             (fe_warning_record *)(g_warning_record_free_list->next & 0xfffffffe);
      }
      if (record == (fe_warning_record *)0x0) {
        record = (fe_warning_record *)0x0;
      }
      else {
        cVar3 = pfVar2->state[uVar6];
        pragma_warning_record_set_link(&record->next,(uint)pfVar2->saved,0);
        record->value = (int)cVar3 << 0x1c | uVar6;
      }
      pfVar2->saved = record;
    }
    local_a0c = (char)uVar7;
    pfVar2->state[uVar6] = local_a0c;
    if ((699 < uVar6) && (uVar6 < 1000)) {
      if (uVar6 <= g_warning_state_emit_min) {
        g_warning_state_emit_min = uVar6;
      }
      if (g_warning_state_emit_max <= uVar6) {
        g_warning_state_emit_max = uVar6;
      }
    }
    pcVar1 = local_a10 + 1;
    local_a10 = local_a10 + 1;
  } while (pcVar1->number != 0);
  g_define_list = vector_new(0x28,1);
  g_include_path_list = vector_new(0x28,1);
  g_forced_include_list = vector_new(0x28,1);
  if (g_c9il_mode == 0) {
    g_options_signature = SigForPbCb("C",1,g_options_signature);
  }
  iVar13 = 0;
  pcVar12 = option_next_argument;
  pcVar5 = option_next_argument();
  for (iVar13 = opt_match_switch(g_switch_table,pcVar5,pcVar12,iVar13); iVar13 != 0;
      iVar13 = opt_match_switch(g_switch_table,pcVar5,pcVar12,iVar13)) {
    iVar13 = 0;
    pcVar12 = option_next_argument;
    pcVar5 = option_next_argument();
  }
  g_warning_state->level = g_opt_W_level;
  iVar13 = file_make_canonical_path(acStack_a08,PTR_s_vc60_pdb_1065df24,0x208);
  pcVar5 = g_opt_Fo_name;
  if (iVar13 == 0) {
    diag_fatal(0x53,0x162,PTR_s_vc60_pdb_1065df24,0x4d,0x163);
  }
  uVar6 = 0xffffffff;
  pcVar8 = acStack_a08;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar3 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar3 != '\0');
  if (0xff < ~uVar6 - 1) {
    diag_fatal_simple(5);
  }
  uVar6 = 0xffffffff;
  pcVar8 = acStack_a08;
  do {
    pcVar10 = pcVar8;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar10 = pcVar8 + 1;
    cVar3 = *pcVar8;
    pcVar8 = pcVar10;
  } while (cVar3 != '\0');
  uVar6 = ~uVar6;
  pcVar8 = pcVar10 + -uVar6;
  pcVar10 = &g_pdb_file_name;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar10 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
    pcVar10 = pcVar10 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar10 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar10 = pcVar10 + 1;
  }
  if (pcVar5 != (char *)0x0) {
    iVar13 = file_make_canonical_path(acStack_a08,pcVar5,0x208);
    puVar11 = g_arenas[1].cur;
    if (iVar13 == 0) {
      diag_fatal(0x53,0x162,g_opt_Fo_name,0x4d,0x163);
    }
    uVar6 = 0xffffffff;
    pcVar5 = acStack_a08;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar3 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar3 != '\0');
    g_arenas[1].cur = g_arenas[1].cur + (~uVar6 + 3 & 0xfffffffc);
    if (g_arenas[1].end < g_arenas[1].cur) {
      arena_grow(g_arenas + 1);
    }
    uVar6 = 0xffffffff;
    g_object_file_name = (char *)puVar11;
    pcVar5 = acStack_a08;
    do {
      pcVar8 = pcVar5;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar8 = pcVar5 + 1;
      cVar3 = *pcVar5;
      pcVar5 = pcVar8;
    } while (cVar3 != '\0');
    uVar6 = ~uVar6;
    puVar9 = (uchar *)(pcVar8 + -uVar6);
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)puVar11 = *(undefined4 *)puVar9;
      puVar9 = puVar9 + 4;
      puVar11 = puVar11 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar11 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar11 = puVar11 + 1;
    }
  }
  if (g_opt_Z7 != 0) {
    g_opt_Zi = '\x01';
    g_debug_types_in_pdb = '\0';
  }
  g_c9il_mode = g_c9il_mode | g_incremental == '\0';
  g_opt_GFR = g_opt_GFR & g_incremental;
  g_pdb_gi = &g_pdb_split;
  if (g_split_pdbs == '\0') {
    g_pdb_gi = &g_pdb;
  }
  g_debug_types_in_pdb = g_debug_types_in_pdb & g_opt_Zi;
  if (g_opt_Jd != '\0') {
    lex_clear_lead_byte_classes();
  }
  if (g_pack_stack == (fe_pack_stack *)0x0) {
    pragma_pack_stack_init();
  }
  if (g_opt_Yl_symbol != (char *)0x0) {
    uVar6 = 0xffffffff;
    pcVar5 = g_opt_Yl_symbol;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar3 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar3 != '\0');
    if (0xff < ~uVar6 - 1) {
      diag_fatal_simple(5);
    }
    uVar6 = 0xffffffff;
    pcVar5 = g_opt_Yl_symbol;
    do {
      pcVar8 = pcVar5;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar8 = pcVar5 + 1;
      cVar3 = *pcVar5;
      pcVar5 = pcVar8;
    } while (cVar3 != '\0');
    uVar6 = ~uVar6;
    pcVar5 = pcVar8 + -uVar6;
    pcVar8 = g_opt_Yl_name;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar8 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar8 = pcVar8 + 1;
    }
  }
  if (g_unknown_option != (char *)0x0) {
    diag_fatal(7,g_unknown_option,"c1");
  }
  if (g_opt_source_file == 0) {
    diag_fatal_simple(8);
  }
  if (g_create_pch_header_name != (char *)0x0) {
    g_pch_create = '\x01';
    if (g_use_pch_header_name == (char *)0x0) goto LAB_10612c52;
    cVar3 = file_name_equal((byte *)g_create_pch_header_name,(byte *)g_use_pch_header_name);
    if (cVar3 != '\0') {
      g_use_pch = '\0';
      g_use_pch_header_name = (char *)0x0;
    }
  }
  if (g_pch_create == '\0') {
    g_opt_pch_types_in_pdb = 0;
  }
  if (g_use_pch_header_name != (char *)0x0) {
    g_use_pch = '\x01';
  }
LAB_10612c52:
  if (g_opt_YX_header != 0) {
    g_pch_automatic = '\x01';
  }
  g_pch_debug_in_object = g_pch_debug_in_object | g_pch_automatic;
  if ((g_opt_E_preprocess != 0) || (g_opt_Zg != '\0')) {
    g_pch_automatic = '\0';
    g_opt_YX_header = 0;
    g_pch_create = '\0';
    g_create_pch_header_name = (char *)0x0;
    g_use_pch = '\0';
    g_use_pch_header_name = (char *)0x0;
    g_pch_debug_in_object = '\0';
    g_opt_pch_types_in_pdb = 0;
  }
  if (g_switch_words != (char **)0x0) {
    mem_free(g_switch_words);
    g_switch_words = (char **)0x0;
  }
  return;
}

