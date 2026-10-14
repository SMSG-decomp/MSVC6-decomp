void __cdecl browse_record_fill_member_reference(byte *rec,c1_symbol *sym)

{
  if (((g_browse_excluded_kinds[sym->kind & 0x1f] == 0) && (g_browse_skip_symbol != sym)) &&
     ((sym->flags3 & 1) == 0)) {
    if ((sym->kind & 0x1f) == 4) {
      if ((((sym->detail).cls)->flags3e & 2) != 0) goto code_r0x1046928e;
      if ((((sym->detail).cls)->flags3f & 0x80) != 0) {
        browse_record_set_kind14(rec);
        return;
      }
    }
    if ((g_compile_flags_c8 & 0x10000000) == 0) {
      (*g_il_emitter->vtbl->entity_id)(g_il_emitter,sym);
      decl_position_set_symbol((c1xx_browse_record *)rec,sym);
      return;
    }
  }
code_r0x1046928e:
  *rec = 0x14;
  return;
}

