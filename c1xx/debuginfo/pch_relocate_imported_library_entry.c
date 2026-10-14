void __cdecl pch_relocate_imported_library_entry(int entry)

{
  pch_relocate_slot_once(&g_pch_image,(uint *)(entry + 0x10));
  return;
}

