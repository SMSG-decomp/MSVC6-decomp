void __fastcall pdb_array_destroy(c1xx_pdb_array *array)

{
  if (array->data != (c1_u32 *)0x0) {
    __3_YAXPAX_Z(array->data);
  }
  return;
}

