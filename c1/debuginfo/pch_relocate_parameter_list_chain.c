void __cdecl pch_relocate_parameter_list_chain(uint *entry)

{
  for (; entry != (uint *)0x0; entry = (uint *)*entry) {
    pch_relocate_slot_once(&g_pch_image,(uint)entry);
    pch_relocate_counted_slot_array((int *)(entry + 1));
  }
  return;
}

