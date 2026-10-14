int __thiscall idb_check_options(c1xx_idb *idb,int options_signature,int *result_out)

{
  int iVar1;
  
  if ((idb->file).regions.count == 0) {
    *result_out = 0;
    idb->options_signature = options_signature;
    return 1;
  }
  if (idb->options_signature == options_signature) {
    *result_out = 2;
    idb->options_signature = options_signature;
    return 1;
  }
  *result_out = 1;
  if ((idb->file).cursor == 0) {
    iVar1 = (*idb->vtbl->idb_invalidate)(idb);
    if (iVar1 != 0) {
      idb->options_signature = options_signature;
      return 1;
    }
  }
  return 0;
}

