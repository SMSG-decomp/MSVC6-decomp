void __cdecl pch_relocate_attribute_tables(void)

{
  pch_relocate_symtab_entries(PTR_104d15e0,(void *)0x0,(void *)0x0);
  pch_relocate_symtab_entries(g_clone_attribute_table,(void *)0x0,(void *)0x0);
  pch_relocate_symtab_entries(g_vcall_attribute_table,(void *)0x0,(void *)0x0);
  pch_relocate_symtab_entries(g_debug_type_by_id_table,(void *)0x0,(void *)0x0);
  return;
}

