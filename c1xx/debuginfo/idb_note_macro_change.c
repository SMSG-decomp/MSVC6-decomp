void __fastcall idb_note_macro_change(c1xx_idb *idb)

{
  (idb->file).current.flags = (idb->file).current.flags | 8;
  (*idb->vtbl->idb_note_layout_dependency)(idb);
  return;
}

