void * __fastcall import_enum_table_init(void *table)

{
  int iVar1;
  uint *cursor;
  
  cursor = table;
  for (iVar1 = 0x100; iVar1 != 0; iVar1 = iVar1 + -1) {
    *cursor = 0;
    cursor = cursor + 1;
  }
  return table;
}

