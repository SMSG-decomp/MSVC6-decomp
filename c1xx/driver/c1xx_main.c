int __cdecl c1xx_main(int argc,char **argv)

{
  int iVar1;
  void *pvStackY_14;
  
  g_compile_phase = 1;
  token_buffers_init();
  c1xx_atexit(c1xx_main_exit_handler);
  g_option_args_left = argc;
  g_option_argv_cursor = argv;
  pvStackY_14 = (void *)0x10444d10;
  opt_prescan_memory_switches(argv);
  c1xx_main_stub();
  GetSystemInfo((LPSYSTEM_INFO)&g_system_info);
  arenas_init_all();
  pvStackY_14 = (void *)0x10444d2f;
  opt_parse_command_line(argc,argv);
  if (g_opt_debugBreak != '\0') {
    DebugBreak();
  }
  if (g_c9il_mode == '\0') {
    g_compile_flags_cc = g_compile_flags_cc & 0xffffdfff;
  }
  else {
    g_compile_flags_cc = g_compile_flags_cc | 0x2000;
  }
  pvStackY_14 = ExceptionList;
  ExceptionList = &pvStackY_14;
  iVar1 = c1xx_compile();
  ExceptionList = pvStackY_14;
  return iVar1;
}

