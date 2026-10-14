void __cdecl linker_response_write(driver_ctx *ctx)

{
  passrec *pass;
  optrec *opt;
  char *buf;
  char *value_buf;
  int rc;
  char *text;
  char *text_2;
  cl_srcfile *f;
  cl_srcfile *f_2;
  driver_ctx *drv;
  
  drv = ctx;
  buf = xmalloc(0x400);
  value_buf = xmalloc(0x400);
  pass = ctx->pass;
  strcpy(buf,ctx->temp_prefix);
  strcat(buf,"lk");
  if (g_Bz_no_run == 0) {
    ctx = (driver_ctx *)fopen(buf,"w");
    if (ctx == (driver_ctx *)0x0) {
      cl_error(0x7e2);
    }
  }
  else {
    ctx = (driver_ctx *)0x0;
  }
  for (opt = drv->pass_options; opt != (optrec *)0x0; opt = opt->next) {
    rc = option_goes_to_pass(opt,pass);
    if (rc != 0) {
      if ((opt->flags & 8) == 0) {
        file_printf((FILE *)ctx,"%c",(uint)(byte)pass->prefix);
      }
      text = action_expand_percent(buf,opt->name,drv);
      file_printf((FILE *)ctx,"%s",text);
      if (opt->value != (char *)0x0) {
        if ((opt->flags & 4) == 0) {
          file_printf((FILE *)ctx," ");
        }
        text_2 = action_expand_percent(value_buf,opt->value,drv);
        quote_argument(buf,text_2);
        file_printf((FILE *)ctx,"%s",buf);
      }
      file_printf((FILE *)ctx,"\n");
    }
  }
  for (f = drv->files; f != (cl_srcfile *)0x0; f = f->next) {
    if (f->type == 5) {
      quote_argument(buf,f->fullname);
      file_printf((FILE *)ctx,"%cdef:%s\n",(uint)(byte)pass->prefix,buf);
    }
  }
  for (f_2 = drv->files; f_2 != (cl_srcfile *)0x0; f_2 = f_2->next) {
    if ((g_file_types[f_2->type].kind == 1) && (f_2->type != 5)) {
      quote_argument(buf,f_2->fullname);
      file_printf((FILE *)ctx,"%s\n",buf);
    }
  }
  if (ctx != (driver_ctx *)0x0) {
    fclose((FILE *)ctx);
  }
  xfree(value_buf);
  xfree(buf);
  return;
}

