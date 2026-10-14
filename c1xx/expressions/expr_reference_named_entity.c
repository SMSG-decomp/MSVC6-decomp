c1_node * __cdecl expr_reference_named_entity(c1_symbol *sym,int in_class_scope)

{
  char cVar1;
  c1_node *pcVar2;
  int iVar3;
  c1_type *pcVar4;
  c1_symbol *pcVar5;
  c1_symbol *pcVar6;
  c1_node *obj;
  byte bVar7;
  c1_type local_10;
  
  cVar1 = (char)in_class_scope;
  while( true ) {
    pcVar6 = sym;
    pcVar5 = (c1_symbol *)0x0;
    if ((sym->kind & 0x1f) == 0x12) {
      if (sym->type == (c1_type *)0x0) {
        return (c1_node *)0x0;
      }
      pcVar6 = *(c1_symbol **)(*(int *)sym->type + 8);
      pcVar5 = sym;
    }
    if ((pcVar6->kind & 0x1f) == 0x1a) {
      pcVar6 = *(c1_symbol **)pcVar6->type;
    }
    bVar7 = pcVar6->kind & 0x1f;
    if (bVar7 == 0x19) {
      diag_error(0x372,pcVar6);
      return (c1_node *)0x0;
    }
    if (bVar7 == 0x17) {
      pcVar2 = (pcVar6->tail).tparam_value;
      if (pcVar2->op == '\x06') {
        return pcVar2;
      }
      if (pcVar2->op == 'd') {
        pcVar2 = expr_check_namespace_in_expression_2
                           (0x17,pcVar2,cVar1,pcVar5,pcVar6,sym,in_class_scope);
        return pcVar2;
      }
    }
    if (bVar7 == 5) {
      if (g_current_scope->qualified != '\0') {
        pcVar2 = tree_new_symbol_ref(sym,'\0');
        return pcVar2;
      }
      access_check_member(pcVar5);
      if ((sym->flags1 & 0x80) == 0) {
        pcVar2 = tree_new_value_constant(pcVar6);
        return pcVar2;
      }
      pcVar2 = expr_check_member_reference_context(sym,&pcVar6->kind);
      return pcVar2;
    }
    if ((((bVar7 == 0x10) || (bVar7 == 7)) || (bVar7 == 6)) || (bVar7 == 0x1b)) {
      pcVar2 = tree_new_symbol_ref(pcVar6,'\0');
      return pcVar2;
    }
    if (((bVar7 != 2) && (bVar7 != 3)) && (((bVar7 != 0x11 && (bVar7 != 8)) || (cVar1 != '\0')))) {
      if ((pcVar6->flags2 & 0x10) != 0) {
        pcVar2 = tree_new_symbol_ref(sym,'\0');
        return pcVar2;
      }
      if (((pcVar6->kind & 0x1f) == 10) && ((pcVar6->flags5 & 0x10) != 0)) {
        pcVar5 = sym_lookup_pair_local_then_global(pcVar6,(uint *)&in_class_scope);
        cVar1 = decl_check_default_argument_expression(pcVar6);
        if (cVar1 == '\0') {
          return (c1_node *)0x0;
        }
        pcVar6 = class_lookup_member_set
                           (g_current_scope,(pcVar5->type->extra).cls,*(void **)(in_class_scope + 8)
                            ,2,0);
        pcVar2 = tree_new_symbol_ref(pcVar6,'\0');
        obj = expr_reference_named_entity(pcVar5,0);
        pcVar2 = expr_build_member_access('P',obj,pcVar2);
        return pcVar2;
      }
      cVar1 = decl_check_default_argument_expression(pcVar6);
      if (cVar1 == '\0') {
        return (c1_node *)0x0;
      }
      bVar7 = pcVar6->kind & 0x1f;
      if (((bVar7 == 7) || (bVar7 == 8)) || (bVar7 == 6)) {
        cVar1 = '\x01';
      }
      else {
        cVar1 = '\0';
      }
      pcVar2 = tree_new_symbol_ref(pcVar6,cVar1);
      if (pcVar2 == (c1_node *)0x0) {
        return (c1_node *)0x0;
      }
      bVar7 = pcVar6->kind & 0x1f;
      if (((bVar7 == 7) || (bVar7 == 8)) || (bVar7 == 6)) {
        local_10.base = pcVar6->type;
        local_10.debug_index = 0;
        local_10.extra.cls = (c1_symbol *)0x0;
        local_10.flags = (byte)(local_10.base)->flags & 0x1f;
        local_10.code = 0x4086;
        pcVar4 = type_intern(&local_10);
        pcVar2->type = pcVar4;
        return pcVar2;
      }
      if ((((pcVar6->flags5 & 4) != 0) && (bVar7 != 0xb)) && (bVar7 != 0xc)) {
        return pcVar2;
      }
      if (pcVar2->op != 0x98) {
        pcVar2 = expr_member_value(pcVar6,pcVar2);
        return pcVar2;
      }
      return pcVar2;
    }
    if (g_current_scope->qualified != '\0') goto LAB_10411d78;
    iVar3 = sym_is_static_data_member(pcVar6);
    if (iVar3 == 0) break;
    access_check_member(pcVar5);
    pcVar5 = *(c1_symbol **)(**(int **)pcVar5->type + 8);
    if ((pcVar5->kind & 0x1f) == 0xf) {
      pcVar5 = g_scope_vector->entries[(short)pcVar5->key_ref];
    }
    if ((((pcVar6->flags2 & 4) == 0) && ((((pcVar5->detail).cls)->flags3e & 1) != 0)) &&
       ((((pcVar5->detail).cls)->flags3f & 1) == 0)) {
      tmpl_work_queue_add(pcVar5,(int *)0x0);
    }
    cVar1 = '\0';
    sym = sym_static_member_stand_in(pcVar6);
  }
  cVar1 = decl_check_default_argument_expression(pcVar6);
  if (cVar1 == '\0') {
    return (c1_node *)0x0;
  }
  if (((sym->flags1 & 0x80) != 0) && ((pcVar6->flags1 & 0x10) != 0x10)) {
    pcVar2 = expr_check_member_reference_context(sym,&pcVar6->kind);
    return pcVar2;
  }
  if ((sym->kind & 0x1f) != 0x12) {
    pcVar2 = expr_resolve_member_or_overload_fragment();
    return pcVar2;
  }
LAB_10411d78:
  pcVar2 = tree_new_symbol_ref(sym,'\0');
  return pcVar2;
}

