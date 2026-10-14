void __cdecl pch_relocate_scope_vector(void)

{
  if (g_scope_vector != (c1_symbol_vector *)0x0) {
    pch_fixup_counted_pointer_array((short *)g_scope_vector,(void *)0x0);
  }
  return;
}

