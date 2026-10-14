char * __cdecl decorate_template_constant_argument(char *out,c1_node *node)

{
  void *pvVar1;
  c1_node *pcVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  ushort uVar7;
  int iVar8;
  char *_Dest;
  char *pcVar9;
  bool bVar10;
  
  if ((node->kind & 7) != 5) {
    node = fold_static_const_member(node);
  }
  bVar6 = node->kind & 7;
  if (bVar6 == 5) {
    *out = '1';
    out[1] = '@';
    diag_error(0x3c3);
    return out + 2;
  }
  if (bVar6 == 3) {
    uVar7 = node->type->code;
    bVar6 = (byte)uVar7;
    if ((char)bVar6 < '\0') {
      *out = '1';
      if (node->left == (void *)0x0 && node->right == (void *)0x0) {
        out[1] = '@';
        return out + 2;
      }
      bVar6 = node->kind & 7;
      if (bVar6 != 4) {
        uVar7 = node->type->code & 0x8f;
        if (((((uVar7 != 0x82) && (uVar7 != 0x83)) || ((char)node->type->base->code < '\0')) ||
            ((node->op != 'd' || (pcVar2 = node->left, pcVar2 == (c1_node *)0x0)))) ||
           ((pcVar2->kind & 7) != 4)) goto LAB_104745fa;
        if (bVar6 != 4) {
          node = pcVar2;
        }
      }
      pcVar3 = decorate_name_body(out + 1,node->left,(c1_symbol *)0x0);
      return pcVar3;
    }
    if ((node->flags & 8) != 0) {
      *out = 'D';
      pcVar3 = decorate_number(out + 1,(uint)node->left);
      return pcVar3;
    }
    if ((uVar7 & 0x110) != 0) {
      *out = '0';
      pcVar3 = decorate_signed_number(out + 1,(int)node->left);
      return pcVar3;
    }
    if ((bVar6 >> 5 & 1) != 0) {
      *out = '2';
      _Dest = out + 1;
      iVar4 = sprintf(_Dest,"%.16LE",*(undefined8 *)node->left);
      bVar10 = false;
      iVar8 = 0;
      pcVar3 = _Dest;
      pcVar9 = _Dest;
      if (0 < iVar4) {
        do {
          switch(_Dest[iVar8]) {
          case '+':
            *pcVar3 = 'C';
            pcVar9 = pcVar3;
            break;
          default:
            diag_fatal(1,".\\outdname.c",0x23c);
          case '-':
            *pcVar3 = 'B';
            pcVar9 = pcVar3;
            break;
          case '.':
            *pcVar3 = 'A';
            pcVar9 = pcVar3;
            break;
          case '0':
            if (!bVar10) goto switchD_10474581_caseD_31;
            goto LAB_104745a9;
          case '1':
          case '2':
          case '3':
          case '4':
          case '5':
          case '6':
          case '7':
          case '8':
          case '9':
switchD_10474581_caseD_31:
            bVar10 = false;
            *pcVar3 = _Dest[iVar8];
            break;
          case 'E':
          case 'e':
            bVar10 = true;
            iVar5 = (int)pcVar3 - (int)pcVar9;
            while ((0 < iVar5 && (pcVar3[-1] == '0'))) {
              pcVar3 = pcVar3 + -1;
              iVar5 = (int)pcVar3 - (int)pcVar9;
            }
            *pcVar3 = 'E';
            pcVar9 = pcVar3;
          }
          pcVar3 = pcVar3 + 1;
LAB_104745a9:
          iVar8 = iVar8 + 1;
        } while (iVar8 < iVar4);
      }
      *pcVar3 = '@';
      return pcVar3 + 1;
    }
    *out = '1';
  }
  else {
    if (-1 < (char)node->type->code) {
      return out;
    }
    *out = '1';
    bVar6 = node->kind;
    while (((bVar6 & 7) == 1 && (node->op == 'd'))) {
      node = node->left;
      bVar6 = node->kind;
    }
    if ((((node->kind & 7) == 1) && (uVar7 = node->type->code, (char)uVar7 < '\0')) &&
       ((uVar7 = uVar7 & 0x8f, uVar7 == 0x86 || (uVar7 == 0x82)))) {
      node = node->left;
    }
    if ((node->kind & 7) == 4) {
      pvVar1 = node->left;
      bVar10 = (*(byte *)((int)pvVar1 + 1) & 2) != 0;
      if (bVar10) {
        *(byte *)((int)pvVar1 + 1) = *(byte *)((int)pvVar1 + 1) & 0xfc;
      }
      pcVar3 = decorate_name_body(out + 1,node->left,(c1_symbol *)0x0);
      if (!bVar10) {
        return pcVar3;
      }
      *(byte *)((int)pvVar1 + 1) = *(byte *)((int)pvVar1 + 1) & 0xfe | 2;
      return pcVar3;
    }
  }
LAB_104745fa:
  out[1] = '@';
  diag_error(0x3c4);
  return out + 2;
}

