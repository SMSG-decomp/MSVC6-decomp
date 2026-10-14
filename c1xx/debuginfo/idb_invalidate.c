int __fastcall idb_invalidate(c1xx_idb *idb)

{
  uint uVar1;
  uint uVar2;
  c1_idb_region *pcVar3;
  c1_u16 *pcVar4;
  int iVar5;
  uint uVar6;
  uint *src;
  uint uStack_8;
  uint *dst;
  
  idb->invalidated = 1;
  if (idb->state == 1) {
    idb->state = 5;
  }
  uVar1 = (idb->file).cursor;
  uVar2 = (idb->file).regions.capacity;
  if (uVar2 < uVar1) {
    uVar2 = uVar2 * 3 >> 1;
    uStack_8 = uVar1;
    if (uVar1 <= uVar2) {
      uStack_8 = uVar2;
    }
    pcVar3 = __2_YAPAXI_Z(uStack_8 << 4);
    uVar2 = 0;
    if (pcVar3 == (c1_idb_region *)0x0) {
      return 0;
    }
    if (-1 < (int)(uStack_8 - 1)) {
      pcVar4 = &pcVar3->start_line;
      uVar6 = uStack_8;
      do {
        ((c1_idb_region *)(pcVar4 + -4))->signature = 0;
        *(int *)(pcVar4 + -2) = -1;
        *pcVar4 = 0;
        pcVar4[1] = 0;
        *(c1_u8 *)(pcVar4 + 2) = '\x18';
        pcVar4 = pcVar4 + 8;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    if ((idb->file).regions.data != (c1_idb_region *)0x0) {
      if ((idb->file).regions.count != 0) {
        iVar5 = 0;
        do {
          src = (uint *)(((idb->file).regions.data)->pad0d + iVar5 + -0xd);
          dst = (uint *)(pcVar3->pad0d + iVar5 + -0xd);
          uVar2 = uVar2 + 1;
          iVar5 = iVar5 + 0x10;
          *dst = *src;
          dst[1] = src[1];
          dst[2] = src[2];
          dst[3] = src[3];
        } while (uVar2 < (idb->file).regions.count);
      }
      __3_YAXPAX_Z((idb->file).regions.data);
    }
    (idb->file).regions.data = pcVar3;
    (idb->file).regions.capacity = uStack_8;
  }
  (idb->file).regions.count = uVar1;
  return 1;
}

