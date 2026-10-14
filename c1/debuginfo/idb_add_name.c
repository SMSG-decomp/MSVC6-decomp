int __thiscall idb_add_name(c1_idb_state *idb,char *name)

{
  uint uVar1;
  uint *puVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  ulong *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  char *pcVar11;
  
  uVar8 = 0xffffffff;
  pcVar11 = name;
  do {
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    cVar3 = *pcVar11;
    pcVar11 = pcVar11 + 1;
  } while (cVar3 != '\0');
  uVar4 = SigForPbCb(name,~uVar8 - 1,0);
  uVar8 = (idb->names).rgw.itMac;
  uVar9 = (uVar4 & 0x3fff) >> 5;
  if (uVar8 < uVar9 + 1) {
    do {
      uVar1 = uVar8 + 1;
      uVar10 = (idb->names).rgw.itMax;
      if (uVar10 < uVar1) {
        uVar5 = uVar10 * 3 >> 1;
        uVar10 = uVar1;
        if (uVar1 <= uVar5) {
          uVar10 = uVar5;
        }
        puVar6 = __2_YAPAXI_Z(uVar10 * 4);
        if (puVar6 == (ulong *)0x0) {
          return 0;
        }
        if ((idb->names).rgw.rgt != (ulong *)0x0) {
          uVar5 = 0;
          if ((idb->names).rgw.itMac != 0) {
            do {
              uVar7 = uVar5 + 1;
              puVar6[uVar5] = (idb->names).rgw.rgt[uVar5];
              uVar5 = uVar7;
            } while (uVar7 < (idb->names).rgw.itMac);
          }
          __3_YAXPAX_Z((idb->names).rgw.rgt);
        }
        (idb->names).rgw.rgt = puVar6;
        (idb->names).rgw.itMax = uVar10;
      }
      puVar6 = (idb->names).rgw.rgt;
      (idb->names).rgw.itMac = uVar1;
      puVar6[uVar8] = 0;
      uVar8 = (idb->names).rgw.itMac;
    } while (uVar8 < uVar9 + 1);
  }
  puVar2 = (idb->names).rgw.rgt + uVar9;
  *puVar2 = *puVar2 | 1 << ((byte)(uVar4 & 0x3fff) & 0x1f);
  return 1;
}

