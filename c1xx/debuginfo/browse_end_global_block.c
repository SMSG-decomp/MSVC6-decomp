int __cdecl browse_end_global_block(void)

{
  if ((((((g_current_enum_type->extra).cls)->flags3 & 1) == 0) && (g_browse_file != (char *)0x0)) &&
     ((g_block_depth == '\0' || (g_opt_FR_browse != 0)))) {
    (*g_il_emitter->vtbl->end_block)();
  }
  return (int)g_current_enum_type;
}

