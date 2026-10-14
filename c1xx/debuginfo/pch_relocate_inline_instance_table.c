void __cdecl pch_relocate_inline_instance_table(void)

{
  pch_relocate_symtab_entries
            (g_vcall_thunk_table,pch_relocate_vcall_thunk_key,pch_relocate_symbol_chain);
  return;
}

