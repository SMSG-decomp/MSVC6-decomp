void __cdecl class_shift_member_offsets(c1_symbol *cls,int delta,c1_u32 from_offset)

{
  int iVar1;
  byte bVar2;
  c1_sym_link *first;
  char local_18 [4];
  int local_14;
  int local_c;
  
  if ((cls->x28).members == (c1_sym_list *)0x0) {
    first = (c1_sym_link *)0x0;
  }
  else {
    first = ((cls->x28).members)->head;
  }
  list_cursor_init(local_18,first);
  local_c = 0;
  if (local_18[0] != '\0') {
    local_c = local_14;
  }
LAB_1043baea:
  while( true ) {
    iVar1 = local_c;
    if (local_c == 0) {
      g_class_def_stack[g_class_depth].offset = g_class_def_stack[g_class_depth].offset + delta;
      return;
    }
    if ((local_14 == 0) || (local_14 = *(int *)(local_14 + 4), local_c = local_14, local_14 == 0)) {
      local_c = 0;
    }
    bVar2 = *(byte *)(iVar1 + -8) & 0x1f;
    if (bVar2 == 3) goto LAB_1043bb1d;
    if (bVar2 == 2) break;
    if (((bVar2 == 0xf) && ((*(byte *)(iVar1 + 0x12) & 1) == 0)) &&
       (from_offset <= *(uint *)(iVar1 + 0xc))) {
      *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) + delta;
    }
  }
  goto LAB_1043bb22;
LAB_1043bb1d:
  if ((*(byte *)(iVar1 + -4) & 0x40) == 0) {
LAB_1043bb22:
    if (from_offset <= *(uint *)(iVar1 + 0x1c)) {
      *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) + delta;
    }
  }
  goto LAB_1043baea;
}

