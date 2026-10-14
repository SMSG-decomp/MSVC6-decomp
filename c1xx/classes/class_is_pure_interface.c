char __cdecl class_is_pure_interface(c1_symbol *cls)

{
  fe_name **cls_entry;
  void *pvVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  c1_symbol *pcVar5;
  c1_member_iter local_58;
  c1_member_iter local_40;
  c1_member_iter local_28;
  c1xx_ovl_set_iter local_10;
  
  cls_entry = &cls->name;
  list_cursor_init_from_head(&local_58.cursor,(cls->x28).members);
  local_58.next = (void *)0x0;
  local_58.filter = 1;
  local_58.cls = cls_entry;
  if (local_58.cursor.valid != '\0') {
    local_58.next = local_58.cursor.current;
  }
  do {
    local_58.current = local_58.next;
    if (local_58.next == (void *)0x0) {
      class_member_iter_init(&local_28,cls_entry,2);
      ovl_set_iter_init(&local_10,(void *)0x0);
      do {
        while (cVar2 = sym_overload_iter_next(&local_10), cVar2 == '\0') {
          cVar2 = class_member_iter_next(&local_28);
          pvVar1 = local_28.current;
          if (cVar2 == '\0') {
            class_member_iter_init(&local_40,cls_entry,4);
            do {
              do {
                while( true ) {
                  if (local_40.next == (int *)0x0) {
                    return '\x01';
                  }
                  local_40.current = local_40.next;
                  iVar4 = class_member_iter_step(&local_40.cursor);
                  local_40.next =
                       (void *)(-(uint)((char)iVar4 != '\0') & (uint)local_40.cursor.current);
                  if ((*(byte *)((int)local_40.current + -8) & 0x1f) != 3) break;
                  if ((*(void **)local_40.current != g_name_vbptr) &&
                     (*(void **)local_40.current != g_name_vfptr)) {
                    return '\x01';
                  }
                }
              } while ((((g_compile_flags_cc & 0x100000) != 0) &&
                       ((*(byte *)((int)local_40.current + -8) & 0x1f) == 0xf)) &&
                      ((*(byte *)((int)local_40.current + 0x12) & 2) != 0));
              if ((*(byte *)((int)local_40.current + -8) & 0x1f) != 0xf) {
                return '\x01';
              }
              pcVar5 = class_member_iter_base_class(&local_40);
              cVar2 = class_is_pure_interface(pcVar5);
            } while (cVar2 != '\0');
            return '\0';
          }
          local_10.current = (c1_sym_link *)0x0;
          local_10.start = local_28.current;
          iVar4 = sym_is_data_or_function_2
                            ((c1_symbol *)
                             &((c1_sym_link *)((int)local_28.current + -0x10))->position);
          if (((char)iVar4 == '\0') && ((local_10.start[-1].position & 0x1f) != 0x1a)) {
            local_10.next = *(c1_sym_link **)&(local_10.start)->type;
          }
          else {
            local_10.next = pvVar1;
          }
        }
        pcVar5 = (c1_symbol *)&local_10.current[-1].position;
        if ((local_10.current[-1].position & 0x1f) == 0x1a) {
          pcVar5 = (((local_10.current)->type).alias)->target;
        }
      } while ((((pcVar5->flags21 & 2) != 0) && ((*(byte *)((int)&pcVar5->tail + 8) & 4) != 0)) ||
              ((pcVar5->flags3 & 1) != 0));
      return '\0';
    }
    if ((local_58.cursor.current == (void *)0x0) ||
       (local_58.cursor.current = *(void **)((int)local_58.cursor.current + 4),
       local_58.next = local_58.cursor.current, local_58.cursor.current == (void *)0x0)) {
      local_58.next = (void *)0x0;
    }
    uVar3 = class_member_iter_matches(&local_58);
  } while ((char)uVar3 == '\0');
  return '\0';
}

