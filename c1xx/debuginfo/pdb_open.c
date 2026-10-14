void __cdecl pdb_open(void)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint age;
  uint signature;
  char *pcVar4;
  c1_line_map_row *pcVar5;
  uint incremental_flag;
  int options_result;
  
  if (((g_opt_E_preprocess == 0) || (g_opt_FD != '\0')) && (g_opt_Zg == '\0')) {
    if (g_batch_continuing == '\0') {
      if (g_split_pdbs == '\0') {
        if (((g_debug_types_in_pdb != '\0') || (g_c9il_mode == '\0')) ||
           ((g_incremental != '\0' || ((g_minimal_rebuild == '\0' || (g_opt_FD == '\0')))))) {
          pcVar4 = "ri";
          if (g_opt_ZX == 0) {
            pcVar4 = "i";
          }
          bVar1 = pdb_open_validated(&g_pdb,g_pdb_file_name,&g_pdb_signature,&g_pdb_age,0x1000,
                                     pcVar4);
          if (bVar1 == 0) {
            pcVar4 = g_pdb_file_name;
            goto LAB_10485349;
          }
        }
      }
      else {
        if ((g_debug_types_in_pdb != '\0') && (g_opt_E_preprocess == 0)) {
          pcVar4 = "ri";
          if (g_opt_ZX == 0) {
            pcVar4 = "i";
          }
          bVar1 = pdb_open_validated(&g_pdb,g_pdb_file_name,&g_pdb_signature,&g_pdb_age,0x1000,
                                     pcVar4);
          if (bVar1 == 0) {
            diag_fatal_file_errno(0x53,0x162,g_pdb_file_name);
          }
        }
        if (g_split_pdbs == '\0') {
          pcVar4 = g_pdb_file_name;
        }
        else {
          if (g_idb_file_name == '\0') {
            pdb_make_idb_name(&g_idb_file_name);
          }
          pcVar4 = &g_idb_file_name;
        }
        iVar3 = _strnicmp(g_pdb_file_name,pcVar4,0x100);
        if (iVar3 == 0) {
          diag_fatal(0x4a,g_pdb_file_name);
        }
        if ((((g_c9il_mode == '\0') || (g_incremental != '\0')) || (g_minimal_rebuild != '\0')) ||
           ((g_opt_FD != '\0' || (g_opt_ZI != '\0')))) {
          if (g_split_pdbs == '\0') {
            pcVar4 = g_pdb_file_name;
          }
          else {
            if (g_idb_file_name == '\0') {
              pdb_make_idb_name(&g_idb_file_name);
            }
            pcVar4 = &g_idb_file_name;
          }
          bVar1 = pdb_open_validated(g_pdb_gi,pcVar4,&g_pdb_gi_signature,&g_pdb_gi_age,0x400,
                                     (char *)0x0);
          if (bVar1 == 0) {
            if (g_split_pdbs == '\0') {
              pcVar4 = g_pdb_file_name;
            }
            else {
              if (g_idb_file_name == '\0') {
                pdb_make_idb_name(&g_idb_file_name);
              }
              pcVar4 = &g_idb_file_name;
            }
LAB_10485349:
            diag_fatal_file_errno(0x53,0x162,pcVar4);
          }
        }
      }
      if ((g_c9il_mode == '\0') || (g_incremental != '\0')) {
        iVar3 = NameMap::open((PDB *)g_pdb_gi->pdb,1,(NameMap **)&g_pdb_gi->namemap);
        if (iVar3 == 0) {
          if (g_split_pdbs == '\0') {
            pcVar4 = g_pdb_file_name;
          }
          else {
            if (g_idb_file_name == '\0') {
              pdb_make_idb_name(&g_idb_file_name);
            }
            pcVar4 = &g_idb_file_name;
          }
          diag_fatal_file_errno(0x53,0x162,pcVar4);
        }
      }
      else if (g_opt_ZI != '\0') {
        pdb_open_idb(incremental_flag,options_result);
        return;
      }
    }
    if (g_c9il_mode == '\0') {
      ilstore_open(g_pdb_gi->pdb);
    }
  }
  if ((g_incremental == '\0') || (g_opt_E_preprocess != 0)) {
LAB_104479a3:
    incremental_flag = incremental_flag & 0xffffff00;
  }
  else {
    incremental_flag = CONCAT31(incremental_flag._1_3_,1);
    if (g_opt_Zg != '\0') goto LAB_104479a3;
  }
  iVar3 = pdb_open_file(g_pdb_gi->pdb,0,g_pdb_gi->namemap,g_opt_source_file,g_object_file_name,
                        g_source_tracker_iface,incremental_flag & 0xff,0,0,&g_idb);
  if (iVar3 == 0) {
    diag_fatal(0x49,".\\main.c",0x275);
  }
  iVar3 = (*g_idb->vtbl->idb_check_options)(g_idb,g_options_signature,&options_result);
  if (iVar3 == 0) {
    diag_fatal(0x49,".\\main.c",0x27a);
  }
  if (options_result != 2) {
    _unlink(g_object_file_name);
  }
  if (g_debug_types_in_pdb == '\0') goto LAB_10447a63;
  if (g_pdb.pdb == (c1xx_pdb *)0x0) {
    age = 0;
LAB_104854b9:
    signature = 0;
  }
  else {
    age = (*(g_pdb.pdb)->vtbl->query_age)(g_pdb.pdb);
    if (g_pdb.pdb == (c1xx_pdb *)0x0) goto LAB_104854b9;
    signature = (*(g_pdb.pdb)->vtbl->query_signature)(g_pdb.pdb);
  }
  iVar3 = (*g_idb->vtbl->idb_set_pdb_signature)(g_idb,signature,age);
  if (iVar3 == 0) {
    diag_fatal(0x49,".\\main.c",0x289);
  }
LAB_10447a63:
  if ((g_opt_GI != '\0') || (g_opt_Z7 != '\0')) {
    (*g_idb->vtbl->idb_force_recompile)(g_idb);
  }
  if (g_gm_forced_incremental != '\0') {
    (*g_idb->vtbl->idb_disable_incremental)(g_idb);
  }
  if ((g_minimal_rebuild != '\0') || (g_opt_FD != '\0')) {
    pdb_open_for_minimal_rebuild(g_minimal_rebuild_tracker,g_opt_source_file);
    bVar1 = 1;
    iVar3 = -1;
    pcVar4 = pp_position_file_name(&g_token_position);
    pdb_source_file_push(g_minimal_rebuild_tracker,pcVar4,iVar3,bVar1);
    if (g_minimal_rebuild != '\0') {
      incremental_flag = 0;
      cVar2 = pdb_file_stack_top_object(g_minimal_rebuild_tracker,(c1_mre_file **)&incremental_flag)
      ;
      if ((cVar2 != '\0') &&
         (iVar3 = (*g_idb->vtbl->idb_set_tracker)(g_idb,(c1_mre_file *)incremental_flag), iVar3 == 0
         )) {
        diag_fatal(0x49,".\\main.c",0x2a8);
      }
    }
  }
  g_il_emitter = il_emitter_get_preferred();
  if ((g_use_pch == '\0') && (g_pch_automatic == '\0')) {
    iVar3 = (*g_idb->vtbl->idb_begin_unit)(g_idb,&g_ilstore_status);
    if (iVar3 == 0) {
      diag_fatal(0x49,".\\main.c",0x2b6);
    }
    if (((g_pch_creating != 0) || (g_ilstore_status != 1)) ||
       (cVar2 = (*g_il_emitter->vtbl->reopen)(g_il_emitter), cVar2 == '\0')) {
      (*g_il_emitter->vtbl->open)(g_il_emitter);
    }
  }
  else {
    iVar3 = (*g_idb->vtbl->idb_begin_unit_no_check)(g_idb,&g_ilstore_status);
    if (iVar3 == 0) {
      diag_fatal(0x49,".\\main.c",0x2b2);
    }
  }
  if (g_use_pch == '\0') {
    il_emitter_begin_region_at_top_level(g_il_emitter,g_ilstore_status == 5);
    return;
  }
  if (g_line_map_cached_row.position == g_token_position) {
    pcVar5 = &g_line_map_cached_row;
  }
  else {
    pcVar5 = pp_line_map_find_entry(&g_line_map,g_token_position);
  }
  iVar3 = (pcVar5->line - pcVar5->position) + g_token_position;
  if (g_line_map_cached_row.position == g_token_position) {
    pcVar5 = &g_line_map_cached_row;
  }
  else {
    pcVar5 = pp_line_map_find_entry(&g_line_map,g_token_position);
  }
  g_lex_position = g_lex_position + 1;
  vector_push_triple((int *)&g_line_map,g_lex_position,0,(int)pcVar5->file);
  g_token_position = g_lex_position;
  il_emitter_begin_region_at_top_level(g_il_emitter,g_ilstore_status == 5);
  if (g_line_map_cached_row.position == g_token_position) {
    pcVar5 = &g_line_map_cached_row;
  }
  else {
    pcVar5 = pp_line_map_find_entry(&g_line_map,g_token_position);
  }
  g_lex_position = g_lex_position + 1;
  vector_push_triple((int *)&g_line_map,g_lex_position,iVar3,(int)pcVar5->file);
  g_token_position = g_lex_position;
  return;
}

