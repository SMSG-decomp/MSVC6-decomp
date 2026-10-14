c1_node * __thiscall conv_build_decayed_conversion(c1_conversion *conv,c1_node *dest)

{
  c1_conversion *pcVar1;
  int iVar2;
  c1_node *pcVar3;
  
  pcVar3 = tree_new_unary('d',conv->first->source,conv->expr);
  pcVar1 = conv->first;
  iVar2 = conv->target_kind;
  pcVar1->target_symbol = conv->target_symbol;
  pcVar1->target_kind = iVar2;
  pcVar1 = conv->first;
  pcVar1->expr = pcVar3;
  pcVar3 = conv_apply_conversion(pcVar1,dest);
  return pcVar3;
}

