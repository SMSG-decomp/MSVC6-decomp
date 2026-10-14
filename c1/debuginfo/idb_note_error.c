int __fastcall idb_note_error(c1_idb_state *idb)

{
  uchar *puVar1;
  
  if ((idb->state != 1) && (idb->state != 5)) {
    puVar1 = &(idb->file).current.flags;
    *puVar1 = *puVar1 | 0x10;
  }
  return 1;
}

