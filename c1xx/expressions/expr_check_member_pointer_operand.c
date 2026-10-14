char __cdecl expr_check_member_pointer_operand(c1_node *node)

{
  c1_type *pcVar1;
  char cVar2;
  ushort uVar3;
  
  cVar2 = '\0';
  pcVar1 = *(c1_type **)((int)node->left + 4);
  uVar3 = pcVar1->code & 0x8f;
  if ((uVar3 == 0x8a) || (uVar3 == 0x8e)) {
    diag_error_C2296_or_C2297(node->op,1,pcVar1);
    cVar2 = '\x01';
  }
  pcVar1 = *(c1_type **)((int)node->right + 4);
  uVar3 = pcVar1->code & 0x8f;
  if ((uVar3 == 0x8a) || (uVar3 == 0x8e)) {
    diag_error_C2296_or_C2297(node->op,2,pcVar1);
    cVar2 = '\x01';
  }
  return cVar2;
}

