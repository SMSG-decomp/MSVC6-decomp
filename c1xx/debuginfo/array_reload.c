int __thiscall array_reload(c1xx_pdb_array *array,c1_u32 **cursor)

{
  c1_u32 **ppcVar1;
  c1_u32 **ppcVar2;
  uint *src;
  uint uVar3;
  uint uVar4;
  c1_u32 **ppcVar5;
  uint *src_2;
  uint *dst;
  
  ppcVar1 = cursor;
  ppcVar5 = (c1_u32 **)**cursor;
  *cursor = *cursor + 1;
  if ((c1_u32 **)array->capacity < ppcVar5) {
    ppcVar2 = (c1_u32 **)((uint)((int)array->capacity * 3) >> 1);
    cursor = ppcVar5;
    if (ppcVar5 <= ppcVar2) {
      cursor = ppcVar2;
    }
    src = __2_YAPAXI_Z((int)cursor * 4);
    if (src == (uint *)0x0) {
      return 0;
    }
    if (array->data != (c1_u32 *)0x0) {
      uVar3 = 0;
      if (array->count != 0) {
        do {
          uVar4 = uVar3 + 1;
          src[uVar3] = array->data[uVar3];
          uVar3 = uVar4;
        } while (uVar4 < array->count);
      }
      __3_YAXPAX_Z(array->data);
    }
    array->data = src;
    array->capacity = (c1_u32)cursor;
  }
  array->count = (c1_u32)ppcVar5;
  src_2 = *ppcVar1;
  dst = array->data;
  for (; ppcVar5 != (c1_u32 **)0x0; ppcVar5 = (c1_u32 **)((int)ppcVar5 - 1)) {
    *dst = *src_2;
    src_2 = src_2 + 1;
    dst = dst + 1;
  }
  *ppcVar1 = *ppcVar1 + array->count;
  return 1;
}

