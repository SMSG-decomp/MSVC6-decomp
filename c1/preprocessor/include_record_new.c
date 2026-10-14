c1_u8 * include_record_new(void *name,void *canonical_name)

{
  fe_file_record *pfVar1;
  
  pfVar1 = (fe_file_record *)g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 0x18;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  if (pfVar1 == (fe_file_record *)0x0) {
    pfVar1 = (fe_file_record *)0x0;
  }
  else {
    *(uchar *)((int)pfVar1 + 4) = '\x15';
    pfVar1->name = name;
  }
  pfVar1->canonical_name = canonical_name;
  if (g_current_scope->file_records != (fe_file_record *)0x0) {
    pfVar1->next = g_current_scope->file_records;
  }
  g_current_scope->file_records = pfVar1;
  return (c1_u8 *)pfVar1;
}

