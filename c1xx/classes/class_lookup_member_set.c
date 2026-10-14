c1_symbol * __thiscall
class_lookup_member_set(c1_scope_stack *scope,c1_symbol *cls,void *name,uint flags,int error_number)

{
  c1_u8 cVar1;
  c1_u8 cVar2;
  c1_u8 cVar3;
  c1_keyed_cell *pcVar4;
  fe_name *name_00;
  c1_keyed_cell *pcVar5;
  c1_keyed_cell *pcVar6;
  c1_scope_stack *pcVar7;
  void *name_01;
  c1_keyed_list *pcVar8;
  c1_arena *a;
  c1_u8 *pcVar9;
  byte *pbVar10;
  c1_symbol *pcVar11;
  byte bVar12;
  uint uVar13;
  char ambiguous;
  
  name_01 = name;
  ambiguous = '\0';
  if ((cls->flags2 & 4) == 0) {
    tmpl_instantiate_if_needed(cls);
  }
  if ((cls->name == name) && (((byte)flags & 0x20) == 0x20)) {
    pcVar8 = tree_new_list_cell((c1_keyed_list *)0x0,0,cls);
  }
  else {
    pcVar8 = class_lookup_member_name(cls,name,flags & 0xffffffbf);
    if (pcVar8 == (c1_keyed_list *)0x0) {
      if ((flags & 0x40) != 0) {
        if (g_member_set_retry_guard == 0) {
          g_member_set_retry_guard = g_member_set_retry_guard + 1;
          pcVar9 = expr_build_member_access_implicit(scope,name);
        }
        else {
          pcVar9 = (c1_u8 *)0x0;
        }
        pcVar7 = g_current_scope;
        g_member_set_retry_guard = 0;
        if (pcVar9 == (c1_u8 *)0x0) {
          cVar1 = g_current_scope->reported;
          cVar2 = g_current_scope->access_op;
          pcVar11 = g_current_scope->qual_class;
          cVar3 = g_current_scope->qualified;
          g_current_scope->reported = '\0';
          pcVar7->qual_class = (c1_symbol *)0x0;
          pcVar7->access_op = '\x01';
          pcVar7->qualified = '\0';
          pcVar9 = expr_build_member_access_implicit(scope,name);
          if (cVar3 == '\0') {
            g_current_scope->qual_class = (c1_symbol *)0x0;
            g_current_scope->access_op = '\x01';
            g_current_scope->qualified = '\0';
            g_current_scope->reported = '\0';
          }
          else {
            g_current_scope->qual_class = pcVar11;
            g_current_scope->access_op = cVar2;
            g_current_scope->qualified = '\x01';
            g_current_scope->reported = cVar1;
          }
          if (pcVar9 == (c1_u8 *)0x0) {
            return (c1_symbol *)0x0;
          }
        }
        pbVar10 = *(byte **)pcVar9;
        if ((*pbVar10 & 0x1f) == 0x12) {
          pbVar10 = *(byte **)(**(int **)(pbVar10 + 0x14) + 8);
        }
        bVar12 = *pbVar10 & 0x1f;
        if ((((bVar12 != 0) && (bVar12 < 0xf)) && (bVar12 != 5)) &&
           (((pbVar10[0x20] & 7) == 7 && ((**(ushort **)(pbVar10 + 0x14) & 0x200) != 0)))) {
          name_00 = *(fe_name **)(*(int *)(*(ushort **)(pbVar10 + 0x14) + 4) + 8);
          if ((cls->name == name_00) && ((flags & 1) != 0)) {
            pcVar8 = tree_new_list_cell((c1_keyed_list *)0x0,0,cls);
          }
          else {
            pcVar8 = class_lookup_member_name(cls,name_00,flags & 0xffffffbf);
          }
          pcVar7 = g_current_scope;
          if (pcVar8 != (c1_keyed_list *)0x0) {
            cVar1 = g_current_scope->access_op;
            cVar2 = g_current_scope->reported;
            pcVar11 = g_current_scope->qual_class;
            cVar3 = g_current_scope->qualified;
            g_current_scope->reported = '\0';
            pcVar7->qual_class = (c1_symbol *)0x0;
            pcVar7->access_op = '\x01';
            pcVar7->qualified = '\0';
            lookup_name_in_context(scope,name_00,0x132);
            if (cVar3 == '\0') {
              g_current_scope->qual_class = (c1_symbol *)0x0;
              g_current_scope->access_op = '\x01';
              g_current_scope->qualified = '\0';
              g_current_scope->reported = '\0';
            }
            else {
              g_current_scope->qual_class = pcVar11;
              g_current_scope->access_op = cVar1;
              g_current_scope->qualified = '\x01';
              g_current_scope->reported = cVar2;
            }
            pcVar11 = class_lookup_member_set_tail
                                (pcVar8,cls,name_00,ambiguous,pcVar8,flags,error_number);
            return pcVar11;
          }
        }
      }
      return (c1_symbol *)0x0;
    }
    if ((((flags & 1) == 0) || (cls->name != name)) &&
       ((pcVar4 = pcVar8->head, pcVar4 != pcVar8->tail && ((flags & 0x80) == 0)))) {
      if (error_number != 0) {
        ambiguous = '\x01';
        pcVar5 = pcVar4;
        for (pcVar6 = pcVar4->key; pcVar6 != (c1_keyed_cell *)0x0; pcVar6 = pcVar6->key) {
          pcVar5 = pcVar6;
        }
        diag_error((short)error_number,pcVar5->sym,name);
        for (pcVar5 = pcVar4; pcVar5 != (c1_keyed_cell *)0x0; pcVar5 = pcVar5->next) {
          pcVar9 = base_path_text_for_diag((int *)pcVar5,1);
          diag_warning(1,error_number,(pcVar5 != pcVar4) + 0x17c,name,pcVar9);
        }
      }
      pcVar8->tail = pcVar8->head;
      pcVar8->head->next = (c1_keyed_cell *)0x0;
    }
  }
  name = pcVar8;
  if ((g_compile_flags_c4 & 0x400) == 0) {
    if ((((g_block_depth != '\0') && (g_class_depth < 0)) &&
        ((g_compile_flags_c8 & 0x10000000) == 0)) &&
       (((((g_compile_flags_c8 & 0x40000000) == 0 || (((byte)g_compile_flags_cc & 8) != 0)) ||
         ((g_compile_flags_c4 & 0x200) != 0)) && (((byte)g_compile_flags_cc & 0x50) == 0)))) {
      flags = 4;
      goto LAB_1040db8e;
    }
    flags = 0;
  }
  else {
    flags = g_token_arena_index;
    if (g_token_arena_index != 0) goto LAB_1040db8e;
  }
  if ((void **)g_symbol_free_lists[g_symbol_size_class_table[0x12]] != (void **)0x0) {
    pcVar11 = sym_record_reuse_tail
                        (g_symbol_size_class_table[0x12],
                         (void **)g_symbol_free_lists[g_symbol_size_class_table[0x12]],name_01,
                         ambiguous,name,flags);
    return pcVar11;
  }
LAB_1040db8e:
  a = g_arenas + flags;
  uVar13 = g_symbol_size_table[0x12] + 3;
  pcVar11 = (c1_symbol *)a->cur;
  pcVar9 = g_arenas[flags].end;
  a->cur = &pcVar11->kind + (uVar13 & 0xfffffffc);
  if (pcVar9 < &pcVar11->kind + (uVar13 & 0xfffffffc)) {
    arena_grow(a);
  }
  if (pcVar11 == (c1_symbol *)0x0) {
    pcVar11 = (c1_symbol *)0x0;
  }
  else {
    pcVar11->kind = pcVar11->kind & 0xf2 | 0x12;
    if (&pcVar11->name != (fe_name **)0x0) {
      pcVar11->name = name_01;
      pcVar11->next = (c1_symbol *)0x0;
    }
  }
  pcVar11->type = name;
  if (ambiguous != '\0') {
    pcVar11->flags3 = pcVar11->flags3 | 4;
  }
  return pcVar11;
}

