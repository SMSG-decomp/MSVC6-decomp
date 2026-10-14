c1_symbol * __cdecl decl_tag_check_kind_and_browse(c1_symbol *sym,int kind)

{
  c1_symbol *a;
  
  if (sym == (c1_symbol *)0x0) {
    return (c1_symbol *)0x0;
  }
  a = class_check_tag_kind_consistency(sym,(c1_u16)kind);
  if ((g_browse_file != (char *)0x0) && ((g_block_depth == '\0' || (g_opt_FR_browse != 0)))) {
    (*g_il_emitter->vtbl->reference_symbol)((int)a);
  }
  return a;
}

