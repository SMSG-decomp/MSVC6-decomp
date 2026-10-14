int __cdecl run_program(int mode,passrec *pass,char *program,char *envvar,char **argv)

{
  size_t size;
  size_t len;
  char *env;
  char *p;
  char *q;
  int t_2;
  int *err;
  HMODULE hModule;
  cl_invoke_pass invoke_fn;
  cl_abort_pass abort_fn;
  char **word_p_3;
  uint status;
  HANDLE hEvent;
  int *err_2;
  int t;
  char **word_p;
  size_t size_2;
  char **word_p_2;
  int t_3;
  char *spawn_argv [2];
  uint result;
  void *seh_saved_esp;
  void *seh_prev;
  void *seh_handler;
  cl_seh_scope *seh_scopetable;
  int seh_trylevel;
  void *sp;
  char *q_2;
  char *q_3;
  char *q_4;
  
  seh_trylevel = -1;
  seh_scopetable = &g_run_program_scopetable;
  seh_handler = &_except_handler3;
  seh_prev = ExceptionList;
  if (mode == 0) {
    ExceptionList = &seh_prev;
    if (envvar != (char *)0x0) {
      ExceptionList = &seh_prev;
      size = strlen(envvar);
      size_2 = size + 2;
      if ((pass->flags & 4) == 0) {
        word_p = argv + 1;
        q_3 = *word_p;
        while (q_3 != (char *)0x0) {
          len = strlen(q_3);
          size_2 = size_2 + 1 + len;
          word_p = word_p + 1;
          q_3 = *word_p;
        }
      }
      env = xmalloc(size_2);
      p = strcpy_end(env,envvar);
      if ((pass->flags & 4) == 0) {
        word_p_2 = argv + 1;
        q_4 = *word_p_2;
        while (q_4 != (char *)0x0) {
          q = strcpy_end(p,q_4);
          *q = ' ';
          p = q + 1;
          word_p_2 = word_p_2 + 1;
          q_4 = *word_p_2;
        }
      }
      *p = '\0';
      t_2 = _putenv(env);
      if (t_2 != 0) {
        cl_error(0x7ed,program);
      }
      xfree(env);
      if ((pass->flags & 4) == 0) {
        spawn_argv[0] = *argv;
        spawn_argv[1] = (char *)0x0;
        argv = spawn_argv;
      }
    }
  }
  else if ((mode < 1) || (ExceptionList = &seh_prev, 3 < mode)) {
    ExceptionList = &seh_prev;
    cl_error(0);
  }
  _flushall();
  err = _errno();
  *err = 0;
  g_ctrl_c_seen = 0;
  g_current_pass = pass;
  if ((pass->flags & 4) == 0) {
    g_pass_running = 1;
    status = _spawnvp(0,program,argv);
    g_pass_running = 0;
  }
  else {
    if (pass->invoke == (cl_invoke_pass)0x0) {
      hModule = LoadLibraryA(program);
      if (hModule != (HMODULE)0x0) {
        invoke_fn = (cl_invoke_pass)GetProcAddress(hModule,"_InvokeCompilerPass@12");
        abort_fn = (cl_abort_pass)GetProcAddress(hModule,"_AbortCompilerPass@4");
        if ((invoke_fn == (cl_invoke_pass)0x0) || (abort_fn == (cl_abort_pass)0x0)) {
          FreeLibrary(hModule);
        }
        else {
          pass->module = hModule;
          pass->invoke = invoke_fn;
          pass->abort = abort_fn;
        }
      }
      if (pass->invoke == (cl_invoke_pass)0x0) {
        cl_error(0x7eb,program);
      }
    }
    t = 0;
    q_2 = *argv;
    word_p_3 = argv;
    while (q_2 != (char *)0x0) {
      word_p_3 = word_p_3 + 1;
      t = t + 1;
      q_2 = *word_p_3;
    }
    g_pass_running = 1;
    seh_trylevel = 0;
    status = (*pass->invoke)(t,argv,pass->flags >> 3 & 1);
    seh_trylevel = -1;
    g_pass_running = 0;
    if ((status != 0) || ((pass->flags & 8) != 0)) {
      pass_unload(pass);
    }
  }
  if ((g_ctrl_c_seen != 0) || ((status & 0xff00) == 0x8000)) {
    cl_exit(4);
  }
  if (status == 0xf101) {
    if ((g_enc_event_name != (char *)0x0) &&
       (hEvent = OpenEventA(2,0,g_enc_event_name), hEvent != (HANDLE)0x0)) {
      SetEvent(hEvent);
      CloseHandle(hEvent);
    }
    cl_exit(6);
  }
  if (((int)status < 0) && (err_2 = _errno(), *err_2 != 0)) {
    cl_error(0x7eb,program);
  }
  t_3 = 0;
  if (status != 0) {
    if (status == 0x20d) {
      cl_error(0x7ee,program);
    }
    t_3 = 2;
  }
  ExceptionList = seh_prev;
  return t_3;
}

