void __fastcall browse_emit_records(c1_il_emitter_browse *emitter)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  void *pvStack_c;
  long alStack_8 [2];
  
  (*emitter->vtbl->flush)();
  alStack_8[0] = ftell(g_browse_sbr_file);
  browse_add_record(0x16,(c1_symbol *)0x0);
  (*emitter->vtbl->flush)();
  iVar2 = (*g_idb->vtbl->idb_browse_region_count)(g_idb);
  uVar4 = 0;
  if (0 < iVar2) {
    do {
      iVar3 = (*g_idb->vtbl->idb_browse_region)(g_idb,uVar4,&pvStack_c);
      if (iVar3 == 0) {
        diag_fatal(0x49,".\\nbrowser.c",0x7c7);
      }
      if (*(int *)((int)pvStack_c + 8) != -1) {
        g_browse_sbr_file->_cnt = g_browse_sbr_file->_cnt + -1;
        if (g_browse_sbr_file->_cnt < 0) {
          _flsbuf(0x17,g_browse_sbr_file);
        }
        else {
          *g_browse_sbr_file->_ptr = '\x17';
          g_browse_sbr_file->_ptr = g_browse_sbr_file->_ptr + 1;
        }
        fwrite(pvStack_c,0xc,1,g_browse_sbr_file);
      }
      uVar4 = uVar4 + 1;
    } while ((int)uVar4 < iVar2);
  }
  g_browse_sbr_file->_cnt = g_browse_sbr_file->_cnt + -1;
  if (g_browse_sbr_file->_cnt < 0) {
    _flsbuf(0x18,g_browse_sbr_file);
  }
  else {
    *g_browse_sbr_file->_ptr = '\x18';
    g_browse_sbr_file->_ptr = g_browse_sbr_file->_ptr + 1;
  }
  uVar4 = 0xffffffff;
  pcVar5 = g_opt_source_file;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  fwrite(g_opt_source_file,~uVar4,1,g_browse_sbr_file);
  fwrite(alStack_8,4,1,g_browse_sbr_file);
  alStack_8[1] = 0x4a525301;
  fwrite(alStack_8 + 1,4,1,g_browse_sbr_file);
  return;
}

