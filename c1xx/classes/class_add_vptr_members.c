void __cdecl class_add_vptr_members(c1_symbol *cls)

{
  byte bVar1;
  char cVar2;
  c1_symbol *pcVar3;
  c1_symbol *pcVar4;
  c1_vtable_record *pcVar5;
  c1_sym_link *first;
  void *pvVar6;
  char cVar7;
  void *pvVar8;
  char local_42;
  char local_41;
  c1_member_iter base_iter;
  c1_member_iter local_28;
  c1xx_ovl_set_iter local_10;
  
  local_42 = '\0';
  local_41 = '\0';
  if ((cls->x28).members == (c1_sym_list *)0x0) {
    first = (c1_sym_link *)0x0;
  }
  else {
    first = ((cls->x28).members)->head;
  }
  list_cursor_init(&base_iter,first);
  base_iter.next = (void *)0x0;
  base_iter.filter = 4;
  pvVar8 = base_iter.cursor.current;
  pvVar6 = base_iter.next;
  base_iter.cls = &cls->name;
  if (base_iter.cursor.valid != '\0') {
    base_iter.next = base_iter.cursor.current;
    pvVar6 = base_iter.next;
  }
  do {
    while( true ) {
      base_iter.next = pvVar6;
      base_iter.current = base_iter.next;
      pvVar6 = base_iter.next;
      if (base_iter.next == (void *)0x0) goto LAB_10435ac4;
      if ((pvVar8 == (void *)0x0) ||
         (pvVar6 = *(void **)((int)pvVar8 + 4), pvVar8 = pvVar6, base_iter.cursor.current = pvVar6,
         pvVar6 == (void *)0x0)) {
        pvVar6 = (void *)0x0;
      }
      bVar1 = *(byte *)((int)base_iter.next + -8) & 0x1f;
      if (bVar1 == 3) break;
      if ((((g_compile_flags_cc & 0x100000) == 0) || (bVar1 != 0xf)) ||
         ((*(byte *)((int)base_iter.next + 0x12) & 2) == 0)) {
        pcVar3 = (c1_symbol *)((int)base_iter.next + -8);
        if ((*(byte *)((int)base_iter.next + -8) & 0x1f) != 0xf) goto LAB_10435ac4;
        base_iter.next = pvVar6;
        class_note_base_table_pointers(cls,pcVar3,&local_42);
        pvVar8 = base_iter.cursor.current;
        pvVar6 = base_iter.next;
      }
    }
  } while ((*(void **)base_iter.next == g_name_vbptr) || (*(void **)base_iter.next == g_name_vfptr))
  ;
LAB_10435ac4:
  base_iter.next = pvVar6;
  pcVar3 = cls;
  cVar7 = local_41;
  if (((((cls->detail).cls)->layout_flags3a & 0x80) == 0) && (local_42 != '\0')) {
    pcVar3 = class_declare_table_pointer_member(cls,1);
    cVar7 = '\x01';
  }
  if ((((cls->detail).cls)->layout_flags3a & 0x40) == 0) {
    class_member_iter_init(&local_28,&cls->name,2);
    ovl_set_iter_init(&local_10,(void *)0x0);
    do {
      while (cVar2 = sym_overload_iter_next(&local_10), cVar2 == '\0') {
        cVar2 = class_member_iter_next(&local_28);
        if (cVar2 == '\0') goto LAB_10435b26;
        sym_overload_iter_init(&local_10,local_28.current);
      }
      pcVar4 = (c1_symbol *)&local_10.current[-1].position;
      if ((local_10.current[-1].position & 0x1f) == 0x1a) {
        pcVar4 = (((local_10.current)->type).alias)->target;
      }
    } while (((pcVar4->flags21 & 2) == 0) ||
            (cVar2 = class_overrides_base_virtual(local_10.current,cls,'\0'), cVar2 != '\0'));
    pcVar4 = class_declare_table_pointer_member(cls,0);
    pcVar5 = class_vtable_record_new(0,cls,0,pcVar4);
    vector_push((c1_vector *)((cls->detail).cls)->vftables,pcVar5);
  }
LAB_10435b26:
  if (cVar7 != '\0') {
    pcVar5 = class_new_vbtable_record(cls,pcVar3);
    vector_push((c1_vector *)((cls->detail).cls)->vbtables,pcVar5);
  }
  class_end_member_layout(cls);
  return;
}

