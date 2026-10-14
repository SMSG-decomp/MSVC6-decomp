int __cdecl c1_run_exit_handlers(void)

{
  void *local_14;
  undefined *puStack_10;
  sehtable_entry *psStack_c;
  int try_level;
  
  psStack_c = &g_run_exit_handlers_scope_table;
  puStack_10 = &_except_handler3;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  while (0 < g_atexit_count) {
    try_level = 0;
    g_atexit_count = g_atexit_count + -1;
    (*g_atexit_table[g_atexit_count])();
  }
  ExceptionList = local_14;
  return 0;
}

