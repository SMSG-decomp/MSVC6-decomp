void __cdecl opt_parse_command_line(int argc,char **argv)

{
  uint *puVar1;
  char cVar2;
  c1_u8 *pcVar3;
  c1xx_warning_state *pcVar4;
  char *file;
  byte *pbVar5;
  char *pcVar6;
  FILE *_File;
  c1_warning_record *pcVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  c1_u32 *object_name_src;
  c1_u32 *pcVar11;
  char *pcVar12;
  bool bVar13;
  int iVar14;
  char acStack_a08 [518];
  char acStack_802 [2050];
  void *next_argument_fn_2;
  void *next_argument_fn;
  
  decl_push_linkage_specification(0);
  if (g_include_alias_table == (void *)0x0) {
    include_alias_table_new();
  }
  crc16_tables_init();
  setlocale(2,"");
  lex_mark_mbcs_lead_bytes();
  file_name_case_table_init();
  if (1 < argc) {
    pcVar6 = argv[1];
    if (*pcVar6 == '@') {
      _File = fopen(pcVar6 + 1,"rt");
      if (_File == (FILE *)0x0) {
        diag_fatal_file_errno(0x54,0x151,argv[1] + 1);
        c1xx_raise_exit(1);
      }
      pcVar6 = fgets(acStack_802 + 2,0x800,_File);
      while (pcVar6 != (char *)0x0) {
        pcVar6 = acStack_802 + 2;
        if (acStack_802[2] != ';') {
          uVar8 = 0xffffffff;
          pcVar12 = acStack_802 + 2;
          do {
            if (uVar8 == 0) break;
            uVar8 = uVar8 - 1;
            cVar2 = *pcVar12;
            pcVar12 = pcVar12 + 1;
          } while (cVar2 != '\0');
          if (acStack_802[~uVar8] == '\n') {
            acStack_802[~uVar8] = '\0';
          }
          if (((acStack_802[2] == 'P') && (acStack_802[3] == '1')) && (acStack_802[4] == ':')) {
            pcVar6 = acStack_802 + 5;
          }
          pbVar5 = str_dup_arena(pcVar6,1);
          opt_parse_switch_string(pbVar5);
        }
        pcVar6 = fgets(acStack_802 + 2,0x800,_File);
      }
      fclose(_File);
    }
  }
  pbVar5 = (byte *)getenv("MSC_CMD_FLAGS");
  opt_parse_switch_string(pbVar5);
  pcVar3 = g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 0x3f4;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  if (pcVar3 == (c1_u8 *)0x0) {
    g_warning_state = (c1xx_warning_state *)0x0;
  }
  else {
    pcVar3[1000] = '\x01';
    pcVar3[0x3e9] = '\0';
    pcVar3[0x3ea] = '\0';
    pcVar3[0x3eb] = '\0';
    pcVar3[0x3ec] = '\0';
    pcVar3[0x3ed] = '\0';
    pcVar3[0x3ee] = '\0';
    pcVar3[0x3ef] = '\0';
    pcVar3[0x3f0] = '\0';
    pcVar3[0x3f1] = '\0';
    pcVar3[0x3f2] = '\0';
    pcVar3[0x3f3] = '\0';
    g_warning_state = (c1xx_warning_state *)pcVar3;
  }
  puVar10 = &g_default_warning_levels;
  do {
    pcVar4 = g_warning_state;
    uVar8 = *puVar10;
    uVar9 = puVar10[1];
    if (g_warning_state->saved != (c1_warning_record *)0x0) {
      if (g_warning_record_free_list == (c1_warning_record *)0x0) {
        pcVar7 = arena_alloc(g_arenas,8);
      }
      else {
        pcVar7 = g_warning_record_free_list;
        g_warning_record_free_list =
             (c1_warning_record *)(g_warning_record_free_list->next & 0xfffffffe);
      }
      if (pcVar7 == (c1_warning_record *)0x0) {
        pcVar7 = (c1_warning_record *)0x0;
      }
      else {
        cVar2 = pcVar4->state[uVar8];
        pcVar7->next = (uint)pcVar4->saved | 1;
        pcVar7->value = (int)cVar2 << 0x1c | uVar8;
      }
      pcVar4->saved = pcVar7;
    }
    pcVar4->state[uVar8] = (char)uVar9;
    if ((699 < uVar8) && (uVar8 < 1000)) {
      if (uVar8 <= g_warning_state_emit_min) {
        g_warning_state_emit_min = uVar8;
      }
      if (g_warning_state_emit_max <= uVar8) {
        g_warning_state_emit_max = uVar8;
      }
    }
    puVar1 = puVar10 + 2;
    puVar10 = puVar10 + 2;
  } while (*puVar1 != 0);
  g_define_list = vector_new(0x28,1);
  g_include_path_list = vector_new(0x28,1);
  g_forced_include_list = vector_new(0x28,1);
  if (g_c9il_mode == 0) {
    g_options_signature = SigForPbCb("CPP",3,g_options_signature);
  }
  iVar14 = 0;
  next_argument_fn = option_next_argument;
  pcVar6 = option_next_argument();
  for (iVar14 = opt_match_switch(g_switch_table,pcVar6,next_argument_fn,iVar14); iVar14 != 0;
      iVar14 = opt_match_switch(g_switch_table,pcVar6,next_argument_fn_2,iVar14)) {
    iVar14 = 0;
    next_argument_fn_2 = option_next_argument;
    pcVar6 = option_next_argument();
  }
  g_warning_state->level = g_opt_W_level;
  pcVar6 = file_make_canonical_path(acStack_a08,g_opt_Fd_pdb,0x208);
  if (pcVar6 == (char *)0x0) {
    diag_fatal(0x53,0x162,g_opt_Fd_pdb,0x4d,0x163);
  }
  uVar8 = 0xffffffff;
  pcVar6 = acStack_a08;
  do {
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    cVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar2 != '\0');
  if (0xff < ~uVar8 - 1) {
    diag_fatal_simple(5);
  }
  uVar8 = 0xffffffff;
  pcVar6 = acStack_a08;
  do {
    pcVar12 = pcVar6;
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    pcVar12 = pcVar6 + 1;
    cVar2 = *pcVar6;
    pcVar6 = pcVar12;
  } while (cVar2 != '\0');
  uVar8 = ~uVar8;
  pcVar6 = pcVar12 + -uVar8;
  pcVar12 = g_pdb_file_name;
  for (uVar9 = uVar8 >> 2; file = g_opt_Fo_object, uVar9 != 0; uVar9 = uVar9 - 1) {
    *(undefined4 *)pcVar12 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar12 = pcVar12 + 4;
  }
  bVar13 = g_opt_Fo_object != (char *)0x0;
  for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
    *pcVar12 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar12 = pcVar12 + 1;
  }
  if (bVar13) {
    pcVar6 = file_make_canonical_path(acStack_a08,file,0x208);
    pcVar11 = (c1_u32 *)g_arenas[1].cur;
    if (pcVar6 == (char *)0x0) {
      diag_fatal(0x53,0x162,g_opt_Fo_object,0x4d,0x163);
    }
    uVar8 = 0xffffffff;
    pcVar6 = acStack_a08;
    do {
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      cVar2 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar2 != '\0');
    g_arenas[1].cur = g_arenas[1].cur + (~uVar8 + 3 & 0xfffffffc);
    if (g_arenas[1].end < g_arenas[1].cur) {
      arena_grow(g_arenas + 1);
    }
    uVar8 = 0xffffffff;
    g_object_file_name = (char *)pcVar11;
    pcVar6 = acStack_a08;
    do {
      pcVar12 = pcVar6;
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      pcVar12 = pcVar6 + 1;
      cVar2 = *pcVar6;
      pcVar6 = pcVar12;
    } while (cVar2 != '\0');
    uVar8 = ~uVar8;
    object_name_src = (c1_u32 *)(pcVar12 + -uVar8);
    for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
      *pcVar11 = *object_name_src;
      object_name_src = object_name_src + 1;
      pcVar11 = pcVar11 + 1;
    }
    for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
      *(c1_u8 *)pcVar11 = (c1_u8)*object_name_src;
      object_name_src = (c1_u32 *)((int)object_name_src + 1);
      pcVar11 = (c1_u32 *)((int)pcVar11 + 1);
    }
  }
  if (g_opt_Z7 != '\0') {
    g_opt_Zi = '\x01';
    g_debug_types_in_pdb = '\0';
  }
  g_c9il_mode = g_c9il_mode | g_incremental == 0;
  g_opt_GFR = g_opt_GFR & g_incremental;
  g_pdb_gi = &g_pdb_split;
  if (g_split_pdbs == '\0') {
    g_pdb_gi = &g_pdb;
  }
  if (g_minimal_rebuild == '\0') {
    g_debug_types_in_pdb = g_debug_types_in_pdb & g_opt_Zi;
  }
  else {
    if (g_incremental == 0) {
      g_gm_forced_incremental = '\x01';
      g_incremental = 1;
      g_opt_GI = 1;
    }
    g_debug_types_in_pdb = '\x01';
  }
  if (g_opt_Jd != '\0') {
    lex_clear_lead_byte_classes();
  }
  if (g_pack_stack == (c1_pack_stack *)0x0) {
    pragma_pack_stack_init();
  }
  if (g_opt_Yl != (char *)0x0) {
    uVar8 = 0xffffffff;
    pcVar6 = g_opt_Yl;
    do {
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      cVar2 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar2 != '\0');
    if (0xff < ~uVar8 - 1) {
      diag_fatal_simple(5);
    }
    uVar8 = 0xffffffff;
    pcVar6 = g_opt_Yl;
    do {
      pcVar12 = pcVar6;
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      pcVar12 = pcVar6 + 1;
      cVar2 = *pcVar6;
      pcVar6 = pcVar12;
    } while (cVar2 != '\0');
    uVar8 = ~uVar8;
    pcVar6 = pcVar12 + -uVar8;
    pcVar12 = g_pch_library_id;
    for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
      *(undefined4 *)pcVar12 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar12 = pcVar12 + 4;
    }
    for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
      *pcVar12 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar12 = pcVar12 + 1;
    }
  }
  if (g_opt_unrecognized != 0) {
    diag_fatal(7,g_opt_unrecognized,"c1");
  }
  if (g_opt_source_file != 0) {
    if (g_create_pch_header_name == (char *)0x0) {
      if (g_pch_create == '\0') {
        g_opt_pch_types_in_pdb = 0;
      }
      if (g_opt_Yu_header != (char *)0x0) {
        g_use_pch = '\x01';
      }
    }
    else {
      g_pch_create = '\x01';
      if (g_opt_Yu_header != (char *)0x0) {
        opt_resolve_pch_switches(g_create_pch_header_name,g_opt_Yu_header,0);
        return;
      }
    }
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
      g_opt_Yu_header = (char *)0x0;
      g_pch_debug_in_object = '\0';
      g_opt_pch_types_in_pdb = 0;
    }
    if (g_switch_words != (char **)0x0) {
      mem_free(g_switch_words);
      g_switch_words = (char **)0x0;
    }
    return;
  }
  diag_fatal_simple(8);
}

