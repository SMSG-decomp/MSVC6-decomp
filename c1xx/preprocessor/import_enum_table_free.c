void __fastcall import_enum_table_free(void *table)

{
  int iVar1;
  uint *cell;
  uint *next;
  
  iVar1 = 0x100;
  do {
    cell = *(uint **)table;
    while (cell != (uint *)0x0) {
      next = (uint *)*cell;
      __3_YAXPAX_Z(cell);
      cell = next;
    }
    table = (void *)((int)table + 4);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

