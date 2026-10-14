void __cdecl init_warn_local_static_thread_safety(c1_symbol *sym)

{
  if ((((g_compile_flags_c4 & 0x20000) != 0) && ((sym->storage & 7) == 3)) &&
     ((g_compile_flags_c4 & 0x20) == 0)) {
    diag_warning(3,0x280,sym);
    init_static_guard_begin();
  }
  return;
}

