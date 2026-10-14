int __cdecl debug_type_record_class_fieldlist(int pass,c1_symbol *cls,int *count,ushort *property)

{
  c1_u32 *member;
  c1_u8 cVar1;
  fe_name *pfVar2;
  ushort *puVar3;
  byte bVar4;
  char cVar5;
  ushort uVar6;
  int iVar7;
  uint uVar8;
  c1_sym_link *pcVar9;
  c1_symbol *pcVar10;
  short sVar11;
  uint uVar12;
  c1_member_iter member_iter;
  c1_vbase_vector *local_18;
  short vec_pos;
  int *vec_item;
  c1_symbol *local_c;
  int item_second;
  char local_4;
  
  class_member_iter_init(&member_iter,&cls->name,4);
  puVar3 = g_cv_record_body;
  uVar12 = 0;
  local_4 = ((cls->detail).cls)->vbases != (c1_vbase_vector *)0x0;
  if ((bool)local_4) {
    local_18 = ((cls->detail).cls)->vbases;
    vec_pos = 0;
  }
  *count = 0;
  if (pass == 2) {
    *puVar3 = 0x1203;
  }
  do {
    while( true ) {
      if (member_iter.next == (void *)0x0) goto LAB_1043bfc5;
      member_iter.current = member_iter.next;
      iVar7 = class_member_iter_step(&member_iter.cursor);
      member_iter.next = (void *)(-(uint)((char)iVar7 != '\0') & (uint)member_iter.cursor.current);
      bVar4 = *(byte *)((int)member_iter.current + -8) & 0x1f;
      if (bVar4 == 3) break;
      if (((g_compile_flags_cc & 0x100000) == 0) ||
         ((bVar4 != 0xf || ((*(byte *)((int)member_iter.current + 0x12) & 2) == 0)))) {
        if ((*(byte *)((int)member_iter.current + -8) & 0x1f) != 0xf) goto LAB_1043bfc5;
        if ((*(byte *)((int)member_iter.current + 0x12) & 1) == 0) {
          if ((*(byte *)((int)member_iter.current + 0x12) & 2) == 0) {
            pcVar10 = g_scope_vector->entries[*(short *)((int)member_iter.current + 0x10)];
          }
          else {
            pcVar10 = (c1_symbol *)0x0;
          }
          uVar6 = debug_field_bclass(pass,(int)member_iter.current + -8,pcVar10,
                                     (ushort *)((uVar12 & 0xffff) + 2 + (int)g_cv_record_body));
          uVar12 = uVar12 + uVar6;
          if (pass == 2) {
            uVar8 = debug_type_pad_to_4((char *)((uVar12 & 0xffff) + 2 + (int)puVar3),(char)uVar12);
            uVar8 = uVar8 & 0xffff;
          }
          else {
            uVar8 = 0;
          }
          uVar12 = uVar12 + uVar8;
          *count = *count + 1;
          if (0xfafd < (uVar12 & 0xffff) + 2) {
            diag_fatal_simple(0x43);
          }
        }
      }
    }
  } while ((*(void **)member_iter.current == g_name_vbptr) ||
          (*(void **)member_iter.current == g_name_vfptr));
LAB_1043bfc5:
  if (*(int *)((int)member_iter.cls + 0x20) == 0) {
    member_iter.cursor.current = (void *)0x0;
  }
  else {
    member_iter.cursor.current = *(void **)(*(int *)((int)member_iter.cls + 0x20) + 4);
  }
  member_iter.cursor.valid = member_iter.cursor.current != (void *)0x0;
  if ((bool)member_iter.cursor.valid) {
    member_iter.next = member_iter.cursor.current;
  }
  do {
    while( true ) {
      member_iter.current = member_iter.next;
      if (member_iter.next == (void *)0x0) goto LAB_1043c04f;
      iVar7 = class_member_iter_step(&member_iter.cursor);
      member_iter.next = (void *)(-(uint)((char)iVar7 != '\0') & (uint)member_iter.cursor.current);
      bVar4 = *(byte *)((int)member_iter.current + -8) & 0x1f;
      if (bVar4 == 3) break;
      if (((g_compile_flags_cc & 0x100000) == 0) ||
         ((bVar4 != 0xf || ((*(byte *)((int)member_iter.current + 0x12) & 2) == 0)))) {
        if ((*(byte *)((int)member_iter.current + -8) & 0x1f) != 0xf) goto LAB_1043c04f;
        if ((*(byte *)((int)member_iter.current + 0x12) & 1) != 0) {
          if ((*(byte *)((int)member_iter.current + 0x12) & 2) == 0) {
            pcVar10 = g_scope_vector->entries[*(short *)((int)member_iter.current + 0x10)];
          }
          else {
            pcVar10 = (c1_symbol *)0x0;
          }
          uVar6 = debug_field_vbclass(pass,(int)member_iter.current + -8,(int)pcVar10,cls,
                                      (ushort *)((uVar12 & 0xffff) + 2 + (int)g_cv_record_body));
          uVar12 = uVar12 + uVar6;
          if (pass == 2) {
            uVar8 = debug_type_pad_to_4((char *)((uVar12 & 0xffff) + 2 + (int)puVar3),(char)uVar12);
            uVar8 = uVar8 & 0xffff;
          }
          else {
            uVar8 = 0;
          }
          uVar12 = uVar12 + uVar8;
          *count = *count + 1;
          if (0xfafd < (uVar12 & 0xffff) + 2) {
            diag_fatal_simple(0x43);
          }
        }
      }
    }
  } while ((*(void **)member_iter.current == g_name_vbptr) ||
          (*(void **)member_iter.current == g_name_vfptr));
LAB_1043c04f:
  while ((local_4 != '\0' && (iVar7 = vector_iterator_next((uint *)&local_18), (char)iVar7 != '\0'))
        ) {
    local_c = (c1_symbol *)*vec_item;
    item_second = vec_item[1];
    cVar5 = class_has_direct_base(cls,local_c);
    if (cVar5 == '\0') {
      uVar6 = debug_field_ivbclass
                        (pass,(int)local_c,cls,
                         (ushort *)((uVar12 & 0xffff) + 2 + (int)g_cv_record_body));
      uVar12 = uVar12 + uVar6;
      if (pass == 2) {
        uVar8 = debug_type_pad_to_4((char *)((uVar12 & 0xffff) + 2 + (int)puVar3),(char)uVar12);
        uVar8 = uVar8 & 0xffff;
      }
      else {
        uVar8 = 0;
      }
      uVar12 = uVar12 + uVar8;
      *count = *count + 1;
      if (0xfafd < (uVar12 & 0xffff) + 2) {
        debug_field_list_overflow_tail();
      }
    }
  }
  if ((cls->x28).members == (c1_sym_list *)0x0) {
    pcVar9 = (c1_sym_link *)0x0;
  }
  else {
    pcVar9 = ((cls->x28).members)->head;
  }
  for (; sVar11 = (short)uVar12, pcVar9 != (c1_sym_link *)0x0; pcVar9 = pcVar9->next) {
    member = &pcVar9[-1].position;
    bVar4 = (byte)pcVar9[-1].position & 0x1f;
    if (((((bVar4 != 0xf) && (bVar4 != 5)) && (bVar4 != 0x1a)) &&
        (pfVar2 = pcVar9->name, pfVar2 != g_name_vbptr)) &&
       ((bVar4 != 3 || ((pcVar9[1].position & 0x80000000) == 0)))) {
      if ((bVar4 == 4) && (pfVar2 == g_name_unnamed)) {
        pcVar10 = (c1_symbol *)(pcVar9->type).alias;
        cVar1 = pcVar10->kind;
        while ((char)cVar1 < '\0') {
          pcVar10 = *(c1_symbol **)&pcVar10->flags4;
          cVar1 = pcVar10->kind;
        }
        if ((pcVar10->flags1 & 1) == 0) goto LAB_1043c41e;
      }
      else {
LAB_1043c41e:
        if (((pfVar2 == (fe_name *)0x0) || (pfVar2 == g_name_unnamed)) ||
           ((pfVar2 == g_name_alignment_member ||
            (((bVar4 != 0 && (bVar4 < 0xf)) && ((pcVar9->type).type == (c1_type *)0x0))))))
        goto LAB_1043c3da;
      }
      if ((bVar4 == 0x11) || (bVar4 == 8)) {
        iVar7 = debug_is_vbase_or_scalar_deleting_dtor((c1_symbol *)member);
        if (((char)iVar7 != '\0') || (cls->name == g_name_unnamed)) goto LAB_1043c3da;
        uVar8 = debug_field_method(pass,(byte *)member,
                                   (ushort *)((uVar12 & 0xffff) + 2 + (int)g_cv_record_body),count,
                                   property);
        uVar12 = uVar12 + uVar8;
        *count = *count + -1;
      }
      else if ((bVar4 == 4) || (bVar4 = (byte)pcVar9[1].position & 7, bVar4 == 7)) {
        uVar8 = debug_field_nesttype
                          (pass,(c1_symbol *)member,
                           (ushort *)((uVar12 & 0xffff) + 2 + (int)g_cv_record_body));
        uVar12 = uVar12 + uVar8;
      }
      else if (pfVar2 == g_name_vfptr) {
        uVar8 = debug_field_vfunctab
                          (pass,(int)member,(int)cls,
                           (ushort *)((uVar12 & 0xffff) + 2 + (int)g_cv_record_body));
        uVar12 = uVar12 + uVar8;
      }
      else if (bVar4 == 3) {
        uVar8 = debug_field_stmember
                          (pass,(c1_symbol *)member,
                           (ushort *)((uVar12 & 0xffff) + 2 + (int)g_cv_record_body));
        uVar12 = uVar12 + uVar8;
      }
      else {
        uVar8 = debug_field_member(pass,(byte *)member,
                                   (ushort *)((uVar12 & 0xffff) + 2 + (int)g_cv_record_body));
        uVar12 = uVar12 + uVar8;
      }
      if (pass == 2) {
        uVar8 = debug_type_pad_to_4((char *)((uVar12 & 0xffff) + 2 + (int)puVar3),(char)uVar12);
        uVar8 = uVar8 & 0xffff;
      }
      else {
        uVar8 = 0;
      }
      uVar12 = uVar12 + uVar8;
      *count = *count + 1;
      if (0xfafd < (uVar12 & 0xffff) + 2) {
        diag_fatal_simple(0x43);
      }
    }
LAB_1043c3da:
    sVar11 = (short)uVar12;
    if (pcVar9 == (c1_sym_link *)0x0) break;
  }
  if (pass != 2) {
    return 0;
  }
  iVar7 = cvserver_emit_type(sVar11 + 2);
  return iVar7;
}

