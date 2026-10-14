c2_node * __fastcall merge_operand_lists(c2_node *a,c2_node *b,c2_cmp_fn *cmp)

{
  c2_node *pcVar1;
  c2_cmp_fn *pcVar2;
  int iVar3;
  
  pcVar2 = cmp;
  pcVar1 = (c2_node *)&cmp;
  while (a != (c2_node *)0x0) {
    if (b == (c2_node *)0x0) goto LAB_1070af23;
    iVar3 = (*pcVar2)(a,b);
    if (iVar3 < 1) {
      pcVar1->next = a;
      pcVar1 = a;
      a = a->next;
    }
    else {
      pcVar1->next = b;
      pcVar1 = b;
      b = b->next;
    }
  }
  if (b != (c2_node *)0x0) {
    pcVar1->next = b;
    return (c2_node *)cmp;
  }
LAB_1070af23:
  pcVar1->next = a;
  return (c2_node *)cmp;
}

