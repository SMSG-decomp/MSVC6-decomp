void __cdecl mainCRTStartup(void)

{
  int *mode;
  int *mode_2;
  char ***initenv;
  int ret;
  char **argv;
  _startupinfo startup;
  char **envp;
  int argc;
  void *seh_saved_esp;
  void *seh_prev;
  void *seh_handler;
  cl_seh_scope *seh_scopetable;
  int seh_trylevel;
  
  seh_scopetable = &g_crt_startup_scopetable;
  seh_handler = &_except_handler3;
  seh_prev = ExceptionList;
  seh_saved_esp = &stack0xffffffc0;
  seh_trylevel = 0;
  ExceptionList = &seh_prev;
  __set_app_type(1);
  __onexitend = (_PVFV *)0xffffffff;
  __onexitbegin = (_PVFV *)0xffffffff;
  mode = __p__fmode();
  *mode = _fmode;
  mode_2 = __p__commode();
  *mode_2 = _commode;
  _adjust_fdiv = *(int *)_adjust_fdiv_exref;
  _setargv();
  if (__defaultmatherr == 0) {
    __setusermatherr(&_matherr);
  }
  _setdefaultprecision();
  _initterm(__xi_a,__xi_z);
  startup.newmode = _newmode;
  __getmainargs(&argc,&argv,&envp,_dowildcard,&startup);
  _initterm(__xc_a,__xc_z);
  initenv = __p___initenv();
  *initenv = envp;
  ret = cl_main(argc,argv);
  exit(ret);
}

