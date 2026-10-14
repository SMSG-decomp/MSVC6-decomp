void msvcrt_handle_init(void)

{
  g_msvcrt_module_borrowed = 1;
  g_msvcrt_module = GetModuleHandleA("msvcrt.dll");
  return;
}

