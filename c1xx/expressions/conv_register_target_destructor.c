c1_node * __thiscall
conv_register_target_destructor(c1_conversion *conv,c1_node *dest,c1_node *call)

{
  int iVar1;
  c1_node *pcVar2;
  
  iVar1 = conv->target_kind;
  if (iVar1 == 1) {
    eh_register_temporary_destructor(dest,conv->target);
    call->kind = call->kind | 0x20;
    return call;
  }
  if (iVar1 == 2) {
    eh_register_named_object_destructor(conv->target_symbol,conv->target);
  }
  else if ((iVar1 == 3) && (conv->target_symbol != (c1_symbol *)0x0)) {
    pcVar2 = expr_full_expression_guarded(call,2);
    type_check_destructible_2(conv->target_symbol);
    return pcVar2;
  }
  return call;
}

