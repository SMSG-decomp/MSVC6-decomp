int __fastcall idb_note_pragma_begin(c1xx_idb *idb)

{
  c1xx_idb_vtbl *pcVar1;
  int iVar2;
  c1_idb_class_record *pcVar3;
  c1_idb_class_record *pcVar4;
  bool bVar5;
  
  iVar2 = 5;
  bVar5 = true;
  pcVar3 = &(idb->file).pending_class;
  pcVar4 = &g_idb_empty_class_record;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = pcVar3->class_ni == pcVar4->class_ni;
    pcVar3 = (c1_idb_class_record *)&pcVar3->first_region;
    pcVar4 = (c1_idb_class_record *)&pcVar4->first_region;
  } while (bVar5);
  if (!bVar5) {
    pcVar1 = idb->vtbl;
    (idb->file).current.flags = (idb->file).current.flags | 8;
    iVar2 = (*pcVar1->idb_note_layout_dependency)(idb);
    return iVar2;
  }
  return 1;
}

