int __cdecl cl_main(int argc,char **argv)

{
  char *s;
  int v;
  int v_2;
  int v_3;
  int v_4;
  int iVar1;
  cl_optrec *opt;
  size_t value_len;
  size_t name_len;
  char *text;
  char *text_end;
  cl_optrec *opt_2;
  cl_srcfile *f;
  int index;
  int i;
  int cl_tail_count;
  char **cl_words;
  int cl_count;
  char *cl_var;
  char *cl_tail_var;
  cl_optrec *rec;
  cl_srcfile *file;
  int *pass;
  char **cl_tail_words;
  int forced_type;
  void *seh_saved_esp;
  void *seh_prev;
  void *seh_handler;
  cl_seh_scope *seh_scopetable;
  int seh_trylevel;
  char bt;
  char *s_2;
  
  seh_scopetable = &g_cl_main_scopetable;
  seh_handler = &_except_handler3;
  seh_prev = ExceptionList;
  seh_saved_esp = &stack0xffffff9c;
  seh_trylevel = 0;
  ExceptionList = &seh_prev;
  install_ctrl_handler();
  cl_var = getenv("CL");
  cl_tail_var = getenv("_CL_");
  cl_words = cmdline_split(cl_var,1);
  cl_count = argv_count(cl_words);
  cl_tail_words = cmdline_split(cl_tail_var,1);
  cl_tail_count = argv_count(cl_tail_words);
  s = program_path();
  *argv = s;
  driver_ctx_init(s,g_driver_ctx_ptr);
  if ((argc == 1) && (cl_count == 0)) {
    print_usage_and_exit();
  }
  v = option_prescan(cl_tail_words,cl_tail_count,"nologo",&g_nologo);
  if ((v == 0) && (v_2 = option_prescan(argv + 1,argc + -1,"nologo",&g_nologo), v_2 == 0)) {
    option_prescan(cl_words,cl_count,"nologo",&g_nologo);
  }
  if (g_nologo == 0) {
    print_banner();
  }
  v_3 = option_prescan(cl_tail_words,cl_tail_count,"noover",&g_noover);
  if ((v_3 == 0) && (v_4 = option_prescan(argv + 1,argc + -1,"noover",&g_noover), v_4 == 0)) {
    option_prescan(cl_words,cl_count,"noover",&g_noover);
  }
  iVar1 = argv_count(g_default_switches);
  options_parse_argv(g_default_switches,iVar1);
  for (opt = g_driver_ctx_ptr->pass_options; opt != (cl_optrec *)0x0; opt = opt->next) {
    opt->flags = opt->flags | 1;
  }
  i = 0;
  rec = (cl_optrec *)g_driver_ctx_ptr;
  while (rec = ((cl_ctx *)rec)->user_options, (cl_ctx *)rec != (cl_ctx *)0x0) {
    *(byte *)&((cl_ctx *)rec)->pass_options = *(byte *)&((cl_ctx *)rec)->pass_options | 1;
    if (g_default_switch_is_typed[i] != 0) {
      *(byte *)&((cl_ctx *)rec)->pass_options = *(byte *)&((cl_ctx *)rec)->pass_options | 0x20;
    }
    i = i + 1;
  }
  g_parsing_defaults = 0;
  if (0 < cl_count) {
    options_parse_argv(cl_words,cl_count);
  }
  if (1 < argc) {
    options_parse_argv(argv + 1,argc + -1);
  }
  if (0 < cl_tail_count) {
    options_parse_argv(cl_tail_words,cl_tail_count);
  }
  if (g_echoed_response != 0) {
    msg_write(2,"\n");
  }
  options_check_requirements();
  pass_set_driver_vars(g_driver_ctx_ptr);
  iVar1 = g_noover;
  if (g_show_commands != 0) {
    g_Gm = 0;
  }
  if ((g_enc != 0) && (g_Gi != 0)) {
    index = 0;
    g_noover = 1;
    option_apply(g_gi_off_argv,&index,0);
    g_Gi = 0;
  }
  g_noover = iVar1;
  if (g_Bv != 0) {
    print_pass_versions();
  }
  options_add_include_env();
  temp_prefix_create(g_driver_ctx_ptr);
  opt_2 = g_unknown_options;
  if (g_help != 0) {
    print_help();
    opt_2 = g_unknown_options;
  }
  for (; rec = opt_2, opt_2 != (cl_optrec *)0x0; opt_2 = opt_2->next) {
    if (opt_2->value == (char *)0x0) {
      cl_warning(0xfa2,opt_2->name);
    }
    else {
      value_len = strlen(opt_2->value);
      name_len = strlen(opt_2->name);
      text = xmalloc(value_len + 2 + name_len);
      s_2 = opt_2->value;
      text_end = strcpy_end(text,opt_2->name);
      strcpy_end(text_end,s_2);
      cl_warning(0xfa2,text);
      xfree(text);
    }
  }
  if (g_driver_ctx_ptr->files == (cl_srcfile *)0x0) {
    cl_error(0x7d3);
  }
  if (g_bt_type == (char *)0x0) {
    forced_type = 8;
  }
  else {
    bt = *g_bt_type;
    if (bt == 'C') {
      forced_type = 0;
    }
    else if ((bt == 'O') || (bt != 'P')) {
      forced_type = 3;
    }
    else {
      forced_type = 1;
    }
  }
  f = g_driver_ctx_ptr->files;
  rec = (cl_optrec *)0x0;
  do {
    file = f;
    if (f == (cl_srcfile *)0x0) {
      stderr_to_stdout();
      compile_all(g_driver_ctx_ptr);
      g_driver_ctx_ptr->file = (cl_srcfile *)0x0;
      if (g_any_pass_run == 0) {
        cl_warning(0xfb5);
      }
      seh_trylevel = -1;
      cl_exit(-(uint)(g_exit_failed != 0) & 2);
    }
    if ((forced_type == 8) || (f->explicit_type != 0)) {
      if (f->type == 8) {
        if (g_preprocess_only == 0) {
          f->type = 3;
          cl_warning(0xfb8,f->name);
        }
        else {
          f->type = 0;
        }
      }
    }
    else {
      f->type = forced_type;
      f->explicit_type = 1;
    }
    for (pass = g_file_types[f->type].passes; *pass != 5; pass = pass + 1) {
      if ((g_passes[*pass].flags & 1) != 0) goto LAB_00401c2b;
    }
    cl_warning(0xfbb,f->name);
LAB_00401c2b:
    f = f->next;
  } while( true );
}

