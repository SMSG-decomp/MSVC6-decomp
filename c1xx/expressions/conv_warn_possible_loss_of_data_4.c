void conv_warn_possible_loss_of_data_4(c1_conversion *esi)

{
  c1_node *in_stack_0000000c;
  
  diag_warning(2,0xf4,(uint)esi->op);
  conv_apply_standard_conversion(esi,in_stack_0000000c);
  return;
}

