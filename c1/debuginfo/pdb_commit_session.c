byte __fastcall pdb_commit_session(c1_pdb_state *pdb)

{
  NameMap *this;
  TPI *this_00;
  char cVar1;
  int iVar2;
  
  if (pdb->pdb == (PDB *)0x0) {
    return 1;
  }
  if (pdb->read_only != '\0') {
    return 1;
  }
  this = pdb->name_map;
  if (this != (NameMap *)0x0) {
    iVar2 = (*this->vtbl->commit)(this);
    if (iVar2 == 0) {
      return 0;
    }
  }
  this_00 = pdb->tpi;
  if (this_00 != (TPI *)0x0) {
    iVar2 = (*this_00->vtbl->Commit)(this_00);
    if (iVar2 == 0) {
      return 0;
    }
  }
  if (pdb->stream_table != (fe_pdb_blob_table *)0x0) {
    cVar1 = pdb_blob_stream_flush(pdb->stream_table);
    if (cVar1 == '\0') {
      return 0;
    }
  }
  iVar2 = (*pdb->pdb->vtbl->Commit)(pdb->pdb);
  return iVar2 != 0;
}

