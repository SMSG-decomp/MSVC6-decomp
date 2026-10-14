int __thiscall idb_read_dependencies(c1_idb_state *idb,Stream *stream,int *complete)

{
  Array_DWORD *array;
  ISet *array_00;
  Stream_vtbl *pSVar1;
  uint uVar2;
  int iVar3;
  Stream *pSVar4;
  Buffer BStack_14;
  
  pSVar4 = stream;
  *complete = 0;
  uVar2 = (*stream->vtbl->QueryCb)(stream);
  if (uVar2 < 4) {
    return 0;
  }
  BStack_14.pbStart = (c1_u8 *)0x0;
  BStack_14.pbEnd = (PB)0x0;
  BStack_14.cbAlloc = 0;
  BStack_14.pfnMove = (_func_44 *)0x0;
  BStack_14.pfnMoveArg = (void *)0x0;
  iVar3 = il_buffer_reserve(&BStack_14,uVar2);
  if (iVar3 != 0) {
    if (&stack0x00000000 != (undefined1 *)0xfffffffc) {
      stream = (Stream *)BStack_14.pbEnd;
    }
    il_buffer_set_memory
              (&BStack_14,BStack_14.pbStart,(c1_u8 *)((int)(Stream_vtbl **)BStack_14.pbEnd + uVar2))
    ;
    iVar3 = (*pSVar4->vtbl->Read2)(pSVar4,0,stream,uVar2);
    if (iVar3 != 0) {
      if (stream->vtbl != (Stream_vtbl *)0x1306c77) {
        stream = stream + 1;
        _unlink(g_object_file_name);
        if (BStack_14.pbStart == (c1_u8 *)0x0) {
          return 1;
        }
        __3_YAXPAX_Z(BStack_14.pbStart);
LAB_10646563:
        il_buffer_set_memory(&BStack_14,(c1_u8 *)0x0,(c1_u8 *)0x0);
        return 1;
      }
      pSVar1 = stream[1].vtbl;
      idb->pch_generation_used = (c1_u32)pSVar1;
      idb->pch_generation = (c1_u32)pSVar1;
      idb->pdb_signature = (c1_u32)stream[2].vtbl;
      idb->pdb_age = (c1_u32)stream[3].vtbl;
      (idb->dependencies).cdr = (uint)stream[4].vtbl;
      pSVar1 = stream[5].vtbl;
      stream = stream + 6;
      iVar3 = array_set_size(&(idb->dependencies).rgd,(uint)pSVar1);
      if (iVar3 != 0) {
        array = &(idb->dependencies).rgr;
        iVar3 = array_set_size(array,(uint)pSVar1);
        if (((iVar3 != 0) &&
            (iVar3 = array_reload(&(idb->dependencies).isetPresent.rgw,(c1_u32 **)&stream),
            iVar3 != 0)) &&
           (iVar3 = array_reload(&(idb->dependencies).isetDeleted.rgw,(c1_u32 **)&stream),
           iVar3 != 0)) {
          uVar2 = 0;
          if ((idb->dependencies).rgd.itMac != 0) {
            do {
              iVar3 = iset_contains(&(idb->dependencies).isetPresent,uVar2);
              if (iVar3 != 0) {
                (idb->dependencies).rgd.rgt[uVar2] = (ulong)stream->vtbl;
                array->rgt[uVar2] = (ulong)stream[1].vtbl;
                stream = stream + 2;
              }
              uVar2 = uVar2 + 1;
            } while (uVar2 < (idb->dependencies).rgd.itMac);
          }
          pSVar4 = stream + 1;
          (idb->dependencies_2).cdr = (uint)stream->vtbl;
          stream = stream + 2;
          iVar3 = map_arrays_set_size(&idb->dependencies_2,(uint)pSVar4->vtbl);
          if (iVar3 != 0) {
            array_00 = &(idb->dependencies_2).isetPresent;
            iVar3 = array_reload(&array_00->rgw,(c1_u32 **)&stream);
            if ((iVar3 != 0) &&
               (iVar3 = array_reload(&(idb->dependencies_2).isetDeleted.rgw,(c1_u32 **)&stream),
               iVar3 != 0)) {
              uVar2 = 0;
              if ((idb->dependencies_2).rgd.itMac != 0) {
                do {
                  iVar3 = iset_contains(array_00,uVar2);
                  if (iVar3 != 0) {
                    (idb->dependencies_2).rgd.rgt[uVar2] = (ulong)stream->vtbl;
                    (idb->dependencies_2).rgr.rgt[uVar2] = (ulong)stream[1].vtbl;
                    stream = stream + 2;
                  }
                  uVar2 = uVar2 + 1;
                } while (uVar2 < (idb->dependencies_2).rgd.itMac);
              }
              if (stream == (Stream *)BStack_14.pbEnd) {
                *complete = 1;
                if (BStack_14.pbStart == (c1_u8 *)0x0) {
                  return 1;
                }
                __3_YAXPAX_Z(BStack_14.pbStart);
                goto LAB_10646563;
              }
            }
          }
        }
      }
      if (BStack_14.pbStart == (c1_u8 *)0x0) {
        return 0;
      }
      il_buffer_free((int *)&BStack_14);
      return 0;
    }
  }
  if (BStack_14.pbStart != (c1_u8 *)0x0) {
    __3_YAXPAX_Z(BStack_14.pbStart);
    il_buffer_set_memory(&BStack_14,(c1_u8 *)0x0,(c1_u8 *)0x0);
  }
  return 0;
}

