void __fastcall il_emitter_browse_discard(c1_il_emitter_browse *il_emitter_browse)

{
  int iVar1;
  int *piVar2;
  
  if (g_browse_sbr_file != (FILE *)0x0) {
    iVar1 = fclose_if_open(g_browse_sbr_file);
    if (iVar1 != 0) {
      diag_error(0x1a2,il_emitter_browse[1].vtbl);
    }
    iVar1 = _unlink((char *)il_emitter_browse[1].vtbl);
    if (iVar1 != 0) {
      piVar2 = _errno();
      if (*piVar2 != 2) {
        diag_error(0x1a2,il_emitter_browse[1].vtbl);
      }
    }
  }
  return;
}

