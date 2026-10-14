c1_node * __cdecl
expr_build_new(char kind,int placement,c1_symbol *type_sym,int init,c1_node *args,int bound)

{
  c1_u8 cVar1;
  c1_class_record *pcVar2;
  uint uVar3;
  byte bVar4;
  c1_u16 cVar5;
  c1_type *type;
  c1_symbol *pcVar6;
  c1_node *pcVar7;
  void *pvVar8;
  c1_lookup_result *pcVar9;
  c1_lookup_entry *pcVar10;
  c1_node *left;
  c1_node *pcVar11;
  byte *pbVar12;
  c1_symbol *sym;
  c1_type *pcVar13;
  int iVar14;
  uint *call_info_zero_cursor_2;
  uint *call_info_zero_cursor;
  char has_placement;
  bool bVar15;
  char cVar16;
  byte class_41_bit1_clear;
  char cookie_needed;
  c1_node *pcVar17;
  byte local_a2;
  c1_node *assign;
  c1_symbol *pcVar18;
  c1_symbol *cls;
  c1_node *pcVar19;
  void *cell_2c;
  void *cell_30;
  void *cell_34;
  c1_type *ptr_type_cell;
  int iVar20;
  int local_7c;
  uint entity;
  c1_u16 local_74;
  ushort local_72;
  c1_u32 cell_54;
  c1_node *pcVar21;
  c1_type unflagged_type;
  c1_call_record call_info;
  c1_call_record delete_call;
  
  pcVar11 = assign;
  if (type_sym == (c1_symbol *)0x0) {
    return (c1_node *)0x0;
  }
  if ((placement != 0) && (*(int *)(placement + 0x10) == 0)) {
    return (c1_node *)0x0;
  }
  pcVar13 = type_sym->type;
  cVar5 = pcVar13->code;
  bVar4 = (byte)cVar5;
  if (((char)bVar4 < '\0') && ((bVar4 & 0x8f) == 0x80)) {
    diag_error(0x1d0,pcVar13);
    return (c1_node *)0x0;
  }
  bVar15 = false;
  pcVar18 = (c1_symbol *)0x0;
  has_placement = placement != 0;
  pcVar21 = (c1_node *)0x0;
  iVar20 = 0;
  pcVar19 = (c1_node *)0x0;
  entity = 0;
  pcVar17 = (c1_node *)0x0;
  iVar14 = 1;
  cVar16 = '\0';
  cookie_needed = '\0';
  assign = (c1_node *)((uint)assign & 0xffffff00);
  class_41_bit1_clear = 0;
  local_a2 = 0;
  local_7c = 1;
  if ((bVar4 & 0x8f) == 0x83) {
    cVar16 = '\x01';
    pcVar7 = pcVar17;
    do {
      pcVar17 = (c1_node *)bound;
      if (cVar5 != 0x4083) {
        iVar14 = iVar14 * (pcVar13->extra).count;
        pcVar17 = pcVar7;
      }
      pcVar13 = pcVar13->base;
      cVar5 = pcVar13->code;
      pcVar7 = pcVar17;
    } while (((byte)cVar5 & 0x8f) == 0x83);
    bVar15 = -1 < (char)(byte)cVar5;
    if (init != 0) {
      diag_error(0x21a);
      init = 0;
    }
    cell_54 = 0;
    pcVar13 = type_sym->type->base;
    local_74 = 0x82;
    local_72 = decl_apply_default_calling_convention(0x82,0);
    local_7c = iVar14;
  }
  else {
    local_72 = decl_apply_default_calling_convention(0x82,0);
    pcVar13 = type_sym->type;
    cell_54 = 0;
    local_74 = 0x82;
  }
  type = type_intern((c1_type *)&local_74);
  pcVar6 = sym_class_type_of(type_sym);
  cls = pcVar6;
  if (pcVar6 != (c1_symbol *)0x0) {
    if ((pcVar6->flags2 & 4) == 0) {
      tmpl_instantiate_if_needed(pcVar6);
    }
    if (args == (c1_node *)0x0) {
      if ((((pcVar6->detail).cls)->implicit_state41 & 0x10) == 0) {
        tmpl_instantiate_if_incomplete(pcVar6);
        if (((((pcVar6->detail).cls)->implicit_state41 & 0x10) != 0) ||
           ((((pcVar6->detail).cls)->implicit_state43 & 0x10) != 0)) {
          if (((pcVar6->flags22 & 8) != 0) &&
             (pbVar12 = class_find_member_function_walk_overloads(pcVar6,g_name_dtor,(void *)0x0),
             (pbVar12[0x21] & 2) != 0)) {
            assign = (c1_node *)CONCAT31(SUB43(pcVar11,1),1);
          }
          if (bVar15) {
            cookie_needed = '\x01';
          }
        }
      }
      if (kind != '\x02') {
        pvVar8 = g_name_array_new;
        if (cVar16 == '\0') {
          pvVar8 = g_name_new;
        }
        pcVar18 = class_lookup_member_set(g_current_scope,pcVar6,pvVar8,2,0x181);
      }
    }
    tmpl_instantiate_if_incomplete(pcVar6);
    pcVar2 = (pcVar6->detail).cls;
    bVar4 = pcVar2->implicit_state41;
    if (((bVar4 & 2) == 0) && ((pcVar2->implicit_state43 & 2) == 0)) {
      if (init == 0) {
        diag_error(0x200,pcVar6);
        return (c1_node *)0x0;
      }
      if ((pcVar6->flags1 & 0x10) != 0x10) {
        diag_error(0x202,cls);
        return (c1_node *)0x0;
      }
      pcVar6 = cls;
      if (((pcVar2->layout_flags3c & 1) == 0) && (bVar15)) {
        diag_error(0x21b,cls);
        return (c1_node *)0x0;
      }
    }
    else {
      class_41_bit1_clear = (byte)~bVar4 >> 1 & 1;
    }
    local_a2 = (byte)~bVar4 >> 4 & 1;
  }
  if ((args == (c1_node *)0x0) && (pcVar18 == (c1_symbol *)0x0)) {
    pvVar8 = g_name_array_new;
    if (cVar16 == '\0') {
      pvVar8 = g_name_new;
    }
    pcVar9 = (*g_current_scope->global_scope->vtbl->lookup)(g_current_scope->global_scope,pvVar8,1);
    if (pcVar9 == (c1_lookup_result *)0x0) {
      pcVar10 = (c1_lookup_entry *)0x0;
    }
    else {
      pcVar10 = lookup_check_ambiguous_symbol(pcVar9,'\x01');
    }
    if (cVar16 == '\0') {
LAB_1043d096:
      if (pcVar10 == (c1_lookup_entry *)0x0) {
LAB_10477baa:
        pcVar18 = (c1_symbol *)0x0;
        goto LAB_1043ce09;
      }
    }
    else if (pcVar10 == (c1_lookup_entry *)0x0) {
      pcVar9 = (*g_current_scope->global_scope->vtbl->lookup)
                         (g_current_scope->global_scope,g_name_new,1);
      if (pcVar9 != (c1_lookup_result *)0x0) {
        pcVar10 = lookup_check_ambiguous_symbol(pcVar9,'\x01');
        goto LAB_1043d096;
      }
      goto LAB_10477baa;
    }
    pcVar18 = pcVar10->sym;
  }
LAB_1043ce09:
  if ((cVar16 != '\0') || (args == (c1_node *)0x0)) {
    iVar20 = sym_element_size((int)type_sym);
  }
  pcVar11 = args;
  if (pcVar17 == (c1_node *)0x0) {
    pcVar7 = tree_new_unsigned_constant(local_7c);
    tree_new_unsigned_constant(iVar20);
  }
  else {
    if (class_41_bit1_clear == 0) {
      pcVar7 = tree_new_unsigned_constant(local_7c);
      pcVar7 = expr_build_builtin_binary('J',pcVar17,pcVar7);
    }
    else {
      iVar14 = 0;
      sym = decl_new_compiler_variable(4,g_type_unsigned_int);
      pcVar7 = expr_reference_named_entity(sym,iVar14);
      pcVar21 = tree_new_unsigned_constant(local_7c);
      pcVar17 = expr_build_builtin_binary('J',pcVar17,pcVar21);
      pcVar21 = expr_build_builtin_binary('4',pcVar7,pcVar17);
    }
    ptr_type_cell = type;
    if (pcVar18 == (c1_symbol *)0x0) goto LAB_1043ce5d;
    pcVar17 = tree_new_unsigned_constant(iVar20);
    expr_build_builtin_binary('J',pcVar7,pcVar17);
  }
  ptr_type_cell = type;
  if (pcVar18 != (c1_symbol *)0x0) {
    if (cookie_needed != '\0') {
      pcVar19 = (c1_node *)type_size(g_type_unsigned_int);
    }
    entity = sym_new_local_key();
    ptr_type_cell = type;
    pcVar11 = tree_new_leaf_9c(entity,type);
    pcVar11 = tree_new_rvalue(pcVar11);
  }
LAB_1043ce5d:
  pcVar11->type = type;
  if (pcVar6 == (c1_symbol *)0x0) {
    if (init != 0) {
      pcVar11 = decl_variable_initializer_fragment
                          (init,pcVar11,pcVar7,type,cVar16,class_41_bit1_clear,has_placement,pcVar18
                           ,cls,pcVar19,cell_2c,cell_30,cell_34,ptr_type_cell,iVar20,entity,
                           (int)pcVar13,cell_54,pcVar21,call_info.expr,call_info.call,
                           (int)call_info.function,call_info.args,call_info.flags,
                           (int)delete_call.expr,(int)delete_call.call,delete_call.function,
                           delete_call.args,kind,placement);
      return pcVar11;
    }
  }
  else {
    if ((class_41_bit1_clear == 0) && (local_a2 == 0)) {
      pcVar11 = expr_build_new_cold_blocks
                          (pcVar11,type,pcVar6,pcVar7,cVar16,'\0',cookie_needed,pcVar11,
                           has_placement,assign,pcVar18,cls,pcVar19,cell_2c,cell_30,cell_34,
                           ptr_type_cell,iVar20,entity,(int)pcVar13,cell_54,pcVar21,
                           unflagged_type.base,unflagged_type.extra.count,unflagged_type.debug_index
                           ,call_info.expr,call_info.call,(int)call_info.function,call_info.args,
                           call_info.flags,(int)delete_call.expr,(int)delete_call.call,
                           delete_call.function,delete_call.args,kind,placement,type_sym,init,args);
      return pcVar11;
    }
    pcVar17 = pcVar11;
    if (((((pcVar6->detail).cls)->layout_flags3b & 0x80) != 0) && ((pcVar6->flags3 & 4) == 0)) {
      class_check_abstract_instantiation(pcVar6);
      pcVar6->flags3 = pcVar6->flags3 | 4;
    }
    if (cVar16 == '\0') {
      pcVar17 = expr_build_new_initializer
                          (args == (c1_node *)0x0,(char)assign,pcVar6,pcVar11,(c1_node *)init,
                           type_sym);
    }
    else {
      if ((cookie_needed != '\0') &&
         (pcVar6 = (c1_symbol *)class_find_vector_deleting_dtor(type), pcVar6 != (c1_symbol *)0x0))
      {
        special_member_need_definition(pcVar6);
        pcVar6->flags21 = pcVar6->flags21 | 0x80;
      }
      pcVar17 = expr_build_array_new_construction
                          (pcVar17,args == (c1_node *)0x0,(int)assign,(int)pcVar19,pcVar7,iVar20);
    }
    if (pcVar17 == (c1_node *)0x0) {
      return (c1_node *)0x0;
    }
    pcVar11 = pcVar17;
    if (((type->base->flags & 0x20) != 0) && (ptr_type_cell = type, (type->flags & 0x20) != 0)) {
      unflagged_type.base = type->base;
      uVar3._0_2_ = type->code;
      uVar3._2_2_ = type->flags;
      unflagged_type.extra = type->extra;
      unflagged_type.debug_index = type->debug_index;
      unflagged_type._0_4_ = uVar3 & 0xffdfffff;
      type = type_intern(&unflagged_type);
      ptr_type_cell = type;
    }
    pcVar17->type = type;
  }
  if (pcVar18 == (c1_symbol *)0x0) {
    return pcVar11;
  }
  pcVar17 = tree_new_unsigned_constant(iVar20);
  pcVar17->type = g_type_unsigned_int;
  pcVar17 = expr_build_builtin_binary('J',pcVar7,pcVar17);
  pcVar17->type = g_type_unsigned_int;
  if (pcVar19 != (c1_node *)0x0) {
    pcVar7 = tree_new_unsigned_constant((int)pcVar19);
    pcVar17 = expr_build_builtin_binary('Q',pcVar17,pcVar7);
    pcVar17->type = PTR_104d151c;
  }
  pcVar17 = tree_append_list_item((c1_node *)0x0,pcVar17,2);
  if (placement != 0) {
    pcVar17->link = *(c1_node **)(placement + 8);
    *(c1_node **)(*(int *)(placement + 8) + 0x14) = pcVar17;
    *(c1_node **)(placement + 8) = pcVar17;
    pcVar17 = (c1_node *)placement;
  }
  pcVar7 = tree_new_symbol_ref(pcVar18,'\0');
  pcVar17 = (c1_node *)expr_build_call(pcVar7,pcVar17);
  if (pcVar17 == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  pcVar7 = pcVar17;
  left = tree_new_leaf_9c(entity,type);
  assign = tree_new_binary('4',left,pcVar7);
  if ((g_opt_eh != '\0') && (g_opt_NoEHForNew == '\0')) {
    if (cVar16 == '\0') {
      cVar16 = tree_has_side_effects((c1_tree_visitor *)&stack0xffffff6c,pcVar11);
      if (cVar16 != '\0') {
        call_info_zero_cursor_2 = (uint *)&call_info.call;
        for (iVar20 = 9; iVar20 != 0; iVar20 = iVar20 + -1) {
          *call_info_zero_cursor_2 = 0;
          call_info_zero_cursor_2 = call_info_zero_cursor_2 + 1;
        }
        cVar1 = pcVar17->op;
        call_info.call = pcVar17;
        while (cVar1 != 'p') {
          call_info.call = (call_info.call)->left;
          cVar1 = (call_info.call)->op;
        }
        call_info.expr = pcVar17;
        if ((call_info.flags & 4) == 0) {
          expr_call_info_decode_callee(&call_info);
        }
        if ((cls == (c1_symbol *)0x0) || (pcVar18 = cls, kind == '\x02')) {
          pcVar18 = (c1_symbol *)0x0;
        }
        pcVar18 = expr_select_operator_new
                            (g_name_delete,
                             *(int *)(((uint)(call_info.function)->type &
                                      -(uint)(((call_info.function)->type->code & 0x80) != 0)) + 8),
                             pcVar18);
        if (pcVar18 == (c1_symbol *)0x0) {
          diag_warning(1,0x123,call_info.function);
        }
        else {
          if (call_info.args == (c1_node *)0x0) {
            call_info.args = (call_info.call)->right;
          }
          cell_2c = (void *)0x0;
          if ((call_info.args != (c1_node *)0x0) &&
             (cell_2c = call_info.args, (call_info.args)->op == '7')) {
            cell_2c = pvRam00000010;
          }
          pcVar17 = call_info.args;
          eh_enter_new_expression_region();
          pcVar19 = tree_new_leaf_9c(entity,ptr_type_cell);
          pcVar19 = tree_new_rvalue(pcVar19);
          pcVar19 = tree_append_list_item((c1_node *)0x0,pcVar19,2);
          if (has_placement == '\0') {
            if (**(int **)(*(int *)(((uint)pcVar18->type &
                                    -(uint)((pcVar18->type->code & 0x80) != 0)) + 8) + 0xc) == 2) {
              pcVar17 = tree_new_int_constant(((cls->detail).cls)->size);
              pcVar19 = tree_append_list_item(pcVar19,pcVar17,2);
            }
          }
          else {
            pvVar8 = *(void **)((int)cell_2c + 8);
            if (pvVar8 != (void *)0x0) {
              if (pvVar8 == cell_2c) {
                cell_34 = (void *)0x0;
              }
              else {
                cell_34 = *(void **)((int)pvVar8 + 8);
              }
              while (cell_34 != (void *)0x0) {
                if (cell_34 == cell_2c) {
                  cell_34 = (void *)0x0;
                }
                else {
                  cell_34 = *(void **)((int)cell_34 + 8);
                }
                pcVar7 = expr_copy_placement_argument((c1_arg_iter *)&stack0xffffff6c,'\x01');
                pcVar19 = tree_append_list_item(pcVar19,pcVar7,2);
              }
            }
            call_info.args = pcVar17;
            if (call_info.expr != (c1_node *)0x0) {
              if (pcVar17->op == '7') {
                *(void **)((int)(call_info.call)->left + 0x10) = pcVar17->right;
                pcVar17 = pcVar17->left;
              }
              (call_info.call)->right = pcVar17;
              call_info.args = pcVar17;
            }
          }
          call_info_zero_cursor = (uint *)&delete_call.call;
          for (iVar20 = 9; iVar20 != 0; iVar20 = iVar20 + -1) {
            *call_info_zero_cursor = 0;
            call_info_zero_cursor = call_info_zero_cursor + 1;
          }
          delete_call.expr = (c1_node *)0x0;
          delete_call.function = pcVar18;
          pcVar17 = eh_leave_new_expression_region();
          if (pcVar17 != (c1_node *)0x0) {
            pcVar19 = tree_new_binary('7',pcVar19,pcVar17);
          }
          if (delete_call.expr != (c1_node *)0x0) {
            if (pcVar19->op == '7') {
              *(void **)((int)(delete_call.call)->left + 0x10) = pcVar19->right;
              pcVar19 = pcVar19->left;
            }
            (delete_call.call)->right = pcVar19;
          }
          delete_call.args = pcVar19;
          pcVar17 = expr_new_build_call_node(&delete_call);
          special_member_need_definition(pcVar18);
          assign = expr_build_eh_state_update(assign,pcVar17,(c1_symbol *)0x0);
          expr_new_mark_eh_state();
        }
      }
    }
    else if (class_41_bit1_clear != 0) {
      pcVar11 = expr_build_new_eh_delete
                          (cVar16,pcVar17,pcVar11,has_placement,assign,cls,pcVar19,cell_2c,cell_30,
                           cell_34,ptr_type_cell,entity,(int)pcVar13,cell_54,pcVar21,call_info.expr,
                           call_info.call,(int)call_info.function,call_info.args,call_info.flags,
                           (int)delete_call.expr,(int)delete_call.call,delete_call.function,
                           delete_call.args,kind);
      return pcVar11;
    }
  }
  pcVar11 = tree_new_comma(assign,pcVar11);
  pcVar11 = expr_spill_for_eh_state(pcVar11);
  pcVar11 = tree_new_comma(pcVar21,pcVar11);
  return pcVar11;
}

