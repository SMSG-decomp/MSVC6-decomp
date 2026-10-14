int __thiscall idb_read_regions(c1_idb_state *idb,Stream *stream)

{
  Array_DWORD *array;
  ISet *array_00;
  Stream_vtbl *n;
  Stream_vtbl **ppSVar1;
  long n_00;
  int iVar2;
  uint uVar3;
  Stream *pSVar4;
  fe_idb_browse_entry *pfVar5;
  ulong *puVar6;
  Buffer data;
  
  pSVar4 = stream;
  n_00 = (*stream->vtbl->QueryCb)(stream);
  data.pbStart = (PB)0x0;
  data.pbEnd = (PB)0x0;
  data.cbAlloc = 0;
  data.pfnMove = (_func_44 *)0x0;
  data.pfnMoveArg = (void *)0x0;
  iVar2 = il_buffer_reserve(&data,n_00);
  if (iVar2 != 0) {
    if (&stack0x00000000 != (undefined1 *)0xfffffffc) {
      stream = (Stream *)data.pbEnd;
    }
    il_buffer_set_memory(&data,data.pbStart,data.pbEnd + n_00);
    iVar2 = (*pSVar4->vtbl->Read2)(pSVar4,0,stream,n_00);
    if (iVar2 != 0) {
      if (stream->vtbl != (Stream_vtbl *)0x1306c77) {
        if (data.pbStart == (PB)0x0) {
          return 1;
        }
        stream = stream + 1;
        __3_YAXPAX_Z(data.pbStart);
LAB_10646807:
        il_buffer_set_memory(&data,(c1_u8 *)0x0,(c1_u8 *)0x0);
        return 1;
      }
      idb->pch_generation_seen = (c1_u32)stream[1].vtbl;
      idb->options_signature = (c1_u32)stream[2].vtbl;
      idb->unk130 = (c1_u32)stream[3].vtbl;
      idb->browse_size = (c1_u32)stream[4].vtbl;
      stream = stream + 5;
      iVar2 = idb_region_array_reload(&(idb->file).regions,(c1_u32 **)&stream);
      if (iVar2 != 0) {
        ppSVar1 = &stream->vtbl;
        stream = stream + 1;
        iVar2 = array12_set_size(&idb->browse_regions,(uint)*ppSVar1);
        if (iVar2 != 0) {
          pSVar4 = stream;
          pfVar5 = (idb->browse_regions).data;
          for (uVar3 = (idb->browse_regions).count * 3 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1)
          {
            *(Stream_vtbl **)pfVar5 = pSVar4->vtbl;
            pSVar4 = pSVar4 + 1;
            pfVar5 = (fe_idb_browse_entry *)&pfVar5->first_line;
          }
          for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
            *(undefined1 *)&pfVar5->old_first_line = *(undefined1 *)&pSVar4->vtbl;
            pSVar4 = (Stream *)((int)&pSVar4->vtbl + 1);
            pfVar5 = (fe_idb_browse_entry *)((int)&pfVar5->old_first_line + 1);
          }
          pSVar4 = stream + (idb->browse_regions).count * 3;
          stream = pSVar4 + 1;
          iVar2 = array_set_size(&(idb->names).rgw,(uint)pSVar4->vtbl);
          if (iVar2 != 0) {
            pSVar4 = stream;
            puVar6 = (idb->names).rgw.rgt;
            for (uVar3 = (idb->names).rgw.itMac & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
              *puVar6 = (ulong)pSVar4->vtbl;
              pSVar4 = pSVar4 + 1;
              puVar6 = puVar6 + 1;
            }
            for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
              *(undefined1 *)puVar6 = *(undefined1 *)&pSVar4->vtbl;
              pSVar4 = (Stream *)((int)&pSVar4->vtbl + 1);
              puVar6 = (ulong *)((int)puVar6 + 1);
            }
            pSVar4 = stream + (idb->names).rgw.itMac;
            (idb->file_times).cdr = (uint)pSVar4->vtbl;
            n = pSVar4[1].vtbl;
            stream = pSVar4 + 2;
            iVar2 = array_set_size(&(idb->file_times).rgd,(uint)n);
            if (iVar2 != 0) {
              array = &(idb->file_times).rgr;
              iVar2 = array_set_size(array,(uint)n);
              if (iVar2 != 0) {
                array_00 = &(idb->file_times).isetPresent;
                iVar2 = array_reload(&array_00->rgw,(c1_u32 **)&stream);
                if ((iVar2 != 0) &&
                   (iVar2 = array_reload(&(idb->file_times).isetDeleted.rgw,(c1_u32 **)&stream),
                   iVar2 != 0)) {
                  uVar3 = 0;
                  if ((idb->file_times).rgd.itMac != 0) {
                    do {
                      iVar2 = iset_contains(array_00,uVar3);
                      if (iVar2 != 0) {
                        (idb->file_times).rgd.rgt[uVar3] = (ulong)stream->vtbl;
                        array->rgt[uVar3] = (ulong)stream[1].vtbl;
                        stream = stream + 2;
                      }
                      uVar3 = uVar3 + 1;
                    } while (uVar3 < (idb->file_times).rgd.itMac);
                  }
                  if (stream == (Stream *)data.pbEnd) {
                    if (data.pbStart == (PB)0x0) {
                      return 1;
                    }
                    __3_YAXPAX_Z(data.pbStart);
                    goto LAB_10646807;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if (data.pbStart != (PB)0x0) {
    __3_YAXPAX_Z(data.pbStart);
    il_buffer_set_memory(&data,(c1_u8 *)0x0,(c1_u8 *)0x0);
  }
  return 0;
}

