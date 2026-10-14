void __cdecl pch_fixup_counted_pointer_array(short *arr,void *callback)

{
  uint *slot;
  int iVar1;
  
  if ((arr != (short *)0x0) && (iVar1 = 0, slot = (uint *)arr, 0 < *arr)) {
    do {
      slot = slot + 1;
      pch_relocate_slot_once(&g_pch_image,slot);
      if (callback != (void *)0x0) {
        (*callback)(*slot);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *arr);
  }
  return;
}

