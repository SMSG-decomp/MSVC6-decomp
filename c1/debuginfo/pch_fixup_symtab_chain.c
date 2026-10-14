void __cdecl
pch_fixup_symtab_chain
          (fe_symtab_entry *entry,void *key_fn,void *value_fn,char fix_key,char fix_value)

{
  for (; entry != (fe_symtab_entry *)0x0; entry = entry->next) {
    if (fix_key != '\0') {
      pch_relocate_slot_once(&g_pch_image,(uint)entry);
    }
    if (fix_value != '\0') {
      pch_relocate_slot_once(&g_pch_image,(uint)&entry->value);
    }
    pch_relocate_slot_once(&g_pch_image,(uint)&entry->next);
    if (key_fn != (void *)0x0) {
      (*key_fn)(entry->key);
    }
    if (value_fn != (void *)0x0) {
      (*value_fn)(entry->value);
    }
  }
  return;
}

