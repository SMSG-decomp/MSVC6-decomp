void __fastcall pdb_blob_stream_destroy(int *table)

{
  int *piVar1;
  int *cell;
  
  cell = (int *)table[2];
  while (cell != (int *)0x0) {
    piVar1 = (int *)*cell;
    __3_YAXPAX_Z((void *)cell[1]);
    __3_YAXPAX_Z((void *)cell[3]);
    __3_YAXPAX_Z(cell);
    cell = piVar1;
  }
  table[2] = 0;
  if ((int *)*table != (int *)0x0) {
    (**(code **)(*(int *)*table + 0x18))();
    *table = 0;
  }
  return;
}

