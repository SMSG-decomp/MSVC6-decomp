c1_node * __thiscall expr_copy_placement_argument(c1_arg_iter *arg_iter,char from_new_expression)

{
  c1_u8 cVar1;
  c1_type *type;
  char cVar2;
  int iVar3;
  c1_node *pcVar4;
  c1_node *pcVar5;
  c1_node *pcVar6;
  uint entity;
  c1_type *pcVar7;
  void *pvVar8;
  c1_placement_slot src;
  char *expr;
  void **entity_00;
  c1_node *expr_00;
  c1_node **ppcVar9;
  c1_node *local_a4;
  c1_placement_slot slot;
  c1_node *local_9c;
  c1_node *local_98;
  c1_node *local_94;
  c1_arg_iter iter;
  c1_call_record view;
  c1_tree_visitor local_58;
  uint zeroed_4c;
  c1_call_record delete_view;
  c1_saved_operand saved;
  c1_saved_operand saved_result;
  
  pcVar4 = arg_iter->current->left;
  type = pcVar4->type;
  slot.iter = arg_iter;
  if ((type->code & 0x200) == 0) {
    local_58.kind_mask = 0xff;
    local_58.pad05[0] = '\0';
    local_58.pad05[1] = '\0';
    local_58.pad05[2] = '\0';
    local_58.vtbl = &g_side_effect_visitor_vtable;
    cVar2 = tree_has_side_effects(&local_58,pcVar4);
    src = (c1_placement_slot)arg_iter->current->left;
    if (cVar2 != '\0') {
      slot = src;
      pcVar4 = expr_spill_to_temporary(&slot.operand);
      pcVar5 = tree_new_binary_typed_right('7',slot.operand,pcVar4);
      arg_iter->current->left = pcVar5;
      pcVar5->link = arg_iter->current;
      pcVar4 = tree_copy_to_arena(pcVar4,g_expr_arena_index);
      return pcVar4;
    }
  }
  else {
    iVar3 = expr_is_intrinsic_0xdf_call((char *)pcVar4);
    if ((char)iVar3 == '\0') {
      local_a4 = expr_build_address_of(arg_iter->current->left,2);
      pcVar4 = expr_spill_to_temporary(&local_a4);
      pcVar5 = tree_new_unary('=',type,pcVar4);
      pcVar6 = tree_new_binary_typed_right('7',local_a4,pcVar5);
      arg_iter->current->left = pcVar6;
      pcVar6->link = arg_iter->current;
      if (from_new_expression == '\0') {
        pcVar4 = pcVar5;
      }
      pcVar4 = tree_copy_to_arena(pcVar4,g_expr_arena_index);
      return pcVar4;
    }
    expr_saved_operand_init(&saved,arg_iter->current->left);
    pcVar4 = (c1_node *)expr_saved_operand_slot2((int *)&saved);
    local_98 = (c1_node *)0x0;
    local_9c = (c1_node *)((pcVar4->op != 0xc1) - 1 & (uint)pcVar4);
    local_94 = (c1_node *)0x0;
    if (local_9c != (c1_node *)0x0) {
      expr_saved_operand_split_pair((int *)&local_9c);
      pcVar4 = local_98;
    }
    ppcVar9 = &view.call;
    for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
      *ppcVar9 = (c1_node *)0x0;
      ppcVar9 = ppcVar9 + 1;
    }
    if (pcVar4 != (c1_node *)0x0) {
      cVar1 = pcVar4->op;
      view.call = pcVar4;
      while (cVar1 != 'p') {
        view.call = (view.call)->left;
        cVar1 = (view.call)->op;
      }
    }
    local_a4 = (c1_node *)0x0;
    view.expr = pcVar4;
    if ((view.flags & 4) == 0) {
      expr_call_info_decode_callee(&view);
    }
    if (((*(byte *)((int)&(view.function)->tail + 8) & 0x20) == 0) ||
       (iVar3 = tree_list_length((int)(view.call)->right), iVar3 != 1)) {
      if ((view.flags & 8) == 0) {
        expr_call_view_find_first_arg_slot(&view);
      }
      local_58.vtbl = (void **)view.arg_expr;
      entity = sym_new_local_key();
      pcVar4 = tree_new_leaf_9c(entity,type);
      pcVar7 = type_pointer_with_qualifiers(type,0);
      pcVar4 = tree_new_cast(pcVar7,pcVar4);
      if ((view.flags & 8) == 0) {
        expr_call_view_find_first_arg_slot(&view);
      }
      if ((view.flags & 0x10) == 0) {
        (view.arg_slot)->left = pcVar4;
      }
      else {
        (view.arg_slot)->left = pcVar4;
      }
      pcVar4->link = view.arg_slot;
      local_a4 = view.expr;
      view.arg_expr = pcVar4;
      if (local_9c != (c1_node *)0x0) {
        if (local_98 == (c1_node *)0x0) {
          expr_saved_operand_split_pair((int *)&local_9c);
        }
        delete_view.expr = tree_copy_to_arena(local_94,g_expr_arena_index);
        ppcVar9 = &delete_view.call;
        for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
          *ppcVar9 = (c1_node *)0x0;
          ppcVar9 = ppcVar9 + 1;
        }
        if (delete_view.expr != (c1_node *)0x0) {
          cVar1 = (delete_view.expr)->op;
          delete_view.call = delete_view.expr;
          while (cVar1 != 'p') {
            delete_view.call = (delete_view.call)->left;
            cVar1 = (delete_view.call)->op;
          }
        }
        pcVar5 = tree_new_leaf_9c(entity,type);
        delete_view.object = tree_new_rvalue(pcVar5);
        if (delete_view.expr != (c1_node *)0x0) {
          if ((delete_view.flags & 4) == 0) {
            expr_call_info_decode_callee(&delete_view);
          }
          (delete_view.this_arg)->right = delete_view.object;
          (delete_view.object)->link = delete_view.this_arg;
        }
        local_a4 = expr_build_eh_state_update(local_a4,delete_view.expr,(type->extra).cls);
      }
      eh_register_temporary_destructor(pcVar4,type);
      pcVar4 = tree_new_leaf_9c(entity,type);
      pcVar4 = tree_new_unary('=',type,pcVar4);
      pcVar4 = tree_append_list_item((c1_node *)0x0,pcVar4,0);
      pcVar4 = expr_build_call_of((c1_symbol *)0x0,(type->extra).cls,(c1_node *)local_58.vtbl,pcVar4
                                  ,'\0',1,'\0');
      pcVar4 = expr_build_address_of(pcVar4,2);
      arg_iter = slot.iter;
      if (&stack0x00000000 != (undefined1 *)0x80) {
        expr_call_view_init(&view,(char *)pcVar4);
        arg_iter = slot.iter;
      }
    }
    if (view.args == (c1_node *)0x0) {
      view.args = (view.call)->right;
    }
    iter.current = (c1_node *)0x0;
    iter.list = (c1_node *)0x0;
    iter.next = (c1_node *)0x0;
    if ((view.args != (c1_node *)0x0) && (iter.list = view.args, (view.args)->op == '7')) {
      iter.list = pcRam00000010;
    }
    local_58.kind_mask = '\0';
    local_58.pad05[0] = '\0';
    local_58.pad05[1] = '\0';
    local_58.pad05[2] = '\0';
    pcVar5 = (c1_node *)0x0;
    zeroed_4c = 0;
    iter.args = view.args;
    if (from_new_expression == '\0') {
      eh_enter_new_expression_region();
      iter.current = (c1_node *)0x0;
      iter.next = (iter.list)->link;
      while (pcVar4 = iter.next, iter.next != (c1_node *)0x0) {
        if (iter.next == iter.list) {
          iter.next = (c1_node *)0x0;
        }
        else {
          iter.next = (iter.next)->link;
        }
        iter.current = pcVar4;
        pcVar4 = expr_copy_placement_argument(&iter,'\0');
        pcVar5 = tree_append_list_item(pcVar5,pcVar4,2);
      }
      pcVar4 = view.expr;
      view.args = iter.args;
      if (view.expr != (c1_node *)0x0) {
        if ((iter.args)->op == '7') {
          *(void **)((int)(view.call)->left + 0x10) = (iter.args)->right;
          view.args = (iter.args)->left;
        }
        (view.call)->right = view.args;
      }
    }
    if (local_a4 != (c1_node *)0x0) {
      pcVar4 = tree_new_binary_typed_right('7',local_a4,pcVar4);
    }
    pcVar6 = pcVar4;
    if (local_9c != (c1_node *)0x0) {
      pcVar6 = local_9c->right;
      pcVar4->link = pcVar6;
      pcVar6->left = pcVar4;
      pcVar6 = local_9c;
      local_98 = pcVar4;
    }
    expr_saved_operand_replace_slot2(&saved,pcVar6);
    pvVar8 = (void *)expr_saved_operand_rebind((int *)&saved);
    arg_iter->current->left = pvVar8;
    *(c1_node **)((int)pvVar8 + 8) = arg_iter->current;
    if (from_new_expression == '\0') {
      pcVar4 = eh_leave_new_expression_region();
      if (pcVar4 != (c1_node *)0x0) {
        pcVar5 = tree_new_binary('7',pcVar5,pcVar4);
      }
      expr_save_operand_for_reuse(&view,pcVar5);
      if (&stack0x00000000 != (undefined1 *)0x80) {
        expr_call_view_init(&view,expr);
      }
      entity_00 = (void **)sym_new_local_key();
      local_58.vtbl = entity_00;
      pcVar7 = type_pointer_with_qualifiers(type,0);
      pcVar4 = tree_new_leaf_9c((int)entity_00,pcVar7);
      pcVar4 = tree_new_unary('=',pcVar7,pcVar4);
      pcVar4 = tree_new_unary('=',type,pcVar4);
      if (view.expr != (c1_node *)0x0) {
        if ((view.flags & 4) == 0) {
          expr_call_info_decode_callee(&view);
        }
        (view.this_arg)->right = pcVar4;
        pcVar4->link = view.this_arg;
      }
      local_a4 = view.expr;
      view.object = pcVar4;
      if (local_9c != (c1_node *)0x0) {
        if (local_98 == (c1_node *)0x0) {
          expr_saved_operand_split_pair((int *)&local_9c);
        }
        delete_view.expr = tree_copy_to_arena(local_94,g_expr_arena_index);
        ppcVar9 = &delete_view.call;
        for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
          *ppcVar9 = (c1_node *)0x0;
          ppcVar9 = ppcVar9 + 1;
        }
        if (delete_view.expr != (c1_node *)0x0) {
          cVar1 = (delete_view.expr)->op;
          delete_view.call = delete_view.expr;
          while (cVar1 != 'p') {
            delete_view.call = (delete_view.call)->left;
            cVar1 = (delete_view.call)->op;
          }
        }
        pcVar4 = tree_copy_to_arena(pcVar4,g_expr_arena_index);
        if (delete_view.expr != (c1_node *)0x0) {
          if ((delete_view.flags & 4) == 0) {
            expr_call_info_decode_callee(&delete_view);
          }
          (delete_view.this_arg)->right = pcVar4;
          pcVar4->link = delete_view.this_arg;
        }
        delete_view.object = pcVar4;
        local_a4 = expr_build_eh_state_update(local_a4,delete_view.expr,(type->extra).cls);
        entity_00 = local_58.vtbl;
      }
      expr_clone_for_reuse(&saved,local_a4);
      expr_saved_operand_init(&saved_result,expr_00);
      pcVar4 = tree_new_leaf_9c((int)entity_00,pcVar7);
      expr_saved_operand_replace_slot1(&saved_result,pcVar4);
      pcVar4 = (c1_node *)expr_saved_operand_rebind((int *)&saved_result);
      return pcVar4;
    }
    src = (c1_placement_slot)(iter.list)->link->left;
  }
  pcVar4 = tree_copy_to_arena(src.operand,g_expr_arena_index);
  return pcVar4;
}

