c1_node * __cdecl expr_build_binary(c1_u8 op,c1_node *left,c1_node *right)

{
  c1_type *pcVar1;
  byte bVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  c1_node *pcVar6;
  c1_node *pcVar7;
  c1_node *pcVar8;
  c1_symbol *cls;
  
  pcVar7 = left;
  if ((left != (c1_node *)0x0) && (left->op == 0xe8)) {
    switch(op) {
    case '3':
    case '4':
    case '8':
    case ':':
    case '@':
    case 'B':
    case 'G':
    case 'I':
    case 'K':
    case 'N':
    case 'R':
    case 'T':
    case 'U':
    case 'W':
    case '\\':
      pcVar7 = property_build_access(op,left,right);
      return pcVar7;
    case 'A':
      pcVar7 = property_build_access(op,left,right);
      return pcVar7;
    }
    pcVar7 = property_build_access(op,left,(c1_node *)0x0);
    if (pcVar7 == (c1_node *)0x0) {
      return (c1_node *)0x0;
    }
  }
  pcVar6 = right;
  if (((right == (c1_node *)0x0) || (right->op != 0xe8)) ||
     (pcVar6 = property_build_access(op,right,(c1_node *)0x0), pcVar6 != (c1_node *)0x0)) {
    if ((pcVar7 == (c1_node *)0x0) || (pcVar6 == (c1_node *)0x0)) {
      if ((op != '2') && (op != 'O')) {
        return (c1_node *)0x0;
      }
      expr_count_evaluated_operator();
      return (c1_node *)0x0;
    }
    if (pcVar7->op == 0x98) {
      diag_error(0x113,pcVar7->left);
      return (c1_node *)0x0;
    }
    if (pcVar6->op == 0x98) {
      diag_error(0x113,pcVar6->left);
      return (c1_node *)0x0;
    }
    pcVar1 = pcVar7->type;
    iVar5 = type_is_class_or_enum(pcVar1);
    if ((((char)iVar5 == '\0') &&
        (iVar5 = type_is_template_type_parameter(pcVar1), (char)iVar5 == '\0')) &&
       ((pcVar1->code & 0xfff) != 0x802)) {
      bVar2 = (byte)pcVar1->code;
      if (((char)bVar2 < '\0') && ((bVar2 & 0x8f) == 0x80)) {
        cVar3 = type_is_class_or_template_parameter(pcVar1->base);
      }
      else {
        cVar3 = '\0';
      }
    }
    else {
      cVar3 = '\x01';
    }
    left = (c1_node *)CONCAT31(left._1_3_,cVar3);
    pcVar6 = fold_static_const_member(pcVar6);
    if (cVar3 == '\0') {
      if (pcVar6 == (c1_node *)0x0) goto LAB_10413c1c;
      pcVar1 = pcVar6->type;
      iVar5 = type_is_class_or_enum(pcVar1);
      if (((((char)iVar5 == '\0') &&
           (iVar5 = type_is_template_type_parameter(pcVar1), (char)iVar5 == '\0')) &&
          ((pcVar1->code & 0xfff) != 0x802)) &&
         (((bVar2 = (byte)pcVar1->code, -1 < (char)bVar2 || ((bVar2 & 0x8f) != 0x80)) ||
          (cVar4 = type_is_class_or_template_parameter(pcVar1->base), cVar4 == '\0'))))
      goto LAB_10413c1c;
    }
    right = (c1_node *)((uint)right & 0xffffff00);
    pcVar8 = expr_apply_overloaded_operator(op,pcVar7,pcVar6,(uint)left,1,(byte *)&right);
    if (pcVar8 != (c1_node *)0x0) {
      if (((op == '2') || (op == 'O')) &&
         ((g_tree_op_to_il_op[pcVar8->op] < 0x1b || (0x1c < g_tree_op_to_il_op[pcVar8->op])))) {
        expr_count_evaluated_operator();
      }
      return pcVar8;
    }
    if (((op != '4') || (cVar3 == '\0')) || (pcVar1 = pcVar7->type, (pcVar1->code & 0x100) != 0)) {
      if ((char)right != '\0') {
        pcVar7 = expr_build_binary_return_null();
        return pcVar7;
      }
LAB_10413c1c:
      if ((op == '2') || (op == 'O')) {
        pcVar6 = expr_full_expression_guarded(pcVar6,3);
      }
      pcVar7 = expr_build_builtin_binary(op,pcVar7,pcVar6);
      return pcVar7;
    }
    if ((pcVar1->code & 0x200) == 0) {
      cls = (c1_symbol *)0x0;
    }
    else {
      cls = (pcVar1->extra).cls;
    }
    if ((cls->flags2 & 4) == 0) {
      tmpl_instantiate_if_needed(cls);
    }
    if (((((cls->detail).cls)->implicit_state41 & 8) == 0) &&
       ((((cls->detail).cls)->implicit_state43 & 8) == 0)) {
      diag_error(0x246,cls);
      return (c1_node *)0x0;
    }
  }
  return (c1_node *)0x0;
}

