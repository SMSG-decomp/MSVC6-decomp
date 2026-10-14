c1_node * __cdecl expr_warn_cast_on_lvalue(c1_node *node,uint mode)

{
  byte *pbVar1;
  c1_type *pcVar2;
  uint uVar3;
  uint uVar4;
  c1_node *pcVar5;
  c1_tag_symbol *tag;
  byte bVar6;
  c1_type *pcVar7;
  
  if (node == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  if ((node->kind & 0x20) != 0) {
    uVar3 = mode & 10;
    if (uVar3 != 0) {
      if (uVar3 == 2) goto LAB_1061d176;
      if (uVar3 != 8) {
        diag_fatal(1,".\\trees.c",0x15ae);
      }
    }
    return (c1_node *)0x0;
  }
LAB_1061d176:
  do {
    if (node->op != 'v') break;
    node = node->left;
  } while (node != (c1_node *)0x0);
  if (node->op == 'd') {
    if (g_ms_extensions == '\0') {
      return (c1_node *)0x0;
    }
    pcVar2 = node->type;
    uVar3 = type_size(*(c1_type **)((int)node->left + 4));
    uVar4 = type_size(pcVar2);
    if (uVar4 <= uVar3) {
      do {
        node = node->left;
        if (node->op != 'd') {
          if ((mode & 1) != 0) {
            diag_warning(4,0xd5);
          }
          if ((node->kind & 7) == 4) {
            pbVar1 = (byte *)((int)node->left + 4);
            *pbVar1 = *pbVar1 | 8;
          }
          else {
            pcVar5 = node;
            if ((&g_token_class)[node->op] == '=') {
              pcVar5 = node->left;
            }
            pcVar5 = expr_find_lvalue_symbol_node(pcVar5);
            if ((pcVar5 != (c1_node *)0x0) && ((pcVar5->kind & 7) == 4)) {
              pcVar5 = expr_warn_cast_on_lvalue_fragment(pcVar5,node,(byte)mode);
              return pcVar5;
            }
          }
          goto LAB_1061d188;
        }
        pcVar2 = node->type;
        uVar3 = type_size(*(c1_type **)((int)node->left + 4));
        uVar4 = type_size(pcVar2);
      } while (uVar4 <= uVar3);
    }
    return (c1_node *)0x0;
  }
LAB_1061d188:
  if (node->op == ']') {
    node = node->left;
  }
  if (node->op == 0x5e) {
    return (c1_node *)0x0;
  }
  if ((&g_token_class)[node->op] != '=') {
    return (c1_node *)0x0;
  }
  pcVar2 = node->type;
  pcVar7 = pcVar2;
  while ((bVar6 = (byte)pcVar7->code, (bVar6 & 0x8f) == 0x83 || ((bVar6 & 0x83) == 0x81))) {
    pcVar7 = pcVar7->base;
  }
  bVar6 = (byte)pcVar7->flags >> 5 & 1;
  if ((pcVar2->code & 0x200) != 0) {
    if ((pcVar2->code & 0x200) == 0) {
      tag = (c1_tag_symbol *)0x0;
    }
    else {
      tag = (c1_tag_symbol *)(pcVar2->extra).sym;
    }
    bVar6 = bVar6 | (byte)(tag->alignment >> 10) & 1;
  }
  pcVar5 = node->left;
  if ((pcVar5->op == 'P') && (pcVar5->left->op == 'p')) {
    pcVar5 = expr_report_const_lvalue(bVar6,pcVar5->left,pcVar5,(byte)mode);
    return pcVar5;
  }
  if (((mode & 1) != 0) && (bVar6 != 0)) {
    diag_error(0xa6);
  }
  return pcVar5;
}

