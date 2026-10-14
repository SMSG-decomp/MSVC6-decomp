void __thiscall dword_array_fill(c1xx_pdb_array *array,c1_u32 *value)

{
  uint uVar1;
  
  uVar1 = 0;
  if (array->count != 0) {
    do {
      array->data[uVar1] = *value;
      uVar1 = uVar1 + 1;
    } while (uVar1 < array->count);
  }
  return;
}

