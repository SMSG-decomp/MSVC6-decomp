int __thiscall array12_set_size(fe_idb_browse_table *array,uint n)

{
  uint uVar1;
  fe_idb_browse_entry *pfVar2;
  int iVar3;
  uint *src_words;
  uint uVar4;
  uint *dst_words;
  
  if (array->capacity < n) {
    uVar1 = array->capacity * 3 >> 1;
    uVar4 = n;
    if (n <= uVar1) {
      uVar4 = uVar1;
    }
    pfVar2 = __2_YAPAXI_Z(uVar4 * 0xc);
    if (pfVar2 == (fe_idb_browse_entry *)0x0) {
      return 0;
    }
    if (array->data != (fe_idb_browse_entry *)0x0) {
      uVar1 = 0;
      if (array->count != 0) {
        iVar3 = 0;
        do {
          src_words = (uint *)((int)&array->data->old_first_line + iVar3);
          dst_words = (uint *)((int)&pfVar2->old_first_line + iVar3);
          uVar1 = uVar1 + 1;
          iVar3 = iVar3 + 0xc;
          *dst_words = *src_words;
          dst_words[1] = src_words[1];
          dst_words[2] = src_words[2];
        } while (uVar1 < array->count);
      }
      __3_YAXPAX_Z(array->data);
    }
    array->data = pfVar2;
    array->capacity = uVar4;
  }
  array->count = n;
  return 1;
}

