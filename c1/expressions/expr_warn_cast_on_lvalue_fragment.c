c1_node * __cdecl expr_warn_cast_on_lvalue_fragment(c1_node *found,c1_node *node,byte mode)

{
  byte *pbVar1;
  c1_type *pcVar2;
  c1_node *pcVar3;
  c1_tag_symbol *tag;
  byte bVar4;
  c1_type *pcVar5;
  
  pbVar1 = (byte *)((int)found->left + 4);
  *pbVar1 = *pbVar1 | 8;
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
  pcVar5 = pcVar2;
  while ((bVar4 = (byte)pcVar5->code, (bVar4 & 0x8f) == 0x83 || ((bVar4 & 0x83) == 0x81))) {
    pcVar5 = pcVar5->base;
  }
  bVar4 = (byte)pcVar5->flags >> 5 & 1;
  if ((pcVar2->code & 0x200) != 0) {
    if ((pcVar2->code & 0x200) == 0) {
      tag = (c1_tag_symbol *)0x0;
    }
    else {
      tag = (c1_tag_symbol *)(pcVar2->extra).sym;
    }
    bVar4 = bVar4 | (byte)(tag->alignment >> 10) & 1;
  }
  pcVar3 = node->left;
  if ((pcVar3->op == 'P') && (pcVar3->left->op == 'p')) {
    pcVar3 = expr_report_const_lvalue(bVar4,pcVar3->left,pcVar3,mode);
    return pcVar3;
  }
  if (((mode & 1) != 0) && (bVar4 != 0)) {
    diag_error(0xa6);
  }
  return pcVar3;
}

