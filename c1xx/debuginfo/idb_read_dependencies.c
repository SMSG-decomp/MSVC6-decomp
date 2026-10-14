int __thiscall idb_read_dependencies(c1xx_idb *idb,int *stream,int *complete_out)

{
  c1xx_pdb_array *array;
  c1xx_pdb_iset *array_00;
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  c1_byte_buffer contents;
  
  piVar1 = stream;
  *complete_out = 0;
  uVar2 = (**(code **)*stream)();
  if (uVar2 < 4) {
    return 0;
  }
  contents.start = (c1_u8 *)0x0;
  contents.cur = (c1_u8 *)0x0;
  contents.size = 0;
  contents.on_move = (c1_il_buffer_move_fn)0x0;
  contents.move_ctx = (void *)0x0;
  iVar3 = il_buffer_reserve(&contents,uVar2);
  if (iVar3 != 0) {
    if (&stack0x00000000 != (undefined1 *)0xfffffffc) {
      stream = (int *)contents.cur;
    }
    il_buffer_set_memory(&contents,contents.start,contents.cur + uVar2);
    iVar3 = (**(code **)(*piVar1 + 0x1c))(0,stream);
    if (iVar3 != 0) {
      if (*stream != 0x1306c77) {
        stream = stream + 1;
        _unlink(g_object_file_name);
        if (contents.start == (c1_u8 *)0x0) {
          return 1;
        }
        __3_YAXPAX_Z(contents.start);
LAB_1048db50:
        il_buffer_set_memory(&contents,(c1_u8 *)0x0,(c1_u8 *)0x0);
        return 1;
      }
      iVar3 = stream[1];
      idb->pch_generation_loaded = iVar3;
      idb->pch_generation = iVar3;
      idb->pdb_signature = stream[2];
      idb->pdb_age = stream[3];
      (idb->header_times).count = stream[4];
      uVar2 = stream[5];
      stream = stream + 6;
      iVar3 = array_set_size(&(idb->header_times).domain,uVar2);
      if (iVar3 != 0) {
        array = &(idb->header_times).range;
        iVar3 = array_set_size(array,uVar2);
        if (((iVar3 != 0) &&
            (iVar3 = array_reload(&(idb->header_times).present,(c1_u32 **)&stream), iVar3 != 0)) &&
           (iVar3 = array_reload(&(idb->header_times).deleted,(c1_u32 **)&stream), iVar3 != 0)) {
          uVar2 = 0;
          if ((idb->header_times).domain.count != 0) {
            do {
              iVar3 = iset_contains(&(idb->header_times).present,uVar2);
              if (iVar3 != 0) {
                (idb->header_times).domain.data[uVar2] = *stream;
                array->data[uVar2] = stream[1];
                stream = stream + 2;
              }
              uVar2 = uVar2 + 1;
            } while (uVar2 < (idb->header_times).domain.count);
          }
          puVar4 = (uint *)(stream + 1);
          (idb->header_signatures).count = *stream;
          stream = stream + 2;
          iVar3 = map_arrays_set_size(&idb->header_signatures,*puVar4);
          if (iVar3 != 0) {
            array_00 = &(idb->header_signatures).present;
            iVar3 = array_reload(array_00,(c1_u32 **)&stream);
            if ((iVar3 != 0) &&
               (iVar3 = array_reload(&(idb->header_signatures).deleted,(c1_u32 **)&stream),
               iVar3 != 0)) {
              uVar2 = 0;
              if ((idb->header_signatures).domain.count != 0) {
                do {
                  iVar3 = iset_contains(array_00,uVar2);
                  if (iVar3 != 0) {
                    (idb->header_signatures).domain.data[uVar2] = *stream;
                    (idb->header_signatures).range.data[uVar2] = stream[1];
                    stream = stream + 2;
                  }
                  uVar2 = uVar2 + 1;
                } while (uVar2 < (idb->header_signatures).domain.count);
              }
              if (stream == (int *)contents.cur) {
                *complete_out = 1;
                if (contents.start == (c1_u8 *)0x0) {
                  return 1;
                }
                __3_YAXPAX_Z(contents.start);
                goto LAB_1048db50;
              }
            }
          }
        }
      }
      if (contents.start == (c1_u8 *)0x0) {
        return 0;
      }
      il_buffer_free(&contents);
      return 0;
    }
  }
  if (contents.start != (c1_u8 *)0x0) {
    __3_YAXPAX_Z(contents.start);
    il_buffer_set_memory(&contents,(c1_u8 *)0x0,(c1_u8 *)0x0);
  }
  return 0;
}

