char __cdecl class_overrides_base_virtual(c1_sym_link *fn,c1_symbol *cls,char report)

{
  char cVar1;
  int iVar2;
  c1_vtable_slot *slot;
  c1_symbol *pcVar3;
  int *piVar4;
  int iVar5;
  char local_3d;
  c1_member_iter base_iter;
  c1_vtable_vector *local_20;
  short vftable_index;
  int local_18;
  c1_vbase_vector *local_14;
  short vbase_index;
  int local_c;
  int local_4;
  
  local_3d = '\0';
  if ((fn->name->flags & 0x100000) == 0) {
    return '\0';
  }
  list_cursor_init_from_head(&base_iter.cursor,(cls->x28).members);
  base_iter.filter = 4;
  base_iter.next = (int *)0x0;
  piVar4 = base_iter.cursor.current;
  base_iter.cls = &cls->name;
  if (base_iter.cursor.valid != '\0') {
    base_iter.next = base_iter.cursor.current;
  }
LAB_10436a20:
  do {
    while( true ) {
      base_iter.current = base_iter.next;
      if (base_iter.current == (int *)0x0) {
        return local_3d;
      }
      if ((piVar4 == (int *)0x0) ||
         (base_iter.next = (void *)piVar4[1], piVar4 = base_iter.next,
         base_iter.cursor.current = base_iter.next, base_iter.next == (int *)0x0)) {
        base_iter.next = (int *)0x0;
      }
      if ((*(byte *)((int)base_iter.current + -8) & 0x1f) != 3) break;
      if ((*(void **)base_iter.current != g_name_vbptr) &&
         (*(void **)base_iter.current != g_name_vfptr)) {
        return local_3d;
      }
    }
  } while ((((g_compile_flags_cc & 0x100000) != 0) &&
           ((*(byte *)((int)base_iter.current + -8) & 0x1f) == 0xf)) &&
          ((*(byte *)((int)base_iter.current + 0x12) & 2) != 0));
  if ((*(byte *)((int)base_iter.current + -8) & 0x1f) != 0xf) {
    return local_3d;
  }
  if ((*(byte *)((int)base_iter.current + 0x12) & 2) == 0) {
    pcVar3 = g_scope_vector->entries[(short)*(int *)((int)base_iter.current + 0x10)];
  }
  else {
    pcVar3 = (c1_symbol *)0x0;
  }
  local_4 = 0;
  local_20 = ((pcVar3->detail).cls)->vftables;
  vftable_index = 0;
  local_14 = ((pcVar3->detail).cls)->vbases;
  vbase_index = 0;
  do {
    iVar2 = vector_iterator_next((uint *)&local_20);
    cVar1 = (char)iVar2;
    iVar2 = local_18;
    while (local_18 = iVar2, cVar1 == '\0') {
      iVar2 = vector_iterator_next((uint *)&local_14);
      base_iter.next = base_iter.next;
      piVar4 = base_iter.cursor.current;
      if ((char)iVar2 == '\0') goto LAB_10436a20;
      local_4 = local_c;
      local_20 = *(c1_vtable_vector **)(local_c + 0x14);
      vftable_index = 0;
      iVar2 = vector_iterator_next((uint *)&local_20);
      cVar1 = (char)iVar2;
      iVar2 = local_18;
    }
    iVar5 = 0;
    while (iVar5 < *(int *)(iVar2 + 0x10)) {
      slot = (c1_vtable_slot *)(iVar5 * 0x10 + *(int *)(iVar2 + 0x18));
      iVar5 = iVar5 + 1;
      if (slot == (c1_vtable_slot *)0x0) break;
      if ((fn->name == ((c1_sym_link *)slot->member)->name) &&
         (cVar1 = class_check_override_return_type(fn,(c1_sym_link *)slot->member,cls,report),
         cVar1 != '\0')) {
        if (report == '\0') {
          return '\x01';
        }
        local_3d = '\x01';
      }
    }
  } while( true );
}

