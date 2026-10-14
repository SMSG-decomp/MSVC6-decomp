int __thiscall array8_set_size(c1_pair_array *array,uint n)

{
  c1_u32_pair *pcVar1;
  uint uVar2;
  c1_u32_pair *pcVar3;
  uint uVar4;
  uint uVar5;
  
  if (array->capacity < n) {
    uVar2 = array->capacity * 3 >> 1;
    uVar5 = n;
    if (n <= uVar2) {
      uVar5 = uVar2;
    }
    pcVar3 = __2_YAPAXI_Z(uVar5 * 8);
    if (pcVar3 == (c1_u32_pair *)0x0) {
      return 0;
    }
    if (array->data != (c1_u32_pair *)0x0) {
      uVar2 = 0;
      if (array->count != 0) {
        do {
          pcVar1 = array->data;
          uVar4 = uVar2 + 1;
          pcVar3[uVar2].first = pcVar1[uVar2].first;
          pcVar3[uVar2].second = pcVar1[uVar2].second;
          uVar2 = uVar4;
        } while (uVar4 < array->count);
      }
      __3_YAXPAX_Z(array->data);
    }
    array->data = pcVar3;
    array->capacity = uVar5;
  }
  array->count = n;
  return 1;
}

