char __fastcall il_emitter_browse_reopen(c1_il_emitter_browse *emitter)

{
  int iVar1;
  int *piVar2;
  size_t sVar3;
  c1_il_emitter_browse_vtbl *file;
  int iStack_2c;
  long lStack_28;
  _stat st;
  
  if (g_opt_GFR == '\0') {
    return '\0';
  }
  iVar1 = stat(emitter[1].vtbl,&st);
  if (iVar1 == -1) {
    piVar2 = _errno();
    if (*piVar2 != 2) {
      diag_fatal_file_errno(0x53,0x154,(char *)emitter[1].vtbl);
    }
    return '\0';
  }
  if (st.st_size != 0) {
    iVar1 = (*g_idb->vtbl->idb_browse_size)(g_idb);
    if (iVar1 * 2 < st.st_size) {
      return '\0';
    }
    g_browse_sbr_file = fopen((char *)emitter[1].vtbl,"r+b");
    if (g_browse_sbr_file == (FILE *)0x0) {
      diag_fatal_file_errno(0x53,0x154,(char *)emitter[1].vtbl);
    }
    setvbuf(g_browse_sbr_file,(char *)0x0,0,0x1000);
    iVar1 = fseek(g_browse_sbr_file,-8,2);
    if ((((iVar1 == 0) && (sVar3 = fread(&lStack_28,4,1,g_browse_sbr_file), sVar3 == 1)) &&
        (sVar3 = fread(&iStack_2c,4,1,g_browse_sbr_file), sVar3 == 1)) && (iStack_2c == 0x4a525301))
    {
      iVar1 = fseek(g_browse_sbr_file,lStack_28,0);
      if (iVar1 == 0) {
        g_emitter_region_mode = 2;
        return '\x01';
      }
      file = emitter[1].vtbl;
    }
    else {
      iVar1 = fseek(g_browse_sbr_file,0,2);
      if (iVar1 == 0) {
        g_emitter_region_mode = 2;
        return '\x01';
      }
      file = emitter[1].vtbl;
    }
    diag_fatal_file_errno(0x53,0x154,(char *)file);
    g_emitter_region_mode = 2;
    return '\x01';
  }
  g_browse_sbr_file = fopen((char *)emitter[1].vtbl,"w+b");
  if (g_browse_sbr_file == (FILE *)0x0) {
    diag_fatal_file_errno(0x53,0x154,(char *)emitter[1].vtbl);
  }
  setvbuf(g_browse_sbr_file,(char *)0x0,0,0x1000);
  iVar1 = (*g_idb->vtbl->idb_browse_table_reset)(g_idb);
  if (iVar1 != 0) {
    g_emitter_region_mode = 2;
    return '\x01';
  }
  diag_fatal(0x49,".\\nbrowser.c",0x682);
}

