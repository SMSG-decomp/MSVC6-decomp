c1_node * __cdecl
expr_check_namespace_in_expression_2
          (byte kind,c1_node *bound,char in_class,c1_symbol *ovl_set,c1_symbol *target,
          c1_symbol *sym,int in_class_scope)

{
  char cVar1;
  byte bVar2;
  c1_node *pcVar3;
  int iVar4;
  c1_type *pcVar5;
  c1_symbol *pcVar6;
  c1_symbol *sym_00;
  c1_node *obj;
  c1_u16 cStack00000010;
  ushort uStack00000012;
  c1_type *pcStack00000014;
  c1_type_extra cStack00000018;
  c1_u32 cStack0000001c;
  
  if (*(char *)bound->left != '\x06') {
    while( true ) {
      if (kind == 5) {
        if (g_current_scope->qualified != '\0') {
          pcVar3 = tree_new_symbol_ref(sym,'\0');
          return pcVar3;
        }
        access_check_member(ovl_set);
        if ((sym->flags1 & 0x80) == 0) {
          pcVar3 = tree_new_value_constant(target);
          return pcVar3;
        }
        pcVar3 = expr_check_member_reference_context(sym,&target->kind);
        return pcVar3;
      }
      if ((((kind == 0x10) || (kind == 7)) || (kind == 6)) || (kind == 0x1b)) break;
      if (((kind != 2) && (kind != 3)) && (((kind != 0x11 && (kind != 8)) || (in_class != '\0')))) {
        if ((target->flags2 & 0x10) != 0) {
          pcVar3 = tree_new_symbol_ref(sym,'\0');
          return pcVar3;
        }
        if (((target->kind & 0x1f) == 10) && ((target->flags5 & 0x10) != 0)) {
          pcVar6 = sym_lookup_pair_local_then_global(target,(uint *)&in_class_scope);
          cVar1 = decl_check_default_argument_expression(target);
          if (cVar1 == '\0') {
            return (c1_node *)0x0;
          }
          sym_00 = class_lookup_member_set
                             (g_current_scope,(pcVar6->type->extra).cls,
                              *(void **)(in_class_scope + 8),2,0);
          pcVar3 = tree_new_symbol_ref(sym_00,'\0');
          obj = expr_reference_named_entity(pcVar6,0);
          pcVar3 = expr_build_member_access('P',obj,pcVar3);
          return pcVar3;
        }
        cVar1 = decl_check_default_argument_expression(target);
        if (cVar1 == '\0') {
          return (c1_node *)0x0;
        }
        bVar2 = target->kind & 0x1f;
        if (((bVar2 == 7) || (bVar2 == 8)) || (bVar2 == 6)) {
          cVar1 = '\x01';
        }
        else {
          cVar1 = '\0';
        }
        pcVar3 = tree_new_symbol_ref(target,cVar1);
        if (pcVar3 == (c1_node *)0x0) {
          return (c1_node *)0x0;
        }
        bVar2 = target->kind & 0x1f;
        if (((bVar2 == 7) || (bVar2 == 8)) || (bVar2 == 6)) {
          pcStack00000014 = target->type;
          cStack0000001c = 0;
          cStack00000018.cls = (c1_symbol *)0x0;
          uStack00000012 = (byte)pcStack00000014->flags & 0x1f;
          cStack00000010 = 0x4086;
          pcVar5 = type_intern((c1_type *)&stack0x00000010);
          pcVar3->type = pcVar5;
          return pcVar3;
        }
        if ((((target->flags5 & 4) != 0) && (bVar2 != 0xb)) && (bVar2 != 0xc)) {
          return pcVar3;
        }
        if (pcVar3->op != 0x98) {
          pcVar3 = expr_member_value(target,pcVar3);
          return pcVar3;
        }
        return pcVar3;
      }
      if (g_current_scope->qualified != '\0') {
LAB_10411d78:
        pcVar3 = tree_new_symbol_ref(sym,'\0');
        return pcVar3;
      }
      iVar4 = sym_is_static_data_member(target);
      if (iVar4 == 0) {
        cVar1 = decl_check_default_argument_expression(target);
        if (cVar1 == '\0') {
          return (c1_node *)0x0;
        }
        if (((sym->flags1 & 0x80) != 0) && ((target->flags1 & 0x10) != 0x10)) {
          pcVar3 = expr_check_member_reference_context(sym,&target->kind);
          return pcVar3;
        }
        if ((sym->kind & 0x1f) != 0x12) {
          pcVar3 = expr_resolve_member_or_overload_fragment();
          return pcVar3;
        }
        goto LAB_10411d78;
      }
      access_check_member(ovl_set);
      pcVar6 = *(c1_symbol **)(**(int **)ovl_set->type + 8);
      if ((pcVar6->kind & 0x1f) == 0xf) {
        pcVar6 = g_scope_vector->entries[(short)pcVar6->key_ref];
      }
      if ((((target->flags2 & 4) == 0) && ((((pcVar6->detail).cls)->flags3e & 1) != 0)) &&
         ((((pcVar6->detail).cls)->flags3f & 1) == 0)) {
        tmpl_work_queue_add(pcVar6,(int *)0x0);
      }
      in_class = '\0';
      sym = sym_static_member_stand_in(target);
      target = sym;
      ovl_set = (c1_symbol *)0x0;
      if ((sym->kind & 0x1f) == 0x12) {
        if (sym->type == (c1_type *)0x0) {
          return (c1_node *)0x0;
        }
        target = *(c1_symbol **)(*(int *)sym->type + 8);
        ovl_set = sym;
      }
      if ((target->kind & 0x1f) == 0x1a) {
        target = *(c1_symbol **)target->type;
      }
      kind = target->kind & 0x1f;
      if (kind == 0x19) {
        diag_error(0x372,target);
        return (c1_node *)0x0;
      }
      if (kind == 0x17) {
        pcVar3 = (target->tail).tparam_value;
        if (pcVar3->op == '\x06') {
          return pcVar3;
        }
        if (pcVar3->op == 'd') {
          pcVar3 = expr_check_namespace_in_expression_2
                             (0x17,pcVar3,'\0',ovl_set,target,sym,in_class_scope);
          return pcVar3;
        }
      }
    }
    bound = tree_new_symbol_ref(target,'\0');
  }
  return bound;
}

