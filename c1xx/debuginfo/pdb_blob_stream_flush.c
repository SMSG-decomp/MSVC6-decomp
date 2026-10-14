char __fastcall pdb_blob_stream_flush(c1_pdb_blob_table *table)

{
  c1_u8 cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  c1_u8 *pcVar6;
  c1_u8 *pcVar7;
  c1_u8 *local_58;
  c1_u8 *local_54;
  c1_pdb_blob_index_record *index_record;
  c1_pdb_blob_table *local_4c;
  uint name_offset;
  uint data_size;
  uint data_offset;
  c1_pdb_blob_stream_header header;
  c1_byte_buffer data_buf;
  c1_byte_buffer index_buf;
  c1_pdb_blob_entry *entry;
  
  if (table->dirty == '\0') {
    return '\x01';
  }
  if (table->count == 0) {
    local_4c = table;
    iVar2 = (*table->stream->vtbl->truncate)();
    if (iVar2 == 0) {
      return '\0';
    }
  }
  else {
    entry = table->entries;
    index_buf.start = (c1_u8 *)0x0;
    index_buf.cur = (c1_u8 *)0x0;
    index_buf.size = 0;
    index_buf.on_move = (c1_il_buffer_move_fn)0x0;
    index_buf.move_ctx = (void *)0x0;
    data_buf.start = (c1_u8 *)0x0;
    data_buf.cur = (c1_u8 *)0x0;
    data_buf.size = 0;
    data_buf.on_move = (c1_il_buffer_move_fn)0x0;
    data_buf.move_ctx = (void *)0x0;
    header.signature = 0x1306e64;
    header.count = 0;
    for (; local_4c = table, entry != (c1_pdb_blob_entry *)0x0; entry = entry->next) {
      header.count = header.count + 1;
      pcVar6 = (c1_u8 *)entry->name;
      uVar3 = 0xffffffff;
      pcVar7 = pcVar6;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      name_offset = (int)data_buf.cur - (int)data_buf.start;
      if ((pcVar6 == (c1_u8 *)0x0) ||
         (iVar2 = il_buffer_reserve_advance(&data_buf,uVar3,&local_58), iVar2 == 0)) {
joined_r0x1049a37e:
        if (data_buf.start != (c1_u8 *)0x0) {
          il_buffer_free(&data_buf);
        }
        if (index_buf.start == (c1_u8 *)0x0) {
          return '\0';
        }
        il_buffer_free(&index_buf);
        return '\0';
      }
      pcVar7 = local_58;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar7 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar7 = pcVar7 + 1;
      }
      pcVar6 = entry->data;
      uVar4 = entry->size;
      data_offset = (int)data_buf.cur - (int)data_buf.start;
      data_size = uVar4;
      if ((pcVar6 == (c1_u8 *)0x0) ||
         (iVar2 = il_buffer_reserve_advance(&data_buf,uVar4,&local_54), iVar2 == 0))
      goto joined_r0x1049a37e;
      pcVar7 = local_54;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar7 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar7 = pcVar7 + 1;
      }
      if ((&stack0x00000000 == (undefined1 *)0x48) ||
         (iVar2 = il_buffer_reserve_advance(&index_buf,0x10,(c1_u8 **)&index_record), iVar2 == 0))
      goto joined_r0x1049a37e;
      index_record->name_size = uVar3;
      index_record->name_offset = name_offset;
      index_record->data_size = data_size;
      index_record->data_offset = data_offset;
      table = local_4c;
    }
    header.index_size = (int)index_buf.cur - (int)index_buf.start;
    header.data_size = (int)data_buf.cur - (int)data_buf.start;
    iVar2 = (*table->stream->vtbl->replace)(table->stream,&header,0x10);
    if (((iVar2 == 0) ||
        (iVar2 = (*table->stream->vtbl->append)
                           (table->stream,index_buf.start,(int)index_buf.cur - (int)index_buf.start)
        , iVar2 == 0)) ||
       (iVar2 = (*table->stream->vtbl->append)
                          (table->stream,data_buf.start,(int)data_buf.cur - (int)data_buf.start),
       iVar2 == 0)) {
      if (data_buf.start != (c1_u8 *)0x0) {
        __3_YAXPAX_Z(data_buf.start);
        il_buffer_set_memory(&data_buf,(c1_u8 *)0x0,(c1_u8 *)0x0);
        data_buf.size = 0;
      }
      if (index_buf.start != (c1_u8 *)0x0) {
        __3_YAXPAX_Z(index_buf.start);
        il_buffer_set_memory(&index_buf,(c1_u8 *)0x0,(c1_u8 *)0x0);
      }
      return '\0';
    }
    if (data_buf.start != (c1_u8 *)0x0) {
      __3_YAXPAX_Z(data_buf.start);
      il_buffer_set_memory(&data_buf,(c1_u8 *)0x0,(c1_u8 *)0x0);
      data_buf.size = 0;
    }
    if (index_buf.start != (c1_u8 *)0x0) {
      __3_YAXPAX_Z(index_buf.start);
      il_buffer_set_memory(&index_buf,(c1_u8 *)0x0,(c1_u8 *)0x0);
    }
  }
  table->dirty = '\0';
  return '\x01';
}

