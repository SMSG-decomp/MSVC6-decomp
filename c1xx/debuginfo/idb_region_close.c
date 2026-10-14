uint __thiscall
idb_region_close(c1xx_idb *idb,uint line,int consume_following,int *changed,int *layout_changed)

{
  byte bVar1;
  c1xx_source_tracker_iface *hasher;
  c1_mre_file *pcVar2;
  bool bVar3;
  c1_u16 cVar4;
  c1_u8 cVar5;
  c1_u8 cVar6;
  c1_u8 cVar7;
  uint uVar8;
  c1_idb_region *pcVar9;
  c1_u16 *pcVar10;
  c1_u32 cVar11;
  int iVar12;
  uint *entry;
  uint *entry_2;
  uint *entry_3;
  uint uVar13;
  uint *dst_3;
  uint *dst;
  uint *dst_2;
  uint uVar14;
  uint uStack_2c;
  uint uStack_18;
  uint uStack_14;
  ushort uStack_6;
  
  *changed = 0;
  *layout_changed = 0;
  hasher = idb->source_tracker;
  (idb->file).current.line_count = (short)line - (idb->file).current.start_line;
  uStack_2c = (*hasher->vtbl->take)(hasher,(int *)&(idb->file).current,&(idb->file).current.length);
  uStack_2c = uStack_2c & 0xff;
  if (uStack_2c != 0) {
    uVar8 = (idb->file).cursor;
    if (uVar8 < (idb->file).regions.count) {
      pcVar9 = (idb->file).regions.data + uVar8;
      cVar11 = pcVar9->signature;
      iVar12 = pcVar9->length;
      uStack_18._0_2_ = pcVar9->start_line;
      uStack_18._2_2_ = pcVar9->line_count;
      uVar8._0_1_ = pcVar9->flags;
      uVar8._1_1_ = pcVar9->pad0d[0];
      uVar8._2_1_ = pcVar9->pad0d[1];
      uVar8._3_1_ = pcVar9->pad0d[2];
      bVar1 = (idb->file).current.flags;
      if (((bVar1 & 7) == 1) || (((undefined1)uVar8 & 7) != 1)) {
        bVar3 = false;
        uStack_6 = uStack_18._2_2_;
      }
      else {
        cVar11 = 0;
        iVar12 = -1;
        uStack_18 = line & 0xffff;
        uStack_14 = CONCAT31(uStack_14._1_3_,3);
        bVar3 = true;
        uStack_6 = 0;
        uVar8 = uStack_14;
      }
      if ((cVar11 == (idb->file).current.signature) && (iVar12 == (idb->file).current.length)) {
        if (((bVar1 & 0x20) != 0) && ((idb->file).current.start_line != (c1_u16)uStack_18)) {
          *changed = 1;
          if ((((idb->file).current.flags & 0x40) == 0) && ((uVar8 & 0x40) == 0)) {
            *layout_changed = 0;
          }
          else {
            *layout_changed = 1;
          }
        }
      }
      else {
        *changed = 1;
        if ((((idb->file).current.flags & 0x40) == 0) && ((uVar8 & 0x40) == 0)) {
          iVar12 = 0;
        }
        else {
          iVar12 = 1;
        }
        *layout_changed = iVar12;
        iVar12 = (uint)(idb->file).current.line_count - (uint)uStack_6;
        if (((iVar12 != 0) && (pcVar2 = (idb->file).tracker, pcVar2 != (c1_mre_file *)0x0)) &&
           (uStack_2c = (*pcVar2->vtbl->note_line_delta)
                                  (pcVar2,(idb->file).current.start_line + 1,iVar12), uStack_2c == 0
           )) {
          return 0;
        }
        if ((((idb->file).current.flags & 8) != 0) || ((uVar8 & 8) != 0)) {
          (idb->file).changed = '\x01';
        }
      }
      if (bVar3) {
        uVar8 = (idb->file).regions.capacity;
        cVar11 = (idb->file).cursor;
        uVar13 = (idb->file).regions.count + 1;
        if (uVar8 < uVar13) {
          uVar8 = uVar8 * 3 >> 1;
          line = uVar13;
          if (uVar13 <= uVar8) {
            line = uVar8;
          }
          pcVar9 = __2_YAPAXI_Z(line << 4);
          if (pcVar9 == (c1_idb_region *)0x0) {
            return uStack_2c;
          }
          vector_constructor_iterator(pcVar9,0x10,line,gi_region_entry_init_empty);
          if ((idb->file).regions.data != (c1_idb_region *)0x0) {
            uVar8 = 0;
            if ((idb->file).regions.count != 0) {
              iVar12 = 0;
              do {
                dst = (uint *)(pcVar9->pad0d + iVar12 + -0xd);
                entry = (uint *)(((idb->file).regions.data)->pad0d + iVar12 + -0xd);
                uVar8 = uVar8 + 1;
                iVar12 = iVar12 + 0x10;
                *dst = *entry;
                dst[1] = entry[1];
                dst[2] = entry[2];
                dst[3] = entry[3];
              } while (uVar8 < (idb->file).regions.count);
            }
            __3_YAXPAX_Z((idb->file).regions.data);
          }
          (idb->file).regions.data = pcVar9;
          (idb->file).regions.capacity = line;
        }
        pcVar9 = (idb->file).regions.data;
        (idb->file).regions.count = uVar13;
        memmove(pcVar9 + cVar11 + 1,pcVar9 + cVar11,((cVar11 + 1) * 0xfffffff + uVar13) * 0x10);
        pcVar9 = (idb->file).regions.data + cVar11;
        pcVar9->signature = (idb->file).current.signature;
        pcVar9->length = (idb->file).current.length;
        cVar4 = (idb->file).current.line_count;
        pcVar9->start_line = (idb->file).current.start_line;
        pcVar9->line_count = cVar4;
        cVar5 = (idb->file).current.pad0d[0];
        cVar6 = (idb->file).current.pad0d[1];
        cVar7 = (idb->file).current.pad0d[2];
        pcVar9->flags = (idb->file).current.flags;
        pcVar9->pad0d[0] = cVar5;
        pcVar9->pad0d[1] = cVar6;
        pcVar9->pad0d[2] = cVar7;
      }
      else {
        pcVar9 = (idb->file).regions.data + (idb->file).cursor;
        pcVar9->signature = (idb->file).current.signature;
        pcVar9->length = (idb->file).current.length;
        cVar4 = (idb->file).current.line_count;
        pcVar9->start_line = (idb->file).current.start_line;
        pcVar9->line_count = cVar4;
        cVar5 = (idb->file).current.pad0d[0];
        cVar6 = (idb->file).current.pad0d[1];
        cVar7 = (idb->file).current.pad0d[2];
        pcVar9->flags = (idb->file).current.flags;
        pcVar9->pad0d[0] = cVar5;
        pcVar9->pad0d[1] = cVar6;
        pcVar9->pad0d[2] = cVar7;
      }
    }
    else {
      cVar11 = (idb->file).regions.count;
      uVar8 = (idb->file).regions.capacity;
      uVar13 = cVar11 + 1;
      if (uVar8 < uVar13) {
        uVar8 = uVar8 * 3 >> 1;
        if (uVar8 < uVar13) {
          uVar8 = uVar13;
        }
        pcVar9 = __2_YAPAXI_Z(uVar8 << 4);
        if (pcVar9 == (c1_idb_region *)0x0) {
          return 0;
        }
        vector_constructor_iterator(pcVar9,0x10,uVar8,gi_region_entry_init_empty);
        if ((idb->file).regions.data != (c1_idb_region *)0x0) {
          uVar14 = 0;
          if ((idb->file).regions.count != 0) {
            iVar12 = 0;
            do {
              dst_3 = (uint *)(pcVar9->pad0d + iVar12 + -0xd);
              entry_3 = (uint *)(((idb->file).regions.data)->pad0d + iVar12 + -0xd);
              uVar14 = uVar14 + 1;
              iVar12 = iVar12 + 0x10;
              *dst_3 = *entry_3;
              dst_3[1] = entry_3[1];
              dst_3[2] = entry_3[2];
              dst_3[3] = entry_3[3];
            } while (uVar14 < (idb->file).regions.count);
          }
          __3_YAXPAX_Z((idb->file).regions.data);
        }
        (idb->file).regions.data = pcVar9;
        (idb->file).regions.capacity = uVar8;
      }
      pcVar9 = (idb->file).regions.data;
      (idb->file).regions.count = uVar13;
      uStack_2c = 1;
      pcVar9[cVar11].signature = (idb->file).current.signature;
      pcVar9[cVar11].length = (idb->file).current.length;
      cVar4 = (idb->file).current.line_count;
      pcVar9[cVar11].start_line = (idb->file).current.start_line;
      pcVar9[cVar11].line_count = cVar4;
      cVar5 = (idb->file).current.pad0d[0];
      cVar6 = (idb->file).current.pad0d[1];
      cVar7 = (idb->file).current.pad0d[2];
      pcVar9 = pcVar9 + cVar11;
      pcVar9->flags = (idb->file).current.flags;
      pcVar9->pad0d[0] = cVar5;
      pcVar9->pad0d[1] = cVar6;
      pcVar9->pad0d[2] = cVar7;
    }
    uVar8 = (idb->file).cursor + 1;
    (idb->file).cursor = uVar8;
    if ((consume_following != 0) && (uVar8 < (idb->file).regions.count)) {
      do {
        cVar11 = (idb->file).cursor;
        pcVar9 = (idb->file).regions.data;
        if ((pcVar9[cVar11].flags & 7) == 1) {
          return uStack_2c;
        }
        *changed = 1;
        *layout_changed = 1;
        if (((pcVar9[cVar11].line_count != 0) &&
            (pcVar2 = (idb->file).tracker, pcVar2 != (c1_mre_file *)0x0)) &&
           (uStack_2c = (*pcVar2->vtbl->note_line_delta)
                                  (pcVar2,(idb->file).current.start_line + 1,
                                   -(uint)pcVar9[cVar11].line_count), uStack_2c == 0)) {
          return 0;
        }
        if ((pcVar9[cVar11].flags & 8) != 0) {
          (idb->file).changed = '\x01';
        }
        cVar11 = (idb->file).cursor;
        pcVar9 = (idb->file).regions.data;
        iVar12 = cVar11 + 1;
        memmove(pcVar9 + cVar11,pcVar9 + iVar12,
                (iVar12 * 0xfffffff + (idb->file).regions.count) * 0x10);
        pcVar9 = (idb->file).regions.data + ((idb->file).regions.count - 1);
        pcVar9->signature = 0;
        pcVar9->length = -1;
        uStack_14 = CONCAT31(uStack_14._1_3_,0x18);
        uVar13 = uStack_14;
        pcVar9->start_line = 0;
        pcVar9->line_count = 0;
        pcVar9->flags = 0x18;
        pcVar9->pad0d[0] = uStack_14._1_1_;
        pcVar9->pad0d[1] = uStack_14._2_1_;
        pcVar9->pad0d[2] = uStack_14._3_1_;
        uVar8 = (idb->file).regions.capacity;
        uVar14 = (idb->file).regions.count - 1;
        if (uVar8 < uVar14) {
          uVar8 = uVar8 * 3 >> 1;
          line = uVar14;
          if (uVar14 <= uVar8) {
            line = uVar8;
          }
          pcVar9 = __2_YAPAXI_Z(line << 4);
          if (pcVar9 != (c1_idb_region *)0x0) {
            if (-1 < (int)(line - 1)) {
              pcVar10 = &pcVar9->start_line;
              uVar8 = line;
              do {
                ((c1_idb_region *)(pcVar10 + -4))->signature = 0;
                *(int *)(pcVar10 + -2) = -1;
                *pcVar10 = 0;
                pcVar10[1] = 0;
                *(c1_u8 *)(pcVar10 + 2) = '\x18';
                pcVar10 = pcVar10 + 8;
                uVar8 = uVar8 - 1;
              } while (uVar8 != 0);
            }
            if ((idb->file).regions.data != (c1_idb_region *)0x0) {
              uVar8 = 0;
              if ((idb->file).regions.count != 0) {
                iVar12 = 0;
                do {
                  entry_2 = (uint *)(((idb->file).regions.data)->pad0d + iVar12 + -0xd);
                  dst_2 = (uint *)(pcVar9->pad0d + iVar12 + -0xd);
                  uVar8 = uVar8 + 1;
                  iVar12 = iVar12 + 0x10;
                  *dst_2 = *entry_2;
                  dst_2[1] = entry_2[1];
                  dst_2[2] = entry_2[2];
                  dst_2[3] = entry_2[3];
                } while (uVar8 < (idb->file).regions.count);
              }
              __3_YAXPAX_Z((idb->file).regions.data);
            }
            (idb->file).regions.data = pcVar9;
            (idb->file).regions.capacity = line;
            goto LAB_10490293;
          }
        }
        else {
LAB_10490293:
          (idb->file).regions.count = uVar14;
        }
        uStack_14 = uVar13;
      } while ((idb->file).cursor < (idb->file).regions.count);
    }
  }
  return uStack_2c;
}

