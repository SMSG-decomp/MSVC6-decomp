int __thiscall map_save(c1xx_pdb_map *map,c1_byte_buffer *buf)

{
  c1_u8 *pcVar1;
  c1_byte_buffer *buf_00;
  int iVar2;
  uint *word_slot_2;
  uint *word_slot;
  uint *local_8;
  uint local_4;
  uint *word_slot_3;
  uint *word_slot_4;
  
  buf_00 = buf;
  pcVar1 = (c1_u8 *)(map->domain).count;
  if ((&map->count != (c1_u32 *)0x0) &&
     (iVar2 = il_buffer_reserve_get_cur(buf,4,(c1_u8 **)&buf), iVar2 != 0)) {
    il_buffer_set_memory(buf_00,buf_00->start,buf_00->cur + 4);
    buf->start = (c1_u8 *)map->count;
    if ((&stack0x00000000 != (undefined1 *)0xfffffffc) &&
       (iVar2 = il_buffer_reserve_get_cur(buf_00,4,(c1_u8 **)&buf), iVar2 != 0)) {
      il_buffer_set_memory(buf_00,buf_00->start,buf_00->cur + 4);
      word_slot_3 = &(map->present).count;
      buf->start = pcVar1;
      iVar2 = il_buffer_append(buf_00,word_slot_3,4,(c1_u8 **)0x0);
      if (iVar2 != 0) {
        if ((*word_slot_3 != 0) &&
           (iVar2 = il_buffer_append(buf_00,(map->present).data,*word_slot_3 * 4,(c1_u8 **)0x0),
           iVar2 == 0)) {
          return 0;
        }
        word_slot_4 = &(map->deleted).count;
        iVar2 = il_buffer_append(buf_00,word_slot_4,4,(c1_u8 **)0x0);
        if (iVar2 != 0) {
          if ((*word_slot_4 != 0) &&
             (iVar2 = il_buffer_append(buf_00,(map->deleted).data,*word_slot_4 * 4,(c1_u8 **)0x0),
             iVar2 == 0)) {
            return 0;
          }
          local_4 = 0;
          if ((map->domain).count != 0) {
            do {
              if ((local_4 < (map->present).count << 5) &&
                 (((map->present).data[local_4 >> 5] & 1 << ((byte)local_4 & 0x1f)) != 0)) {
                word_slot_2 = (map->domain).data + local_4;
                if (word_slot_2 == (uint *)0x0) {
                  return 0;
                }
                iVar2 = il_buffer_reserve(buf_00,4);
                if (iVar2 == 0) {
                  return 0;
                }
                if (&stack0x00000000 != (undefined1 *)0xfffffffc) {
                  buf = (c1_byte_buffer *)buf_00->cur;
                }
                il_buffer_set_memory(buf_00,buf_00->start,buf_00->cur + 4);
                buf->start = (c1_u8 *)*word_slot_2;
                word_slot = (map->range).data + local_4;
                if (word_slot == (uint *)0x0) {
                  return 0;
                }
                iVar2 = il_buffer_reserve(buf_00,4);
                if (iVar2 == 0) {
                  return 0;
                }
                if (&stack0x00000000 != (undefined1 *)0x8) {
                  local_8 = (uint *)buf_00->cur;
                }
                il_buffer_set_memory(buf_00,buf_00->start,buf_00->cur + 4);
                *local_8 = *word_slot;
              }
              local_4 = local_4 + 1;
            } while (local_4 < (map->domain).count);
          }
          return 1;
        }
      }
    }
  }
  return 0;
}

