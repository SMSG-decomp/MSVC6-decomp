int __fastcall idb_in_function(c1xx_idb *idb)

{
  if ((idb->in_function != '\0') && (g_gm_forced_incremental == '\0')) {
    return 1;
  }
  return 0;
}

