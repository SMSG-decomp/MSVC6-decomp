int __cdecl c1xx_run_exit_handlers(void)

{
  void *local_14;
  void *seh_handler;
  c1_seh_scope *seh_scope_table;
  int seh_try_level;
  
  seh_scope_table = &g_run_exit_handlers_scope_table;
  seh_handler = &_except_handler3;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  while (0 < g_atexit_count) {
    seh_try_level = 0;
    g_atexit_count = g_atexit_count + -1;
    (**(code **)(&g_atexit_table + g_atexit_count * 4))();
  }
  ExceptionList = local_14;
  return 0;
}

