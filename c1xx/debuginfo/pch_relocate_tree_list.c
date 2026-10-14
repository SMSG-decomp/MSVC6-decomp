void __cdecl pch_relocate_tree_list(void **list)

{
  char cVar1;
  
  for (; list != (void **)0x0; list = *list) {
    pch_relocate_slot_once(&g_pch_image,(uint *)list);
    cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)(list + 1));
    if (cVar1 != '\0') {
      pch_relocate_tree(list[1]);
    }
  }
  return;
}

