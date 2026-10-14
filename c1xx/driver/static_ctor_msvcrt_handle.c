void __cdecl static_ctor_msvcrt_handle(void)

{
  g_msvcrt_module_borrowed = '\x01';
  g_msvcrt_module = GetModuleHandleA("msvcrt.dll");
  return;
}

