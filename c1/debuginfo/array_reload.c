int __thiscall array_reload(Array_DWORD *array,c1_u32 **cursor)

{
  c1_u32 **ppcVar1;
  c1_u32 **ppcVar2;
  ulong *puVar3;
  uint uVar4;
  uint uVar5;
  c1_u32 **ppcVar6;
  ulong *puVar7;
  
  ppcVar1 = cursor;
  ppcVar6 = (c1_u32 **)**cursor;
  *cursor = *cursor + 1;
  if ((c1_u32 **)array->itMax < ppcVar6) {
    ppcVar2 = (c1_u32 **)((uint)((int)array->itMax * 3) >> 1);
    cursor = ppcVar6;
    if (ppcVar6 <= ppcVar2) {
      cursor = ppcVar2;
    }
    puVar3 = __2_YAPAXI_Z((int)cursor * 4);
    if (puVar3 == (ulong *)0x0) {
      return 0;
    }
    if (array->rgt != (ulong *)0x0) {
      uVar4 = 0;
      if (array->itMac != 0) {
        do {
          uVar5 = uVar4 + 1;
          puVar3[uVar4] = array->rgt[uVar4];
          uVar4 = uVar5;
        } while (uVar5 < array->itMac);
      }
      __3_YAXPAX_Z(array->rgt);
    }
    array->rgt = puVar3;
    array->itMax = (uint)cursor;
  }
  array->itMac = (uint)ppcVar6;
  puVar3 = *ppcVar1;
  puVar7 = array->rgt;
  for (; ppcVar6 != (c1_u32 **)0x0; ppcVar6 = (c1_u32 **)((int)ppcVar6 - 1)) {
    *puVar7 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar7 = puVar7 + 1;
  }
  *ppcVar1 = *ppcVar1 + array->itMac;
  return 1;
}

