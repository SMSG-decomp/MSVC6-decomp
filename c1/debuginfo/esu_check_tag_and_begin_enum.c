c1_tag_symbol * __cdecl esu_check_tag_and_begin_enum(c1_tag_symbol *tag,ushort specifier_code)

{
  c1_tag_symbol *sym;
  
  sym = class_check_tag_kind_consistency(tag,specifier_code);
  if (sym == (c1_tag_symbol *)0x0) {
    return (c1_tag_symbol *)0x0;
  }
  if (((sym->flags2 & 1) == 0) && ((specifier_code & 0x100) != 0)) {
    g_current_enum_type = sym->type;
    g_enum_last_value = 0xffffffff;
    g_enum_last_value_high = -1;
    sym->size = 4;
    sym->flags1 = sym->flags1 | 1;
    g_current_enum_tag = sym;
    if ((g_browse_file != (char *)0x0) &&
       (((g_block_depth == '\0' || (g_opt_FR_browse != 0)) && (sym->name != g_name_unnamed)))) {
      (*g_il_emitter->vtbl->begin_block)();
      (*g_il_emitter->vtbl->define_symbol)(g_il_emitter,(c1_symbol *)sym);
      (*g_il_emitter->vtbl->set_owner)(sym);
    }
  }
  return sym;
}

