int __thiscall iset_ensure_room(ISet *set,uint n)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ulong *puVar4;
  uint uVar5;
  uint uVar6;
  
  uVar2 = (set->rgw).itMac;
  do {
    if ((n >> 5) + 1 <= uVar2) {
      return 1;
    }
    uVar1 = uVar2 + 1;
    uVar6 = (set->rgw).itMax;
    if (uVar6 < uVar1) {
      uVar3 = uVar6 * 3 >> 1;
      uVar6 = uVar1;
      if (uVar1 <= uVar3) {
        uVar6 = uVar3;
      }
      puVar4 = __2_YAPAXI_Z(uVar6 * 4);
      if (puVar4 == (ulong *)0x0) {
        return 0;
      }
      if ((set->rgw).rgt != (ulong *)0x0) {
        uVar3 = 0;
        if ((set->rgw).itMac != 0) {
          do {
            uVar5 = uVar3 + 1;
            puVar4[uVar3] = (set->rgw).rgt[uVar3];
            uVar3 = uVar5;
          } while (uVar5 < (set->rgw).itMac);
        }
        __3_YAXPAX_Z((set->rgw).rgt);
      }
      (set->rgw).rgt = puVar4;
      (set->rgw).itMax = uVar6;
    }
    (set->rgw).itMac = uVar1;
    (set->rgw).rgt[uVar2] = 0;
    uVar2 = (set->rgw).itMac;
  } while( true );
}

