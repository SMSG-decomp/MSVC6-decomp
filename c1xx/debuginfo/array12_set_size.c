int __thiscall array12_set_size(c1xx_pdb_array *array,uint n)

{
  uint uVar1;
  c1_u32 *pcVar2;
  int iVar3;
  uint *src;
  uint uVar4;
  uint *dst;
  
  if (array->capacity < n) {
    uVar1 = array->capacity * 3 >> 1;
    uVar4 = n;
    if (n <= uVar1) {
      uVar4 = uVar1;
    }
    pcVar2 = __2_YAPAXI_Z(uVar4 * 0xc);
    if (pcVar2 == (c1_u32 *)0x0) {
      return 0;
    }
    if (array->data != (c1_u32 *)0x0) {
      uVar1 = 0;
      if (array->count != 0) {
        iVar3 = 0;
        do {
          src = (uint *)(iVar3 + (int)array->data);
          dst = (uint *)(iVar3 + (int)pcVar2);
          uVar1 = uVar1 + 1;
          iVar3 = iVar3 + 0xc;
          *dst = *src;
          dst[1] = src[1];
          dst[2] = src[2];
        } while (uVar1 < array->count);
      }
      __3_YAXPAX_Z(array->data);
    }
    array->data = pcVar2;
    array->capacity = uVar4;
  }
  array->count = n;
  return 1;
}

