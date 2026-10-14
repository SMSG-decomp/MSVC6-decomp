int __thiscall idb_note_pragma_output(c1xx_idb *idb,int pragma_kind)

{
  c1_u8 *pcVar1;
  
  if ((idb->state != 1) && (idb->state != 5)) {
    pcVar1 = &(idb->file).current.flags;
    *pcVar1 = *pcVar1 | 0x10;
  }
  return 1;
}

