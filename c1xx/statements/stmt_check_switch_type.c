void __thiscall stmt_check_switch_type(void *this,c1_node *edi,c1_conversion *conv)

{
  c1_node *pcVar1;
  c1_type *pcVar2;
  c1_type *unaff_EBP;
  short n;
  c1_u16 in_stack_00000010;
  c1_u16 in_stack_00000012;
  c1_type *in_stack_00000014;
  c1_type_extra in_stack_00000018;
  void *in_stack_0000001c;
  int in_stack_00000038;
  
  conv->mode = '\x04';
  conv->flags = '\0';
  conv->expr = edi;
  if (edi == this) {
    in_stack_00000010 = 0x80f;
    in_stack_00000012 = (c1_u16)this;
    in_stack_00000014 = this;
    in_stack_00000018 = (c1_type_extra)this;
    in_stack_0000001c = this;
    pcVar2 = type_intern((c1_type *)&stack0x00000010);
    conv->source = pcVar2;
    conv->target = unaff_EBP;
    conv_compute_conversion(conv);
  }
  else {
    conv->source = edi->type;
    conv->target = unaff_EBP;
    conv_compute_conversion(conv);
  }
  if ((conv->flags4e & 1) != 0) {
    pcVar1 = conv_apply_conversion(conv,(c1_node *)0x0);
    expr_full_expression_guarded(pcVar1,3);
    return;
  }
  diag_begin_global(g_token_position);
  if (in_stack_00000038 == 0) {
    n = 0x1c3;
  }
  else {
    n = 0x1c2;
  }
  diag_error(n);
  conv_report_cannot_convert(conv,'\0');
  diag_end_global();
  pcVar1 = tree_new_int_constant(0);
  expr_full_expression_guarded(pcVar1,3);
  return;
}

