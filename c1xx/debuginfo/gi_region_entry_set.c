c1_idb_region * __thiscall
gi_region_entry_set(c1_idb_region *region,byte kind,int signature,int length,short start_line,
                   byte no_reuse)

{
  region->signature = signature;
  region->start_line = start_line;
  region->length = length;
  region->line_count = 0;
  region->flags = (no_reuse & 1) << 4 | kind & 7;
  return region;
}

