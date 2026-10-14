void __fastcall pdb_array_destroy(Array_DWORD *array)

{
  if (array->rgt != (ulong *)0x0) {
    __3_YAXPAX_Z(array->rgt);
  }
  return;
}

