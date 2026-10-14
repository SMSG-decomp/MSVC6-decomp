void __fastcall idb_note_sizeof(c1_idb_state *idb)

{
  (*idb->vtbl->idb_note_layout_dependency)(idb);
  return;
}

