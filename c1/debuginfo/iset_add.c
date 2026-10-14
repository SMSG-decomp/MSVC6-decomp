int __thiscall iset_add(ISet *set,uint n)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  ulong *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar3 = (set->rgw).itMac;
  uVar7 = n >> 5;
  if (uVar3 < uVar7 + 1) {
    do {
      uVar1 = uVar3 + 1;
      uVar8 = (set->rgw).itMax;
      if (uVar8 < uVar1) {
        uVar4 = uVar8 * 3 >> 1;
        uVar8 = uVar1;
        if (uVar1 <= uVar4) {
          uVar8 = uVar4;
        }
        puVar5 = __2_YAPAXI_Z(uVar8 * 4);
        if (puVar5 == (ulong *)0x0) {
          return 0;
        }
        if ((set->rgw).rgt != (ulong *)0x0) {
          uVar4 = 0;
          if ((set->rgw).itMac != 0) {
            do {
              uVar6 = uVar4 + 1;
              puVar5[uVar4] = (set->rgw).rgt[uVar4];
              uVar4 = uVar6;
            } while (uVar6 < (set->rgw).itMac);
          }
          __3_YAXPAX_Z((set->rgw).rgt);
        }
        (set->rgw).rgt = puVar5;
        (set->rgw).itMax = uVar8;
      }
      (set->rgw).itMac = uVar1;
      (set->rgw).rgt[uVar3] = 0;
      uVar3 = (set->rgw).itMac;
    } while (uVar3 < uVar7 + 1);
  }
  puVar2 = (set->rgw).rgt + uVar7;
  *puVar2 = *puVar2 | 1 << ((byte)n & 0x1f);
  return 1;
}

