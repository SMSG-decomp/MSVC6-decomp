void __cdecl keywords_intern(void)

{
  char *pcVar1;
  void *pvVar2;
  void **ppvVar3;
  void ***slot_cursor;
  char **row;
  
  row = &g_keyword_table;
  do {
    pvVar2 = name_intern(row[1]);
    pcVar1 = *row;
    row = row + 2;
    *(void **)pcVar1 = pvVar2;
  } while (*row != (char *)0x0);
  ppvVar3 = &g_name_main;
  slot_cursor = g_entry_point_name_slots;
  do {
    slot_cursor = slot_cursor + 1;
    *(uint *)((int)*ppvVar3 + 8) = *(uint *)((int)*ppvVar3 + 8) | 0x40000000;
    ppvVar3 = *slot_cursor;
  } while (ppvVar3 != (void **)0x0);
  return;
}

