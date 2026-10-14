c1_node * __cdecl expr_build_typeid_expression(c1_node *operand)

{
  c1_u16 cVar1;
  c1_symbol *cls;
  c1_u8 cVar2;
  c1_node *pcVar3;
  c1_node *pcVar4;
  c1_type *type;
  uint uVar5;
  c1_type **ppcVar6;
  
  pcVar3 = expr_resolve_address_of_overload(operand);
  if ((pcVar3 == (c1_node *)0x0) || ((pcVar3->kind & 8) != 0)) {
    return (c1_node *)0x0;
  }
  type = pcVar3->type;
  ppcVar6 = &pcVar3->type;
  cVar1 = type->code;
  if ((cVar1 == 0x80c) || (cVar1 == 0x80e)) {
    pcVar4 = expr_resolve_function_address((c1_type *)0x0,pcVar3);
    if (pcVar4 == (c1_node *)0x0) {
      expr_report_function_operand('y',pcVar3);
      pcVar3 = expr_build_static_typeid(g_type_int);
      return pcVar3;
    }
    type = pcVar4->type;
    ppcVar6 = &pcVar4->type;
    pcVar3 = pcVar4;
  }
  else if (((byte)cVar1 & 0x8f) == 0x83) {
    type = conv_array_to_pointer_type(pcVar3);
  }
  if ((type->code & 0x200) == 0) goto LAB_10473bab;
  cls = (type->extra).cls;
  cVar2 = class_is_polymorphic(cls);
  if (cVar2 == '\0') goto LAB_10473bab;
  cVar2 = pcVar3->op;
  pcVar4 = pcVar3;
  while (cVar2 == '7') {
    pcVar4 = pcVar4->right;
    cVar2 = pcVar4->op;
  }
  if (cVar2 == '=') {
    pcVar4 = pcVar4->left;
    cVar2 = pcVar4->op;
    if ((cVar2 == '\x06') || (cVar2 == 0x9c)) goto LAB_10473bab;
    if (cVar2 == 'A') goto LAB_10473be0;
  }
  else {
    if (cVar2 != 'A') goto LAB_10473bab;
LAB_10473be0:
    pcVar4 = pcVar4->left;
  }
  if ((pcVar4 != (c1_node *)0x0) &&
     (uVar5 = type_classify_class_form(*ppcVar6,(int *)&operand), (uVar5 & 3) != 0)) {
    pcVar3 = expr_warn_rtti_disabled(pcVar3,cls);
    return pcVar3;
  }
LAB_10473bab:
  pcVar3 = expr_build_static_typeid(type);
  return pcVar3;
}

