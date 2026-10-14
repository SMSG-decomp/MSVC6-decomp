int __fastcall idb_note_special_members(c1xx_idb *idb)

{
  c1_u8 *pcVar1;
  
  if ((idb->state != 1) && (idb->state != 5)) {
    pcVar1 = &(idb->file).current.flags;
    *pcVar1 = *pcVar1 | 8;
  }
  return 1;
}

