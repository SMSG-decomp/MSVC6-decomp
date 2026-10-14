char __thiscall pdb_open_for_minimal_rebuild(c1_pdb_state *pdb_state,char *source_name)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  char *pcVar4;
  
  if (g_pdb_gi->pdb == (PDB *)0x0) {
    if (g_split_pdbs == '\0') {
      pcVar4 = &g_pdb_file_name;
    }
    else {
      if (g_idb_file_name == '\0') {
        pdb_make_idb_name(&g_idb_file_name);
      }
      pcVar4 = &g_idb_file_name;
    }
    bVar2 = pdb_open_validated(g_pdb_gi,pcVar4,(int *)&g_pdb_gi_signature,(int *)&g_pdb_gi_age,0x400
                               ,(char *)0x0);
    if ((bVar2 != 0) &&
       (iVar3 = NameMap::open((PDB *)g_pdb_gi->pdb,1,(NameMap **)&g_pdb_gi->name_map), iVar3 != 0))
    goto LAB_10624af1;
    if (g_split_pdbs == '\0') goto LAB_1064be42;
    if (g_idb_file_name == '\0') {
      pdb_make_idb_name(&g_idb_file_name);
      pcVar4 = &g_idb_file_name;
      goto LAB_1064be27;
    }
LAB_1064beec:
    pcVar4 = &g_idb_file_name;
    goto LAB_1064be27;
  }
  if ((g_pdb_gi->name_map == (NameMap *)0x0) &&
     (iVar3 = NameMap::open((PDB *)g_pdb_gi->pdb,1,(NameMap **)&g_pdb_gi->name_map), iVar3 == 0)) {
    if (g_split_pdbs != '\0') {
      if (g_idb_file_name == '\0') {
        pdb_make_idb_name(&g_idb_file_name);
        pcVar4 = &g_idb_file_name;
        goto LAB_1064be27;
      }
      goto LAB_1064beec;
    }
LAB_1064be42:
    pcVar4 = &g_pdb_file_name;
  }
  else {
LAB_10624af1:
    if (g_minimal_rebuild != '\0') {
      if (g_pdb.pdb == (PDB *)0x0) {
        if (g_split_pdbs == '\0') {
          pcVar4 = &g_pdb_file_name;
        }
        else {
          if (g_idb_file_name == '\0') {
            pdb_make_idb_name(&g_idb_file_name);
          }
          pcVar4 = &g_idb_file_name;
        }
        bVar2 = pdb_open_validated(&g_pdb,pcVar4,(int *)&g_pdb_signature,(int *)&g_pdb_age,0x400,"i"
                                  );
        if (bVar2 == 0) {
          if (g_split_pdbs != '\0') {
            if (g_idb_file_name == '\0') {
              pdb_make_idb_name(&g_idb_file_name);
            }
            goto LAB_1064beec;
          }
          goto LAB_1064be42;
        }
      }
      if ((g_pdb.tpi == (TPI *)0x0) && (cVar1 = pdb_open_type_info(&g_pdb), cVar1 == '\0')) {
        diag_fatal_file_errno(0x53,0x162,&g_pdb_file_name);
        return '\0';
      }
    }
    if ((g_pdb_gi->mre != (MREngine *)0x0) ||
       (cVar1 = pdb_open_minimal_rebuild_engine(g_pdb_gi,&g_pdb), cVar1 != '\0')) {
      return '\x01';
    }
    pcVar4 = &g_pdb_file_name;
  }
LAB_1064be27:
  diag_fatal_file_errno(0x53,0x162,pcVar4);
  return '\0';
}

