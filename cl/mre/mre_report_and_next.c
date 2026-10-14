node * __cdecl mre_report_and_next(driver_ctx *ctx,mre_state *st)

{
  cl_mre_srctarg *pcVar1;
  cl_mre_srctarg *pcVar2;
  int rc;
  node *files;
  int rc_2;
  int rc_3;
  srcfile *obj;
  int rc2;
  cl_mre_srctarg *next;
  cl_mre_srctarg *next_3;
  int rc2_2;
  int rc2_3;
  cl_mre_srctarg *next_2;
  int rc_4;
  int ec;
  void *mre;
  cl_mre_srctarg *next_up;
  void *mredrv;
  cl_mre_srctarg *rec_2;
  cl_mre_srctarg *rec;
  cl_mre_srctarg *up;
  cl_mre_srctarg **tail;
  cl_srcfile *source;
  
  if (((g_Gm == 0) || (g_mre_ok == 0)) ||
     ((st->out_of_date == (cl_mre_srctarg *)0x0 &&
      ((st->pending == (cl_mre_srctarg *)0x0 && (st->up_to_date == (cl_mre_srctarg *)0x0)))))) {
    files = (node *)0x0;
  }
  else {
    rc = _MREFOpenByName_24(&mre,g_Fd_name,&ec,g_scratch,g_Brepro,1);
    if (rc == 0) {
      cl_warning(0xfbc);
      g_mre_ok = 0;
      files = list_from_inner_links(st->pending);
    }
    else {
      _MREQueryMreDrv_8(mre,&mredrv);
      rec = st->out_of_date;
      while (rec != (cl_mre_srctarg *)0x0) {
        next_2 = (cl_mre_srctarg *)0x0;
        if (rec != (cl_mre_srctarg *)0x0) {
          next_2 = rec->next;
        }
        _MREDrvFSuccessfulCompile_16
                  (mredrv,(uint)(rec[-1].browse == (char *)0x0),rec->source,rec->target);
        if (rec[-1].browse == (char *)0x0) {
          rec->next = st->succeeded;
          st->succeeded = rec;
          rec = next_2;
        }
        else {
          rec->next = st->failed;
          st->failed = rec;
          rec = next_2;
        }
      }
      st->out_of_date = (cl_mre_srctarg *)0x0;
      rec_2 = st->up_to_date;
      pcVar2 = (cl_mre_srctarg *)0x0;
      while (pcVar1 = rec_2, pcVar1 != (cl_mre_srctarg *)0x0) {
        next_up = (cl_mre_srctarg *)0x0;
        if (pcVar1 != (cl_mre_srctarg *)0x0) {
          next_up = pcVar1->next;
        }
        source = pcVar1[-1].unk14;
        rc_2 = _MREDrvFUpdateTargetFile_12(mredrv,pcVar1->target,0);
        if ((rc_2 == 0) ||
           ((pcVar1->browse != (char *)0x0 &&
            (rc_3 = _MREDrvFUpdateTargetFile_12(mredrv,pcVar1->browse,1), rc_3 == 0)))) {
          pcVar1->next = pcVar2;
          rec_2 = next_up;
          pcVar2 = pcVar1;
        }
        else {
          g_any_pass_run = 1;
          obj = srcfile_new(pcVar1->target,3);
          obj->next = source->next;
          source->next = obj;
          tail = ctx->skipped_tail;
          pcVar1->next = *tail;
          *tail = pcVar1;
          ctx->skipped_tail = &pcVar1->next;
          rec_2 = next_up;
        }
      }
      rc_4 = 0;
      st->up_to_date = (cl_mre_srctarg *)0x0;
      if (st->pending == (cl_mre_srctarg *)0x0) {
        files = (node *)0x0;
      }
      else {
        files = list_from_inner_links(st->pending);
        rc2 = _MREDrvFFilesOutOfDate_8(mredrv,st);
        if (rc2 == 0) {
          cl_warning(0xfbc);
          g_mre_ok = rc_4;
        }
        else {
          files = list_from_inner_links(st->out_of_date);
        }
      }
      if (pcVar2 != (cl_mre_srctarg *)0x0) {
        if (files == (node *)0x0) {
          st->out_of_date = pcVar2;
        }
        else {
          if (g_mre_ok == 0) {
            next = list_to_inner_links(files);
            st->out_of_date = next;
          }
          for (next_3 = st->out_of_date; next_3->next != (cl_mre_srctarg *)0x0;
              next_3 = (cl_mre_srctarg *)
                       (-(uint)(next_3 != (cl_mre_srctarg *)0x0) & (uint)next_3->next)) {
          }
          next_3->next = pcVar2;
        }
        files = list_from_inner_links(st->out_of_date);
      }
      rc2_2 = _MREDrvFRelease_4(mredrv);
      if ((rc2_2 == 0) && (g_mre_ok != 0)) {
        cl_warning(0xfbc);
        g_mre_ok = rc_4;
      }
      rc2_3 = _MREFClose_8(mre,1);
      if ((rc2_3 == 0) && (g_mre_ok != 0)) {
        cl_warning(0xfbc);
        g_mre_ok = rc_4;
      }
    }
  }
  return files;
}

