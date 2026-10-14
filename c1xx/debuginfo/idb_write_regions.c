int __fastcall idb_write_regions(c1xx_idb *idb)

{
  c1_u32 *src;
  c1_u32 cVar1;
  int iVar2;
  int iVar3;
  int *local_2c;
  c1_byte_buffer record;
  c1_byte_buffer backup_copy;
  
  if ((idb->backup_on_write != 0) && (idb->read_from_backup == 0)) {
    iVar2 = (*idb->module_stream->vtbl->query_cb)();
    if (0 < iVar2) {
      backup_copy.start = (c1_u8 *)0x0;
      backup_copy.cur = (c1_u8 *)0x0;
      backup_copy.size = 0;
      backup_copy.on_move = (c1_il_buffer_move_fn)0x0;
      backup_copy.move_ctx = (void *)0x0;
      iVar3 = il_buffer_reserve_get_cur(&backup_copy,iVar2,(c1_u8 **)0x0);
      if (iVar3 == 0) {
LAB_1048da6c:
        if (backup_copy.start != (c1_u8 *)0x0) {
          __3_YAXPAX_Z(backup_copy.start);
          il_buffer_set_memory(&backup_copy,(c1_u8 *)0x0,(c1_u8 *)0x0);
        }
        return 0;
      }
      il_buffer_set_memory(&backup_copy,backup_copy.start,backup_copy.cur + iVar2);
      iVar2 = (*idb->module_stream->vtbl->read_at)
                        (0,backup_copy.start,(int)backup_copy.cur - (int)backup_copy.start);
      if (iVar2 == 0) goto LAB_1048da6c;
      iVar2 = (*idb->module_stream_backup->vtbl->replace)
                        (backup_copy.start,(int)backup_copy.cur - (int)backup_copy.start);
      if (iVar2 == 0) goto LAB_1048da6c;
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
    iVar2 = il_buffer_reserve_advance(&record,4,(c1_u8 **)&local_2c);
    if (iVar2 != 0) {
      *local_2c = 0x1306c77;
      if (&idb->regions_pch_generation != (int *)0x0) {
        iVar2 = il_buffer_reserve_advance(&record,4,(c1_u8 **)&local_2c);
        if (iVar2 != 0) {
          *local_2c = idb->regions_pch_generation;
          if (&idb->options_signature != (int *)0x0) {
            iVar2 = il_buffer_reserve_advance(&record,4,(c1_u8 **)&local_2c);
            if (iVar2 != 0) {
              *local_2c = idb->options_signature;
              if (&idb->unk130 != (int *)0x0) {
                iVar2 = il_buffer_reserve_advance(&record,4,(c1_u8 **)&local_2c);
                if (iVar2 != 0) {
                  *local_2c = idb->unk130;
                  if (&idb->browse_size != (int *)0x0) {
                    iVar2 = il_buffer_reserve_advance(&record,4,(c1_u8 **)&local_2c);
                    if (iVar2 != 0) {
                      *local_2c = idb->browse_size;
                      iVar2 = array16_save(&(idb->file).regions,&record);
                      if (iVar2 != 0) {
                        src = &(idb->browse_lines).count;
                        iVar2 = il_buffer_append(&record,src,4,(c1_u8 **)0x0);
                        if (iVar2 != 0) {
                          cVar1 = *src;
                          if (cVar1 != 0) {
                            iVar2 = il_buffer_append(&record,(idb->browse_lines).data,cVar1 * 0xc,
                                                     (c1_u8 **)0x0);
                            if (iVar2 == 0) goto LAB_1048da91;
                          }
                          iVar2 = array_save(&idb->name_hash_bits,&record);
                          if (iVar2 != 0) {
                            iVar2 = map_save(&idb->file_times,&record);
                            if (iVar2 != 0) {
                              iVar2 = (*idb->module_stream->vtbl->replace)
                                                (record.start,(int)record.cur - (int)record.start);
                              if (iVar2 != 0) {
                                iVar2 = 1;
                                goto LAB_1048da47;
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
LAB_1048da91:
  iVar2 = 0;
LAB_1048da47:
  if (record.start != (c1_u8 *)0x0) {
    __3_YAXPAX_Z(record.start);
    il_buffer_set_memory(&record,(c1_u8 *)0x0,(c1_u8 *)0x0);
  }
  return iVar2;
}

