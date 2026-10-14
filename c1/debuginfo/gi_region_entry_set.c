fe_idb_region * __thiscall
gi_region_entry_set(fe_idb_region *region,byte kind,int hash_lo,int hash_hi,short start_line,
                   byte flag)

{
  region->signature = hash_lo;
  region->start_line = start_line;
  region->length = hash_hi;
  region->line_count = 0;
  region->flags = (flag & 1) << 4 | kind & 7;
  return region;
}

