int __cdecl
rtti_collect_base_class_descriptors
          (int cls,c1_vector *v,uint *attributes,int parent,int *path_cursor)

{
  short sVar1;
  ushort *puVar2;
  void *pvVar3;
  c1_symbol *cls_00;
  int iVar4;
  int *piVar5;
  c1_u8 *local_24;
  int local_20;
  int local_1c;
  char local_18 [4];
  int *local_14;
  int *local_10;
  int *local_c;
  int local_8;
  uint step;
  
  puVar2 = (ushort *)*path_cursor;
  local_20 = 0;
  local_1c = 0;
  local_24 = (c1_u8 *)0x0;
  if (puVar2 != (ushort *)0x0) {
    sVar1 = (short)path_cursor[1];
    if ((int)sVar1 < (int)(uint)*puVar2) {
      iVar4 = *(int *)(*(int *)(puVar2 + 4) + sVar1 * 4);
      *(short *)(path_cursor + 1) = sVar1 + 1;
      path_cursor[2] = iVar4;
    }
  }
  pvVar3 = (void *)rtti_base_class_descriptor_symbol
                             ((c1_symbol *)cls,&local_24,(int *)path_cursor[2]);
  vector_push(v,pvVar3);
  local_8 = cls + 8;
  if (*(int *)(cls + 0x28) == 0) {
    pvVar3 = (void *)0x0;
  }
  else {
    pvVar3 = *(void **)(*(int *)(cls + 0x28) + 4);
  }
  list_cursor_init(local_18,pvVar3);
  step = 4;
  local_c = (int *)0x0;
  piVar5 = local_14;
  if (local_18[0] != '\0') {
    local_c = local_14;
  }
  do {
    while( true ) {
      local_10 = local_c;
      if (local_10 == (int *)0x0) goto LAB_104b4866;
      if ((piVar5 == (int *)0x0) ||
         (local_c = (int *)piVar5[1], piVar5 = local_c, local_14 = local_c, local_c == (int *)0x0))
      {
        local_c = (int *)0x0;
      }
      if ((*(byte *)(local_10 + -2) & 0x1f) == 3) break;
      if (((g_compile_flags_cc._2_1_ & 0x10) == 0) ||
         (((*(byte *)(local_10 + -2) & 0x1f) != 0xf || ((*(byte *)((int)local_10 + 0x12) & 2) == 0))
         )) {
        if ((*(byte *)(local_10 + -2) & 0x1f) != 0xf) goto LAB_104b4866;
        local_1c = local_1c + 1;
        if ((*(byte *)((int)local_10 + 0x12) & 2) == 0) {
          cls_00 = g_scope_vector->entries[(short)local_10[4]];
        }
        else {
          cls_00 = (c1_symbol *)0x0;
        }
        iVar4 = rtti_collect_base_class_descriptors
                          ((int)cls_00,v,attributes,(int)local_24,path_cursor);
        local_20 = local_20 + iVar4;
        local_c = local_c;
        piVar5 = local_14;
      }
    }
  } while (((void *)*local_10 == g_name_vbptr) || ((void *)*local_10 == g_name_vfptr));
LAB_104b4866:
  if (1 < local_1c) {
    *attributes = *attributes | 1;
  }
  if ((local_24 != (c1_u8 *)0x0) &&
     (*(int *)(local_24 + 8) = local_20 + local_1c, (local_24[0x18] & 2) != 0)) {
    *attributes = *attributes | 4;
  }
  return local_20 + local_1c;
}

