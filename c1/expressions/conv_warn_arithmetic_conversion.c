void __cdecl conv_warn_arithmetic_conversion(c1_u8 op,c1_node *node,c1_type *type)

{
  ushort uVar1;
  ushort uVar2;
  c1_type *type_00;
  uint op_00;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  void *lo;
  void *hi;
  
  if (g_warning_state->level < 2) {
    return;
  }
  uVar1 = type->code;
  if ((uVar1 & 0x30) == 0) {
    return;
  }
  op_00 = (uint)op;
  switch(op_00) {
  case 0x34:
  case 0x3a:
  case 0x47:
  case 0x4b:
  case 0x52:
  case 0x70:
  case 0x74:
  case 0x7d:
    break;
  default:
    return;
  }
  if (node == (c1_node *)0x0) {
    return;
  }
  type_00 = node->type;
  uVar2 = type_00->code;
  if ((uVar2 & 0x30) == 0) {
    return;
  }
  if (((byte)uVar2 >> 5 & 1) == 0) {
    if (((byte)uVar1 >> 5 & 1) == 0) {
      if ((node->kind & 7) == 3) {
        lo = node->left;
        hi = node->right;
        if ((uVar1 & 0x2000) == 0) {
          if (g_ms_extensions == '\0') {
            conv_warn_constant_conversion
                      (CONCAT22((short)((uint)type_00 >> 0x10),uVar2),
                       CONCAT22((short)((uint)g_warning_state >> 0x10),uVar1),'\0',(uint)lo,(uint)hi
                       ,type,op_00,type_00);
            return;
          }
        }
        else if ((((uVar2 & 0x2000) == 0) &&
                 ((((g_ms_extensions != '\0' || ((uVar2 & 0xfff) != 0x11)) ||
                   ((uVar2 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0')))) &&
                (((int)hi < 1 && ((int)hi < 0)))) {
          diag_warning(4,0xf5,op_00,type_00,type);
        }
        uVar1 = type->code;
        uVar2 = type_00->code;
        if (uVar1 == uVar2) {
          return;
        }
        if ((uVar2 & 0x2000) == 0) {
          if (((g_ms_extensions == '\0') && ((uVar2 & 0xfff) == 0x11)) &&
             (((uVar2 & 0x1000) == 0 && (g_opt_J_unsigned_char != '\0')))) {
            conv_warn_arithmetic_conversion_fragment
                      (uVar1,'\0',(uint)lo,(uint)hi,type,op_00,type_00);
            return;
          }
          iVar7 = 0;
        }
        else {
          iVar7 = 1;
        }
        if (((uVar1 & 0x2000) == 0) &&
           ((((g_ms_extensions != '\0' || ((uVar1 & 0xfff) != 0x11)) || ((uVar1 & 0x1000) != 0)) ||
            (g_opt_J_unsigned_char == '\0')))) {
          iVar4 = 0;
        }
        else {
          iVar4 = 1;
        }
        uVar5 = type_size_scalar(type);
        iVar7 = conv_constant_out_of_range(uVar5,iVar4,iVar7,(uint)lo,(uint)hi);
        if (iVar7 == 0) {
          return;
        }
        diag_warning(2,0x131,op_00,type_00,type);
        return;
      }
      uVar5 = type_size_scalar(type_00);
      uVar6 = type_size_scalar(type);
      if (uVar5 <= uVar6) {
        return;
      }
      if ((((type_00->code & 0x110) != 0) && ((node->op == 'p' || (node->op == '=')))) &&
         (bVar3 = diag_warning(3,0xf2,op_00,type_00,type), bVar3 != 0)) {
        conv_warn_arithmetic_conversion_fragment_2();
        return;
      }
      if ((((byte)type_00->code & 0x1f) == 0x13) || (iVar7 = 3, (type_00->code & 0x100) != 0)) {
        iVar7 = 4;
      }
      goto LAB_1061bc2e;
    }
    uVar5 = type_size_scalar(type_00);
    uVar6 = type_size_scalar(type);
    if (uVar5 < uVar6) {
      return;
    }
    if ((node->kind & 7) == 3) {
      conv_warn_float_truncation_1(op,node,type,(uint *)0x0,'\x01');
      return;
    }
  }
  else if (((byte)uVar1 >> 4 & 1) == 0) {
    if ((node->kind & 7) == 3) {
      conv_warn_float_truncation_2(op,node,type);
      return;
    }
    uVar5 = type_size_scalar(type_00);
    uVar6 = type_size_scalar(type);
    if (uVar6 < uVar5) {
      iVar7 = 3;
    }
    else {
      iVar7 = type_size_scalar(type_00);
      iVar4 = type_size_scalar(type);
      if (iVar4 != iVar7) {
        return;
      }
      if ((type_00->code & 0x28) != 0x28) {
        return;
      }
      if ((type->code & 0x28) == 0x28) {
        return;
      }
      iVar7 = 4;
    }
    goto LAB_1061bc2e;
  }
  iVar7 = 2;
LAB_1061bc2e:
  diag_warning(iVar7,0xf4,op_00,type_00,type);
  return;
}

