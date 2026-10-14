int __fastcall idb_note_line_dependency(c1xx_idb *idb)

{
  byte bVar1;
  
  if ((idb->state != 1) && (idb->state != 5)) {
    (idb->file).current.flags = (idb->file).current.flags | 0x20;
    return 1;
  }
  if (((idb->include_stack).count != 0) &&
     (((idb->file).untracked == '\0' && (bVar1 = (idb->file).current.flags, (bVar1 & 7) == 2)))) {
    (idb->file).current.flags = bVar1 | 0x20;
  }
  return 1;
}

