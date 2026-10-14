void __cdecl pch_fixup_global_roots(void)

{
  void **slot;
  
  slot = &g_pch_saved_globals;
  do {
    pch_relocate_pointer(&g_pch_image,(uint *)slot);
    slot = slot + 1;
  } while (slot < (void **)((int)&g_type_hash + 1U));
  pch_relocate_line_map_pointer();
  return;
}

