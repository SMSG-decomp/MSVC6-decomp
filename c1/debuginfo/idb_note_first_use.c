int __fastcall idb_note_first_use(c1_idb_state *idb)

{
  uchar *puVar1;
  
  if ((idb->state != 1) && (idb->state != 5)) {
    puVar1 = &(idb->file).current.flags;
    *puVar1 = *puVar1 | 8;
  }
  return 1;
}

