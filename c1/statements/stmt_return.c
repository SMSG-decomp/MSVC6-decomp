void __cdecl stmt_return(c1_node *value,int has_value)

{
  c1_type *type;
  byte bVar1;
  ushort uVar2;
  int iVar3;
  byte naked;
  
  type = PTR_1065d46c;
  if (PTR_1065d46c != (c1_type *)0x0) {
    naked = g_current_function->flags22 & 1;
    if ((naked != 0) && (has_value != 0)) {
      diag_error(0x1ea,0x4c,0x7d);
      return;
    }
    bVar1 = (byte)PTR_1065d46c->code >> 6;
    if (value == (c1_node *)0x0) {
      if ((bVar1 & 1) == 0) {
        func_warn_must_return_value(naked,g_current_function);
        return;
      }
    }
    else {
      if ((bVar1 & 1) != 0) {
        diag_warning(1,0x62,g_current_function);
        stmt_emit_expression(value);
        il_emit_tuple(0x3a,PTR_106692b4);
        return;
      }
      conv_check_conversion_to_type('}',PTR_1065d46c,value);
      iVar3 = expr_refers_to_local_variable(value);
      if ((char)iVar3 != '\0') {
        diag_warning(1,0xac);
      }
      uVar2 = PTR_1065d46c->flags & 0x18;
      if ((uVar2 == 0x18) || (uVar2 == 8)) {
        value = type_based_pointer_from_node(type,value);
      }
      il_emit_pragma_or_segment_record(0x24);
      il_emit_expression_tree(value);
      value->type = type;
      il_emit_tuple(0x41,value);
      g_compile_flags_c8 = g_compile_flags_c8 | 0x800;
    }
    il_emit_tuple(0x3a,PTR_106692b4);
  }
  return;
}

