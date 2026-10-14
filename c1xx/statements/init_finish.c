void __cdecl init_finish(c1_symbol *sym)

{
  init_finish_variable(sym);
  if ((g_compile_flags_cc & 0x800) != 0) {
    g_compile_flags_cc = g_compile_flags_cc & 0xfffff7ff;
    sym->flags4 = sym->flags4 & 0xfb;
  }
  return;
}

