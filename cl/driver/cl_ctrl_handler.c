int cl_ctrl_handler(ulong ctrl_type)

{
  g_ctrl_c_seen = 1;
  if (g_pass_running == 0) {
    SetConsoleCtrlHandler((PHANDLER_ROUTINE)0x0,1);
    cl_exit(4);
  }
  if ((g_current_pass->flags & 4) != 0) {
    (*g_current_pass->abort)(2);
  }
  return 1;
}

