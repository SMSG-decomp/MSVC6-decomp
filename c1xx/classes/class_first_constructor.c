int __cdecl class_first_constructor(int cls)

{
  uint uVar1;
  void *pvVar2;
  c1_u8 local_18;
  void *local_14;
  void *local_10;
  void *local_c;
  void *local_8;
  int kind;
  
  if (*(int *)(cls + 0x28) == 0) {
    pvVar2 = (void *)0x0;
  }
  else {
    pvVar2 = *(void **)(*(int *)(cls + 0x28) + 4);
  }
  list_cursor_init(&stack0xffffffe8,pvVar2);
  kind = 2;
  pvVar2 = (void *)0x0;
  local_8 = (void *)(cls + 8);
  if (local_18 != '\0') {
    pvVar2 = local_14;
  }
  do {
    if (pvVar2 == (void *)0x0) {
      return 0;
    }
    if ((local_14 == (void *)0x0) ||
       (local_14 = *(void **)((int)local_14 + 4), local_c = local_14, local_14 == (void *)0x0)) {
      local_c = (void *)0x0;
    }
    local_10 = pvVar2;
    uVar1 = class_member_iter_matches((c1_member_iter *)&stack0xffffffe8);
    pvVar2 = local_c;
  } while (((char)uVar1 == '\0') || ((*(byte *)((int)local_10 + -7) & 0x10) != 0x10));
  return (int)local_10 + -8;
}

