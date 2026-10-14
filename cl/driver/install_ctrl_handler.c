void __cdecl install_ctrl_handler(void)

{
  SetConsoleCtrlHandler(cl_ctrl_handler,1);
  return;
}

