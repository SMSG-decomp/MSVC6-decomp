void __cdecl browse_record_fill_owner(c1_browse_record *rec,c1_symbol *sym)

{
  if (((g_browse_symbol_kind_excluded[sym->kind & 0x1f] == 0) && (g_browse_skip_symbol != sym)) &&
     ((sym->flags1 & 0x40) == 0)) {
    (*g_il_emitter->vtbl->entity_id)(g_il_emitter,sym);
    browse_record_set_symbol(rec,sym);
    return;
  }
  rec->kind = '\x14';
  return;
}

