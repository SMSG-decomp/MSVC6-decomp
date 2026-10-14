int __fastcall idb_note_layout_dependency(c1xx_idb *idb)

{
  (idb->file).current.flags = (idb->file).current.flags | 0x40;
  return 1;
}

