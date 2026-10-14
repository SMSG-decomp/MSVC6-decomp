void __thiscall import_enum_table_get(void *table,char **enum_name,int *value)

{
  *enum_name = *(char **)(*(int *)((int)table + 0x408) + 8);
  *value = *(int *)(*(int *)((int)table + 0x408) + 0xc);
  return;
}

