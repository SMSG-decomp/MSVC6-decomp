void __cdecl pch_relocate_name_chain(void *entry)

{
  void *p;
  
  for (; entry != (uint *)0x0; entry = *(void **)entry) {
    pch_relocate_slot_once(&g_pch_image,entry);
    pch_relocate_slot_once(&g_pch_image,(uint *)((int)entry + 4));
    pch_relocate_slot_once(&g_pch_image,(uint *)((int)entry + 0xc));
    p = *(void **)((int)entry + 0xc);
    if (p != (void *)0x0) {
      pch_relocate_pair(p);
    }
  }
  return;
}

