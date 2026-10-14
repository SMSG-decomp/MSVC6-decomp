c1_node * __cdecl
decl_variable_initializer_fragment
          (int init,c1_node *alloc,c1_node *count_expr,c1_type *ptr_type,char is_array,
          char class_41_bit1_clear,char has_placement,c1_symbol *opnew,c1_symbol *cls,
          c1_node *iter_args,c1_node *iter_list,c1_node *iter_current,c1_node *iter_next,
          c1_type *ptr_type_cell,int elem_size,int temp_key,int cell_4c,int cell_54,
          c1_node *count_assign,c1_node *call_info,c1_node *call_info_4,int call_info_10,
          void *call_info_18,byte call_info_24,int cell_94,int cell_98,c1_symbol *cell_a4,
          c1_node *cell_ac,char kind,int placement)

{
  c1_u8 cVar1;
  char cVar2;
  c1_node *pcVar3;
  c1_node *pcVar4;
  c1_node *pcVar5;
  c1_symbol *pcVar6;
  c1_node *pcVar7;
  int iVar8;
  c1_node **ppcVar9;
  int *piVar10;
  
  pcVar7 = (c1_node *)init_element_access(alloc,(c1_node *)init);
  if (opnew == (c1_symbol *)0x0) {
    return pcVar7;
  }
  pcVar3 = tree_new_unsigned_constant(elem_size);
  pcVar3->type = g_type_unsigned_int;
  pcVar3 = expr_build_builtin_binary('J',count_expr,pcVar3);
  pcVar3->type = g_type_unsigned_int;
  if (iter_args != (c1_node *)0x0) {
    pcVar4 = tree_new_unsigned_constant((int)iter_args);
    pcVar3 = expr_build_builtin_binary('Q',pcVar3,pcVar4);
    pcVar3->type = PTR_104d151c;
  }
  pcVar3 = tree_append_list_item((c1_node *)0x0,pcVar3,2);
  if (placement != 0) {
    pcVar3->link = *(c1_node **)(placement + 8);
    *(c1_node **)(*(int *)(placement + 8) + 0x14) = pcVar3;
    *(c1_node **)(placement + 8) = pcVar3;
    pcVar3 = (c1_node *)placement;
  }
  pcVar4 = tree_new_symbol_ref(opnew,'\0');
  pcVar3 = (c1_node *)expr_build_call(pcVar4,pcVar3);
  if (pcVar3 == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  pcVar4 = pcVar3;
  pcVar5 = tree_new_leaf_9c(temp_key,ptr_type);
  pcVar4 = tree_new_binary('4',pcVar5,pcVar4);
  if ((g_opt_eh != '\0') && (g_opt_NoEHForNew == '\0')) {
    if (is_array == '\0') {
      iter_list = (c1_node *)0x4;
      iter_args = (c1_node *)&PTR_expr_call_needs_eh_cleanup_104bcbf0;
      cVar2 = tree_has_side_effects((c1_tree_visitor *)&iter_args,pcVar7);
      if (cVar2 != '\0') {
        ppcVar9 = &call_info_4;
        for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
          *ppcVar9 = (c1_node *)0x0;
          ppcVar9 = ppcVar9 + 1;
        }
        cVar1 = pcVar3->op;
        call_info_4 = pcVar3;
        while (cVar1 != 'p') {
          call_info_4 = call_info_4->left;
          cVar1 = call_info_4->op;
        }
        call_info = pcVar3;
        if ((call_info_24 & 4) == 0) {
          expr_call_info_decode_callee((c1_call_record *)&call_info);
        }
        iVar8 = call_info_10;
        if ((cls == (c1_symbol *)0x0) || (pcVar6 = cls, kind == '\x02')) {
          pcVar6 = (c1_symbol *)0x0;
        }
        pcVar6 = expr_select_operator_new
                           (g_name_delete,
                            *(int *)(((uint)*(byte **)(call_info_10 + 0x14) &
                                     -(uint)((**(byte **)(call_info_10 + 0x14) & 0x80) != 0)) + 8),
                            pcVar6);
        if (pcVar6 == (c1_symbol *)0x0) {
          diag_warning(1,0x123,iVar8);
        }
        else {
          if (call_info_18 == (void *)0x0) {
            call_info_18 = call_info_4->right;
          }
          iter_current = (c1_node *)0x0;
          iter_list = (c1_node *)0x0;
          iter_next = (c1_node *)0x0;
          if ((call_info_18 != (void *)0x0) &&
             (iter_list = call_info_18, *(char *)call_info_18 == '7')) {
            iter_list = pcRam00000010;
          }
          cell_4c = 0;
          cell_54 = 0;
          iter_args = call_info_18;
          eh_enter_new_expression_region();
          pcVar3 = tree_new_leaf_9c(temp_key,ptr_type_cell);
          pcVar3 = tree_new_rvalue(pcVar3);
          pcVar3 = tree_append_list_item((c1_node *)0x0,pcVar3,2);
          if (has_placement == '\0') {
            if (**(int **)(*(int *)(((uint)pcVar6->type & -(uint)((pcVar6->type->code & 0x80) != 0))
                                   + 8) + 0xc) == 2) {
              pcVar5 = tree_new_int_constant(((cls->detail).cls)->size);
              pcVar3 = tree_append_list_item(pcVar3,pcVar5,2);
            }
          }
          else {
            iter_current = (c1_node *)0x0;
            pcVar5 = iter_list->link;
            iter_next = pcVar5;
            if (pcVar5 != (c1_node *)0x0) {
              iter_current = pcVar5;
              if (pcVar5 == iter_list) {
                iter_next = (c1_node *)0x0;
              }
              else {
                iter_next = pcVar5->link;
              }
              while (pcVar5 = iter_next, iter_next != (c1_node *)0x0) {
                if (iter_next == iter_list) {
                  iter_next = (c1_node *)0x0;
                }
                else {
                  iter_next = iter_next->link;
                }
                iter_current = pcVar5;
                pcVar5 = expr_copy_placement_argument((c1_arg_iter *)&iter_args,'\x01');
                pcVar3 = tree_append_list_item(pcVar3,pcVar5,2);
              }
            }
            call_info_18 = iter_args;
            if (call_info != (c1_node *)0x0) {
              if (iter_args->op == '7') {
                *(void **)((int)call_info_4->left + 0x10) = iter_args->right;
                call_info_18 = iter_args->left;
              }
              call_info_4->right = call_info_18;
            }
          }
          piVar10 = &cell_98;
          for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
            *piVar10 = 0;
            piVar10 = piVar10 + 1;
          }
          cell_94 = 0;
          cell_a4 = pcVar6;
          pcVar5 = eh_leave_new_expression_region();
          if (pcVar5 != (c1_node *)0x0) {
            pcVar3 = tree_new_binary('7',pcVar3,pcVar5);
          }
          if (cell_94 != 0) {
            if (pcVar3->op == '7') {
              *(void **)(*(int *)(cell_98 + 0x10) + 0x10) = pcVar3->right;
              pcVar3 = pcVar3->left;
            }
            *(c1_node **)(cell_98 + 0x14) = pcVar3;
          }
          cell_ac = pcVar3;
          pcVar3 = expr_new_build_call_node(&cell_94);
          special_member_need_definition(pcVar6);
          pcVar4 = expr_build_eh_state_update(pcVar4,pcVar3,(c1_symbol *)0x0);
          expr_new_mark_eh_state();
        }
      }
    }
    else if (class_41_bit1_clear != '\0') {
      pcVar7 = expr_build_new_eh_delete
                         (is_array,pcVar3,pcVar7,has_placement,pcVar4,cls,iter_args,iter_list,
                          iter_current,iter_next,ptr_type_cell,temp_key,cell_4c,cell_54,count_assign
                          ,call_info,call_info_4,call_info_10,call_info_18,call_info_24,cell_94,
                          cell_98,cell_a4,cell_ac,kind);
      return pcVar7;
    }
  }
  pcVar7 = tree_new_comma(pcVar4,pcVar7);
  pcVar7 = expr_spill_for_eh_state(pcVar7);
  pcVar7 = tree_new_comma(count_assign,pcVar7);
  return pcVar7;
}

