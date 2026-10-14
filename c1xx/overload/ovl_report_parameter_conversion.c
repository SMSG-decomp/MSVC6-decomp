c1_node * __cdecl
ovl_report_parameter_conversion
          (int argno,c1_conversion *conv,c1_node *arg,c1_type *param_type,c1_type **param_cursor,
          int param_index,c1_node *result,c1_symbol *fn,c1_type *type,c1_node *args,
          char compute_here)

{
  c1_type *pcVar1;
  c1_node *pcVar2;
  c1_conversion *conv_00;
  char cStack00000013;
  c1_symbol *pcVar3;
  c1_type *pcVar4;
  int directive;
  
  diag_begin_global(g_token_position);
  if (fn == (c1_symbol *)0x0) {
    pcVar4 = arg->type;
    directive = 0x54;
    pcVar3 = (c1_symbol *)type;
  }
  else {
    pcVar4 = arg->type;
    directive = 0x44;
    pcVar3 = fn;
  }
  diag_error(0x298,directive,pcVar3,argno,pcVar4,param_type);
  conv_report_cannot_convert(conv,'\0');
  diag_end_global();
  cStack00000013 = '\x01';
  do {
    args = args->right;
    argno = argno + -1;
    conv_00 = conv + -1;
    if (argno < 1) {
      pcVar2 = eh_leave_new_expression_region();
      if (cStack00000013 != '\0') {
        return (c1_node *)0x0;
      }
      if (pcVar2 == (c1_node *)0x0) {
        return result;
      }
      pcVar2 = tree_new_binary_typed_right('7',result,pcVar2);
      return pcVar2;
    }
    pcVar2 = args->left;
    if ((pcVar2 == (c1_node *)0x0) || ((pcVar2->kind & 8) != 0)) {
      eh_leave_new_expression_region();
      return (c1_node *)0x0;
    }
    pcVar4 = *param_cursor;
    if ((pcVar4->code == 0x80d) && (param_index != argno)) {
LAB_1042ccae:
      if (conv_00 == (c1_conversion *)0x0) {
        conv_00 = (c1_conversion *)0x0;
      }
      else {
        conv_00->op = '`';
        conv[-1].mode = '\x02';
        conv[-1].flags = '\x04';
        conv[-1].expr = pcVar2;
        pcVar1 = pcVar2->type;
        conv[-1].target = pcVar4;
        conv[-1].source = pcVar1;
        conv_compute_conversion(conv_00);
      }
      if ((conv_00->flags4e & 1) == 0) {
        pcVar2 = ovl_report_parameter_conversion
                           (argno,conv_00,pcVar2,pcVar4,param_cursor,param_index,result,fn,type,args
                            ,compute_here);
        return pcVar2;
      }
    }
    else {
      param_cursor = param_cursor + -1;
      param_index = param_index + -1;
      if (compute_here != '\0') goto LAB_1042ccae;
    }
    pcVar2 = conv_apply_conversion(conv_00,(c1_node *)0x0);
    args->left = pcVar2;
    conv = conv_00;
    if (pcVar2 == (c1_node *)0x0) {
      cStack00000013 = '\x01';
    }
    else {
      pcVar2->link = args;
      if (pcVar4->code == 0x80d) {
        args->type = g_type_none;
      }
      else {
        args->type = pcVar2->type;
      }
    }
  } while( true );
}

