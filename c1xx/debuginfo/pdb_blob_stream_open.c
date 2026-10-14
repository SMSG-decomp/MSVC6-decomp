char __cdecl pdb_blob_stream_open(c1xx_pdb *pdb,char *name,c1_pdb_blob_table **out)

{
  char cVar1;
  c1_pdb_blob_table *pcVar2;
  int iVar3;
  
  pcVar2 = __2_YAPAXI_Z(0x10);
  if (pcVar2 != (c1_pdb_blob_table *)0x0) {
    pcVar2 = pdb_blob_stream_init(pcVar2);
    if (pcVar2 != (c1_pdb_blob_table *)0x0) {
      iVar3 = (*pdb->vtbl->open_stream)(name,pcVar2);
      if (iVar3 != 0) {
        cVar1 = pdb_blob_stream_load(pcVar2);
        if (cVar1 != '\0') {
          *out = pcVar2;
          return '\x01';
        }
      }
      pdb_blob_stream_destroy((int *)pcVar2);
      __3_YAXPAX_Z(pcVar2);
    }
  }
  *out = (c1_pdb_blob_table *)0x0;
  return '\0';
}

