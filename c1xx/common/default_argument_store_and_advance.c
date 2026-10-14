void __thiscall default_argument_store_and_advance(c1_deferred_parse *rec,c1_node *expr)

{
  c1_node *pcVar1;
  void *pvVar2;
  longlong zero_value;
  
  rec->parse_pending = '\0';
  if (expr == (c1_node *)0x0) {
    zero_value._0_4_ = 0;
    zero_value._4_4_ = 0;
    pcVar1 = tree_new_constant(g_type_int,&zero_value,g_expr_arena_index);
  }
  else {
    pcVar1 = expr_resolve_address_of_overload(expr);
    tree_attach_typed_link(pcVar1,*rec->param_type);
    pcVar1 = conv_convert_expression(0xc6,*rec->param_type,pcVar1,'\x02','\x04');
  }
  pvVar2 = (void *)expr_finish_full_expression((int)pcVar1);
  pcVar1 = rec->default_arg;
  pcVar1->left = pvVar2;
  if (rec->keep_state == '\0') {
    pcVar1 = pcVar1->link;
    rec->default_arg = pcVar1;
    rec->param_type = rec->param_type + 1;
    if (pcVar1 == rec->last_default) {
      rec->default_arg = (c1_node *)0x0;
    }
  }
  return;
}

