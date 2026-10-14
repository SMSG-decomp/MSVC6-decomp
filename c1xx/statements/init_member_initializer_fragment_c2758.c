int __cdecl
init_member_initializer_fragment_c2758
          (c1_symbol *member,uint member_flag,int *member_link,c1_symbol *sym,
          c1_node *mem_initializers)

{
  c1_u32 *sym_00;
  c1_class_record *pcVar1;
  fe_name *pfVar2;
  c1_symbol *cls;
  byte bVar3;
  c1_node *pcVar4;
  c1_type *pcVar5;
  int iVar6;
  c1_symbol *elem_class;
  c1_node *pcVar7;
  c1_sym_link *pcVar8;
  char emit;
  short sVar9;
  uint dtor_kind;
  char register_dtor;
  
  cls = sym;
code_r0x1046f7d3:
  sVar9 = 0x2f6;
LAB_1046f796:
  diag_error(sVar9,member);
LAB_1041aa6d:
  do {
    if ((member_link == (int *)0x0) ||
       (member_link = (int *)member_link[1], member_link == (int *)0x0)) {
      eh_leave_try();
      pcVar7 = mem_initializers;
      if (mem_initializers != (c1_node *)0x0) goto LAB_1046f819;
      goto LAB_1041a825;
    }
    member = (c1_symbol *)(member_link + -2);
  } while ((((((*(byte *)(member_link + -2) & 0x1f) == 0x11) ||
             ((*(byte *)(member_link + -2) & 0x1f) == 8)) ||
            ((*(byte *)((int)member_link + 0x1b) & 0x80) != 0)) ||
           (((void *)*member_link == g_name_alignment_member ||
            (iVar6 = sym_is_static_data_member(member), iVar6 != 0)))) ||
          (((*(byte *)((int)member_link + -6) & 0x10) != 0 ||
           ((bVar3 = member->kind & 0x1f, bVar3 == 5 || (bVar3 == 0x1a))))));
  if (bVar3 == 0xf) {
    if ((*(byte *)((int)member_link + 0x12) & 1) != 0) goto LAB_1041aa6d;
    iVar6 = member_link[3];
    member_flag = member_flag & 0xffffff00;
    elem_class = g_scope_vector->entries[(short)member_link[4]];
  }
  else {
    elem_class = sym_class_type_of(member);
    if (elem_class == (c1_symbol *)0x0) {
      iVar6 = member_link[7];
      elem_class = (c1_symbol *)0x0;
    }
    else {
      iVar6 = member_link[7];
      member_flag = CONCAT31(member_flag._1_3_,1);
    }
  }
  pcVar7 = init_take_base_initializer((int *)&mem_initializers,(byte *)member);
  if (pcVar7 == (c1_node *)0x0) {
    if (elem_class == (c1_symbol *)0x0) {
      if ((*(byte *)((int)member_link + -6) & 0x80) != 0) {
        pcVar5 = (c1_type *)member_link[3];
        if ((pcVar5->code & 0x8f) == 0x83) {
          pcVar5 = type_skip_arrays(pcVar5->base);
        }
        if (((byte)pcVar5->flags >> 5 & 1) != 0) {
          iVar6 = init_member_initializer_fragment_c2439
                            (member,member_flag,member_link,sym,mem_initializers);
          return iVar6;
        }
      }
      pcVar5 = (c1_type *)member_link[3];
      bVar3 = (byte)pcVar5->code;
      if (((char)bVar3 < '\0') && ((bVar3 & 0x8f) == 0x80)) {
        iVar6 = init_member_initializer_fragment_c2758
                          (member,member_flag,member_link,sym,mem_initializers);
        return iVar6;
      }
      if ((pcVar5->code & 0x8f) == 0x83) {
        pcVar5 = type_skip_arrays(pcVar5->base);
      }
      if (((byte)pcVar5->flags >> 5 & 1) != 0) goto code_r0x1046f7d3;
      goto LAB_1041aa6d;
    }
    if ((elem_class->flags2 & 4) == 0) {
      tmpl_instantiate_if_needed(elem_class);
    }
    if (((((elem_class->detail).cls)->implicit_state41 & 2) == 0) &&
       ((((elem_class->detail).cls)->implicit_state43 & 2) == 0)) goto LAB_1046f7af;
    if ((*(byte *)((int)member_link + -6) & 0x80) != 0) {
      init_member_array_elements(member,elem_class,(c1_node *)0x0,iVar6,'\0');
      goto LAB_1041aa6d;
    }
    if ((char)member_flag == '\0') {
      access_set_special_member_context('\x01');
    }
    pcVar4 = expr_this_plus_offset((int)elem_class,0,iVar6);
    pcVar7 = expr_build_call_of((c1_symbol *)0x0,elem_class,pcVar4,(c1_node *)0x0,'\0',member_flag,
                                '\x01');
    pcVar7 = expr_full_expression_guarded(pcVar7,0);
    if ((pcVar7 != (c1_node *)0x0) && ((pcVar7->op != '=' || (pcVar7->left != pcVar4)))) {
LAB_1041a9f6:
      stmt_emit_expression(pcVar7);
    }
  }
  else {
    if ((((member->kind & 0x1f) == 3) && ((*(byte *)member_link[3] & 0x8f) == 0x83)) &&
       ((elem_class == (c1_symbol *)0x0 || ((elem_class->flags1 & 0x10) == 0x10)))) {
      if (((*(byte *)((int)&g_current_function->tail + 8) & 0x20) == 0) ||
         ((g_current_function->flags3 & 1) == 0)) {
        diag_error(0x218,sym,member);
      }
      else if ((elem_class == (c1_symbol *)0x0) || ((*(byte *)((int)member_link + -6) & 0x80) == 0))
      {
        init_member_memcpy_string((c1_type *)member,iVar6,pcVar7);
      }
      else {
        init_member_array_elements(member,elem_class,pcVar7,iVar6,'\x01');
      }
      goto LAB_1041aa6d;
    }
    if (elem_class == (c1_symbol *)0x0) {
      if (pcVar7->op == '`') {
        pcVar7 = pcVar7->left;
      }
      pcVar7 = expr_full_expression_guarded(pcVar7,1);
      init_set_target_symbol(member);
      g_init_member_store_active = 1;
      iVar6 = init_member_initializer_store(iVar6,(ushort *)member_link[3],pcVar7,(byte *)member);
      if (iVar6 == 0) {
        diag_error(0x1b7,member);
      }
      g_init_member_store_active = 0;
      PTR_104d2c58 = (c1_symbol *)0x0;
      g_init_target_is_reference = '\0';
      goto LAB_1041aa6d;
    }
    if ((elem_class->flags1 & 0x10) != 0x10) {
      sVar9 = 0x21e;
      goto LAB_1046f796;
    }
    if ((char)member_flag == '\0') {
      access_set_special_member_context('\x01');
    }
    register_dtor = '\x01';
    emit = '\0';
    dtor_kind = member_flag;
    pcVar4 = expr_this_plus_offset((int)elem_class,0,iVar6);
    pcVar7 = expr_build_call_of((c1_symbol *)0x0,elem_class,pcVar4,pcVar7,emit,dtor_kind,
                                register_dtor);
    pcVar7 = expr_full_expression_guarded(pcVar7,0);
    if (pcVar7 != (c1_node *)0x0) goto LAB_1041a9f6;
  }
  access_set_special_member_context('\0');
  goto LAB_1041aa6d;
LAB_1046f819:
  pfVar2 = *(fe_name **)(*(int *)(*(int *)((int)pcVar7->left + 0x10) + 0x10) + 8);
  if ((sym->x28).members == (c1_sym_list *)0x0) {
    pcVar8 = (c1_sym_link *)0x0;
  }
  else {
    pcVar8 = ((sym->x28).members)->head;
  }
  if (pcVar8 != (c1_sym_link *)0x0) {
    while (sym_00 = &pcVar8[-1].position, pcVar8->name != pfVar2) {
      if ((pcVar8 == (c1_sym_link *)0x0) || (pcVar8 = pcVar8->next, pcVar8 == (c1_sym_link *)0x0))
      goto LAB_1046f847;
    }
    bVar3 = (byte)*sym_00 & 0x1f;
    if ((bVar3 == 0x11) || ((bVar3 == 8 || (bVar3 == 4)))) {
      sVar9 = 0x1b4;
    }
    else {
      iVar6 = sym_is_static_data_member((c1_symbol *)sym_00);
      if (iVar6 == 0) {
        sVar9 = 0x1b5;
      }
      else {
        sVar9 = 0x1b6;
      }
    }
    diag_error(sVar9,pfVar2);
    if (sym_00 != (c1_u32 *)0x0) goto LAB_1046f80e;
  }
LAB_1046f847:
  diag_error(0x266,sym,pfVar2);
LAB_1046f80e:
  pcVar7 = pcVar7->right;
  if (pcVar7 == (c1_node *)0x0) {
LAB_1041a825:
    pcVar1 = (sym->detail).cls;
    if ((pcVar1->layout_flags3c & 0x80) == 0) {
      bVar3 = *(byte *)((int)&g_current_function->tail + 8);
      if ((((bVar3 & 0x20) == 0) || ((pcVar1->implicit_state42 & 4) == 0)) &&
         (((bVar3 & 0x10) == 0 || ((pcVar1->implicit_state42 & 2) == 0)))) {
        sym = (c1_symbol *)CONCAT31(sym._1_3_,1);
      }
      else {
        sym = (c1_symbol *)((uint)sym._1_3_ << 8);
      }
      class_mark_used_and_count_vbases(cls,sym);
    }
    return 1;
  }
  goto LAB_1046f819;
LAB_1046f7af:
  sVar9 = 0x200;
  member = elem_class;
  goto LAB_1046f796;
}

