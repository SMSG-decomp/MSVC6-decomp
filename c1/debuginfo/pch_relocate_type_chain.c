void __cdecl pch_relocate_type_chain(uint *entry)

{
  for (; entry != (uint *)0x0; entry = (uint *)*entry) {
    pch_relocate_slot_once(&g_pch_image,(uint)entry);
    pch_relocate_type_descriptor((c1_type *)(entry + 1));
  }
  return;
}

