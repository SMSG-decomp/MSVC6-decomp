char __fastcall pdb_blob_stream_load(c1_pdb_blob_table *table)

{
  c1_u32 cVar1;
  uint uVar2;
  int iVar3;
  c1_pdb_blob_entry *entry;
  char *pcVar4;
  void *pvVar5;
  uint uVar6;
  c1_pdb_blob_index_record *record;
  c1_u8 *src;
  c1_u8 *src_2;
  c1_u32 *dst_2;
  c1_u32 *dst;
  c1_u8 *data_cur;
  c1_pdb_blob_index_record *index_records;
  c1_pdb_blob_entry *prev_entry;
  c1_pdb_blob_stream_header header;
  c1_byte_buffer data_buf;
  c1_byte_buffer index_buf;
  
  uVar2 = (*table->stream->vtbl->query_cb)();
  if ((uVar2 == 0) || (0x10 < uVar2)) {
    table->entries = (c1_pdb_blob_entry *)0x0;
    table->count = 0;
    table->dirty = '\0';
    if (uVar2 == 0) {
      return '\x01';
    }
    iVar3 = (*table->stream->vtbl->read_at)(table->stream,0,&header,0x10);
    cVar1 = header.index_size;
    if ((((iVar3 != 0) && (header.signature == 0x1306e64)) && (0 < header.count)) &&
       (header.index_size == header.count << 4)) {
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
      iVar3 = il_buffer_reserve(&index_buf,header.index_size);
      if (iVar3 != 0) {
        if (&stack0x00000000 != (undefined1 *)0x44) {
          index_records = (c1_pdb_blob_index_record *)index_buf.cur;
        }
        il_buffer_set_memory(&index_buf,index_buf.start,index_buf.cur + cVar1);
        iVar3 = (*table->stream->vtbl->read_at)(table->stream,0x10,index_records,header.index_size);
        cVar1 = header.data_size;
        if ((iVar3 != 0) && (iVar3 = il_buffer_reserve(&data_buf,header.data_size), iVar3 != 0)) {
          if (&stack0x00000000 != (undefined1 *)0x48) {
            data_cur = data_buf.cur;
          }
          il_buffer_set_memory(&data_buf,data_buf.start,data_buf.cur + cVar1);
          iVar3 = (*table->stream->vtbl->read_at)
                            (table->stream,header.index_size + 0x10,data_cur,header.data_size);
          if (iVar3 != 0) {
            prev_entry = (c1_pdb_blob_entry *)0x0;
            if (table->count < header.count) {
              do {
                record = index_records + table->count;
                entry = __2_YAPAXI_Z(0x10);
                if (entry == (c1_pdb_blob_entry *)0x0) goto joined_r0x1049a32e;
                pcVar4 = __2_YAPAXI_Z(record->name_size);
                entry->name = pcVar4;
                if (pcVar4 == (char *)0x0) {
                  __3_YAXPAX_Z(entry);
                  goto joined_r0x1049a32e;
                }
                entry->size = record->data_size;
                pvVar5 = __2_YAPAXI_Z(record->data_size);
                entry->data = pvVar5;
                if (pvVar5 == (void *)0x0) {
                  __3_YAXPAX_Z(entry->name);
                  __3_YAXPAX_Z(entry);
                  goto joined_r0x1049a32e;
                }
                uVar2 = record->name_size;
                src = data_cur + record->name_offset;
                dst_2 = (c1_u32 *)entry->name;
                for (uVar6 = uVar2 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
                  *dst_2 = *(c1_u32 *)src;
                  src = (c1_u8 *)((int)src + 4);
                  dst_2 = dst_2 + 1;
                }
                for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
                  *(c1_u8 *)dst_2 = *src;
                  src = src + 1;
                  dst_2 = (c1_u32 *)((int)dst_2 + 1);
                }
                uVar2 = record->data_size;
                src_2 = data_cur + record->data_offset;
                dst = entry->data;
                for (uVar6 = uVar2 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
                  *dst = *(c1_u32 *)src_2;
                  src_2 = (c1_u8 *)((int)src_2 + 4);
                  dst = dst + 1;
                }
                for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
                  *(c1_u8 *)dst = *src_2;
                  src_2 = src_2 + 1;
                  dst = (c1_u32 *)((int)dst + 1);
                }
                entry->next = (c1_pdb_blob_entry *)0x0;
                if (prev_entry == (c1_pdb_blob_entry *)0x0) {
                  table->entries = entry;
                }
                else {
                  prev_entry->next = entry;
                }
                iVar3 = table->count + 1;
                table->count = iVar3;
                prev_entry = entry;
              } while (iVar3 < header.count);
            }
            if (data_buf.start != (c1_u8 *)0x0) {
              __3_YAXPAX_Z(data_buf.start);
              il_buffer_set_memory(&data_buf,(c1_u8 *)0x0,(c1_u8 *)0x0);
              data_buf.size = 0;
            }
            if (index_buf.start == (c1_u8 *)0x0) {
              return '\x01';
            }
            __3_YAXPAX_Z(index_buf.start);
            il_buffer_set_memory(&index_buf,(c1_u8 *)0x0,(c1_u8 *)0x0);
            return '\x01';
          }
        }
      }
joined_r0x1049a32e:
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
  }
  return '\0';
}

