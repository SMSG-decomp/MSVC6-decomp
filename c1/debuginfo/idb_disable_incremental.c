void __fastcall idb_disable_incremental(c1_idb_state *idb)

{
  (*idb->vtbl->idb_force_recompile)(idb);
  idb->regions_disabled = '\x01';
  return;
}

