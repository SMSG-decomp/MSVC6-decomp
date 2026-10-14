char __thiscall
conv_function_cast_is_unsafe(c1_conversion *conv,c1_type *from,c1_type *to,char strict)

{
  c1_type_list *to_params;
  c1_type_list *from_params;
  char cVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  c1_type *to_00;
  c1_type *from_00;
  c1_symbol *cls;
  c1_symbol *cls_00;
  c1_type **ppcVar7;
  c1_type **ppcVar8;
  
  iVar3 = type_category(from);
  iVar4 = type_category(to);
  if (iVar3 != 1) {
    while (iVar4 != 1) {
      if (strict != '\0') {
        iVar5 = type_size(from);
        iVar6 = type_size(to);
        if (iVar5 != iVar6) {
          return '\x01';
        }
      }
      if (iVar3 == iVar4) {
        switch(iVar3) {
        case 0:
          if ((from->code == 0x80d) && (to->code == 0x80d)) {
            return '\0';
          }
        default:
          diag_fatal(1,".\\convert.cpp",0xc23);
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
          goto conv_function_cast_is_unsafe_return_false;
        case 0xb:
          if ((((byte)to->flags ^ (byte)from->flags) & 7) != 0) {
            return '\x01';
          }
          if (((from->code ^ to->code) & 0xe000) == 0) {
            cVar1 = '\x01';
            to_00 = type_function_return(to);
            from_00 = type_function_return(from);
            cVar1 = conv_function_cast_is_unsafe(conv,from_00,to_00,cVar1);
            if (cVar1 != '\0') {
              return '\x01';
            }
            to_params = ((to->extra).params)->list;
            from_params = ((from->extra).params)->list;
            iVar4 = from_params->count;
            if (iVar4 == to_params->count) {
              ppcVar7 = to_params->types;
              ppcVar8 = from_params->types;
              if (iVar4 < 1) {
                return '\0';
              }
              while (cVar1 = conv_function_cast_is_unsafe(conv,*ppcVar8,*ppcVar7,'\x01'),
                    cVar1 == '\0') {
                ppcVar8 = ppcVar8 + 1;
                ppcVar7 = ppcVar7 + 1;
                iVar4 = iVar4 + -1;
                if (iVar4 < 1) {
                  return '\0';
                }
              }
            }
            else if (((from->flags & 7) == 1) && (iVar4 <= to_params->count)) {
              cVar1 = conv_function_cast_is_unsafe_parameters(from_params,to_params,iVar4,conv);
              return cVar1;
            }
            return '\x01';
          }
          return '\x01';
        case 0xc:
        case 0xd:
          if (strict != '\0') {
            uVar2 = from->code & 0x8f;
            if ((uVar2 == 0x8a) || (uVar2 == 0x8e)) {
              cls_00 = (from->extra).cls;
            }
            else {
              cls_00 = (c1_symbol *)0x0;
            }
            uVar2 = to->code & 0x8f;
            if ((uVar2 == 0x8a) || (uVar2 == 0x8e)) {
              cls = (to->extra).cls;
            }
            else {
              cls = (c1_symbol *)0x0;
            }
            iVar4 = class_complete_for_use(cls);
            iVar3 = class_complete_for_use(cls_00);
            if (iVar3 != iVar4) {
              return '\x01';
            }
          }
        case 8:
        case 9:
        case 10:
        case 0xe:
        case 0xf:
          to = to->base;
          from = from->base;
        }
      }
      else {
        if (strict != '\0') {
          return '\x01';
        }
        if (iVar3 == 3) {
          return '\0';
        }
        if (iVar4 == 3) {
          return '\0';
        }
        if (iVar3 == 0xb) {
          return '\x01';
        }
        if (iVar4 == 0xb) {
          return '\x01';
        }
        cVar1 = (char)from->code;
        if ((-1 < cVar1) && (-1 < (char)to->code)) {
          return '\0';
        }
        if ((char)to->code < '\0') {
          to = to->base;
        }
        if (cVar1 < '\0') {
          from = from->base;
        }
      }
      strict = '\0';
      iVar3 = type_category(from);
      iVar4 = type_category(to);
      if (iVar3 == 1) {
        return '\0';
      }
    }
  }
conv_function_cast_is_unsafe_return_false:
  return '\0';
}

