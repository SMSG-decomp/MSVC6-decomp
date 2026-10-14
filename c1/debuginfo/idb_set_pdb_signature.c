int __thiscall idb_set_pdb_signature(c1_idb_state *idb,int signature,uint age)

{
  int iVar1;
  
  if ((idb->pdb_signature != signature) || (age < idb->pdb_age)) {
    idb->pdb_signature = signature;
    iVar1 = (*idb->vtbl->idb_invalidate)(idb);
    if (iVar1 == 0) {
      return 0;
    }
  }
  idb->pdb_age = age;
  return 1;
}

