void __cdecl pch_relocate_pending_special_members(void)

{
  if (g_pending_special_members != (c1_symbol_vector *)0x0) {
    pch_fixup_counted_pointer_array((short *)g_pending_special_members,(void *)0x0);
  }
  return;
}

