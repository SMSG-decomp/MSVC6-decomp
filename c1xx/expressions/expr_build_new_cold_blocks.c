c1_node * __cdecl
expr_build_new_cold_blocks
          (c1_node *alloc,c1_type *ptr_type,c1_symbol *cls,c1_node *count_expr,char is_array,
          char class_41_bit1_clear,char cookie_needed,c1_node *alloc_cell,char has_placement,
          c1_node *assign,c1_symbol *opnew,c1_symbol *cls_cell,c1_node *cell_28,c1_node *cell_2c,
          c1_node *cell_30,c1_node *cell_34,c1_type *ptr_type_cell,int elem_size,int temp_key,
          int cell_4c,int cell_54,c1_node *count_assign,c1_type *cell_60,c1_u32 cell_64,
          c1_u32 cell_68,c1_node *call_info,c1_node *call_info_4,int call_info_10,
          c1_node *call_info_18,byte call_info_24,int cell_94,int cell_98,c1_symbol *cell_a4,
          c1_node *cell_ac,char kind,int placement,c1_symbol *type_sym,int init,c1_node *args)

{
  c1_u8 cVar1;
  c1_type *pcVar2;
  char cVar3;
  c1_node *pcVar4;
  c1_node *pcVar5;
  c1_node *left;
  c1_symbol *pcVar6;
  int iVar7;
  c1_node **ppcVar8;
  int *piVar9;
  uint uStack0000005c;
  
  if ((init != 0) || ((is_array != '\0' && (cell_28 != (c1_node *)0x0)))) {
    if (((((cls->detail).cls)->layout_flags3b & 0x80) != 0) && ((cls->flags3 & 4) == 0)) {
      class_check_abstract_instantiation(cls);
      cls->flags3 = cls->flags3 | 4;
    }
    if (is_array == '\0') {
      alloc = expr_build_new_initializer
                        (args == (c1_node *)0x0,(char)assign,cls,alloc,(c1_node *)init,type_sym);
    }
    else {
      if ((cookie_needed != '\0') &&
         (pcVar6 = (c1_symbol *)class_find_vector_deleting_dtor(ptr_type),
         pcVar6 != (c1_symbol *)0x0)) {
        special_member_need_definition(pcVar6);
        pcVar6->flags21 = pcVar6->flags21 | 0x80;
      }
      alloc = expr_build_array_new_construction
                        (alloc_cell,args == (c1_node *)0x0,(int)assign,(int)cell_28,count_expr,
                         elem_size);
    }
    if (alloc == (c1_node *)0x0) {
      return (c1_node *)0x0;
    }
    pcVar2 = ptr_type_cell;
    if (((ptr_type->base->flags & 0x20) != 0) && (pcVar2 = ptr_type, (ptr_type->flags & 0x20) != 0))
    {
      cell_60 = ptr_type->base;
      uStack0000005c._0_2_ = ptr_type->code;
      uStack0000005c._2_2_ = ptr_type->flags;
      cell_64 = (ptr_type->extra).count;
      cell_68 = ptr_type->debug_index;
      uStack0000005c = uStack0000005c & 0xffdfffff;
      ptr_type = type_intern((c1_type *)&uStack0000005c);
      pcVar2 = ptr_type;
    }
    ptr_type_cell = pcVar2;
    alloc->type = ptr_type;
    alloc_cell = alloc;
  }
  if (opnew == (c1_symbol *)0x0) {
    return alloc;
  }
  pcVar4 = tree_new_unsigned_constant(elem_size);
  pcVar4->type = g_type_unsigned_int;
  pcVar4 = expr_build_builtin_binary('J',count_expr,pcVar4);
  pcVar4->type = g_type_unsigned_int;
  if (cell_28 != (c1_node *)0x0) {
    pcVar5 = tree_new_unsigned_constant((int)cell_28);
    pcVar4 = expr_build_builtin_binary('Q',pcVar4,pcVar5);
    pcVar4->type = PTR_104d151c;
  }
  pcVar4 = tree_append_list_item((c1_node *)0x0,pcVar4,2);
  if (placement != 0) {
    pcVar4->link = *(c1_node **)(placement + 8);
    *(c1_node **)(*(int *)(placement + 8) + 0x14) = pcVar4;
    *(c1_node **)(placement + 8) = pcVar4;
    pcVar4 = (c1_node *)placement;
  }
  pcVar5 = tree_new_symbol_ref(opnew,'\0');
  pcVar4 = (c1_node *)expr_build_call(pcVar5,pcVar4);
  if (pcVar4 == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  pcVar5 = pcVar4;
  left = tree_new_leaf_9c(temp_key,ptr_type);
  assign = tree_new_binary('4',left,pcVar5);
  if ((g_opt_eh != '\0') && (g_opt_NoEHForNew == '\0')) {
    if (is_array == '\0') {
      cell_2c = (c1_node *)0x4;
      cell_28 = (c1_node *)&PTR_expr_call_needs_eh_cleanup_104bcbf0;
      cVar3 = tree_has_side_effects((c1_tree_visitor *)&cell_28,alloc_cell);
      if (cVar3 != '\0') {
        ppcVar8 = &call_info_4;
        for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
          *ppcVar8 = (c1_node *)0x0;
          ppcVar8 = ppcVar8 + 1;
        }
        cVar1 = pcVar4->op;
        call_info_4 = pcVar4;
        while (cVar1 != 'p') {
          call_info_4 = call_info_4->left;
          cVar1 = call_info_4->op;
        }
        call_info = pcVar4;
        if ((call_info_24 & 4) == 0) {
          expr_call_info_decode_callee((c1_call_record *)&call_info);
        }
        iVar7 = call_info_10;
        if ((cls_cell == (c1_symbol *)0x0) || (pcVar6 = cls_cell, kind == '\x02')) {
          pcVar6 = (c1_symbol *)0x0;
        }
        pcVar6 = expr_select_operator_new
                           (g_name_delete,
                            *(int *)(((uint)*(byte **)(call_info_10 + 0x14) &
                                     -(uint)((**(byte **)(call_info_10 + 0x14) & 0x80) != 0)) + 8),
                            pcVar6);
        if (pcVar6 == (c1_symbol *)0x0) {
          diag_warning(1,0x123,iVar7);
        }
        else {
          if (call_info_18 == (c1_node *)0x0) {
            call_info_18 = call_info_4->right;
          }
          cell_30 = (c1_node *)0x0;
          cell_2c = (c1_node *)0x0;
          cell_34 = (c1_node *)0x0;
          if ((call_info_18 != (c1_node *)0x0) && (cell_2c = call_info_18, call_info_18->op == '7'))
          {
            cell_2c = pcRam00000010;
          }
          cell_4c = 0;
          cell_54 = 0;
          cell_28 = call_info_18;
          eh_enter_new_expression_region();
          pcVar4 = tree_new_leaf_9c(temp_key,ptr_type_cell);
          pcVar4 = tree_new_rvalue(pcVar4);
          pcVar4 = tree_append_list_item((c1_node *)0x0,pcVar4,2);
          if (has_placement == '\0') {
            if (**(int **)(*(int *)(((uint)pcVar6->type & -(uint)((pcVar6->type->code & 0x80) != 0))
                                   + 8) + 0xc) == 2) {
              pcVar5 = tree_new_int_constant(((cls_cell->detail).cls)->size);
              pcVar4 = tree_append_list_item(pcVar4,pcVar5,2);
            }
          }
          else {
            cell_30 = (c1_node *)0x0;
            pcVar5 = cell_2c->link;
            cell_34 = pcVar5;
            if (pcVar5 != (c1_node *)0x0) {
              cell_30 = pcVar5;
              if (pcVar5 == cell_2c) {
                cell_34 = (c1_node *)0x0;
              }
              else {
                cell_34 = pcVar5->link;
              }
              while (pcVar5 = cell_34, cell_34 != (c1_node *)0x0) {
                if (cell_34 == cell_2c) {
                  cell_34 = (c1_node *)0x0;
                }
                else {
                  cell_34 = cell_34->link;
                }
                cell_30 = pcVar5;
                pcVar5 = expr_copy_placement_argument((c1_arg_iter *)&cell_28,'\x01');
                pcVar4 = tree_append_list_item(pcVar4,pcVar5,2);
              }
            }
            call_info_18 = cell_28;
            if (call_info != (c1_node *)0x0) {
              if (cell_28->op == '7') {
                *(void **)((int)call_info_4->left + 0x10) = cell_28->right;
                call_info_18 = cell_28->left;
              }
              call_info_4->right = call_info_18;
            }
          }
          piVar9 = &cell_98;
          for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
            *piVar9 = 0;
            piVar9 = piVar9 + 1;
          }
          cell_94 = 0;
          cell_a4 = pcVar6;
          pcVar5 = eh_leave_new_expression_region();
          if (pcVar5 != (c1_node *)0x0) {
            pcVar4 = tree_new_binary('7',pcVar4,pcVar5);
          }
          if (cell_94 != 0) {
            if (pcVar4->op == '7') {
              *(void **)(*(int *)(cell_98 + 0x10) + 0x10) = pcVar4->right;
              pcVar4 = pcVar4->left;
            }
            *(c1_node **)(cell_98 + 0x14) = pcVar4;
          }
          cell_ac = pcVar4;
          pcVar4 = expr_new_build_call_node(&cell_94);
          special_member_need_definition(pcVar6);
          assign = expr_build_eh_state_update(assign,pcVar4,(c1_symbol *)0x0);
          expr_new_mark_eh_state();
        }
      }
    }
    else if (class_41_bit1_clear != '\0') {
      pcVar4 = expr_build_new_eh_delete
                         (is_array,pcVar4,alloc_cell,has_placement,assign,cls_cell,cell_28,cell_2c,
                          cell_30,cell_34,ptr_type_cell,temp_key,cell_4c,cell_54,count_assign,
                          call_info,call_info_4,call_info_10,call_info_18,call_info_24,cell_94,
                          cell_98,cell_a4,cell_ac,kind);
      return pcVar4;
    }
  }
  pcVar4 = tree_new_comma(assign,alloc_cell);
  pcVar4 = expr_spill_for_eh_state(pcVar4);
  pcVar4 = tree_new_comma(count_assign,pcVar4);
  return pcVar4;
}

