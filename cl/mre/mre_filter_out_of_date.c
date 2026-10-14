node * __cdecl mre_filter_out_of_date(driver_ctx *ctx,node *files,mre_state *st)

{
  int rc;
  int rc_2;
  char *copy;
  char *copy_2;
  int rc_3;
  int rc_4;
  int iVar1;
  int ec;
  char *options;
  void *mre;
  cl_mre_srctarg *tail;
  void *mredrv;
  cl_compile_node *n;
  cl_srcfile *file;
  cl_mre_srctarg *rec;
  
  tail = (cl_mre_srctarg *)0x0;
  if ((g_Gm != 0) && (g_mre_ok != 0)) {
    rc = _MREFOpenByName_24(&mre,g_Fd_name,&ec,g_scratch,g_Brepro,1);
    if (rc != 0) {
      _MREQueryMreDrv_8(mre,&mredrv);
      _MREDrvOneTimeInit_4(mredrv);
      st->out_of_date = (cl_mre_srctarg *)0x0;
      st->pending = (cl_mre_srctarg *)0x0;
      st->up_to_date = (cl_mre_srctarg *)0x0;
      st->succeeded = (cl_mre_srctarg *)0x0;
      st->failed = (cl_mre_srctarg *)0x0;
      ctx->skipped = (cl_mre_srctarg *)0x0;
      ctx->skipped_tail = &ctx->skipped;
      options = mre_options_string(ctx);
      for (n = files; n != (cl_compile_node *)0x0; n = n->next) {
        file = n->file;
        ctx->file = file;
        pass_set_driver_vars(ctx);
        (n->mre).next = (cl_mre_srctarg *)0x0;
        rec = &n->mre;
        if (tail == (cl_mre_srctarg *)0x0) {
          st->pending = rec;
        }
        else {
          tail->next = rec;
        }
        if ((file->type == 2) || (file->type == 1)) {
          rc_2 = 1;
        }
        else {
          rc_2 = 0;
        }
        (n->mre).is_cpp = rc_2;
        (n->mre).source = file->name;
        tail = rec;
        copy = xstrdup(g_Fo_name);
        (n->mre).target = copy;
        (n->mre).options = options;
        copy_2 = xstrdup(g_browse_name);
        (n->mre).browse = copy_2;
      }
      if (g_mre_ok != 0) {
        rc_3 = _MREDrvFFilesOutOfDate_8(mredrv,st);
        if (rc_3 == 0) {
          if (g_mre_ok != 0) {
            cl_warning(0xfbc);
            g_mre_ok = 0;
          }
        }
        else {
          files = list_from_inner_links(st->out_of_date);
        }
      }
      rc_4 = _MREDrvFRelease_4(mredrv);
      if ((rc_4 == 0) && (g_mre_ok != 0)) {
        cl_warning(0xfbc);
        g_mre_ok = 0;
      }
      iVar1 = _MREFClose_8(mre,g_mre_ok);
      if (iVar1 != 0) {
        return files;
      }
      if (g_mre_ok == 0) {
        return files;
      }
      cl_warning(0xfbc);
      g_mre_ok = 0;
      return files;
    }
    cl_warning(0xfbc);
  }
  g_mre_ok = 0;
  return files;
}

