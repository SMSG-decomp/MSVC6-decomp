int __cdecl compile_batch(driver_ctx *ctx,node *files)

{
  char *text_2;
  char *text;
  srcfile *obj;
  node *order;
  cl_compile_node *cur;
  int *pass;
  UINT id;
  char name_buf [1024];
  int **passes;
  cl_srcfile *file;
  int failures;
  int pass_number;
  int passes_enabled;
  bool batching;
  int n;
  cl_u32 *flags;
  bool not_first;
  int n_2;
  cl_u32 *flags_2;
  cl_srcfile *file_2;
  
  failures = 0;
  passes_enabled = 0;
  n = files->file->type;
  for (pass = g_file_types[n].passes; *pass != 5; pass = pass + 1) {
    if ((g_passes[*pass].flags & 1) != 0) {
      passes_enabled = passes_enabled + 1;
    }
  }
  order = files;
  if (((g_ZM_batch == 0) || (g_batch_allowed == 0)) || (passes_enabled < 2)) {
    batching = false;
    ctx->batch = (cl_compile_node *)0x0;
  }
  else {
    batching = true;
    pass_number = 0;
    ctx->batch = files;
    pass = g_file_types[n].passes;
  }
  do {
    cur = files;
    if (batching) {
      if ((g_passes[*pass].flags & 1) != 0) {
        n_2 = pass_number + 1;
        not_first = 0 < pass_number;
        if (not_first) {
          files = list_reverse(order);
          ctx->batch = files;
        }
        ctx->pass = g_passes + *pass;
        ctx->file = files->file;
        cur = files;
        pass_number = n_2;
        if (n_2 == 1) {
          if (g_first_batch != 0) {
            g_first_batch = 0;
            goto LAB_00404439;
          }
          id = 0x14b;
        }
        else if ((n_2 == 2) && (2 < passes_enabled)) {
          id = 0x14c;
        }
        else {
          if (n_2 != passes_enabled) goto LAB_00404439;
          id = 0x14d;
        }
        text_2 = load_message(id);
        msg_write(2,text_2);
        goto LAB_00404439;
      }
    }
    else {
LAB_00404439:
      for (; cur != (cl_compile_node *)0x0; cur = cur->next) {
        if ((!batching) || (cur->failed == 0)) {
          file_2 = cur->file;
          ctx->file = file_2;
          pass_set_driver_vars(ctx);
          if ((!batching) || (pass_number < 2)) {
            text = path_file_name(name_buf,file_2->name);
            msg_write(2,"%s\n",text);
          }
          if (batching) {
            pass_resolve_program(ctx);
            if (cur->next == (cl_compile_node *)0x0) {
              flags = &ctx->pass->flags;
              *flags = *flags | 8;
            }
            else {
              flags_2 = &ctx->pass->flags;
              *flags_2 = *flags_2 & 0xfffffff7;
            }
            g_exit_failed = run_compiler_pass(ctx);
          }
          else {
            g_exit_failed = run_pass_list(g_file_types[n].passes,ctx,run_compiler_pass);
          }
          if (g_exit_failed == 0) {
LAB_004044e9:
            if ((batching) && (pass_number != passes_enabled)) goto LAB_0040451b;
          }
          else {
            failures = failures + 1;
            cur->failed = 1;
            if (batching) {
              il_files_delete(1);
              goto LAB_004044e9;
            }
          }
          if (g_Fo_name != (char *)0x0) {
            obj = srcfile_new(g_Fo_name,3);
            obj->next = file_2->next;
            file_2->next = obj;
          }
          il_files_delete(1);
        }
LAB_0040451b:
      }
      order = files;
      if (!batching) break;
    }
    pass = pass + 1;
  } while (*pass != 5);
  ctx->batch = (cl_compile_node *)0x0;
  return failures;
}

