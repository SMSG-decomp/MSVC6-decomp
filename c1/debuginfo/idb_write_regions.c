int __fastcall idb_write_regions(c1_idb_state *idb)

{
  uint *src;
  uint uVar1;
  long n;
  int iVar2;
  c1_u32 *local_2c;
  Buffer out;
  Buffer copy;
  
  if ((idb->second_pdb != 0) && (idb->read_second_pdb == 0)) {
    n = (*idb->regions_stream->vtbl->QueryCb)(idb->regions_stream);
    if (0 < n) {
      copy.pbStart = (PB)0x0;
      copy.pbEnd = (PB)0x0;
      copy.cbAlloc = 0;
      copy.pfnMove = (_func_44 *)0x0;
      copy.pfnMoveArg = (void *)0x0;
      iVar2 = il_buffer_reserve_get_cur(&copy,n,(c1_u8 **)0x0);
      if (iVar2 == 0) {
LAB_1064647f:
        if (copy.pbStart != (PB)0x0) {
          __3_YAXPAX_Z(copy.pbStart);
          il_buffer_set_memory(&copy,(c1_u8 *)0x0,(c1_u8 *)0x0);
        }
        return 0;
      }
      il_buffer_set_memory(&copy,copy.pbStart,copy.pbEnd + n);
      iVar2 = (*idb->regions_stream->vtbl->Read2)
                        (idb->regions_stream,0,copy.pbStart,(int)copy.pbEnd - (int)copy.pbStart);
      if (iVar2 == 0) goto LAB_1064647f;
      iVar2 = (*idb->regions_stream_2->vtbl->Replace)
                        (idb->regions_stream_2,copy.pbStart,(int)copy.pbEnd - (int)copy.pbStart);
      if (iVar2 == 0) goto LAB_1064647f;
      if (copy.pbStart != (PB)0x0) {
        __3_YAXPAX_Z(copy.pbStart);
        il_buffer_set_memory(&copy,(c1_u8 *)0x0,(c1_u8 *)0x0);
      }
    }
  }
  out.pbStart = (PB)0x0;
  out.pbEnd = (PB)0x0;
  out.cbAlloc = 0;
  out.pfnMove = (_func_44 *)0x0;
  out.pfnMoveArg = (void *)0x0;
  if (&stack0x00000000 != (undefined1 *)0x2c) {
    iVar2 = il_buffer_reserve_advance(&out,4,(c1_u8 **)&local_2c);
    if (iVar2 != 0) {
      *local_2c = 0x1306c77;
      if (&idb->pch_generation_seen != (c1_u32 *)0x0) {
        iVar2 = il_buffer_reserve_advance(&out,4,(c1_u8 **)&local_2c);
        if (iVar2 != 0) {
          *local_2c = idb->pch_generation_seen;
          if (&idb->options_signature != (c1_u32 *)0x0) {
            iVar2 = il_buffer_reserve_advance(&out,4,(c1_u8 **)&local_2c);
            if (iVar2 != 0) {
              *local_2c = idb->options_signature;
              if (&idb->unk130 != (c1_u32 *)0x0) {
                iVar2 = il_buffer_reserve_advance(&out,4,(c1_u8 **)&local_2c);
                if (iVar2 != 0) {
                  *local_2c = idb->unk130;
                  if (&idb->browse_size != (c1_u32 *)0x0) {
                    iVar2 = il_buffer_reserve_advance(&out,4,(c1_u8 **)&local_2c);
                    if (iVar2 != 0) {
                      *local_2c = idb->browse_size;
                      iVar2 = array16_save(&(idb->file).regions,&out);
                      if (iVar2 != 0) {
                        src = &(idb->browse_regions).count;
                        iVar2 = il_buffer_append(&out,src,4,(c1_u8 **)0x0);
                        if (iVar2 != 0) {
                          uVar1 = *src;
                          if (uVar1 != 0) {
                            iVar2 = il_buffer_append(&out,(idb->browse_regions).data,uVar1 * 0xc,
                                                     (c1_u8 **)0x0);
                            if (iVar2 == 0) goto LAB_106464a4;
                          }
                          iVar2 = array_save(&(idb->names).rgw,&out);
                          if (iVar2 != 0) {
                            iVar2 = map_save(&idb->unit_files,&out);
                            if (iVar2 != 0) {
                              iVar2 = (*idb->regions_stream->vtbl->Replace)
                                                (idb->regions_stream,out.pbStart,
                                                 (int)out.pbEnd - (int)out.pbStart);
                              if (iVar2 != 0) {
                                iVar2 = 1;
                                goto LAB_1064645a;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_106464a4:
  iVar2 = 0;
LAB_1064645a:
  if (out.pbStart != (PB)0x0) {
    __3_YAXPAX_Z(out.pbStart);
    il_buffer_set_memory(&out,(c1_u8 *)0x0,(c1_u8 *)0x0);
  }
  return iVar2;
}

