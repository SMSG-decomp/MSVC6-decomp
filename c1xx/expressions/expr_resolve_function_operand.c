void __cdecl expr_resolve_function_operand(uint op,c1_node **operand,c1_node *other)

{
  c1_u16 cVar1;
  c1_node *pcVar2;
  
  cVar1 = (*operand)->type->code;
  if ((cVar1 == 0x80c) || (cVar1 == 0x80e)) {
    pcVar2 = tree_strip_address_of(*operand);
    if (pcVar2->op == 'S') {
      pcVar2 = pcVar2->right;
    }
    else if (pcVar2->op != '\x06') {
      return;
    }
    if ((*(byte *)pcVar2->left & 0x1f) == 0x12) {
      pcVar2->left = *(void **)(**(int **)((int)pcVar2->left + 0x14) + 8);
    }
    pcVar2 = expr_resolve_function_address(other->type,*operand);
    if (pcVar2 != (c1_node *)0x0) {
      *operand = pcVar2;
      return;
    }
    expr_report_function_operand((c1_u8)op,*operand);
  }
  return;
}

