c1_node * __cdecl
expr_build_new_eh_delete
          (char is_array,c1_node *alloc_call,c1_node *alloc,char has_placement,c1_node *assign,
          c1_symbol *cls,c1_node *cell_28,c1_node *cell_2c,c1_node *cell_30,c1_node *cell_34,
          c1_type *ptr_type,int temp_key,int cell_4c,int cell_54,c1_node *count_assign,
          c1_node *call_info,c1_node *call_info_4,int call_info_10,c1_node *call_info_18,
          byte call_info_24,int cell_94,int cell_98,c1_symbol *cell_a4,c1_node *cell_ac,char kind)

{
  c1_u8 cVar1;
  c1_symbol *pcVar2;
  c1_node *pcVar3;
  c1_node *pcVar4;
  byte *pbVar5;
  int iVar6;
  int *piVar7;
  c1_node **ppcVar8;
  
  pbVar5 = class_find_default_constructor(cls->type);
  if ((pbVar5[0x23] & 0x10) == 0) {
    ppcVar8 = &call_info_4;
    for (iVar6 = 9; iVar6 != 0; iVar6 = iVar6 + -1) {
      *ppcVar8 = (c1_node *)0x0;
      ppcVar8 = ppcVar8 + 1;
    }
    cVar1 = alloc_call->op;
    call_info_4 = alloc_call;
    while (cVar1 != 'p') {
      call_info_4 = call_info_4->left;
      cVar1 = call_info_4->op;
    }
    call_info = alloc_call;
    if ((call_info_24 & 4) == 0) {
      expr_call_info_decode_callee((c1_call_record *)&call_info);
    }
    iVar6 = call_info_10;
    if ((cls == (c1_symbol *)0x0) || (pcVar2 = cls, kind == '\x02')) {
      pcVar2 = (c1_symbol *)0x0;
    }
    piVar7 = g_name_array_delete;
    if (is_array == '\0') {
      piVar7 = g_name_delete;
    }
    pcVar2 = expr_select_operator_new
                       (piVar7,*(int *)(((uint)*(byte **)(call_info_10 + 0x14) &
                                        -(uint)((**(byte **)(call_info_10 + 0x14) & 0x80) != 0)) + 8
                                       ),pcVar2);
    if (pcVar2 == (c1_symbol *)0x0) {
      diag_warning(1,0x123,iVar6);
    }
    else {
      if (call_info_18 == (c1_node *)0x0) {
        call_info_18 = call_info_4->right;
      }
      cell_30 = (c1_node *)0x0;
      cell_2c = (c1_node *)0x0;
      cell_34 = (c1_node *)0x0;
      if ((call_info_18 != (c1_node *)0x0) && (cell_2c = call_info_18, call_info_18->op == '7')) {
        cell_2c = pcRam00000010;
      }
      cell_4c = 0;
      cell_54 = 0;
      cell_28 = call_info_18;
      eh_enter_new_expression_region();
      pcVar3 = tree_new_leaf_9c(temp_key,ptr_type);
      pcVar3 = tree_new_rvalue(pcVar3);
      pcVar3 = tree_append_list_item((c1_node *)0x0,pcVar3,2);
      if (has_placement == '\0') {
        if (**(int **)(*(int *)(((uint)pcVar2->type & -(uint)((pcVar2->type->code & 0x80) != 0)) + 8
                               ) + 0xc) == 2) {
          pcVar4 = tree_new_int_constant(((cls->detail).cls)->size);
          pcVar3 = tree_append_list_item(pcVar3,pcVar4,2);
        }
      }
      else {
        cell_30 = (c1_node *)0x0;
        pcVar4 = cell_2c->link;
        cell_34 = pcVar4;
        if (pcVar4 != (c1_node *)0x0) {
          cell_30 = pcVar4;
          if (pcVar4 == cell_2c) {
            cell_34 = (c1_node *)0x0;
          }
          else {
            cell_34 = pcVar4->link;
          }
          while (pcVar4 = cell_34, cell_34 != (c1_node *)0x0) {
            if (cell_34 == cell_2c) {
              cell_34 = (c1_node *)0x0;
            }
            else {
              cell_34 = cell_34->link;
            }
            cell_30 = pcVar4;
            pcVar4 = expr_copy_placement_argument((c1_arg_iter *)&cell_28,'\x01');
            pcVar3 = tree_append_list_item(pcVar3,pcVar4,2);
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
      piVar7 = &cell_98;
      for (iVar6 = 9; iVar6 != 0; iVar6 = iVar6 + -1) {
        *piVar7 = 0;
        piVar7 = piVar7 + 1;
      }
      cell_94 = 0;
      cell_a4 = pcVar2;
      pcVar4 = eh_leave_new_expression_region();
      if (pcVar4 != (c1_node *)0x0) {
        pcVar3 = tree_new_binary('7',pcVar3,pcVar4);
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
      special_member_need_definition(pcVar2);
      assign = expr_build_eh_state_update(assign,pcVar3,(c1_symbol *)0x0);
      expr_new_mark_eh_state();
    }
  }
  pcVar3 = tree_new_comma(assign,alloc);
  pcVar3 = expr_spill_for_eh_state(pcVar3);
  pcVar3 = tree_new_comma(count_assign,pcVar3);
  return pcVar3;
}

