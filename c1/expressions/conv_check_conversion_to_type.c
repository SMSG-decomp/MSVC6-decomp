int __cdecl conv_check_conversion_to_type(c1_u8 op,c1_type *type,c1_node *node)

{
  char cVar1;
  c1_type *pcVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  
  if (((node->kind & 0x80) != 0) &&
     (((uVar3 = type->code & 0x8f, uVar3 == 0x83 || (uVar3 == 0x82)) || (uVar3 == 0x86)))) {
    return 1;
  }
  iVar4 = type_check_compatible(op,type,node->type);
  uVar3 = type->code;
  if ((char)uVar3 < '\0') {
    return iVar4;
  }
  pcVar2 = node->type;
  if ((char)pcVar2->code < '\0') {
    return iVar4;
  }
  cVar1 = (char)pcVar2->code;
  while (cVar1 < '\0') {
    pcVar2 = pcVar2->base;
    cVar1 = (char)pcVar2->code;
  }
  iVar5 = (((byte)pcVar2->code & 0x40) >> 6) + ((uVar3 & 0x40) >> 6);
  if (op == '6') {
    if (iVar5 == 1) {
      diag_warning(4,0x35);
      conv_warn_arithmetic_conversion('6',node,type);
      return iVar4;
    }
  }
  else {
    if (iVar5 == 1) {
      if (op == '}') {
        if ((uVar3 & 0x40) != 0) {
          if (g_ms_extensions == '\0') {
            diag_error(0x232,g_current_function);
            conv_warn_arithmetic_conversion('}',node,type);
            return iVar4;
          }
          diag_warning(1,0x62,g_current_function);
          conv_warn_arithmetic_conversion('}',node,type);
          return iVar4;
        }
        if (g_ms_extensions != '\0') {
          diag_warning(1,0x46);
          conv_warn_arithmetic_conversion('}',node,type);
          return iVar4;
        }
        if ((g_current_function->flags22 & 1) == 0) {
          diag_error(0x231,g_current_function);
          conv_warn_arithmetic_conversion('}',node,type);
          return iVar4;
        }
        goto LAB_1061a90e;
      }
    }
    else if (iVar5 != 2) {
      conv_warn_arithmetic_conversion(op,node,type);
      return iVar4;
    }
    diag_error(0x78);
  }
LAB_1061a90e:
  conv_warn_arithmetic_conversion(op,node,type);
  return iVar4;
}

