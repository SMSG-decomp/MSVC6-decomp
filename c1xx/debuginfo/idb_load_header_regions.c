uint __thiscall idb_load_header_regions(c1xx_idb *idb,c1_idb_include_state *include_state)

{
  c1_u32 cVar1;
  char *name;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  c1xx_pdb *pdb;
  c1_u32 *pcStack_12c;
  c1xx_pdb_stream *stream;
  c1_byte_buffer contents;
  char local_110 [272];
  
  name = idb_header_stream_name(idb,include_state,local_110,0x10e);
  if (idb->read_from_backup == 0) {
    pdb = idb->pdb;
  }
  else {
    pdb = idb->pdb_backup;
  }
  uVar2 = (*pdb->vtbl->open_stream)(pdb,name,&stream);
  if (uVar2 == 0) {
    return 0;
  }
  iVar3 = (*stream->vtbl->query_cb)();
  if (iVar3 < 1) goto LAB_1048e306;
  contents.start = (c1_u8 *)0x0;
  contents.cur = (c1_u8 *)0x0;
  contents.size = 0;
  contents.on_move = (c1_il_buffer_move_fn)0x0;
  contents.move_ctx = (void *)0x0;
  if ((iVar3 == 0) || (iVar4 = il_buffer_grow(&contents,iVar3), iVar4 != 0)) {
    if (&stack0x00000000 != (undefined1 *)0x12c) {
      pcStack_12c = (c1_u32 *)contents.cur;
    }
    if (contents.start != (c1_u8 *)0x0) {
      contents.cur = contents.cur + iVar3;
    }
    iVar3 = (*stream->vtbl->read_at)(stream,0,pcStack_12c,iVar3);
    if (iVar3 == 0) goto LAB_1048e32b;
    uVar2 = 1;
    cVar1 = *pcStack_12c;
    pcStack_12c = pcStack_12c + 1;
    if ((cVar1 == 0x1306c77) &&
       ((iVar3 = idb_region_array_reload(&include_state->regions,&pcStack_12c), iVar3 == 0 ||
        (pcStack_12c != (c1_u32 *)contents.cur)))) goto LAB_1048e32b;
  }
  else {
LAB_1048e32b:
    uVar2 = 0;
  }
  if (contents.start != (c1_u8 *)0x0) {
    __3_YAXPAX_Z(contents.start);
  }
LAB_1048e306:
  uVar5 = (*stream->vtbl->release)();
  return uVar2 & uVar5;
}

