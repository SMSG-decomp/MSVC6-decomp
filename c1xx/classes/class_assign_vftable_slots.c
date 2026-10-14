void __cdecl class_assign_vftable_slots(c1_symbol *cls)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  c1_member_iter local_28;
  c1xx_ovl_set_iter local_10;
  
  list_cursor_init_from_head(&local_28.cursor,(cls->x28).members);
  local_28.current = (c1_u8 *)0x0;
  local_28.next = (void *)0x0;
  local_28.filter = 2;
  if (local_28.cursor.valid != '\0') {
    local_28.next = local_28.cursor.current;
  }
  local_28.cls = &cls->name;
  ovl_set_iter_init(&local_10,(void *)0x0);
  do {
    while ((local_10.start == (c1_sym_link *)0x0 || (local_10.next == (c1_sym_link *)0x0))) {
LAB_10436da3:
      cVar2 = class_member_iter_next(&local_28);
      if (cVar2 == '\0') {
        return;
      }
      sym_overload_iter_init(&local_10,local_28.current);
    }
    bVar1 = (byte)local_10.next[-1].position;
    while ((bVar1 & 0x1f) == 0x1a) {
      local_10.next = (local_10.next)->next;
      if (local_10.next == (c1_sym_link *)0x0) goto LAB_10436da3;
      bVar1 = (byte)local_10.next[-1].position;
    }
    local_10.current = local_10.next;
    iVar3 = sym_is_data_or_function_2((c1_symbol *)&local_10.start[-1].position);
    if ((char)iVar3 == '\0') {
      local_10.next = (local_10.next)->next;
    }
    else {
      local_10.next = (c1_sym_link *)0x0;
    }
    if ((local_10.current)->name != g_name_ctor) {
      class_member_assign_vftable_slot(local_10.current,cls);
    }
  } while( true );
}

