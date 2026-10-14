void __cdecl pch_relocate_segment_table(void)

{
  pch_relocate_symtab_entries(g_segment_record_table,(void *)0x0,(void *)0x0);
  return;
}

