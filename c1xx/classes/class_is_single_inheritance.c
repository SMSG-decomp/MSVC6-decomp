uint __cdecl class_is_single_inheritance(int cls)

{
  uint uVar1;
  void *first;
  c1_symbol *cls_00;
  int *piVar2;
  bool bVar3;
  char local_18 [4];
  int *local_14;
  int *local_10;
  int *local_c;
  int local_8;
  int kind;
  
  if (*(int *)(cls + 0x28) == 0) {
    first = (void *)0x0;
  }
  else {
    first = *(void **)(*(int *)(cls + 0x28) + 4);
  }
  list_cursor_init(local_18,first);
  kind = 4;
  local_c = (int *)0x0;
  if (local_18[0] != '\0') {
    local_c = local_14;
  }
  uVar1 = *(uint *)(cls + 0x24);
  piVar2 = local_14;
  local_8 = cls + 8;
  if ((*(byte *)(uVar1 + 0x3b) & 0x10) != 0) {
    return uVar1 & 0xffffff00;
  }
LAB_104201cd:
  do {
    local_10 = local_c;
    if (local_10 == (int *)0x0) {
LAB_10420219:
      return CONCAT31((int3)(uVar1 >> 8),1);
    }
    if ((piVar2 == (int *)0x0) ||
       (local_c = (int *)piVar2[1], piVar2 = local_c, local_14 = local_c, local_c == (int *)0x0)) {
      local_c = (int *)0x0;
    }
    uVar1 = CONCAT31((int3)(uVar1 >> 8),(char)local_10[-2]) & 0xffffff1f;
    if ((char)uVar1 == '\x03') {
      if (((void *)*local_10 != g_name_vbptr) && ((void *)*local_10 != g_name_vfptr))
      goto LAB_10420219;
      goto LAB_104201cd;
    }
    if ((((g_compile_flags_cc & 0x100000) == 0) || ((char)uVar1 != '\x0f')) ||
       ((*(byte *)((int)local_10 + 0x12) & 2) == 0)) {
      bVar3 = (*(byte *)(local_10 + -2) & 0x1f) == 0xf;
      uVar1 = CONCAT31((int3)(uVar1 >> 8),bVar3);
      if (!bVar3) goto LAB_10420219;
      uVar1 = local_10[3];
      if (uVar1 != 0) goto LAB_104b34fb;
      if ((*(byte *)((int)local_10 + 0x12) & 2) == 0) {
        cls_00 = g_scope_vector->entries[(short)local_10[4]];
      }
      else {
        cls_00 = (c1_symbol *)0x0;
      }
      uVar1 = class_is_single_inheritance((int)cls_00);
      piVar2 = local_14;
      if ((char)uVar1 == '\0') {
LAB_104b34fb:
        return uVar1 & 0xffffff00;
      }
    }
  } while( true );
}

