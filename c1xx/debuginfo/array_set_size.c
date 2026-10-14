int __thiscall array_set_size(c1xx_pdb_array *array,uint count)

{
  uint uVar1;
  c1_u32 *pcVar2;
  uint uVar3;
  uint uVar4;
  
  if (array->capacity < count) {
    uVar1 = array->capacity * 3 >> 1;
    uVar4 = count;
    if (count <= uVar1) {
      uVar4 = uVar1;
    }
    pcVar2 = __2_YAPAXI_Z(uVar4 * 4);
    if (pcVar2 == (c1_u32 *)0x0) {
      return 0;
    }
    if (array->data != (c1_u32 *)0x0) {
      uVar1 = 0;
      if (array->count != 0) {
        do {
          uVar3 = uVar1 + 1;
          pcVar2[uVar1] = array->data[uVar1];
          uVar1 = uVar3;
        } while (uVar3 < array->count);
      }
      __3_YAXPAX_Z(array->data);
    }
    array->data = pcVar2;
    array->capacity = uVar4;
  }
  array->count = count;
  return 1;
}

