char __fastcall pdb_blob_stream_flush(fe_pdb_blob_table *table)

{
  c1_u8 cVar1;
  fe_pdb_blob_entry *pfVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  c1_u8 *pcVar7;
  c1_u8 *pcVar8;
  c1_u8 *local_58;
  c1_u8 *local_54;
  fe_pdb_blob_index_record *entry;
  fe_pdb_blob_table *local_4c;
  uint local_44;
  uint local_40;
  uint local_3c;
  fe_pdb_blob_stream_header header;
  Buffer data;
  Buffer index;
  
  if (table->dirty == '\0') {
    return '\x01';
  }
  if (table->count == 0) {
    local_4c = table;
    iVar3 = (*table->stream->vtbl->Truncate)(table->stream,0);
    if (iVar3 == 0) {
      return '\0';
    }
  }
  else {
    pfVar2 = table->entries;
    index.pbStart = (PB)0x0;
    index.pbEnd = (PB)0x0;
    index.cbAlloc = 0;
    index.pfnMove = (_func_44 *)0x0;
    index.pfnMoveArg = (void *)0x0;
    data.pbStart = (PB)0x0;
    data.pbEnd = (PB)0x0;
    data.cbAlloc = 0;
    data.pfnMove = (_func_44 *)0x0;
    data.pfnMoveArg = (void *)0x0;
    header.signature = 0x1306e64;
    header.count = 0;
    for (; local_4c = table, pfVar2 != (fe_pdb_blob_entry *)0x0; pfVar2 = pfVar2->next) {
      header.count = header.count + 1;
      pcVar7 = (c1_u8 *)pfVar2->name;
      uVar4 = 0xffffffff;
      pcVar8 = pcVar7;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      uVar4 = ~uVar4;
      local_44 = (int)data.pbEnd - (int)data.pbStart;
      if ((pcVar7 == (c1_u8 *)0x0) ||
         (iVar3 = il_buffer_reserve_advance(&data,uVar4,&local_58), iVar3 == 0)) {
joined_r0x1064d700:
        if (data.pbStart != (PB)0x0) {
          il_buffer_free((int *)&data);
        }
        if (index.pbStart == (PB)0x0) {
          return '\0';
        }
        il_buffer_free((int *)&index);
        return '\0';
      }
      pcVar8 = local_58;
      for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar5 = uVar4 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar8 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      }
      pcVar7 = pfVar2->data;
      uVar5 = pfVar2->size;
      local_3c = (int)data.pbEnd - (int)data.pbStart;
      local_40 = uVar5;
      if ((pcVar7 == (c1_u8 *)0x0) ||
         (iVar3 = il_buffer_reserve_advance(&data,uVar5,&local_54), iVar3 == 0))
      goto joined_r0x1064d700;
      pcVar8 = local_54;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar8 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      }
      if ((&stack0x00000000 == (undefined1 *)0x48) ||
         (iVar3 = il_buffer_reserve_advance(&index,0x10,(c1_u8 **)&entry), iVar3 == 0))
      goto joined_r0x1064d700;
      entry->name_size = uVar4;
      entry->name_offset = local_44;
      entry->data_size = local_40;
      entry->data_offset = local_3c;
      table = local_4c;
    }
    header.index_size = (int)index.pbEnd - (int)index.pbStart;
    header.data_size = (int)data.pbEnd - (int)data.pbStart;
    iVar3 = (*table->stream->vtbl->Replace)(table->stream,&header,0x10);
    if (((iVar3 == 0) ||
        (iVar3 = (*table->stream->vtbl->Append)
                           (table->stream,index.pbStart,(int)index.pbEnd - (int)index.pbStart),
        iVar3 == 0)) ||
       (iVar3 = (*table->stream->vtbl->Append)
                          (table->stream,data.pbStart,(int)data.pbEnd - (int)data.pbStart),
       iVar3 == 0)) {
      if (data.pbStart != (PB)0x0) {
        __3_YAXPAX_Z(data.pbStart);
        il_buffer_set_memory(&data,(c1_u8 *)0x0,(c1_u8 *)0x0);
        data.cbAlloc = 0;
      }
      if (index.pbStart != (PB)0x0) {
        __3_YAXPAX_Z(index.pbStart);
        il_buffer_set_memory(&index,(c1_u8 *)0x0,(c1_u8 *)0x0);
      }
      return '\0';
    }
    if (data.pbStart != (PB)0x0) {
      __3_YAXPAX_Z(data.pbStart);
      il_buffer_set_memory(&data,(c1_u8 *)0x0,(c1_u8 *)0x0);
      data.cbAlloc = 0;
    }
    if (index.pbStart != (PB)0x0) {
      __3_YAXPAX_Z(index.pbStart);
      il_buffer_set_memory(&index,(c1_u8 *)0x0,(c1_u8 *)0x0);
    }
  }
  table->dirty = '\0';
  return '\x01';
}

