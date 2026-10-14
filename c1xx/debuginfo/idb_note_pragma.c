int __thiscall idb_note_pragma(c1xx_idb *idb,int pragma_kind)

{
  (idb->file).current.flags = (idb->file).current.flags | 8;
  return 1;
}

