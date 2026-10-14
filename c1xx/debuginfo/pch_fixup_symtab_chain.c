void __cdecl
pch_fixup_symtab_chain(void *entry,void *key_fn,void *value_fn,char fix_key,char fix_value)

{
  for (; entry != (uint *)0x0; entry = *(void **)((int)entry + 8)) {
    if (fix_key != '\0') {
      pch_relocate_slot_once(&g_pch_image,entry);
    }
    if (fix_value != '\0') {
      pch_relocate_slot_once(&g_pch_image,(uint *)((int)entry + 4));
    }
    pch_relocate_slot_once(&g_pch_image,(uint *)((int)entry + 8));
    if (key_fn != (void *)0x0) {
      (*key_fn)(*(uint *)entry);
    }
    if (value_fn != (void *)0x0) {
      (*value_fn)(*(uint *)((int)entry + 4));
    }
  }
  return;
}

