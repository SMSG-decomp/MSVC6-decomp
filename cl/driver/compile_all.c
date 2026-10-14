void __cdecl compile_all(driver_ctx *ctx)

{
  driver_ctx *ctx_00;
  char *p_3;
  char *root_end_2;
  BOOL ok;
  uint n;
  node *list;
  node *batch;
  uint n_2;
  char *p;
  char *p_2;
  cl_srcfile *file;
  srcfile *exe;
  char saved;
  cl_mre_srctarg *next_rec;
  char *root_end;
  node *rest;
  char name_buf [1024];
  DWORD total_clusters;
  mre_state mre;
  DWORD bytes_per_sector;
  LPCSTR root;
  DWORD free_clusters;
  uint failed;
  uint limit;
  cl_srcfile *next_file;
  node *next;
  cl_mre_srctarg *rec;
  int *passes;
  short batch_index;
  cl_srcfile *file_2;
  cl_srcfile *next_file_2;
  char *p_4;
  
  ctx_00 = ctx;
  failed = 0;
  root = (LPCSTR)0x0;
  limit = 199;
  if (g_batch_limit < 200) {
    limit = g_batch_limit;
  }
  p_4 = ctx->temp_prefix;
  if ((p_4[1] == ':') && (root_end_2 = p_4 + 2, p_4[2] == '\\')) {
LAB_00403a9a:
    if (root_end_2 == (char *)0x0) goto LAB_00403aad;
    saved = root_end_2[1];
    root_end = root_end_2 + 1;
    *root_end = '\0';
    root = ctx_00->temp_prefix;
  }
  else {
    if ((*p_4 == '\\') && ((p_4[1] == '\\' && (p_3 = strchr(p_4 + 2,0x5c), p_3 != (char *)0x0)))) {
      root_end_2 = strchr(p_3 + 1,0x5c);
      goto LAB_00403a9a;
    }
LAB_00403aad:
    root_end = (char *)0x0;
    saved = ctx._3_1_;
  }
  ok = GetDiskFreeSpaceA(root,(LPDWORD)&ctx,&bytes_per_sector,&free_clusters,&total_clusters);
  if ((ok != 0) && (n = (int)ctx * bytes_per_sector * free_clusters, n < limit * 3000000)) {
    limit = n / 3000000;
  }
  g_batch_limit = limit;
  if (root_end != (char *)0x0) {
    *root_end = saved;
  }
  list = compile_list_new(ctx_00);
  batch = mre_filter_out_of_date(ctx_00,list,&mre);
  while (((driver_ctx *)batch != (driver_ctx *)0x0 ||
         (batch = mre_report_and_next(ctx_00,&mre), (driver_ctx *)batch != (driver_ctx *)0x0))) {
    do {
      passes = g_file_types[(int)((driver_ctx *)batch)->user_options->name].passes;
      *(short *)((int)&((driver_ctx *)batch)->user_options->value + 2) = 0;
      next = (cl_compile_node *)((driver_ctx *)batch)->pass_options;
      ctx = (driver_ctx *)batch;
      while ((rest = next, rest != (node *)0x0 && (g_file_types[rest->file->type].passes == passes))
            ) {
        batch_index = *(short *)((int)&ctx->user_options->value + 2);
        free_clusters = CONCAT22((short)((uint)ctx->user_options >> 0x10),batch_index);
        if (g_batch_limit <= batch_index) break;
        rest->file->batch_index = batch_index + 1;
        next = rest->next;
        ctx = (driver_ctx *)rest;
      }
      ctx->pass_options = (cl_optrec *)0x0;
      n_2 = compile_batch(ctx_00,batch);
      failed = failed | n_2;
      batch = rest;
    } while (rest != (node *)0x0);
    batch = mre_report_and_next(ctx_00,&mre);
  }
  if (ctx_00->skipped != (cl_mre_srctarg *)0x0) {
    p = load_message(0x14a);
    msg_write(2,p);
    next_rec = ctx_00->skipped;
    while (rec = next_rec, rec != (cl_mre_srctarg *)0x0) {
      if (rec == (cl_mre_srctarg *)0x0) {
        next_rec = (cl_mre_srctarg *)0x0;
      }
      else {
        next_rec = rec->next;
      }
      p_2 = path_file_name(name_buf,*(char **)((int)rec[-1].unk14 + 4));
      msg_write(2,"%s\n",p_2);
      rec->next = mre.succeeded;
      mre.succeeded = rec;
    }
  }
  if (failed != 0) {
    g_exit_failed = failed;
    return;
  }
  next_file = ctx_00->files;
  file = next_file;
  if (next_file != (cl_srcfile *)0x0) {
    do {
      if (file->type == 3) break;
      file = file->next;
    } while (file != (cl_srcfile *)0x0);
    if (file != (cl_srcfile *)0x0) goto LAB_00403c39;
  }
  file = next_file;
LAB_00403c39:
  ctx_00->file = file;
  pass_set_driver_vars(ctx_00);
  g_exit_failed = run_pass_list(g_passes_link,ctx_00,run_linker);
  if (g_exit_failed == 0) {
    if (g_Fe_name != (char *)0x0) {
      exe = srcfile_new(g_Fe_name,9);
      exe->next = ctx_00->files->next;
      ctx_00->files->next = exe;
    }
    next_file_2 = ctx_00->files;
    do {
      do {
        file_2 = next_file_2;
        if (file_2 == (cl_srcfile *)0x0) {
          return;
        }
        next_file_2 = file_2->next;
      } while (g_file_types[file_2->type].kind != 2);
      ctx_00->file = file_2;
      g_exit_failed = run_pass_list(g_file_types[file_2->type].passes,ctx_00,run_compiler_pass);
    } while (g_exit_failed == 0);
  }
  return;
}

