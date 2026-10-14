c1_node * __cdecl expr_build_cast(c1_u8 op,c1_type *type,c1_node *node)

{
  c1_type *type_00;
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  c1_node *pcVar4;
  int iVar5;
  ushort uVar6;
  
  bVar1 = (byte)type->code;
  if ((bVar1 & 0x83) == 0x81) {
    diag_error(0x42);
    return (c1_node *)0x0;
  }
  if ((bVar1 & 0x8f) == 0x83) {
    diag_error(0x43);
    return (c1_node *)0x0;
  }
  type_00 = node->type;
  uVar3 = conv_classify_cast(type,node,0);
  if (uVar3 < 0x400) {
    pcVar4 = conv_convert_to_type(op,type,node);
    return pcVar4;
  }
  if ((uVar3 & 0x1000) == 0) {
    if (type != g_type_void) {
      uVar6 = type_00->code;
      if (((byte)uVar6 >> 6 & 1) != 0) {
        diag_error(0x45);
        pcVar4 = conv_convert_basic(op,type,node);
        return pcVar4;
      }
      uVar2 = type->code;
      bVar1 = (byte)uVar2;
      if ((char)(byte)uVar6 < '\0') {
        if ((char)bVar1 < '\0') {
          uVar6 = uVar6 & 0x8f;
          if (uVar6 == 0x86) {
            if ((short)(uVar2 & 0x8f) != 0x86) {
              pcVar4 = conv_warn_function_to_data_pointer(uVar2 & 0x8f,node,type,op);
              return pcVar4;
            }
          }
          else if ((uVar6 == 0x82) || (uVar6 == 0x83)) {
            uVar2 = uVar2 & 0x8f;
            if (uVar2 == 0x86) {
              if (g_ms_extensions == '\0') {
                diag_warning(1,0x37,op,type_00,type);
                pcVar4 = conv_convert_basic(op,type,node);
                return pcVar4;
              }
              diag_warning(4,0x37,op,type_00,type);
              pcVar4 = conv_convert_basic(op,type,node);
              return pcVar4;
            }
            if ((((uVar2 == 0x82) || (uVar2 == 0x83)) && ((type->flags & 0x18) == 0x18)) &&
               ((node->kind & 7) == 5)) {
              diag_warning(1,0x78);
              pcVar4 = conv_convert_basic(op,type,node);
              return pcVar4;
            }
          }
        }
        else {
          if ((bVar1 >> 4 & 1) == 0) {
            diag_error(0x1b8,op,type_00,type);
          }
          iVar5 = type_size_scalar(type);
          if (iVar5 < 4) {
            diag_warning(4,0x131,op,type_00,type);
            pcVar4 = conv_convert_basic(op,type,node);
            return pcVar4;
          }
        }
      }
      else if ((char)bVar1 < '\0') {
        if ((uVar6 & 0x110) == 0) {
          diag_error(0x1b8,op,type_00,type);
          return (c1_node *)0x0;
        }
        iVar5 = type_size_scalar(type_00);
        if (4 < iVar5) {
          diag_warning(4,0x131,op,type_00,type);
          pcVar4 = conv_convert_basic(op,type,node);
          return pcVar4;
        }
        iVar5 = type_size_scalar(type_00);
        if (iVar5 < 4) {
          pcVar4 = conv_warn_greater_size(node,type,op);
          return pcVar4;
        }
      }
      else if (((uVar2 & 0x200) != 0) || ((uVar6 & 0x200) != 0)) {
        diag_error(0x1b8,op,type_00,type);
        return (c1_node *)0x0;
      }
    }
    pcVar4 = conv_convert_basic(op,type,node);
    return pcVar4;
  }
  diag_error(0x249,type);
  return (c1_node *)0x0;
}

