char __cdecl pdb_blob_stream_open(PDB *pdb,char *name,fe_pdb_blob_table **out)

{
  char cVar1;
  fe_pdb_blob_table *pfVar2;
  int iVar3;
  
  pfVar2 = __2_YAPAXI_Z(0x10);
  if (pfVar2 != (fe_pdb_blob_table *)0x0) {
    pfVar2 = pdb_blob_stream_init(pfVar2);
    if (pfVar2 != (fe_pdb_blob_table *)0x0) {
      iVar3 = (*pdb->vtbl->OpenStream)(pdb,name,&pfVar2->stream);
      if (iVar3 != 0) {
        cVar1 = pdb_blob_stream_load(pfVar2);
        if (cVar1 != '\0') {
          *out = pfVar2;
          return '\x01';
        }
      }
      pdb_blob_stream_destroy(pfVar2);
      __3_YAXPAX_Z(pfVar2);
    }
  }
  *out = (fe_pdb_blob_table *)0x0;
  return '\0';
}

