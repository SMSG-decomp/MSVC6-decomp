int __thiscall idb_read_regions(c1xx_idb *idb,int *stream)

{
  c1xx_pdb_array *array;
  c1xx_pdb_iset *array_00;
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  c1_u32 *pcVar6;
  c1_idb_browse_entry *pcVar7;
  c1_u32 *pcVar8;
  c1_byte_buffer contents;
  
  piVar5 = stream;
  iVar2 = (**(code **)*stream)();
  contents.start = (c1_u8 *)0x0;
  contents.cur = (c1_u8 *)0x0;
  contents.size = 0;
  contents.on_move = (c1_il_buffer_move_fn)0x0;
  contents.move_ctx = (void *)0x0;
  iVar3 = il_buffer_reserve(&contents,iVar2);
  if (iVar3 != 0) {
    if (&stack0x00000000 != (undefined1 *)0xfffffffc) {
      stream = (int *)contents.cur;
    }
    il_buffer_set_memory(&contents,contents.start,contents.cur + iVar2);
    iVar2 = (**(code **)(*piVar5 + 0x1c))(0,stream);
    if (iVar2 != 0) {
      if (*stream != 0x1306c77) {
        if (contents.start == (c1_u8 *)0x0) {
          return 1;
        }
        stream = stream + 1;
        __3_YAXPAX_Z(contents.start);
LAB_1048ddf4:
        il_buffer_set_memory(&contents,(c1_u8 *)0x0,(c1_u8 *)0x0);
        return 1;
      }
      idb->regions_pch_generation = stream[1];
      idb->options_signature = stream[2];
      idb->unk130 = stream[3];
      idb->browse_size = stream[4];
      stream = stream + 5;
      iVar2 = idb_region_array_reload(&(idb->file).regions,(c1_u32 **)&stream);
      if (iVar2 != 0) {
        uVar4 = *stream;
        stream = stream + 1;
        iVar2 = array12_set_size((c1xx_pdb_array *)&idb->browse_lines,uVar4);
        if (iVar2 != 0) {
          piVar5 = stream;
          pcVar7 = (idb->browse_lines).data;
          for (uVar4 = (idb->browse_lines).count * 3 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
            iVar2 = *piVar5;
            pcVar7->old_first_line = (short)iVar2;
            pcVar7->old_last_line = (short)((uint)iVar2 >> 0x10);
            piVar5 = piVar5 + 1;
            pcVar7 = (c1_idb_browse_entry *)&pcVar7->first_line;
          }
          for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
            *(char *)&pcVar7->old_first_line = (char)*piVar5;
            piVar5 = (int *)((int)piVar5 + 1);
            pcVar7 = (c1_idb_browse_entry *)((int)&pcVar7->old_first_line + 1);
          }
          puVar1 = (uint *)(stream + (idb->browse_lines).count * 3);
          stream = (int *)(puVar1 + 1);
          iVar2 = array_set_size(&idb->name_hash_bits,*puVar1);
          if (iVar2 != 0) {
            pcVar6 = (c1_u32 *)stream;
            pcVar8 = (idb->name_hash_bits).data;
            for (uVar4 = (idb->name_hash_bits).count & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
              *pcVar8 = *pcVar6;
              pcVar6 = pcVar6 + 1;
              pcVar8 = pcVar8 + 1;
            }
            for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
              *(char *)pcVar8 = (char)*pcVar6;
              pcVar6 = (c1_u32 *)((int)pcVar6 + 1);
              pcVar8 = (c1_u32 *)((int)pcVar8 + 1);
            }
            pcVar6 = (c1_u32 *)(stream + (idb->name_hash_bits).count);
            (idb->old_file_times).count = *pcVar6;
            uVar4 = pcVar6[1];
            stream = (int *)(pcVar6 + 2);
            iVar2 = array_set_size(&(idb->old_file_times).domain,uVar4);
            if (iVar2 != 0) {
              array = &(idb->old_file_times).range;
              iVar2 = array_set_size(array,uVar4);
              if (iVar2 != 0) {
                array_00 = &(idb->old_file_times).present;
                iVar2 = array_reload(array_00,(c1_u32 **)&stream);
                if ((iVar2 != 0) &&
                   (iVar2 = array_reload(&(idb->old_file_times).deleted,(c1_u32 **)&stream),
                   iVar2 != 0)) {
                  uVar4 = 0;
                  if ((idb->old_file_times).domain.count != 0) {
                    do {
                      iVar2 = iset_contains(array_00,uVar4);
                      if (iVar2 != 0) {
                        (idb->old_file_times).domain.data[uVar4] = *stream;
                        array->data[uVar4] = stream[1];
                        stream = stream + 2;
                      }
                      uVar4 = uVar4 + 1;
                    } while (uVar4 < (idb->old_file_times).domain.count);
                  }
                  if (stream == (int *)contents.cur) {
                    if (contents.start == (c1_u8 *)0x0) {
                      return 1;
                    }
                    __3_YAXPAX_Z(contents.start);
                    goto LAB_1048ddf4;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if (contents.start != (c1_u8 *)0x0) {
    __3_YAXPAX_Z(contents.start);
    il_buffer_set_memory(&contents,(c1_u8 *)0x0,(c1_u8 *)0x0);
  }
  return 0;
}

