void __cdecl pch_relocate_name_chain(uint *entry)

{
  uint slots;
  
  for (; entry != (uint *)0x0; entry = (uint *)*entry) {
    pch_relocate_slot_once(&g_pch_image,(uint)entry);
    pch_relocate_slot_once(&g_pch_image,(uint)(entry + 1));
    pch_relocate_slot_once(&g_pch_image,(uint)(entry + 3));
    slots = entry[3];
    if (slots != 0) {
      pch_relocate_pair(slots);
    }
  }
  return;
}

