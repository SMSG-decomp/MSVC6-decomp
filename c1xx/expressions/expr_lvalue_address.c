c1_node * __cdecl expr_lvalue_address(c1_node *e,uint mode)

{
  byte *pbVar1;
  int mode_sel;
  c1_type *pcVar2;
  c1_type *pcVar3;
  c1_node *pcVar4;
  c1_symbol *pcVar5;
  byte bVar6;
  char cVar7;
  
  cVar7 = '\0';
  if (e == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  if ((e->kind & 0x20) != 0) {
    if ((mode & 10) == 0) {
      return (c1_node *)0x0;
    }
    mode_sel = (mode & 10) - 2;
    if (mode_sel != 0) {
      pcVar4 = trees_check_lvalue_cast(mode_sel,e,'\0',mode);
      return pcVar4;
    }
  }
  do {
    if (e->op != 'v') break;
    e = e->left;
  } while (e != (c1_node *)0x0);
  if (e->op != 'd') {
LAB_1041341e:
    if (e->op == ']') {
      e = e->left;
    }
    bVar6 = e->op;
    if (bVar6 == 0x5e) {
      return (c1_node *)0x0;
    }
    if (g_token_class[bVar6] != '=') {
      switch((uint)bVar6) {
      case 0x33:
      case 0x34:
      case 0x3a:
      case 0x42:
      case 0x47:
      case 0x49:
      case 0x4b:
      case 0x4e:
      case 0x52:
      case 0x54:
      case 0x55:
      case 0x57:
      case 0x5c:
      case 0x74:
        e = expr_assignment_as_lvalue(e);
        break;
      default:
        bVar6 = (byte)e->type->code;
        if ((-1 < (char)bVar6) || ((bVar6 & 0x8f) != 0x80)) {
          return (c1_node *)0x0;
        }
        break;
      case 0x37:
        e = expr_member_select_by_index(e,mode & 2);
        break;
      case 0x56:
        e = expr_lvalue_through_both_arms(e,mode & 2);
        break;
      case 0x77:
        break;
      case 0xc1:
        e = init_member_select_by_index(e,mode & 2);
      }
      if (e == (c1_node *)0x0) {
        return (c1_node *)0x0;
      }
      cVar7 = '\x01';
    }
    pcVar3 = e->type;
    pcVar2 = pcVar3;
    while ((bVar6 = (byte)pcVar2->code, (bVar6 & 0x8f) == 0x83 || ((bVar6 & 0x83) == 0x81))) {
      pcVar2 = pcVar2->base;
    }
    bVar6 = (byte)pcVar2->flags >> 5 & 1;
    if ((pcVar3->code & 0x200) != 0) {
      if ((pcVar3->code & 0x200) == 0) {
        pcVar5 = (c1_symbol *)0x0;
      }
      else {
        pcVar5 = (pcVar3->extra).cls;
      }
      bVar6 = bVar6 | ((pcVar5->detail).cls)->layout_flags3c >> 4 & 1;
    }
    if (cVar7 == '\0') {
      e = e->left;
    }
    if (((e->op == 'P') && (*(char *)e->left == 'p')) && (-1 < **(char **)((int)e->left + 4))) {
      return (c1_node *)0x0;
    }
    if (((mode & 1) != 0) && (bVar6 != 0)) {
      diag_error(0xa6);
    }
    return e;
  }
  if (g_ms_extensions == '\0') {
    return (c1_node *)0x0;
  }
  pcVar3 = e->type;
  pcVar2 = type_strip_cv_qualifiers(*(c1_type **)((int)e->left + 4));
  pcVar3 = type_strip_cv_qualifiers(pcVar3);
  pcVar4 = e;
  if (pcVar3 == pcVar2) {
    do {
      e = pcVar4->left;
      e->type = pcVar4->type;
      if (e->op != 'd') {
        if ((mode & 1) != 0) {
          diag_warning(4,0xd5);
        }
        if ((e->kind & 7) == 4) {
          pbVar1 = (byte *)((int)e->left + 5);
          *pbVar1 = *pbVar1 | 8;
        }
        else {
          pcVar4 = e;
          if (g_token_class[e->op] == '=') {
            pcVar4 = e->left;
          }
          pcVar4 = expr_find_lvalue_symbol_node(pcVar4);
          if ((pcVar4 != (c1_node *)0x0) && ((pcVar4->kind & 7) == 4)) {
            pbVar1 = (byte *)((int)pcVar4->left + 5);
            *pbVar1 = *pbVar1 | 8;
          }
        }
        goto LAB_1041341e;
      }
      pcVar3 = e->type;
      pcVar2 = type_strip_cv_qualifiers(*(c1_type **)((int)e->left + 4));
      pcVar3 = type_strip_cv_qualifiers(pcVar3);
      pcVar4 = e;
    } while (pcVar3 == pcVar2);
  }
  return (c1_node *)0x0;
}

