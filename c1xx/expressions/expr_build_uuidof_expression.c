c1_node * __cdecl expr_build_uuidof_expression(c1_node *operand)

{
  byte bVar1;
  char cVar2;
  c1_u16 cVar3;
  c1_node *pcVar4;
  c1_node *pcVar5;
  c1_type *pcVar6;
  
  pcVar4 = expr_resolve_address_of_overload(operand);
  if ((pcVar4 != (c1_node *)0x0) && (bVar1 = pcVar4->kind, (bVar1 & 8) == 0)) {
    if (((bVar1 & 7) == 3) && (pcVar4->op == 'e')) {
      pcVar6 = pcVar4->type;
      cVar2 = (char)pcVar6->code;
      while (cVar2 < '\0') {
        pcVar6 = pcVar6->base;
        cVar2 = (char)pcVar6->code;
      }
      if (((pcVar6->code & 0x10) != 0) && ((bVar1 & 0x80) != 0)) {
        pcVar4 = expr_build_uuidof_null();
        return pcVar4;
      }
    }
    pcVar6 = pcVar4->type;
    cVar3 = pcVar6->code;
    if ((cVar3 != 0x80c) && (cVar3 != 0x80e)) {
      if (((byte)cVar3 & 0x8f) == 0x83) {
        pcVar6 = conv_array_to_pointer_type(pcVar4);
      }
      pcVar4 = expr_build_uuidof(pcVar6);
      return pcVar4;
    }
    pcVar5 = expr_resolve_function_address((c1_type *)0x0,pcVar4);
    if (pcVar5 != (c1_node *)0x0) {
      pcVar4 = expr_build_uuidof(pcVar5->type);
      return pcVar4;
    }
    expr_report_function_operand(0xe9,pcVar4);
  }
  return (c1_node *)0x0;
}

