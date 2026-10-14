void __fastcall idb_region_ctor(fe_idb_region *region)

{
  region->length = -1;
  region->signature = 0;
  region->start_line = 0;
  region->line_count = 0;
  region->flags = '\x18';
  return;
}

