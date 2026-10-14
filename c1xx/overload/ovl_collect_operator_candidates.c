c1_ovl_resolution * __thiscall
ovl_collect_operator_candidates
          (c1_ovl_resolution *res,int op,c1_node *left,c1_node *right,c1_type *left_type)

{
  c1_u32 cls;
  bool bVar1;
  c1_scope_stack *pcVar2;
  c1_node *pcVar3;
  c1_type *pcVar4;
  byte bVar5;
  char cVar6;
  c1_builtin_operator_row *rows;
  c1_lookup_entry *pcVar7;
  int iVar8;
  c1_vector *pcVar9;
  fe_name *name;
  byte bVar10;
  c1_symbol *cls_00;
  c1_deferred_action *pcVar11;
  c1_symbol *local_20;
  c1_symbol *local_1c;
  c1_symbol *local_18;
  c1_symbol *local_14;
  c1_symbol_vector_iter local_c;
  
  pcVar3 = right;
  bVar10 = (byte)op;
  ovl_resolution_init(res,(c1_symbol *)0x0,(right != (c1_node *)0x0) + 1,bVar10,3);
  res->args = left;
  (res->extra).right = pcVar3;
  local_18 = (c1_symbol *)0x0;
  bVar1 = false;
  local_20 = (c1_symbol *)0x0;
  local_14 = (c1_symbol *)0x0;
  local_1c = (c1_symbol *)0x0;
  rows = ovl_builtin_candidates_for_operator(bVar10);
  if (rows == (c1_builtin_operator_row *)0x0) {
    name = name_intern_operator(bVar10);
  }
  else {
    name = rows->name;
  }
  pcVar4 = left_type;
  bVar10 = (byte)(name->flags >> 0x1b) & 1;
  if ((((char)op == '4') || ((char)op == 'S')) || ((char)op == 'A')) {
    bVar1 = true;
    if ((left_type != (c1_type *)0x0) &&
       (((left_type->code & 0x200) == 0 || ((left_type->extra).cls == (c1_symbol *)0x0)))) {
      res->failed = '\x01';
      return res;
    }
LAB_1041612f:
    left_type = (c1_type *)0x0;
  }
  else {
    pcVar7 = lookup_name_in_context(g_current_scope,name,0xc10);
    if (pcVar7 == (c1_lookup_entry *)0x0) {
      left_type = (c1_type *)0x0;
    }
    else {
      left_type = (c1_type *)pcVar7->sym;
    }
    if ((c1_symbol *)left_type != (c1_symbol *)0x0) {
      bVar5 = ((c1_symbol *)left_type)->kind & 0x1f;
      if ((((bVar5 != 7) && (bVar5 != 6)) &&
          ((bVar5 != 0x1a ||
           (iVar8 = sym_is_kind_6_7_through_alias(*(c1_symbol **)((c1_symbol *)left_type)->type),
           (char)iVar8 == '\0')))) &&
         ((bVar5 = (byte)left_type->code & 0x1f, bVar5 != 0x10 && (bVar5 != 0x1b))))
      goto LAB_1041612f;
      if (bVar10 != 0) {
        ovl_add_deduced_template_candidates(res,(c1_symbol *)left_type);
      }
      iVar8 = ovl_count_nontemplate_functions((c1_symbol *)left_type);
      res->count = res->count + iVar8;
    }
  }
  if (pcVar4 == (c1_type *)0x0) {
    if (bVar1) goto LAB_1041600b;
  }
  else {
    if ((pcVar4->code & 0x300) == 0) {
      if (((char)pcVar4->code < '\0') && ((pcVar4->base->code & 0x300) != 0)) {
        cls_00 = (pcVar4->base->extra).cls;
      }
      else {
        cls_00 = (c1_symbol *)0x0;
      }
    }
    else {
      cls_00 = (pcVar4->extra).cls;
    }
    local_18 = class_lookup_member_set(g_current_scope,cls_00,name,2,0);
    if (local_18 != (c1_symbol *)0x0) {
      local_20 = *(c1_symbol **)(*(int *)local_18->type + 8);
      bVar5 = local_20->kind & 0x1f;
      if ((bVar5 == 8) ||
         (((bVar5 == 0x1a &&
           (iVar8 = sym_is_member_function_via_alias(*(c1_symbol **)local_20->type),
           (char)iVar8 != '\0')) || ((local_20->kind & 0x1f) == 0x11)))) {
        if (bVar10 != 0) {
          ovl_add_deduced_template_candidates(res,local_20);
        }
        iVar8 = ovl_count_nontemplate_functions(local_20);
        res->count = res->count + iVar8;
      }
      else {
        local_20 = (c1_symbol *)0x0;
      }
    }
    if (bVar1) goto LAB_1041600b;
    pcVar9 = (c1_vector *)lookup_adl_class_and_bases((int)cls_00,(int)name,0);
    if ((pcVar9 != (c1_vector *)0x0) &&
       (local_14 = lookup_adl_result_symbol(pcVar9), local_14 != (c1_symbol *)0x0)) {
      if (bVar10 != 0) {
        ovl_add_deduced_template_candidates(res,local_14);
      }
      iVar8 = ovl_count_nontemplate_functions(local_14);
      res->count = res->count + iVar8;
    }
  }
  if (((right != (c1_node *)0x0) && ((right->type->code & 0x200) != 0)) &&
     ((cls = (right->type->extra).count, cls != 0 &&
      ((pcVar9 = (c1_vector *)lookup_adl_class_and_bases(cls,(int)name,0),
       pcVar9 != (c1_vector *)0x0 &&
       (local_1c = lookup_adl_result_symbol(pcVar9), local_1c != (c1_symbol *)0x0)))))) {
    if (bVar10 != 0) {
      ovl_add_deduced_template_candidates(res,local_1c);
    }
    iVar8 = ovl_count_nontemplate_functions(local_1c);
    res->count = res->count + iVar8;
  }
  pcVar2 = g_current_scope;
  if (g_current_scope->visited_namespaces != (c1_symbol_vector *)0x0) {
    vector_release((int)g_current_scope->visited_namespaces);
  }
  pcVar2->visited_namespaces = (c1_symbol_vector *)0x0;
LAB_1041600b:
  if ((((char)op == '7') || ((char)op == 'S')) || (((char)op == '1' && (right == (c1_node *)0x0))))
  {
    iVar8 = 0;
  }
  else {
    iVar8 = ovl_count_builtin_operator_candidates((char *)rows,left,right);
    res->count = res->count + iVar8;
  }
  if (res->specializations != (c1_symbol_vector *)0x0) {
    vector_iterator_init(&local_c,res->specializations);
    cVar6 = vector_iter_next((int *)&local_c);
    while (cVar6 != '\0') {
      res->count = res->count + 1;
      cVar6 = vector_iter_next((int *)&local_c);
    }
  }
  if (res->count == 0) {
    res->failed = '\x01';
    if (g_deferred_actions_head != (c1_deferred_action *)0x0) {
      pcVar11 = g_deferred_actions_head;
      if (g_tmpl_deduction_depth < 1) {
        do {
          (**pcVar11->vtbl)();
          pcVar11 = pcVar11->next;
        } while (pcVar11 != (c1_deferred_action *)0x0);
      }
      g_deferred_actions_tail = (c1_deferred_action *)0x0;
      g_deferred_actions_head = (c1_deferred_action *)0x0;
      return res;
    }
  }
  else {
    ovl_candidates_alloc(res);
    if (local_20 != (c1_symbol *)0x0) {
      ovl_add_candidates(res,local_20,local_18);
    }
    if (!bVar1) {
      if (left_type != (c1_type *)0x0) {
        ovl_add_candidates(res,(c1_symbol *)left_type,(c1_symbol *)0x0);
      }
      if (local_14 != (c1_symbol *)0x0) {
        ovl_add_candidates(res,local_14,(c1_symbol *)0x0);
      }
      if (local_1c != (c1_symbol *)0x0) {
        ovl_add_candidates(res,local_1c,(c1_symbol *)0x0);
      }
    }
    if (res->specializations != (c1_symbol_vector *)0x0) {
      ovl_add_deduced_specializations(res);
      vector_release((int)res->specializations);
    }
    if (iVar8 != 0) {
      op = 0;
      ovl_add_builtin_operator_candidates(res,(char *)rows,left,right,&op);
      iVar8 = res->count + (op - iVar8);
      res->count = iVar8;
      if (iVar8 == 0) {
        g_deferred_actions_tail = (c1_deferred_action *)0x0;
        g_deferred_actions_head = (c1_deferred_action *)0x0;
        res->failed = '\x01';
        return res;
      }
    }
    res->live = res->count;
    res->head = res->candidates;
    g_deferred_actions_tail = (c1_deferred_action *)0x0;
    g_deferred_actions_head = (c1_deferred_action *)0x0;
  }
  return res;
}

