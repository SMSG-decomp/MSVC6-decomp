int __cdecl
expr_build_constructor_call(c1_symbol *cls,c1_node *obj,int args,char emit,char keep_vbase_flag)

{
  c1_node *pcVar1;
  c1_node *name;
  
  if ((args == 0) && ((((cls->detail).cls)->implicit_state41 & 2) != 0)) {
    pcVar1 = expr_build_builtin_unary(0x3d,obj);
  }
  else {
    pcVar1 = expr_prepare_member_access_object(g_current_scope,'S',obj,'\x01');
    name = expr_lookup_name_expression(g_name_ctor);
    pcVar1 = expr_build_member_access('S',pcVar1,name);
    pcVar1 = (c1_node *)expr_build_call(pcVar1,(c1_node *)args);
    if (pcVar1 == (c1_node *)0x0) {
      return 0;
    }
    if ((keep_vbase_flag == '\0') && ((((cls->detail).cls)->layout_flags3b & 0x10) != 0)) {
      pcVar1 = (c1_node *)tree_zero_second_operand((int)pcVar1);
    }
  }
  if (emit != '\0') {
    pcVar1 = expr_full_expression_guarded(pcVar1,2);
    stmt_emit_expression(pcVar1);
    return 0;
  }
  return (int)pcVar1;
}

