void __cdecl decl_warn_enum_value_out_of_range(c1_u32 value_lo,int value_hi,c1_symbol *sym)

{
  int level;
  
  if (value_hi != 0) {
    if (g_ms_extensions == '\0') {
      level = 1;
    }
    else {
      level = 3;
    }
    diag_warning(level,0x155,sym);
  }
  (sym->x28).value = value_lo;
  g_enum_last_value = value_lo;
  g_enum_last_value_high = value_hi;
  if ((g_browse_file != (char *)0x0) && ((g_block_depth == '\0' || (g_opt_FR_browse != 0)))) {
    (*g_il_emitter->vtbl->define_symbol)(g_il_emitter,sym);
  }
  return;
}

