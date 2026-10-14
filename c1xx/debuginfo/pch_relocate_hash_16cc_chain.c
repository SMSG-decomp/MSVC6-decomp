void __cdecl pch_relocate_hash_16cc_chain(void *entry)

{
  for (; entry != (uint *)0x0; entry = *(void **)entry) {
    pch_relocate_slot_once(&g_pch_image,entry);
    pch_relocate_counted_slot_array((int *)((int)entry + 4));
  }
  return;
}

