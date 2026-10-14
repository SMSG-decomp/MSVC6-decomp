int __thiscall map_save(Map_DWORD_DWORD *map,Buffer *buf)

{
  uint *puVar1;
  PB puVar2;
  uint uVar3;
  Buffer *buf_00;
  int iVar4;
  ulong *puVar5;
  ulong *local_8;
  uint local_4;
  
  buf_00 = buf;
  puVar2 = (PB)(map->rgd).itMac;
  if ((&map->cdr != (uint *)0x0) &&
     (iVar4 = il_buffer_reserve_get_cur(buf,4,(c1_u8 **)&buf), iVar4 != 0)) {
    il_buffer_set_memory(buf_00,buf_00->pbStart,buf_00->pbEnd + 4);
    buf->pbStart = (PB)map->cdr;
    if ((&stack0x00000000 != (undefined1 *)0xfffffffc) &&
       (iVar4 = il_buffer_reserve_get_cur(buf_00,4,(c1_u8 **)&buf), iVar4 != 0)) {
      il_buffer_set_memory(buf_00,buf_00->pbStart,buf_00->pbEnd + 4);
      puVar1 = &(map->isetPresent).rgw.itMac;
      buf->pbStart = puVar2;
      iVar4 = il_buffer_append(buf_00,puVar1,4,(c1_u8 **)0x0);
      if (iVar4 != 0) {
        uVar3 = *puVar1;
        if ((uVar3 != 0) &&
           (iVar4 = il_buffer_append(buf_00,(map->isetPresent).rgw.rgt,uVar3 * 4,(c1_u8 **)0x0),
           iVar4 == 0)) {
          return 0;
        }
        puVar1 = &(map->isetDeleted).rgw.itMac;
        iVar4 = il_buffer_append(buf_00,puVar1,4,(c1_u8 **)0x0);
        if (iVar4 != 0) {
          uVar3 = *puVar1;
          if ((uVar3 != 0) &&
             (iVar4 = il_buffer_append(buf_00,(map->isetDeleted).rgw.rgt,uVar3 * 4,(c1_u8 **)0x0),
             iVar4 == 0)) {
            return 0;
          }
          local_4 = 0;
          if ((map->rgd).itMac != 0) {
            do {
              if ((local_4 < (map->isetPresent).rgw.itMac << 5) &&
                 (((map->isetPresent).rgw.rgt[local_4 >> 5] & 1 << ((byte)local_4 & 0x1f)) != 0)) {
                puVar5 = (map->rgd).rgt + local_4;
                if (puVar5 == (ulong *)0x0) {
                  return 0;
                }
                iVar4 = il_buffer_reserve(buf_00,4);
                if (iVar4 == 0) {
                  return 0;
                }
                if (&stack0x00000000 != (undefined1 *)0xfffffffc) {
                  buf = (Buffer *)buf_00->pbEnd;
                }
                il_buffer_set_memory(buf_00,buf_00->pbStart,buf_00->pbEnd + 4);
                buf->pbStart = (PB)*puVar5;
                puVar5 = (map->rgr).rgt + local_4;
                if (puVar5 == (ulong *)0x0) {
                  return 0;
                }
                iVar4 = il_buffer_reserve(buf_00,4);
                if (iVar4 == 0) {
                  return 0;
                }
                if (&stack0x00000000 != (undefined1 *)0x8) {
                  local_8 = (ulong *)buf_00->pbEnd;
                }
                il_buffer_set_memory(buf_00,buf_00->pbStart,buf_00->pbEnd + 4);
                *local_8 = *puVar5;
              }
              local_4 = local_4 + 1;
            } while (local_4 < (map->rgd).itMac);
          }
          return 1;
        }
      }
    }
  }
  return 0;
}

