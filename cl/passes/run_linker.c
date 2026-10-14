int __cdecl run_linker(driver_ctx *ctx)

{
  passrec *pass;
  char *buf_2;
  char *p;
  char *p_2;
  char *p_3;
  char *p_4;
  size_t len;
  char **argv_00;
  int rc;
  char *envvar;
  char cmdline [2048];
  char *host;
  char **argv;
  char *buf;
  char *exe;
  char *prog;
  
  g_any_pass_run = 1;
  buf_2 = xmalloc(0x400);
  p = cmdline;
  pass = ctx->pass;
  prog = pass->program;
  exe = pass->host;
  if (exe != (char *)0x0) {
    quote_argument(buf_2,exe);
    p = strcpy_end(cmdline,buf_2);
  }
  quote_argument(buf_2,prog);
  p_2 = strcpy_end(p,buf_2);
  linker_response_write(ctx);
  p_3 = strcpy_end(p_2," -link @");
  p_4 = strcpy_end(p_3,ctx->temp_prefix);
  strcpy_end(p_4,"lk");
  len = strlen(cmdline);
  if (0x7ff < len) {
    cl_error(0);
  }
  argv_00 = cmdline_split(cmdline,0);
  if (g_show_commands != 0) {
    msg_write(2,"`%s\'\n",cmdline);
  }
  rc = 0;
  if (g_Bz_no_run == 0) {
    if (g_Bt_time != 0) {
      pass_timer_start();
    }
    if (exe == (char *)0x0) {
      envvar = pass->envvar;
      exe = prog;
    }
    else {
      envvar = (char *)0x0;
    }
    rc = run_program(1,pass,exe,envvar,argv_00);
    if (g_Bt_time != 0) {
      pass_timer_report(prog);
    }
  }
  xfree(argv_00);
  xfree(buf_2);
  return rc;
}

