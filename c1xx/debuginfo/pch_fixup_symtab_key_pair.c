void __cdecl pch_fixup_symtab_key_pair(int key)

{
  pch_relocate_slot_once(&g_pch_image,(uint *)key);
  pch_relocate_slot_once(&g_pch_image,(uint *)(key + 4));
  return;
}

