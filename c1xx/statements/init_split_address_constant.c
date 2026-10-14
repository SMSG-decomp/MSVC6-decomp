int __cdecl init_split_address_constant(c1_node *node,void **base,int *offset)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  c1_node *pcVar4;
  int iVar5;
  c1_node *operand_3;
  c1_type *base_type;
  c1_node *operand;
  c1_node *right;
  c1_type *base_type_2;
  c1_node *operand_2;
  c1_type *base_type_3;
  c1_node *operand_4;
  
  pcVar4 = tree_strip_casts_and_segment_bases(node);
  bVar1 = pcVar4->kind;
  while (uVar3 = (bVar1 & 7) - 2, uVar3 < 4) {
    switch(uVar3) {
    case 1:
      *offset = *offset + (int)pcVar4->left;
      return 1;
    case 2:
      *base = pcVar4->left;
      return 1;
    case 3:
      pcVar4 = expr_string_literal(pcVar4);
      iVar5 = init_split_address_constant_case2_fragment(pcVar4,base);
      return iVar5;
    }
    switch(pcVar4->op) {
    default:
      goto switchD_104424a2_caseD_37;
    case 'A':
    case 'F':
    case 'P':
    case 'S':
      break;
    case 'Q':
      if ((*(byte *)((int)pcVar4->left + 1) & 7) == 3) {
        operand_4 = pcVar4->right;
        pcVar4->right = pcVar4->left;
        pcVar4->left = operand_4;
      }
      break;
    case 0x9e:
      operand = pcVar4->left;
      right = pcVar4->right;
      if ((((operand->kind & 7) == 3) &&
          (operand->left == (void *)0x0 && operand->right == (void *)0x0)) &&
         ((right->kind & 7) == 3)) {
        base_type = right->type;
        cVar2 = (char)base_type->code;
        while (cVar2 < '\0') {
          base_type = base_type->base;
          cVar2 = (char)base_type->code;
        }
        if ((base_type->code & 0x10) != 0) {
          right->left = (void *)0x0;
          right->right = (void *)0x0;
        }
      }
    }
    operand_2 = pcVar4->right;
    if ((operand_2->kind & 7) != 3) {
      return 0;
    }
    base_type_3 = operand_2->type;
    cVar2 = (char)base_type_3->code;
    while (cVar2 < '\0') {
      base_type_3 = base_type_3->base;
      cVar2 = (char)base_type_3->code;
    }
    if ((base_type_3->code & 0x10) == 0) {
      return 0;
    }
    operand_3 = operand_2->left;
    if (pcVar4->op == 'F') {
      operand_3 = (c1_node *)-(int)operand_3;
    }
    *offset = (int)(&operand_3->op + *offset);
    pcVar4 = tree_strip_casts_and_segment_bases(pcVar4->left);
    bVar1 = pcVar4->kind;
  }
switchD_104424a2_caseD_37:
  return 0;
}

