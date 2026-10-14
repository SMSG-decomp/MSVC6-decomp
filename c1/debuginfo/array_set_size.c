int __thiscall array_set_size(Array_DWORD *array,uint n)

{
  uint uVar1;
  ulong *puVar2;
  uint uVar3;
  uint uVar4;
  
  if (array->itMax < n) {
    uVar1 = array->itMax * 3 >> 1;
    uVar4 = n;
    if (n <= uVar1) {
      uVar4 = uVar1;
    }
    puVar2 = __2_YAPAXI_Z(uVar4 * 4);
    if (puVar2 == (ulong *)0x0) {
      return 0;
    }
    if (array->rgt != (ulong *)0x0) {
      uVar1 = 0;
      if (array->itMac != 0) {
        do {
          uVar3 = uVar1 + 1;
          puVar2[uVar1] = array->rgt[uVar1];
          uVar1 = uVar3;
        } while (uVar3 < array->itMac);
      }
      __3_YAXPAX_Z(array->rgt);
    }
    array->rgt = puVar2;
    array->itMax = uVar4;
  }
  array->itMac = n;
  return 1;
}

