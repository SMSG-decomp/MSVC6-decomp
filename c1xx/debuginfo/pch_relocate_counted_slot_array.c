void __cdecl pch_relocate_counted_slot_array(int *array)

{
  int iVar1;
  uint *slot;
  
  iVar1 = 0;
  if (0 < *array) {
    slot = (uint *)(array + 2);
    do {
      pch_relocate_slot_once(&g_pch_image,slot);
      iVar1 = iVar1 + 1;
      slot = slot + 1;
    } while (iVar1 < *array);
  }
  return;
}

