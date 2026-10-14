void __cdecl browse_record_fill_reference(c1_browse_record *rec,c1_symbol *sym)

{
  char cVar1;
  
  rec->kind = '\x14';
  if (((g_browse_symbol_kind_excluded[sym->kind & 0x1f] == 0) && (g_browse_skip_symbol != sym)) &&
     ((sym->flags1 & 0x40) == 0)) {
    cVar1 = sym_check_owner_scope((char *)rec,sym);
    if (cVar1 == '\0') {
      browse_record_set_symbol(rec,sym);
      rec->kind = '\x04';
    }
    return;
  }
  rec->kind = '\x14';
  return;
}

