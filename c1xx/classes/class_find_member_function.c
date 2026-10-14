c1_symbol * __thiscall class_find_member_function(c1_symbol *cls,void *name)

{
  int iVar1;
  uint uVar2;
  c1_u8 local_1c;
  int *local_18;
  int *local_14;
  int *local_10;
  fe_name **local_c;
  int result;
  void *local_4;
  
  if (((cls->detail).cls)->sorted_members == (void **)0x0) {
    list_cursor_init_from_head((c1_list_cursor *)&stack0xffffffe4,(cls->x28).members);
    local_10 = (int *)0x0;
    result = 0;
    if (local_1c != '\0') {
      local_10 = local_18;
    }
    local_4 = name;
    local_c = &cls->name;
    do {
      if (local_10 == (int *)0x0) {
        return (c1_symbol *)0x0;
      }
      local_14 = local_10;
      iVar1 = class_member_iter_step((c1_list_cursor *)&stack0xffffffe4);
      local_10 = (int *)(-(uint)((char)iVar1 != '\0') & (uint)local_18);
      uVar2 = class_member_iter_matches((c1_member_iter *)&stack0xffffffe4);
    } while (((char)uVar2 == '\0') || ((void *)*local_14 != local_4));
  }
  else {
    local_14 = (int *)class_member_table_find(&((cls->detail).cls)->member_count,(uint)name);
  }
  if (local_14 != (int *)0x0) {
    if ((*(byte *)(local_14 + -2) & 0x1f) == 0x11) {
      return (c1_symbol *)(local_14 + -2);
    }
    if ((*(byte *)(local_14 + -2) & 0x1f) == 8) {
      return (c1_symbol *)(local_14 + -2);
    }
  }
  return (c1_symbol *)0x0;
}

