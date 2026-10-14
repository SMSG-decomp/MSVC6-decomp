void __fastcall idb_note_access_declaration(c1_idb_state *idb)

{
  (*idb->vtbl->idb_note_layout_dependency)(idb);
  return;
}

