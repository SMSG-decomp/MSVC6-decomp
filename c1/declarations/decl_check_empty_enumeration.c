c1_type * decl_check_empty_enumeration(void)

{
  int iVar1;
  
  if ((g_ms_extensions == '\0') &&
     (iVar1 = symtab_entry_count(((g_current_enum_type->extra).sym)->tag_members), iVar1 == 0)) {
    diag_error(0x8a);
  }
  if (((((g_current_enum_type->extra).sym)->name != g_name_unnamed) &&
      (g_browse_file != (char *)0x0)) && ((g_block_depth == '\0' || (g_opt_FR_browse != 0)))) {
    (*g_il_emitter->vtbl->end_block)();
  }
  g_compile_flags_c8 = g_compile_flags_c8 | 0x400;
  return g_type_int;
}

