c1_node * __thiscall conv_build_integral_to_floating(c1_conversion *conv,c1_node *dest)

{
  char cVar1;
  c1_node *pcVar2;
  c1_node *extraout_EAX;
  
  cVar1 = conv_constant_warnings_enabled(conv);
  if ((cVar1 != '\0') &&
     ((byte)(&g_type_rank_table)[(byte)conv->target->code & 0xf] <=
      (byte)(&g_type_rank_table)[(byte)conv->source->code & 0xf])) {
    conv_warn_possible_loss_of_data_4(conv);
    return extraout_EAX;
  }
  pcVar2 = conv_apply_standard_conversion(conv,dest);
  return pcVar2;
}

