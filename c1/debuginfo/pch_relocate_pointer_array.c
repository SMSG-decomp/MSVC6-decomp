void __cdecl pch_relocate_pointer_array(uint slots,int count)

{
  if ((slots != 0) && (0 < count)) {
    do {
      pch_relocate_slot_once(&g_pch_image,slots);
      slots = slots + 4;
      count = count + -1;
    } while (count != 0);
  }
  return;
}

