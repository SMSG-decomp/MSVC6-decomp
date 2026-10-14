void __cdecl pdb_open(void)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  int iVar4;
  AGE age;
  SIG signature;
  fe_line_map_row *pfVar5;
  c1_u8 by_handle;
  int local_8;
  int local_4;
  
  if (((g_opt_E_preprocess == 0) || (g_opt_FD != '\0')) && (g_opt_Zg == '\0')) {
    if (g_batch_continuing == '\0') {
      if (g_split_pdbs == '\0') {
        if (((g_debug_types_in_pdb != '\0') || (g_c9il_mode == '\0')) ||
           ((g_incremental != '\0' || ((g_minimal_rebuild == '\0' || (g_opt_FD == '\0')))))) {
          pcVar3 = "ri";
          if (g_opt_ZX == 0) {
            pcVar3 = "i";
          }
          bVar2 = pdb_open_validated(&g_pdb,&g_pdb_file_name,(int *)&g_pdb_signature,
                                     (int *)&g_pdb_age,0x1000,pcVar3);
          if (bVar2 == 0) {
            pcVar3 = &g_pdb_file_name;
            goto LAB_1063dadb;
          }
        }
      }
      else {
        if ((g_debug_types_in_pdb != '\0') && (g_opt_E_preprocess == 0)) {
          pcVar3 = "ri";
          if (g_opt_ZX == 0) {
            pcVar3 = "i";
          }
          bVar2 = pdb_open_validated(&g_pdb,&g_pdb_file_name,(int *)&g_pdb_signature,
                                     (int *)&g_pdb_age,0x1000,pcVar3);
          if (bVar2 == 0) {
            diag_fatal_file_errno(0x53,0x162,&g_pdb_file_name);
          }
        }
        if (g_split_pdbs == '\0') {
          pcVar3 = &g_pdb_file_name;
        }
        else {
          if (g_idb_file_name == '\0') {
            pdb_make_idb_name(&g_idb_file_name);
          }
          pcVar3 = &g_idb_file_name;
        }
        iVar4 = _strnicmp(&g_pdb_file_name,pcVar3,0x100);
        if (iVar4 == 0) {
          diag_fatal(0x4a,&g_pdb_file_name);
        }
        if ((((g_c9il_mode == '\0') || (g_incremental != '\0')) || (g_minimal_rebuild != '\0')) ||
           ((g_opt_FD != '\0' || (g_opt_ZI != '\0')))) {
          if (g_split_pdbs == '\0') {
            pcVar3 = &g_pdb_file_name;
          }
          else {
            if (g_idb_file_name == '\0') {
              pdb_make_idb_name(&g_idb_file_name);
            }
            pcVar3 = &g_idb_file_name;
          }
          bVar2 = pdb_open_validated(g_pdb_gi,pcVar3,(int *)&g_pdb_gi_signature,(int *)&g_pdb_gi_age
                                     ,0x400,(char *)0x0);
          if (bVar2 == 0) {
            if (g_split_pdbs == '\0') {
              pcVar3 = &g_pdb_file_name;
            }
            else {
              if (g_idb_file_name == '\0') {
                pdb_make_idb_name(&g_idb_file_name);
              }
              pcVar3 = &g_idb_file_name;
            }
LAB_1063dadb:
            diag_fatal_file_errno(0x53,0x162,pcVar3);
          }
        }
      }
      if ((((g_c9il_mode == '\0') || (g_incremental != '\0')) || (g_opt_ZI != '\0')) &&
         (iVar4 = NameMap::open((PDB *)g_pdb_gi->pdb,1,(NameMap **)&g_pdb_gi->name_map), iVar4 == 0)
         ) {
        if (g_split_pdbs == '\0') {
          pcVar3 = &g_pdb_file_name;
        }
        else {
          if (g_idb_file_name == '\0') {
            pdb_make_idb_name(&g_idb_file_name);
          }
          pcVar3 = &g_idb_file_name;
        }
        diag_fatal_file_errno(0x53,0x162,pcVar3);
      }
    }
    if (g_c9il_mode == '\0') {
      ilstore_open(g_pdb_gi->pdb);
    }
  }
  if (((g_incremental == '\0') || (g_opt_E_preprocess != 0)) || (local_8 = 1, g_opt_Zg != '\0')) {
    local_8 = 0;
  }
  iVar4 = pdb_open_file(g_pdb_gi->pdb,(PDB *)0x0,g_pdb_gi->name_map,g_opt_source_file,
                        g_object_file_name,g_source_tracker_iface,local_8,0,0,&g_idb);
  if (iVar4 == 0) {
    diag_fatal(0x49,".\\main.c",0x275);
  }
  iVar4 = (*g_idb->vtbl->idb_check_options)(g_idb,g_options_signature,&local_4);
  if (iVar4 == 0) {
    diag_fatal(0x49,".\\main.c",0x27a);
  }
  if (local_4 != 2) {
    _unlink(g_object_file_name);
  }
  if (g_debug_types_in_pdb == '\0') goto LAB_10614ea5;
  if (g_pdb.pdb == (PDB *)0x0) {
    age = 0;
LAB_1063dc4b:
    signature = 0;
  }
  else {
    age = (*(g_pdb.pdb)->vtbl->QueryAge)(g_pdb.pdb);
    if (g_pdb.pdb == (PDB *)0x0) goto LAB_1063dc4b;
    signature = (*(g_pdb.pdb)->vtbl->QuerySignature)(g_pdb.pdb);
  }
  iVar4 = (*g_idb->vtbl->idb_set_pdb_signature)(g_idb,signature,age);
  if (iVar4 == 0) {
    diag_fatal(0x49,".\\main.c",0x289);
  }
LAB_10614ea5:
  if ((g_opt_GI != '\0') || (g_opt_Z7 != 0)) {
    (*g_idb->vtbl->idb_force_recompile)(g_idb);
  }
  if ((g_minimal_rebuild != '\0') || (g_opt_FD != '\0')) {
    pdb_open_for_minimal_rebuild((c1_pdb_state *)g_pdb_file_stack,g_opt_source_file);
    by_handle = '\x01';
    iVar4 = -1;
    pcVar3 = pp_position_file_name(&g_token_position);
    pdb_file_stack_push(g_pdb_file_stack,pcVar3,iVar4,by_handle);
    if (g_minimal_rebuild != '\0') {
      pdb_open_fragment();
      return;
    }
  }
  g_il_emitter = il_emitter_get_preferred();
  if ((g_use_pch == '\0') && (g_pch_automatic == '\0')) {
    iVar4 = (*g_idb->vtbl->idb_begin_unit)(g_idb,&g_ilstore_status);
    if (iVar4 == 0) {
      diag_fatal(0x49,".\\main.c",0x2b6);
    }
    if (((g_pch_creating != 0) || (g_ilstore_status != 1)) ||
       (cVar1 = (*g_il_emitter->vtbl->reopen)(g_il_emitter), cVar1 == '\0')) {
      (*g_il_emitter->vtbl->open)();
    }
  }
  else {
    iVar4 = (*g_idb->vtbl->idb_begin_unit_no_check)(g_idb,&g_ilstore_status);
    if (iVar4 == 0) {
      diag_fatal(0x49,".\\main.c",0x2b2);
    }
  }
  if (g_use_pch != '\0') {
    if (g_line_map_cached_row.position == g_token_position) {
      pfVar5 = &g_line_map_cached_row;
    }
    else {
      pfVar5 = pp_line_map_find_entry(&g_line_map,g_token_position);
    }
    iVar4 = (pfVar5->line - pfVar5->position) + g_token_position;
    if (g_line_map_cached_row.position == g_token_position) {
      pfVar5 = &g_line_map_cached_row;
    }
    else {
      pfVar5 = pp_line_map_find_entry(&g_line_map,g_token_position);
    }
    g_lex_position = g_lex_position + 1;
    vector_push_triple((int *)&g_line_map,g_lex_position,0,(int)pfVar5->file);
    g_token_position = g_lex_position;
    il_emitter_begin_region_at_top_level(g_ilstore_status == 5);
    if (g_line_map_cached_row.position == g_token_position) {
      pfVar5 = &g_line_map_cached_row;
    }
    else {
      pfVar5 = pp_line_map_find_entry(&g_line_map,g_token_position);
    }
    g_lex_position = g_lex_position + 1;
    vector_push_triple((int *)&g_line_map,g_lex_position,iVar4,(int)pfVar5->file);
    g_token_position = g_lex_position;
    return;
  }
  il_emitter_begin_region_at_top_level(g_ilstore_status == 5);
  return;
}

