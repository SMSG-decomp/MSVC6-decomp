int __thiscall idb_note_pragma(c1_idb_state *idb,int pragma)

{
  (idb->file).current.flags = (idb->file).current.flags | 8;
  return 1;
}

