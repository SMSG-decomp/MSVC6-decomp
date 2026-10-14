void __fastcall idb_note_access_declaration(c1xx_idb *idb)

{
  (*idb->vtbl->idb_note_layout_dependency)(idb);
  return;
}

