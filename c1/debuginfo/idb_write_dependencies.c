int __fastcall idb_write_dependencies(c1_idb_state *idb)

{
  long n;
  int iVar1;
  uint n_00;
  c1_u32 *local_2c;
  Buffer out;
  Buffer copy;
  
  if ((idb->second_pdb != 0) && (idb->read_second_pdb == 0)) {
    n = (*idb->deps_stream->vtbl->QueryCb)(idb->deps_stream);
    if (0 < n) {
      copy.pbStart = (PB)0x0;
      copy.pbEnd = (PB)0x0;
      copy.cbAlloc = 0;
      copy.pfnMove = (_func_44 *)0x0;
      copy.pfnMoveArg = (void *)0x0;
      iVar1 = il_buffer_reserve_get_cur(&copy,n,(c1_u8 **)0x0);
      if (iVar1 == 0) {
LAB_106461ce:
        if (copy.pbStart != (PB)0x0) {
          __3_YAXPAX_Z(copy.pbStart);
          il_buffer_set_memory(&copy,(c1_u8 *)0x0,(c1_u8 *)0x0);
        }
        return 0;
      }
      il_buffer_set_memory(&copy,copy.pbStart,copy.pbEnd + n);
      iVar1 = (*idb->deps_stream->vtbl->Read2)
                        (idb->deps_stream,0,copy.pbStart,(int)copy.pbEnd - (int)copy.pbStart);
      if (iVar1 == 0) goto LAB_106461ce;
      iVar1 = (*idb->deps_stream_2->vtbl->Replace)
                        (idb->deps_stream_2,copy.pbStart,(int)copy.pbEnd - (int)copy.pbStart);
      if (iVar1 == 0) goto LAB_106461ce;
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
    iVar1 = il_buffer_reserve_advance(&out,4,(c1_u8 **)&local_2c);
    if (iVar1 != 0) {
      *local_2c = 0x1306c77;
      if (&idb->pch_generation != (c1_u32 *)0x0) {
        iVar1 = il_buffer_reserve_advance(&out,4,(c1_u8 **)&local_2c);
        if (iVar1 != 0) {
          *local_2c = idb->pch_generation;
          if (&idb->pdb_signature != (c1_u32 *)0x0) {
            iVar1 = il_buffer_reserve_advance(&out,4,(c1_u8 **)&local_2c);
            if (iVar1 != 0) {
              *local_2c = idb->pdb_signature;
              if (&idb->pdb_age != (c1_u32 *)0x0) {
                iVar1 = il_buffer_reserve_advance(&out,4,(c1_u8 **)&local_2c);
                if (iVar1 != 0) {
                  *local_2c = idb->pdb_age;
                  local_2c = (c1_u32 *)(idb->dependencies).rgd.itMac;
                  iVar1 = il_buffer_append(&out,&(idb->dependencies).cdr,4,(c1_u8 **)0x0);
                  if (iVar1 != 0) {
                    iVar1 = il_buffer_append(&out,&local_2c,4,(c1_u8 **)0x0);
                    if (iVar1 != 0) {
                      iVar1 = array_save(&(idb->dependencies).isetPresent.rgw,&out);
                      if (iVar1 != 0) {
                        iVar1 = array_save(&(idb->dependencies).isetDeleted.rgw,&out);
                        if (iVar1 != 0) {
                          n_00 = 0;
                          if ((idb->dependencies).rgd.itMac != 0) {
                            do {
                              iVar1 = iset_contains(&(idb->dependencies).isetPresent,n_00);
                              if (iVar1 != 0) {
                                iVar1 = il_buffer_append(&out,(idb->dependencies).rgd.rgt + n_00,4,
                                                         (c1_u8 **)0x0);
                                if (iVar1 == 0) goto LAB_106461f3;
                                iVar1 = il_buffer_append(&out,(idb->dependencies).rgr.rgt + n_00,4,
                                                         (c1_u8 **)0x0);
                                if (iVar1 == 0) goto LAB_106461f3;
                              }
                              n_00 = n_00 + 1;
                            } while (n_00 < (idb->dependencies).rgd.itMac);
                          }
                          iVar1 = map_save(&idb->dependencies_2,&out);
                          if (iVar1 != 0) {
                            iVar1 = (*idb->deps_stream->vtbl->Replace)
                                              (idb->deps_stream,out.pbStart,
                                               (int)out.pbEnd - (int)out.pbStart);
                            if (iVar1 != 0) {
                              iVar1 = 1;
                              goto LAB_106461b3;
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
LAB_106461f3:
  iVar1 = 0;
LAB_106461b3:
  if (out.pbStart != (PB)0x0) {
    il_buffer_free((int *)&out);
  }
  return iVar1;
}

