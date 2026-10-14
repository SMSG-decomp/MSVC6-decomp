uint __fastcall factor_compare_operands(c2_node *n,c2_node *n2)

{
  uint32_t uVar1;
  c2_node *node;
  c2_node *node_00;
  c2_factor_term *pcVar2;
  int iVar3;
  int iVar4;
  
  node = factor_strip_ops(n);
  node_00 = factor_strip_ops(n2);
  pcVar2 = factor_find_term_entry(node);
  uVar1 = pcVar2->x0c;
  iVar4 = (pcVar2->count - 1) * uVar1;
  pcVar2 = factor_find_term_entry(node_00);
  iVar3 = (pcVar2->count - 1) * uVar1;
  if (iVar4 - iVar3 == 0 || iVar4 < iVar3) {
    return (uint)(iVar4 - iVar3 != 0);
  }
  return 0xffffffff;
}

