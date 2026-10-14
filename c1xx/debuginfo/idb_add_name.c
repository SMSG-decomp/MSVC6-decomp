int __thiscall idb_add_name(c1xx_idb *idb,char *name)

{
  uint uVar1;
  uint *puVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  c1_u32 *pcVar6;
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
  uVar8 = (idb->name_hash_bits).count;
  uVar9 = (uVar4 & 0x3fff) >> 5;
  if (uVar8 < uVar9 + 1) {
    do {
      uVar1 = uVar8 + 1;
      uVar10 = (idb->name_hash_bits).capacity;
      if (uVar10 < uVar1) {
        uVar5 = uVar10 * 3 >> 1;
        uVar10 = uVar1;
        if (uVar1 <= uVar5) {
          uVar10 = uVar5;
        }
        pcVar6 = __2_YAPAXI_Z(uVar10 * 4);
        if (pcVar6 == (c1_u32 *)0x0) {
          return 0;
        }
        if ((idb->name_hash_bits).data != (c1_u32 *)0x0) {
          uVar5 = 0;
          if ((idb->name_hash_bits).count != 0) {
            do {
              uVar7 = uVar5 + 1;
              pcVar6[uVar5] = (idb->name_hash_bits).data[uVar5];
              uVar5 = uVar7;
            } while (uVar7 < (idb->name_hash_bits).count);
          }
          __3_YAXPAX_Z((idb->name_hash_bits).data);
        }
        (idb->name_hash_bits).data = pcVar6;
        (idb->name_hash_bits).capacity = uVar10;
      }
      (idb->name_hash_bits).count = uVar1;
      (idb->name_hash_bits).data[uVar8] = 0;
      uVar8 = (idb->name_hash_bits).count;
    } while (uVar8 < uVar9 + 1);
  }
  puVar2 = (idb->name_hash_bits).data + uVar9;
  *puVar2 = *puVar2 | 1 << ((byte)(uVar4 & 0x3fff) & 0x1f);
  return 1;
}

