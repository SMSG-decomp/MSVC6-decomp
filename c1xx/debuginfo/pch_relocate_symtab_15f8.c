void __cdecl pch_relocate_symtab_15f8(void)

{
  g_compile_flags_c8 = g_compile_flags_c8 | 0x10000000;
  pch_relocate_symtab_entries
            (g_template_default_arguments,(void *)0x0,pch_relocate_template_argument_list);
  g_compile_flags_c8 = g_compile_flags_c8 & 0xefffffff;
  return;
}

