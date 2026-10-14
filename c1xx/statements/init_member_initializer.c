int __cdecl init_member_initializer(c1_symbol *sym,c1_node *mem_initializers)

{
  c1_u32 *sym_00;
  c1_class_record *pcVar1;
  fe_name *pfVar2;
  c1_symbol *cls;
  char cVar3;
  byte bVar4;
  c1_node *pcVar5;
  c1_type *pcVar6;
  c1_symbol *elem_class;
  c1_node *pcVar7;
  c1_sym_link *pcVar8;
  int iVar9;
  c1_symbol_type_word offset;
  short sVar10;
  uint uVar11;
  char register_dtor;
  c1_symbol *sym_01;
  uint member_flag;
  c1_sym_link *member_link;
  
  cls = sym;
  eh_enter_try();
  class_note_vtable_built(sym);
  if ((((sym->detail).cls)->layout_flags3b & 0x10) != 0) {
    cVar3 = access_get_special_member_context();
    if (cVar3 == '\0') {
      access_set_special_member_context('\x01');
    }
    class_build_vbase_loop(sym,(int *)&mem_initializers);
    if (cVar3 == '\0') {
      access_set_special_member_context('\0');
    }
  }
  if ((sym->x28).members == (c1_sym_list *)0x0) {
    pcVar8 = (c1_sym_link *)0x0;
  }
  else {
    pcVar8 = ((sym->x28).members)->head;
  }
  while (pcVar8 != (c1_sym_link *)0x0) {
    sym_01 = (c1_symbol *)&pcVar8[-1].position;
    bVar4 = (byte)pcVar8[-1].position & 0x1f;
    member_link = pcVar8;
    if (((((bVar4 != 0x11) && (bVar4 != 8)) && ((pcVar8[1].position & 0x80000000) == 0)) &&
        ((pcVar8->name != g_name_alignment_member &&
         (iVar9 = sym_is_static_data_member(sym_01), iVar9 == 0)))) &&
       (((pcVar8[-1].position & 0x100000) == 0 &&
        ((bVar4 = (byte)*(c1_u32 *)sym_01 & 0x1f, bVar4 != 5 && (bVar4 != 0x1a)))))) {
      if (bVar4 == 0xf) {
        if (((uint)pcVar8[1].name & 0x10000) != 0) goto LAB_1041aa6d;
        offset = pcVar8->type;
        member_flag = member_flag & 0xffffff00;
        elem_class = g_scope_vector->entries[*(short *)&pcVar8[1].name];
      }
      else {
        elem_class = sym_class_type_of(sym_01);
        if (elem_class == (c1_symbol *)0x0) {
          offset = pcVar8[1].type;
          elem_class = (c1_symbol *)0x0;
        }
        else {
          offset = pcVar8[1].type;
          uVar11 = member_flag >> 8;
          member_flag = CONCAT31((int3)uVar11,1);
        }
      }
      pcVar7 = init_take_base_initializer((int *)&mem_initializers,(byte *)sym_01);
      if (pcVar7 == (c1_node *)0x0) {
        if (elem_class == (c1_symbol *)0x0) {
          if ((pcVar8[-1].position & 0x800000) != 0) {
            pcVar6 = (pcVar8->type).type;
            if ((pcVar6->code & 0x8f) == 0x83) {
              pcVar6 = type_skip_arrays(pcVar6->base);
            }
            if (((byte)pcVar6->flags >> 5 & 1) != 0) {
              iVar9 = init_member_initializer_fragment_c2439
                                (sym_01,member_flag,(int *)member_link,sym,mem_initializers);
              return iVar9;
            }
          }
          pcVar6 = (pcVar8->type).type;
          bVar4 = (byte)pcVar6->code;
          if (((char)bVar4 < '\0') && ((bVar4 & 0x8f) == 0x80)) {
            iVar9 = init_member_initializer_fragment_c2758
                              (sym_01,member_flag,(int *)member_link,sym,mem_initializers);
            return iVar9;
          }
          if ((pcVar6->code & 0x8f) == 0x83) {
            pcVar6 = type_skip_arrays(pcVar6->base);
          }
          if (((byte)pcVar6->flags >> 5 & 1) != 0) {
            sVar10 = 0x2f6;
LAB_1046f796:
            diag_error(sVar10,sym_01);
          }
        }
        else {
          if ((elem_class->flags2 & 4) == 0) {
            tmpl_instantiate_if_needed(elem_class);
          }
          if (((((elem_class->detail).cls)->implicit_state41 & 2) == 0) &&
             ((((elem_class->detail).cls)->implicit_state43 & 2) == 0)) {
            sVar10 = 0x200;
            sym_01 = elem_class;
            goto LAB_1046f796;
          }
          if ((pcVar8[-1].position & 0x800000) == 0) {
            if ((char)member_flag == '\0') {
              access_set_special_member_context('\x01');
            }
            pcVar5 = expr_this_plus_offset((int)elem_class,0,(int)offset);
            pcVar7 = expr_build_call_of((c1_symbol *)0x0,elem_class,pcVar5,(c1_node *)0x0,'\0',
                                        member_flag,'\x01');
            pcVar7 = expr_full_expression_guarded(pcVar7,0);
            if ((pcVar7 != (c1_node *)0x0) && ((pcVar7->op != '=' || (pcVar7->left != pcVar5)))) {
LAB_1041a9f6:
              stmt_emit_expression(pcVar7);
            }
LAB_1041a9ff:
            access_set_special_member_context('\0');
          }
          else {
            init_member_array_elements(sym_01,elem_class,(c1_node *)0x0,(int)offset,'\0');
          }
        }
      }
      else if ((((*(c1_u32 *)sym_01 & 0x1f) == 3) && ((((pcVar8->type).type)->code & 0x8f) == 0x83))
              && ((elem_class == (c1_symbol *)0x0 || ((elem_class->flags1 & 0x10) == 0x10)))) {
        if (((*(byte *)((int)&g_current_function->tail + 8) & 0x20) == 0) ||
           ((g_current_function->flags3 & 1) == 0)) {
          diag_error(0x218,sym,sym_01);
        }
        else if ((elem_class == (c1_symbol *)0x0) || ((pcVar8[-1].position & 0x800000) == 0)) {
          init_member_memcpy_string((c1_type *)sym_01,(int)offset,pcVar7);
        }
        else {
          init_member_array_elements(sym_01,elem_class,pcVar7,(int)offset,'\x01');
        }
      }
      else {
        if (elem_class != (c1_symbol *)0x0) {
          if ((elem_class->flags1 & 0x10) == 0x10) {
            if ((char)member_flag == '\0') {
              access_set_special_member_context('\x01');
            }
            register_dtor = '\x01';
            cVar3 = '\0';
            uVar11 = member_flag;
            pcVar5 = expr_this_plus_offset((int)elem_class,0,(int)offset);
            pcVar7 = expr_build_call_of((c1_symbol *)0x0,elem_class,pcVar5,pcVar7,cVar3,uVar11,
                                        register_dtor);
            pcVar7 = expr_full_expression_guarded(pcVar7,0);
            if (pcVar7 != (c1_node *)0x0) goto LAB_1041a9f6;
            goto LAB_1041a9ff;
          }
          sVar10 = 0x21e;
          goto LAB_1046f796;
        }
        if (pcVar7->op == '`') {
          pcVar7 = pcVar7->left;
        }
        pcVar7 = expr_full_expression_guarded(pcVar7,1);
        init_set_target_symbol(sym_01);
        g_init_member_store_active = 1;
        iVar9 = init_member_initializer_store
                          ((int)offset,&((pcVar8->type).type)->code,pcVar7,(byte *)sym_01);
        if (iVar9 == 0) {
          diag_error(0x1b7,sym_01);
        }
        g_init_member_store_active = 0;
        PTR_104d2c58 = (c1_symbol *)0x0;
        g_init_target_is_reference = '\0';
      }
    }
LAB_1041aa6d:
    if (member_link == (c1_sym_link *)0x0) break;
    pcVar8 = member_link->next;
  }
  eh_leave_try();
  pcVar7 = mem_initializers;
  do {
    if (pcVar7 == (c1_node *)0x0) {
      pcVar1 = (sym->detail).cls;
      if ((pcVar1->layout_flags3c & 0x80) == 0) {
        bVar4 = *(byte *)((int)&g_current_function->tail + 8);
        if ((((bVar4 & 0x20) == 0) || ((pcVar1->implicit_state42 & 4) == 0)) &&
           (((bVar4 & 0x10) == 0 || ((pcVar1->implicit_state42 & 2) == 0)))) {
          sym = (c1_symbol *)CONCAT31(sym._1_3_,1);
        }
        else {
          sym = (c1_symbol *)((uint)sym._1_3_ << 8);
        }
        class_mark_used_and_count_vbases(cls,sym);
      }
      return 1;
    }
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
      bVar4 = (byte)*sym_00 & 0x1f;
      if ((bVar4 == 0x11) || ((bVar4 == 8 || (bVar4 == 4)))) {
        sVar10 = 0x1b4;
      }
      else {
        iVar9 = sym_is_static_data_member((c1_symbol *)sym_00);
        if (iVar9 == 0) {
          sVar10 = 0x1b5;
        }
        else {
          sVar10 = 0x1b6;
        }
      }
      diag_error(sVar10,pfVar2);
      if (sym_00 != (c1_u32 *)0x0) goto LAB_1046f80e;
    }
LAB_1046f847:
    diag_error(0x266,sym,pfVar2);
LAB_1046f80e:
    pcVar7 = pcVar7->right;
  } while( true );
}

