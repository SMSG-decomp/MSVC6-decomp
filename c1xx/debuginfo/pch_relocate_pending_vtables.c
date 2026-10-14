void __cdecl pch_relocate_pending_vtables(void)

{
  if (g_pending_vtable_classes != (short *)0x0) {
    pch_fixup_counted_pointer_array(g_pending_vtable_classes,(void *)0x0);
  }
  return;
}

