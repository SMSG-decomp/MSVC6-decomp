char __fastcall pdb_blob_stream_load(fe_pdb_blob_table *table)

{
  uint uVar1;
  int iVar2;
  fe_pdb_blob_entry *pfVar3;
  char *pcVar4;
  void *pvVar5;
  uint uVar6;
  fe_pdb_blob_index_record *entry;
  PB puVar7;
  uchar *puVar8;
  PB puStack_48;
  PB puStack_44;
  fe_pdb_blob_entry *pfStack_3c;
  fe_pdb_blob_stream_header header;
  Buffer data;
  Buffer index;
  
  uVar1 = (*table->stream->vtbl->QueryCb)(table->stream);
  if ((uVar1 == 0) || (0x10 < uVar1)) {
    table->entries = (fe_pdb_blob_entry *)0x0;
    table->count = 0;
    table->dirty = '\0';
    if (uVar1 == 0) {
      return '\x01';
    }
    iVar2 = (*table->stream->vtbl->Read2)(table->stream,0,&header,0x10);
    uVar1 = header.index_size;
    if ((((iVar2 != 0) && (header.signature == 0x1306e64)) && (0 < header.count)) &&
       (header.index_size == header.count << 4)) {
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
      iVar2 = il_buffer_reserve(&index,header.index_size);
      if (iVar2 != 0) {
        if (&stack0x00000000 != (undefined1 *)0x44) {
          puStack_44 = index.pbEnd;
        }
        il_buffer_set_memory(&index,index.pbStart,index.pbEnd + uVar1);
        iVar2 = (*table->stream->vtbl->Read2)(table->stream,0x10,puStack_44,header.index_size);
        uVar1 = header.data_size;
        if ((iVar2 != 0) && (iVar2 = il_buffer_reserve(&data,header.data_size), iVar2 != 0)) {
          if (&stack0x00000000 != (undefined1 *)0x48) {
            puStack_48 = data.pbEnd;
          }
          il_buffer_set_memory(&data,data.pbStart,data.pbEnd + uVar1);
          iVar2 = (*table->stream->vtbl->Read2)
                            (table->stream,header.index_size + 0x10,puStack_48,header.data_size);
          if (iVar2 != 0) {
            pfStack_3c = (fe_pdb_blob_entry *)0x0;
            if (table->count < header.count) {
              do {
                entry = (fe_pdb_blob_index_record *)(puStack_44 + table->count * 0x10);
                pfVar3 = __2_YAPAXI_Z(0x10);
                if (pfVar3 == (fe_pdb_blob_entry *)0x0) goto joined_r0x1064d568;
                pcVar4 = __2_YAPAXI_Z(entry->name_size);
                pfVar3->name = pcVar4;
                if (pcVar4 == (char *)0x0) {
                  __3_YAXPAX_Z(pfVar3);
                  goto joined_r0x1064d568;
                }
                pfVar3->size = entry->data_size;
                pvVar5 = __2_YAPAXI_Z(entry->data_size);
                pfVar3->data = pvVar5;
                if (pvVar5 == (void *)0x0) {
                  __3_YAXPAX_Z(pfVar3->name);
                  __3_YAXPAX_Z(pfVar3);
                  goto joined_r0x1064d568;
                }
                uVar1 = entry->name_size;
                puVar7 = puStack_48 + entry->name_offset;
                puVar8 = (uchar *)pfVar3->name;
                for (uVar6 = uVar1 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
                  *(undefined4 *)puVar8 = *(undefined4 *)puVar7;
                  puVar7 = puVar7 + 4;
                  puVar8 = puVar8 + 4;
                }
                for (uVar1 = uVar1 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
                  *puVar8 = *puVar7;
                  puVar7 = puVar7 + 1;
                  puVar8 = puVar8 + 1;
                }
                uVar1 = entry->data_size;
                puVar7 = puStack_48 + entry->data_offset;
                puVar8 = pfVar3->data;
                for (uVar6 = uVar1 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
                  *(undefined4 *)puVar8 = *(undefined4 *)puVar7;
                  puVar7 = puVar7 + 4;
                  puVar8 = puVar8 + 4;
                }
                for (uVar1 = uVar1 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
                  *puVar8 = *puVar7;
                  puVar7 = puVar7 + 1;
                  puVar8 = puVar8 + 1;
                }
                pfVar3->next = (fe_pdb_blob_entry *)0x0;
                if (pfStack_3c == (fe_pdb_blob_entry *)0x0) {
                  table->entries = pfVar3;
                }
                else {
                  pfStack_3c->next = pfVar3;
                }
                iVar2 = table->count + 1;
                table->count = iVar2;
                pfStack_3c = pfVar3;
              } while (iVar2 < header.count);
            }
            if (data.pbStart != (PB)0x0) {
              __3_YAXPAX_Z(data.pbStart);
              il_buffer_set_memory(&data,(c1_u8 *)0x0,(c1_u8 *)0x0);
              data.cbAlloc = 0;
            }
            if (index.pbStart == (PB)0x0) {
              return '\x01';
            }
            __3_YAXPAX_Z(index.pbStart);
            il_buffer_set_memory(&index,(c1_u8 *)0x0,(c1_u8 *)0x0);
            return '\x01';
          }
        }
      }
joined_r0x1064d568:
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
  }
  return '\0';
}

