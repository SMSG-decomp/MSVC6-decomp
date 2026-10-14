int __cdecl run_compiler_pass(driver_ctx *ctx)

{
  passrec *pass;
  char *buf;
  char *value_buf;
  int k;
  int host_len;
  optrec *opt;
  int k_2;
  int k_3;
  int k_4;
  char **argv;
  char *block;
  char *p;
  int iVar1;
  char *p_2;
  char *p_3;
  char *p_4;
  char **word_2;
  char **next_word;
  char **word;
  size_t size;
  optrec *opt_00;
  char *fmt;
  char *pcVar2;
  cl_copy_fn copy_value;
  char *cur;
  char *host;
  bool enc;
  cl_srcfile *file;
  char *program;
  
  g_any_pass_run = 1;
  buf = xmalloc(0x400);
  value_buf = xmalloc(0x400);
  pass = ctx->pass;
  file = ctx->file;
  program = pass->program;
  host = pass->host;
  k = quoted_length(program);
  size = k + 1;
  if (host != (char *)0x0) {
    host_len = quoted_length(host);
    size = k + 2 + host_len;
  }
  cur = (char *)(uint)(host != (char *)0x0);
  for (opt = ctx->pass_options; opt != (optrec *)0x0; opt = opt->next) {
    k_2 = option_goes_to_pass(opt,pass);
    pcVar2 = cur;
    if (k_2 != 0) {
      k_3 = action_expand_length(opt->name,ctx);
      size = size + 2 + k_3;
      pcVar2 = cur + 1;
      if (opt->value != (char *)0x0) {
        k_4 = action_expand_length(opt->value,ctx);
        size = size + 2 + k_4;
        pcVar2 = cur + 2;
      }
    }
    cur = pcVar2;
  }
  argv = xmalloc((int)cur * 4 + 8);
  block = xmalloc(size);
  copy_value = strcpy;
  if ((pass->flags & 4) == 0) {
    copy_value = quote_argument;
  }
  *argv = block;
  if (host == (char *)0x0) {
    word_2 = argv + 1;
    quote_argument(buf,program);
    cur = strcpy_end(block,buf);
  }
  else {
    quote_argument(buf,host);
    p = strcpy_end(block,buf);
    argv[1] = p + 1;
    word_2 = argv + 2;
    (*copy_value)(buf,program);
    cur = strcpy_end(p + 1,buf);
  }
  for (opt_00 = ctx->pass_options; opt_00 != (optrec *)0x0; opt_00 = opt_00->next) {
    iVar1 = option_goes_to_pass(opt_00,pass);
    next_word = word_2;
    if (iVar1 != 0) {
      pcVar2 = cur + 1;
      *word_2 = pcVar2;
      next_word = word_2 + 1;
      if ((opt_00->flags & 8) == 0) {
        *pcVar2 = pass->prefix;
        pcVar2 = cur + 2;
      }
      cur = pcVar2;
      p_2 = action_expand_percent(buf,opt_00->name,ctx);
      cur = strcpy_end(cur,p_2);
      if (opt_00->value != (char *)0x0) {
        if ((opt_00->flags & 4) == 0) {
          cur = cur + 1;
          *next_word = cur;
          next_word = word_2 + 2;
        }
        p_3 = action_expand_percent(value_buf,opt_00->value,ctx);
        (*copy_value)(buf,p_3);
        cur = strcpy_end(cur,buf);
      }
    }
    word_2 = next_word;
  }
  if (g_enc != 0) {
    p_4 = strchr("2",(uint)(byte)pass->letter);
    if (p_4 != (char *)0x0) {
      enc = true;
      enc_set_environment(ctx,program);
      goto LAB_004047c9;
    }
  }
  enc = false;
LAB_004047c9:
  *word_2 = (char *)0x0;
  if (g_show_commands != 0) {
    msg_write(2,"`");
    word = argv;
    if (host != (char *)0x0) {
      msg_write(2,"%s ",host);
      word = argv + 1;
    }
    fmt = "%s";
    pcVar2 = program;
    while( true ) {
      msg_write(2,fmt,pcVar2);
      pcVar2 = word[1];
      word = word + 1;
      if (pcVar2 == (char *)0x0) break;
      fmt = " %s";
    }
    msg_write(2,"\'\n");
  }
  iVar1 = 0;
  if (g_Bz_no_run == 0) {
    if (g_Bt_time != 0) {
      pass_timer_start();
    }
    if (host == (char *)0x0) {
      pcVar2 = pass->envvar;
      host = program;
      if (file->type == 9) {
        iVar1 = 2;
      }
      else {
        iVar1 = 0;
      }
    }
    else {
      pcVar2 = (char *)0x0;
      iVar1 = 3;
    }
    iVar1 = run_program(iVar1,pass,host,pcVar2,argv);
    if (g_Bt_time != 0) {
      pass_timer_report(program);
    }
  }
  if (enc) {
    enc_clear_environment();
  }
  xfree(argv);
  xfree(block);
  xfree(value_buf);
  xfree(buf);
  return iVar1;
}

