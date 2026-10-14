void __cdecl sym_recycle_record(c1_symbol *sym)

{
  int iVar1;
  
  if (((((g_block_depth == '\0') || (-1 < g_class_depth)) ||
       ((g_compile_flags_c8 & 0x10000000) != 0)) ||
      ((((g_compile_flags_c8 & 0x40000000) != 0 && (((byte)g_compile_flags_cc & 8) == 0)) &&
       ((g_compile_flags_c4 & 0x200) == 0)))) || (((byte)g_compile_flags_cc & 0x50) != 0)) {
    iVar1 = g_symbol_size_class_table[sym->kind & 0x1f];
    sym->next = (c1_symbol *)g_symbol_free_lists[iVar1];
    g_symbol_free_lists[iVar1] = (uint *)&sym->name;
  }
  return;
}

