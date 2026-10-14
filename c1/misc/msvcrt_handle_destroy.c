void __cdecl msvcrt_handle_destroy(void)

{
  if ((g_msvcrt_module != (HMODULE)0x0) && (g_msvcrt_module_borrowed == 0)) {
    FreeLibrary(g_msvcrt_module);
  }
  g_msvcrt_module = (HMODULE)0x0;
  return;
}

