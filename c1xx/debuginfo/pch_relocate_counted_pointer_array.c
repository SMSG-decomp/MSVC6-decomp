void __fastcall pch_relocate_counted_pointer_array(uint *array)

{
  uint *slot;
  uint uVar1;
  
  slot = array + 1;
  pch_relocate_slot_once(&g_pch_image,slot);
  if ((*slot != 0) && (uVar1 = 0, *array != 0)) {
    do {
      pch_relocate_slot_once(&g_pch_image,(uint *)(*slot + uVar1 * 4));
      uVar1 = uVar1 + 1;
    } while (uVar1 < *array);
  }
  return;
}

