uint __thiscall
idb_function_end(c1_idb_state *idb,uint close_header_region,uint end_line,int unused,int *state_out,
                int *result_out)

{
  fe_idb_region *signature;
  uchar *puVar1;
  ushort uVar2;
  uchar uVar3;
  uchar uVar4;
  uchar uVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  fe_idb_region *pfVar10;
  uint *src_words;
  uint uVar11;
  
  g_idb_outside_function = '\x01';
  *result_out = 0;
  idb->in_function = '\0';
  if ((((idb->include_stack).count != 0) || (iVar8 = idb->state, iVar8 == 1)) || (iVar8 == 5)) {
    *state_out = idb->state;
    if (close_header_region != 0) {
      uVar7 = idb_function_region_end(idb,close_header_region,end_line,unused,result_out);
      return uVar7;
    }
    return 1;
  }
  result_out = (int *)0x1;
  if (iVar8 == 4) {
    (idb->file).regions.data[(idb->file).cursor].start_line = (idb->file).current.start_line;
    (*idb->tracker->vtbl->reset)(idb->tracker);
    goto LAB_1064745d;
  }
  if (idb->open_conditionals != 0) {
    puVar1 = &(idb->file).current.flags;
    *puVar1 = *puVar1 | 8;
  }
  signature = &(idb->file).current;
  bVar6 = (*idb->tracker->vtbl->take)
                    (idb->tracker,&signature->signature,&(idb->file).current.length);
  result_out = (int *)(uint)bVar6;
  if (result_out == (int *)0x0) goto LAB_1064745d;
  uVar7 = (idb->file).cursor;
  (idb->file).current.line_count = (short)end_line - (idb->file).current.start_line;
  if (uVar7 < (idb->file).regions.count) {
    if ((((idb->file).current.flags & 8) == 0) || (((idb->file).regions.data[uVar7].flags & 8) != 0)
       ) {
      pfVar10 = (idb->file).regions.data + uVar7;
      pfVar10->signature = signature->signature;
      pfVar10->length = (idb->file).current.length;
      uVar2 = (idb->file).current.line_count;
      pfVar10->start_line = (idb->file).current.start_line;
      pfVar10->line_count = uVar2;
      uVar3 = (idb->file).current.pad0d[0];
      uVar4 = (idb->file).current.pad0d[1];
      uVar5 = (idb->file).current.pad0d[2];
      pfVar10->flags = (idb->file).current.flags;
      pfVar10->pad0d[0] = uVar3;
      pfVar10->pad0d[1] = uVar4;
      pfVar10->pad0d[2] = uVar5;
      goto LAB_1064745d;
    }
    uVar7 = (*idb->vtbl->idb_invalidate)(idb);
    result_out = (int *)((uint)result_out & uVar7);
    iVar8 = region_array_set_size(&(idb->file).regions,(idb->file).regions.count + 1);
    if (iVar8 != 0) {
      pfVar10 = (idb->file).regions.data + ((idb->file).regions.count - 1);
      goto LAB_10647576;
    }
LAB_106476a2:
    uVar7 = 0;
  }
  else {
    uVar7 = (idb->file).regions.count;
    uVar9 = (idb->file).regions.capacity;
    uVar11 = uVar7 + 1;
    if (uVar9 < uVar11) {
      uVar9 = uVar9 * 3 >> 1;
      end_line = uVar11;
      if (uVar11 <= uVar9) {
        end_line = uVar9;
      }
      pfVar10 = __2_YAPAXI_Z(end_line << 4);
      if (pfVar10 == (fe_idb_region *)0x0) goto LAB_106476a2;
      vector_constructor_iterator(pfVar10,0x10,end_line,idb_region_ctor);
      iVar8 = 0;
      if ((idb->file).regions.data != (fe_idb_region *)0x0) {
        close_header_region = 0;
        if ((idb->file).regions.count != 0) {
          do {
            puVar1 = pfVar10->pad0d + iVar8 + -0xd;
            src_words = (uint *)(((idb->file).regions.data)->pad0d + iVar8 + -0xd);
            iVar8 = iVar8 + 0x10;
            *(uint *)puVar1 = *src_words;
            *(uint *)(puVar1 + 4) = src_words[1];
            *(uint *)(puVar1 + 8) = src_words[2];
            *(uint *)(puVar1 + 0xc) = src_words[3];
            close_header_region = close_header_region + 1;
          } while (close_header_region < (idb->file).regions.count);
        }
        __3_YAXPAX_Z((idb->file).regions.data);
      }
      (idb->file).regions.data = pfVar10;
      (idb->file).regions.capacity = end_line;
    }
    pfVar10 = (idb->file).regions.data;
    (idb->file).regions.count = uVar11;
    pfVar10 = pfVar10 + uVar7;
LAB_10647576:
    pfVar10->signature = signature->signature;
    pfVar10->length = (idb->file).current.length;
    uVar2 = (idb->file).current.line_count;
    pfVar10->start_line = (idb->file).current.start_line;
    pfVar10->line_count = uVar2;
    uVar3 = (idb->file).current.pad0d[0];
    uVar4 = (idb->file).current.pad0d[1];
    uVar5 = (idb->file).current.pad0d[2];
    uVar7 = 1;
    pfVar10->flags = (idb->file).current.flags;
    pfVar10->pad0d[0] = uVar3;
    pfVar10->pad0d[1] = uVar4;
    pfVar10->pad0d[2] = uVar5;
  }
  result_out = (int *)((uint)result_out & uVar7);
LAB_1064745d:
  puVar1 = &(idb->file).regions.data[(idb->file).cursor].flags;
  *puVar1 = idb->helper_called << 7 | *puVar1 & 0x7f;
  (*g_il_emitter->vtbl->region_boundary)();
  (idb->file).cursor = (idb->file).cursor + 1;
  if (result_out != (int *)0x0) {
    result_out = (int *)idb_check_next_region(idb,1,1);
    *state_out = idb->state;
  }
  return (uint)result_out;
}

