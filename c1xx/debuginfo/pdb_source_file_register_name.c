uint __fastcall pdb_source_file_register_name(c1_source_file_record *rec)

{
  int iVar1;
  c1_source_file_record **ppcVar2;
  c1_source_file_record *local_4;
  
  ppcVar2 = &local_4;
  local_4 = rec;
  iVar1 = (*g_pdb_gi->namemap->vtbl->get_ni)(rec->name,&local_4);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = CONCAT31((int3)((uint)iVar1 >> 8),rec->tracked);
  if (rec->tracked != '\0') {
    iVar1 = (*rec->file->vtbl->open_recorder)(&g_mre_engine,ppcVar2);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}

