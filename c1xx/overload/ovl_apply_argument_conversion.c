c1_node * __cdecl ovl_apply_argument_conversion(c1_ovl_candidate *cand,int index)

{
  c1_node *pcVar1;
  
  pcVar1 = conv_apply_conversion(cand->conversions + index,(c1_node *)0x0);
  return pcVar1;
}

