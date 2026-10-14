void __cdecl pch_relocate_type_chain(void *entry)

{
  for (; entry != (uint *)0x0; entry = *(void **)entry) {
    pch_relocate_slot_once(&g_pch_image,entry);
    pch_relocate_type_descriptor((ushort *)((int)entry + 4));
  }
  return;
}

