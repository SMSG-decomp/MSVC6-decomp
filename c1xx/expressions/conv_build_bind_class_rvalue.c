c1_node * __thiscall conv_build_bind_class_rvalue(c1_conversion *conv,c1_node *dest)

{
  c1_node *pcVar1;
  c1_type *pcVar2;
  c1_node *pcVar3;
  byte bVar4;
  char register_dtor;
  c1_conversion *pcStack_4;
  
  pcVar1 = conv->expr;
  pcVar2 = pcVar1->type;
  pcStack_4 = conv;
  if ((pcVar2->code & 0x200) != 0) {
    pcVar1 = expr_lvalue_address(pcVar1,2);
    pcVar1 = tree_new_rvalue(pcVar1);
    pcVar1->type = pcVar2;
  }
  if (g_conv_bind_class_rvalue_depth == 0) {
    if ((conv->target_kind == 3) || (conv->target_kind == 6)) {
      pcVar2 = type_base(conv->target);
      if ((pcVar2->code & 0x8f) == 0x83) {
        pcVar2 = type_skip_arrays(pcVar2->base);
      }
      pcVar2 = type_strip_qualifiers_unless_all(conv->source,pcVar2->flags & 0x3e0);
      pcStack_4 = (c1_conversion *)0x0;
      pcVar3 = conv_new_temporary_variable_address(conv,pcVar2,(c1_symbol **)&pcStack_4);
      pcVar1 = tree_append_list_item((c1_node *)0x0,pcVar1,2);
      if ((conv->target_symbol == (c1_symbol *)0x0) ||
         ((bVar4 = conv->target_symbol->storage & 7, 3 < bVar4 && (bVar4 < 7)))) {
        register_dtor = '\x01';
      }
      else {
        register_dtor = '\0';
      }
      pcVar1 = expr_build_call_of((c1_symbol *)0x0,(pcVar2->extra).cls,pcVar3,pcVar1,'\0',1,
                                  register_dtor);
      if (pcVar1 == (c1_node *)0x0) {
        return (c1_node *)0x0;
      }
      eh_register_named_object_destructor((c1_symbol *)pcStack_4,pcVar2);
      pcVar3 = tree_new_symbol_ref((c1_symbol *)pcStack_4,'\0');
      pcVar1 = expr_build_builtin_binary('7',pcVar1,pcVar3);
      pcVar1 = tree_new_rvalue(pcVar1);
    }
    else {
      g_conv_bind_class_rvalue_depth = 1;
      conv_check_nonlvalue_to_reference(conv,conv->source,'\0');
      g_conv_bind_class_rvalue_depth = g_conv_bind_class_rvalue_depth + -1;
    }
  }
  if (conv->op == '}') {
    diag_warning(1,0xac);
  }
  conv->expr = pcVar1;
  if (conv->overload_set == (c1_symbol *)0x0) {
    pcVar1 = conv_build_reference_binding(conv,dest);
    return pcVar1;
  }
  pcVar1 = conv_build_base_reference(conv,dest);
  return pcVar1;
}

