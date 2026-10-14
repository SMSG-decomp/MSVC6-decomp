int __thiscall idb_tracker_note(c1xx_idb *idb,int class_ni,char *member_name)

{
  c1_mre_file *pcVar1;
  int iVar2;
  
  pcVar1 = (idb->file).tracker;
  if (pcVar1 != (c1_mre_file *)0x0) {
    iVar2 = (*pcVar1->vtbl->note_inline_method_mod)(class_ni,member_name,8);
    return iVar2;
  }
  return 1;
}

