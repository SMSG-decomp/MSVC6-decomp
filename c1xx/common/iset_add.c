int __thiscall iset_add(c1xx_pdb_iset *set,uint bit)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  c1_u32 *pcVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar2 = set->count;
  uVar6 = bit >> 5;
  if (uVar2 < uVar6 + 1) {
    do {
      uVar1 = uVar2 + 1;
      if (set->capacity < uVar1) {
        uVar3 = set->capacity * 3 >> 1;
        uVar7 = uVar1;
        if (uVar1 <= uVar3) {
          uVar7 = uVar3;
        }
        pcVar4 = __2_YAPAXI_Z(uVar7 * 4);
        if (pcVar4 == (c1_u32 *)0x0) {
          return 0;
        }
        if (set->data != (c1_u32 *)0x0) {
          uVar3 = 0;
          if (set->count != 0) {
            do {
              uVar5 = uVar3 + 1;
              pcVar4[uVar3] = set->data[uVar3];
              uVar3 = uVar5;
            } while (uVar5 < set->count);
          }
          __3_YAXPAX_Z(set->data);
        }
        set->data = pcVar4;
        set->capacity = uVar7;
      }
      set->count = uVar1;
      set->data[uVar2] = 0;
      uVar2 = set->count;
    } while (uVar2 < uVar6 + 1);
  }
  set->data[uVar6] = set->data[uVar6] | 1 << ((byte)bit & 0x1f);
  return 1;
}

