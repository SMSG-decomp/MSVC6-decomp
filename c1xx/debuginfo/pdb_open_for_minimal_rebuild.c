char __thiscall pdb_open_for_minimal_rebuild(c1_mre_tracker *tracker,char *source_file)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  char *pcVar4;
  
  if (g_pdb_gi->pdb == (c1xx_pdb *)0x0) {
    if (g_split_pdbs == '\0') {
      pcVar4 = g_pdb_file_name;
    }
    else {
      if (g_idb_file_name == '\0') {
        pdb_make_idb_name(&g_idb_file_name);
      }
      pcVar4 = &g_idb_file_name;
    }
    bVar2 = pdb_open_validated(g_pdb_gi,pcVar4,&g_pdb_gi_signature,&g_pdb_gi_age,0x400,(char *)0x0);
    if ((bVar2 != 0) &&
       (iVar3 = NameMap::open((PDB *)g_pdb_gi->pdb,1,(NameMap **)&g_pdb_gi->namemap), iVar3 != 0))
    goto LAB_10447dce;
    if (g_split_pdbs == '\0') goto LAB_10495868;
    if (g_idb_file_name == '\0') {
      pdb_make_idb_name(&g_idb_file_name);
      pcVar4 = &g_idb_file_name;
      goto LAB_1049584d;
    }
LAB_10495912:
    pcVar4 = &g_idb_file_name;
    goto LAB_1049584d;
  }
  if ((g_pdb_gi->namemap == (c1_pdb_namemap *)0x0) &&
     (iVar3 = NameMap::open((PDB *)g_pdb_gi->pdb,1,(NameMap **)&g_pdb_gi->namemap), iVar3 == 0)) {
    if (g_split_pdbs != '\0') {
      if (g_idb_file_name == '\0') {
        pdb_make_idb_name(&g_idb_file_name);
        pcVar4 = &g_idb_file_name;
        goto LAB_1049584d;
      }
      goto LAB_10495912;
    }
LAB_10495868:
    pcVar4 = g_pdb_file_name;
  }
  else {
LAB_10447dce:
    if (g_minimal_rebuild != '\0') {
      if (g_pdb.pdb == (c1xx_pdb *)0x0) {
        if (g_split_pdbs == '\0') {
          pcVar4 = g_pdb_file_name;
        }
        else {
          if (g_idb_file_name == '\0') {
            pdb_make_idb_name(&g_idb_file_name);
          }
          pcVar4 = &g_idb_file_name;
        }
        bVar2 = pdb_open_validated(&g_pdb,pcVar4,&g_pdb_signature,&g_pdb_age,0x400,"i");
        if (bVar2 == 0) {
          if (g_split_pdbs != '\0') {
            if (g_idb_file_name == '\0') {
              pdb_make_idb_name(&g_idb_file_name);
            }
            goto LAB_10495912;
          }
          goto LAB_10495868;
        }
      }
      if ((g_pdb.tpi == (c1_pdb_tpi *)0x0) && (cVar1 = pdb_open_type_info(&g_pdb), cVar1 == '\0')) {
        diag_fatal_file_errno(0x53,0x162,g_pdb_file_name);
        return '\0';
      }
    }
    if ((g_pdb_gi->mre != (c1_mre_engine *)0x0) ||
       (cVar1 = pdb_open_minimal_rebuild_engine(g_pdb_gi,&g_pdb), cVar1 != '\0')) {
      return '\x01';
    }
    pcVar4 = g_pdb_file_name;
  }
LAB_1049584d:
  diag_fatal_file_errno(0x53,0x162,pcVar4);
  return '\0';
}

