c1_node * __thiscall conv_build_integral_to_based_pointer(c1_conversion *conv,c1_node *dest)

{
  c1_node *pcVar1;
  
  pcVar1 = conv_apply_standard_conversion(conv,dest);
  pcVar1 = expr_based_pointer_fixup(pcVar1);
  return pcVar1;
}

