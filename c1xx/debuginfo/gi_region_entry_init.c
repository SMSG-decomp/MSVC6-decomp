void __thiscall gi_region_entry_init(c1_idb_region *region,byte kind)

{
  region->length = -1;
  region->signature = 0;
  region->start_line = 0;
  region->line_count = 0;
  region->flags = kind & 7 | 0x18;
  return;
}

