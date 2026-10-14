void __cdecl pch_relocate_global_1b70(void)

{
  c1_symbol *sym;
  char cVar1;
  
  sym = g_empty_list_sentinel;
  if (g_empty_list_sentinel != (c1_symbol *)0x0) {
    pch_relocate_slot_once(&g_pch_image,(uint *)&g_empty_list_sentinel->name);
    pch_relocate_symbol(&sym->kind);
    pch_relocate_slot_once(&g_pch_image,(uint *)&(sym->detail).value);
    cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)&sym->next);
    if (cVar1 != '\0') {
      pch_relocate_symbol_list_simple((int)sym->next);
    }
  }
  return;
}

