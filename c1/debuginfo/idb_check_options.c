int __thiscall idb_check_options(c1_idb_state *idb,int signature,int *result)

{
  int iVar1;
  
  if ((idb->file).regions.count == 0) {
    *result = 0;
    idb->options_signature = signature;
    return 1;
  }
  if (idb->options_signature == signature) {
    *result = 2;
    idb->options_signature = signature;
    return 1;
  }
  *result = 1;
  if ((idb->file).cursor == 0) {
    iVar1 = (*idb->vtbl->idb_invalidate)(idb);
    if (iVar1 != 0) {
      idb->options_signature = signature;
      return 1;
    }
  }
  return 0;
}

