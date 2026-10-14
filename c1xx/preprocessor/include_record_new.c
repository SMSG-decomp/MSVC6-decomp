c1_u8 * __cdecl include_record_new(int a,int b)

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
    *(c1_u8 *)((int)pfVar1 + 4) = '\x15';
    *(int *)pfVar1 = a;
  }
  pfVar1->canonical_name = (fe_name *)b;
  if (g_current_scope->file_records != (fe_file_record *)0x0) {
    pfVar1->next = g_current_scope->file_records;
  }
  g_current_scope->file_records = pfVar1;
  return (c1_u8 *)pfVar1;
}

