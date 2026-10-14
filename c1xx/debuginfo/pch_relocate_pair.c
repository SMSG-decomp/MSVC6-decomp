void __cdecl pch_relocate_pair(void *p)

{
  pch_relocate_slot_once(&g_pch_image,p);
  pch_relocate_slot_once(&g_pch_image,(uint *)((int)p + 4));
  return;
}

