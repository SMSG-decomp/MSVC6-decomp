int __fastcall idb_write_dependencies(c1xx_idb *idb)

{
  int iVar1;
  int iVar2;
  uint bit;
  c1_u32 *local_2c;
  c1_byte_buffer record;
  c1_byte_buffer backup_copy;
  
  if ((idb->backup_on_write != 0) && (idb->read_from_backup == 0)) {
    iVar1 = (*idb->deps_stream->vtbl->query_cb)();
    if (0 < iVar1) {
      backup_copy.start = (c1_u8 *)0x0;
      backup_copy.cur = (c1_u8 *)0x0;
      backup_copy.size = 0;
      backup_copy.on_move = (c1_il_buffer_move_fn)0x0;
      backup_copy.move_ctx = (void *)0x0;
      iVar2 = il_buffer_reserve_get_cur(&backup_copy,iVar1,(c1_u8 **)0x0);
      if (iVar2 == 0) {
LAB_1048d7bb:
        if (backup_copy.start != (c1_u8 *)0x0) {
          __3_YAXPAX_Z(backup_copy.start);
          il_buffer_set_memory(&backup_copy,(c1_u8 *)0x0,(c1_u8 *)0x0);
        }
        return 0;
      }
      il_buffer_set_memory(&backup_copy,backup_copy.start,backup_copy.cur + iVar1);
      iVar1 = (*idb->deps_stream->vtbl->read_at)
                        (0,backup_copy.start,(int)backup_copy.cur - (int)backup_copy.start);
      if (iVar1 == 0) goto LAB_1048d7bb;
      iVar1 = (*idb->deps_stream_backup->vtbl->replace)
                        (backup_copy.start,(int)backup_copy.cur - (int)backup_copy.start);
      if (iVar1 == 0) goto LAB_1048d7bb;
      if (backup_copy.start != (c1_u8 *)0x0) {
        __3_YAXPAX_Z(backup_copy.start);
        il_buffer_set_memory(&backup_copy,(c1_u8 *)0x0,(c1_u8 *)0x0);
      }
    }
  }
  record.start = (c1_u8 *)0x0;
  record.cur = (c1_u8 *)0x0;
  record.size = 0;
  record.on_move = (c1_il_buffer_move_fn)0x0;
  record.move_ctx = (void *)0x0;
  if (&stack0x00000000 != (undefined1 *)0x2c) {
    iVar1 = il_buffer_reserve_advance(&record,4,(c1_u8 **)&local_2c);
    if (iVar1 != 0) {
      *local_2c = 0x1306c77;
      if (&idb->pch_generation != (int *)0x0) {
        iVar1 = il_buffer_reserve_advance(&record,4,(c1_u8 **)&local_2c);
        if (iVar1 != 0) {
          *local_2c = idb->pch_generation;
          if (&idb->pdb_signature != (c1_u32 *)0x0) {
            iVar1 = il_buffer_reserve_advance(&record,4,(c1_u8 **)&local_2c);
            if (iVar1 != 0) {
              *local_2c = idb->pdb_signature;
              if (&idb->pdb_age != (c1_u32 *)0x0) {
                iVar1 = il_buffer_reserve_advance(&record,4,(c1_u8 **)&local_2c);
                if (iVar1 != 0) {
                  *local_2c = idb->pdb_age;
                  local_2c = (c1_u32 *)(idb->header_times).domain.count;
                  iVar1 = il_buffer_append(&record,&(idb->header_times).count,4,(c1_u8 **)0x0);
                  if (iVar1 != 0) {
                    iVar1 = il_buffer_append(&record,&local_2c,4,(c1_u8 **)0x0);
                    if (iVar1 != 0) {
                      iVar1 = array_save(&(idb->header_times).present,&record);
                      if (iVar1 != 0) {
                        iVar1 = array_save(&(idb->header_times).deleted,&record);
                        if (iVar1 != 0) {
                          bit = 0;
                          if ((idb->header_times).domain.count != 0) {
                            do {
                              iVar1 = iset_contains(&(idb->header_times).present,bit);
                              if (iVar1 != 0) {
                                iVar1 = il_buffer_append(&record,(idb->header_times).domain.data +
                                                                 bit,4,(c1_u8 **)0x0);
                                if (iVar1 == 0) goto LAB_1048d7e0;
                                iVar1 = il_buffer_append(&record,(idb->header_times).range.data +
                                                                 bit,4,(c1_u8 **)0x0);
                                if (iVar1 == 0) goto LAB_1048d7e0;
                              }
                              bit = bit + 1;
                            } while (bit < (idb->header_times).domain.count);
                          }
                          iVar1 = map_save(&idb->header_signatures,&record);
                          if (iVar1 != 0) {
                            iVar1 = (*idb->deps_stream->vtbl->replace)
                                              (record.start,(int)record.cur - (int)record.start);
                            if (iVar1 != 0) {
                              iVar1 = 1;
                              goto LAB_1048d7a0;
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
LAB_1048d7e0:
  iVar1 = 0;
LAB_1048d7a0:
  if (record.start != (c1_u8 *)0x0) {
    il_buffer_free(&record);
  }
  return iVar1;
}

