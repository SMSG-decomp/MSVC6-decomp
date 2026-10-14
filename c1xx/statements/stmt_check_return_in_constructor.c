void __cdecl stmt_check_return_in_constructor(c1_node *node,int kind)

{
  c1_type *pcVar1;
  c1_node *pcVar2;
  c1_node *object;
  uint uVar3;
  byte bVar4;
  byte bVar5;
  c1_symbol *cls;
  uint uStack00000014;
  char emit;
  int dtor_kind;
  char register_dtor;
  
  diag_error(0x216,g_member_function_class);
  bVar4 = g_current_function->flags22 & 1;
  if ((bVar4 != 0) && (kind != 0)) {
    diag_error(0x1ea,0x4c,0x7d);
    return;
  }
  bVar5 = (byte)g_function_return_type->code >> 6;
  uStack00000014 = bVar5 & 1;
  if ((bVar5 & 1) == 0) {
    if (node == (c1_node *)0x0) {
      if (((g_ms_extensions == '\0') || ((g_current_function->flags1 & 0x44) != 0)) ||
         (((g_compile_flags_c4 & 0x1000000) == 0 &&
          ((((g_current_function->name->flags & 0x40000000) == 0 ||
            (g_current_function->scope_index != 0)) || ((g_current_function->storage & 7) != 1))))))
      {
        if ((kind != 2) && (bVar4 == 0)) {
          if ((g_current_function->flags5 & 0x10) == 0) {
            if (kind == 1) {
              diag_error(0x231,g_current_function);
              expr_condition_guarded((c1_node *)0x0,1);
              return;
            }
            goto LAB_1042984e;
          }
          diag_warning(3,0x23,g_current_function);
        }
        g_compile_flags_c8 = g_compile_flags_c8 | 0x800;
        goto LAB_1042984e;
      }
      if ((g_compile_flags_c8 & 2) == 0) {
        g_compile_flags_c8 = g_compile_flags_c8 | 2;
        g_function_return_type = g_type_void;
        diag_warning(1,0x1fc,g_current_function);
      }
      else {
        diag_error(0x269,g_current_function);
      }
      goto LAB_10429985;
    }
    if ((((g_ms_extensions != '\0') && ((g_current_function->flags1 & 0x40) == 0)) &&
        ((g_compile_flags_c4 & 0x1000000) != 0)) && ((g_compile_flags_c8 & 2) == 0)) {
      g_function_return_type = g_type_int;
      g_compile_flags_c8 = g_compile_flags_c8 | 2;
    }
    pcVar2 = expr_resolve_function_address(g_function_return_type,node);
    if (pcVar2 == (c1_node *)0x0) goto LAB_1042984e;
    if ((*(byte *)((int)&g_current_function->tail + 9) & 1) == 0) {
      object = conv_convert_expression('}',g_function_return_type,pcVar2,'\x02','\x04');
      if (object == (c1_node *)0x0) goto LAB_1042984e;
      uVar3 = expr_refers_to_local_variable(object);
      if ((char)uVar3 != '\0') {
        diag_warning(1,0xac);
      }
    }
    else {
      if ((g_function_return_type->code & 0x200) == 0) {
        if (((char)g_function_return_type->code < '\0') &&
           ((g_function_return_type->base->code & 0x200) != 0)) {
          cls = (g_function_return_type->base->extra).cls;
        }
        else {
          cls = (c1_symbol *)0x0;
        }
      }
      else {
        cls = (g_function_return_type->extra).cls;
      }
      if ((cls->flags2 & 4) == 0) {
        return;
      }
      if ((cls->flags1 & 0x10) != 0x10) {
        diag_error(0x229,g_function_return_type);
        goto LAB_1042984e;
      }
      object = expr_lookup_name_expression(PTR_104d1648);
      register_dtor = '\x01';
      dtor_kind = 1;
      emit = '\0';
      pcVar2 = tree_append_list_item((c1_node *)0x0,pcVar2,2);
      pcVar2 = expr_build_call_of((c1_symbol *)0x0,cls,object,pcVar2,emit,dtor_kind,register_dtor);
      if (pcVar2 == (c1_node *)0x0) {
        diag_error(0x229,g_function_return_type);
        goto LAB_1042984e;
      }
      if (kind != 0) {
        pcVar2 = expr_condition_guarded(pcVar2,0);
        kind = 0;
      }
      stmt_emit_expression(pcVar2);
    }
    pcVar1 = object->type;
    if (kind != 0) {
      object = expr_condition_guarded(object,1);
    }
    il_emit_pragma_or_segment_record(0x24);
    il_emit_expression_tree(object);
    object->type = pcVar1;
    il_emit_tuple(0x41,object);
    g_compile_flags_c8 = g_compile_flags_c8 | 0x800;
    kind = 0;
  }
  else {
    if (node != (c1_node *)0x0) {
      if ((((g_ms_extensions == '\0') || ((g_current_function->flags1 & 0x44) != 0)) ||
          ((g_compile_flags_c4 & 0x1000000) == 0)) || ((g_compile_flags_c8 & 2) == 0)) {
        diag_error(0x232,g_current_function);
      }
      else {
        diag_error(0x269,g_current_function);
      }
      goto LAB_1042984e;
    }
LAB_10429985:
    if (kind == 0) {
      if (g_block_depth != '\x02') goto LAB_1042983d;
      func_flow_state_note_8();
    }
    pcVar2 = expr_condition_guarded((c1_node *)0x0,0);
    kind = 0;
    if (pcVar2 != (c1_node *)0x0) {
      kind = 0;
      stmt_emit_expression(pcVar2);
    }
  }
LAB_1042983d:
  il_emit_tuple(0x3a,g_function_exit_label);
LAB_1042984e:
  if (kind != 0) {
    expr_condition_guarded((c1_node *)0x0,1);
  }
  return;
}

