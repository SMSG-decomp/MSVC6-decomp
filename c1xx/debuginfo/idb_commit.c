int __fastcall idb_commit(c1xx_idb *idb)

{
  int iVar1;
  
  iVar1 = idb_write_dependencies(idb);
  if (iVar1 == 0) {
    return 0;
  }
  if ((idb->regions_disabled == '\0') && (iVar1 = idb_write_regions(idb), iVar1 == 0)) {
    return 0;
  }
  return 1;
}

