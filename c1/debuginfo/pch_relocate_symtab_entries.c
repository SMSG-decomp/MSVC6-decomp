void __cdecl pch_relocate_symtab_entries(fe_symtab *tab,void *key_fn,void *value_fn)

{
  fe_symtab_entry ***slot;
  uint uVar1;
  
  if (tab != (fe_symtab *)0x0) {
    slot = &tab->buckets;
    pch_relocate_slot_once(&g_pch_image,(uint)slot);
    uVar1 = 0;
    if (tab->nbuckets != 0) {
      do {
        pch_relocate_slot_once(&g_pch_image,(uint)(*slot + uVar1));
        pch_fixup_symtab_chain((*slot)[uVar1],key_fn,value_fn,tab->flags & 1,tab->flags >> 1 & 1);
        uVar1 = uVar1 + 1;
      } while (uVar1 < tab->nbuckets);
    }
  }
  return;
}

