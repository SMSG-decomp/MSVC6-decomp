uint __thiscall idb_save_header_regions(c1xx_idb *idb,c1_idb_include_state *include_state)

{
  char *name;
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piStack_12c;
  c1_byte_buffer buffer;
  c1xx_pdb_stream *stream;
  char local_110 [272];
  
  name = idb_header_stream_name(idb,include_state,local_110,0x10e);
  iVar1 = (*idb->pdb->vtbl->open_stream)(idb->pdb,name,&stream);
  if (iVar1 == 0) {
    return 0;
  }
  if ((idb->backup_on_write != 0) && (idb->read_from_backup == 0)) {
    iVar1 = (*idb->pdb_backup->vtbl->open_stream)(idb->pdb_backup,name,&piStack_12c);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = (*stream->vtbl->query_cb)();
    if (0 < iVar1) {
      buffer.start = (c1_u8 *)0x0;
      buffer.cur = (c1_u8 *)0x0;
      buffer.size = 0;
      buffer.on_move = (c1_il_buffer_move_fn)0x0;
      buffer.move_ctx = (void *)0x0;
      iVar2 = il_buffer_reserve(&buffer,iVar1);
      if (iVar2 == 0) {
LAB_1048e0f2:
        if (buffer.start == (c1_u8 *)0x0) {
          return 0;
        }
        __3_YAXPAX_Z(buffer.start);
        il_buffer_set_memory(&buffer,(c1_u8 *)0x0,(c1_u8 *)0x0);
        return 0;
      }
      il_buffer_set_memory(&buffer,buffer.start,buffer.cur + iVar1);
      iVar1 = (*stream->vtbl->read_at)(stream,0,buffer.start,(int)buffer.cur - (int)buffer.start);
      if (((iVar1 == 0) ||
          (iVar1 = (**(code **)(*piStack_12c + 0xc))
                             (piStack_12c,buffer.start,(int)buffer.cur - (int)buffer.start),
          iVar1 == 0)) || (iVar1 = (**(code **)(*piStack_12c + 0x18))(), iVar1 == 0))
      goto LAB_1048e0f2;
      if (buffer.start != (c1_u8 *)0x0) {
        __3_YAXPAX_Z(buffer.start);
        il_buffer_set_memory(&buffer,(c1_u8 *)0x0,(c1_u8 *)0x0);
      }
    }
  }
  if ((include_state->regions).count == 1) {
    uVar3 = (*stream->vtbl->truncate)(stream,0);
    goto LAB_1048e14d;
  }
  buffer.start = (c1_u8 *)0x0;
  buffer.cur = (c1_u8 *)0x0;
  buffer.size = 0;
  buffer.on_move = (c1_il_buffer_move_fn)0x0;
  buffer.move_ctx = (void *)0x0;
  if ((&stack0x00000000 == (undefined1 *)0x12c) ||
     (iVar1 = il_buffer_reserve_get_cur(&buffer,4,(c1_u8 **)&piStack_12c), iVar1 == 0)) {
LAB_1048e200:
    uVar3 = 0;
  }
  else {
    il_buffer_set_memory(&buffer,buffer.start,buffer.cur + 4);
    *piStack_12c = 0x1306c77;
    iVar1 = array16_save(&include_state->regions,&buffer);
    if ((iVar1 == 0) ||
       (iVar1 = (*stream->vtbl->replace)(stream,buffer.start,(int)buffer.cur - (int)buffer.start),
       iVar1 == 0)) goto LAB_1048e200;
    uVar3 = 1;
  }
  if (buffer.start != (c1_u8 *)0x0) {
    __3_YAXPAX_Z(buffer.start);
  }
LAB_1048e14d:
  uVar4 = (*stream->vtbl->release)();
  return uVar3 & uVar4;
}

