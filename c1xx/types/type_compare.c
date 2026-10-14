char __thiscall type_compare(c1_type *a,c1_type *b,uint flags)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  c1_type *pcVar5;
  c1_type *pcVar6;
  void *pvVar7;
  void *pvVar8;
  c1_symbol_vector *pcVar9;
  c1_symbol *pcVar10;
  uint flags_00;
  c1_symbol *pcVar11;
  
  if (a != b) {
    do {
      iVar3 = type_category(a);
      iVar4 = type_category(b);
      if (iVar3 != iVar4) {
        if ((flags & 4) == 0) {
          return '\0';
        }
        if (iVar3 == 1) {
          return '\x01';
        }
        iVar3 = type_category(b);
        if (iVar3 == 1) {
          return '\x01';
        }
        return '\0';
      }
      switch(iVar3) {
      default:
        goto switchD_1043a9ec_caseD_0;
      case 1:
      case 2:
      case 4:
        goto switchD_1043a9ec_caseD_1;
      case 3:
        goto switchD_1043a9ec_caseD_3;
      case 5:
      case 6:
        cVar1 = (char)a->code;
        pcVar5 = a;
        while (cVar1 < '\0') {
          pcVar5 = pcVar5->base;
          cVar1 = (char)pcVar5->code;
        }
        if ((pcVar5->code & 0x300) == 0) {
          pcVar11 = (c1_symbol *)0x0;
        }
        else {
          pcVar11 = (pcVar5->extra).cls;
        }
        cVar1 = (char)b->code;
        pcVar5 = b;
        while (cVar1 < '\0') {
          pcVar5 = pcVar5->base;
          cVar1 = (char)pcVar5->code;
        }
        if ((pcVar5->code & 0x300) == 0) {
          pcVar10 = (c1_symbol *)0x0;
        }
        else {
          pcVar10 = (pcVar5->extra).cls;
        }
        if (pcVar11 != pcVar10) {
          if ((flags & 4) != 0) {
            if ((a->code & 0x300) == 0) {
              pcVar11 = (c1_symbol *)0x0;
            }
            else {
              pcVar11 = (a->extra).cls;
            }
            pcVar9 = g_scope_vector;
            if ((b->code & 0x300) == 0) {
              pcVar10 = (c1_symbol *)0x0;
            }
            else {
              pcVar10 = (b->extra).cls;
            }
            do {
              if ((((((pcVar11->detail).cls)->flags3e & 1) != 0) &&
                  ((((pcVar10->detail).cls)->flags3e & 1) != 0)) &&
                 (((((pcVar11->detail).cls)->flags3f & 0x80) != 0 ||
                  ((((pcVar10->detail).cls)->flags3f & 0x80) != 0)))) {
                pvVar7 = tmpl_template_of_instance(pcVar11);
                pvVar8 = tmpl_template_of_instance(pcVar10);
                pcVar9 = g_scope_vector;
                if (pvVar7 == pvVar8) {
                  return '\x01';
                }
              }
            } while (((pcVar11->scope_index != 0) &&
                     (pcVar11 = pcVar9->entries[(short)pcVar11->scope_index],
                     (pcVar11->kind & 0x1f) == 4)) &&
                    ((pcVar10->scope_index != 0 &&
                     (pcVar10 = pcVar9->entries[(short)pcVar10->scope_index],
                     (pcVar10->kind & 0x1f) == 4))));
          }
          if (iVar3 == 6) {
            return '\0';
          }
        }
        goto switchD_1043a9ec_caseD_1;
      case 8:
        if ((((byte)b->flags ^ (byte)a->flags) & 0x18) != 0) {
          return '\0';
        }
        uVar2 = a->flags & 0x18;
        if (((uVar2 == 0x18) || (uVar2 == 8)) && ((a->extra).cls != (b->extra).cls)) {
          return '\0';
        }
        if ((flags & 2) == 0) {
          pcVar5 = a;
          if ((a->code & 0x8f) == 0x83) {
            pcVar5 = type_skip_arrays(a->base);
          }
          pcVar6 = b;
          if ((b->code & 0x8f) == 0x83) {
            pcVar6 = type_skip_arrays(b->base);
          }
          uVar2 = pcVar6->flags ^ pcVar5->flags;
joined_r0x10483402:
          if ((uVar2 & 0x3e0) != 0) {
            return '\0';
          }
        }
        break;
      case 9:
        cVar1 = type_compare_member_pointer(a,b,flags);
        return cVar1;
      case 10:
        if ((flags & 2) == 0) {
          pcVar5 = a;
          if ((a->code & 0x8f) == 0x83) {
            pcVar5 = type_skip_arrays(a->base);
          }
          pcVar6 = b;
          if ((b->code & 0x8f) == 0x83) {
            pcVar6 = type_skip_arrays(b->base);
          }
          if (((pcVar6->flags ^ pcVar5->flags) & 0x3e0) != 0) {
            return '\0';
          }
        }
        flags_00 = flags & 0xfffffffd;
        pcVar5 = type_base(b);
        pcVar6 = type_base(a);
        cVar1 = type_compare_function(pcVar6,pcVar5,flags_00);
        return cVar1;
      case 0xb:
        cVar1 = type_compare_function(a,b,flags & 0xfffffffd);
        return cVar1;
      case 0xc:
      case 0xd:
        if ((a->extra).cls != (b->extra).cls) {
          return '\0';
        }
        if ((flags & 2) == 0) {
          pcVar5 = a;
          if ((a->code & 0x8f) == 0x83) {
            pcVar5 = type_skip_arrays(a->base);
          }
          pcVar6 = b;
          if ((b->code & 0x8f) == 0x83) {
            pcVar6 = type_skip_arrays(b->base);
          }
          uVar2 = pcVar6->flags ^ pcVar5->flags;
          goto joined_r0x10483402;
        }
        break;
      case 0xe:
      case 0xf:
        b = type_base(b);
        a = type_base(a);
        goto LAB_1043a9c9;
      }
      b = type_base(b);
      a = type_base(a);
LAB_1043a9c9:
    } while (a != b);
  }
switchD_1043a9ec_caseD_0:
  return '\x01';
switchD_1043a9ec_caseD_1:
  if (a != b) {
    uVar2 = a->code;
    if ((uVar2 & 0x300) == 0) {
      if ((uVar2 & 0x800) == 0) {
        if (uVar2 != b->code) {
          return '\0';
        }
      }
      else {
        if ((b->code & 0x800) == 0) {
          return '\0';
        }
        if (*(short *)&a->extra != *(short *)&b->extra) {
          return '\0';
        }
      }
    }
    else {
      if ((b->code & 0x300) == 0) {
        return '\0';
      }
      if ((a->extra).cls != (b->extra).cls) {
        return '\0';
      }
    }
  }
switchD_1043a9ec_caseD_3:
  if ((flags & 2) != 0) {
    return '\x01';
  }
  if (((b->flags ^ a->flags) & 0x3e0) == 0) {
    return '\x01';
  }
  return '\0';
}

