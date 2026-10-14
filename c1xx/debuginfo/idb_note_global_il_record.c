int __fastcall idb_note_global_il_record(c1xx_idb *idb)

{
  c1_u8 *pcVar1;
  
  if ((idb->state != 1) && (idb->state != 5)) {
    pcVar1 = &(idb->file).current.flags;
    *pcVar1 = *pcVar1 | 0x10;
  }
  return 1;
}

