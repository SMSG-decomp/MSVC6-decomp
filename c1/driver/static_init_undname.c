void __cdecl static_init_undname(void)

{
  if (g_msvcrt_module != (HMODULE)0x0) {
    _g_undecorate_hook = GetProcAddress(g_msvcrt_module,"__unDNameEx");
    return;
  }
  _g_undecorate_hook = (FARPROC)0x0;
  return;
}

