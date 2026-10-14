c1_node * __cdecl expr_build_delete(char kind,c1_node *operand,c1_node *bound,char is_array)

{
  c1_u16 cVar1;
  c1_symbol *cls;
  bool bVar2;
  c1_type *array_type;
  uint entity;
  c1_node *pcVar3;
  c1_node *pcVar4;
  void *name;
  c1_symbol *delete_set;
  byte *pbVar5;
  c1_type *pcVar6;
  bool bVar7;
  c1_u8 mode;
  c1_u8 flags;
  c1_type local_10;
  
  bVar7 = kind == '\x02';
  if (operand != (c1_node *)0x0) {
    pcVar6 = operand->type;
    cVar1 = pcVar6->code;
    if (((cVar1 != 0x80c) && (cVar1 != 0x80e)) && (operand->op != 0x98)) {
      if ((is_array == '\0') &&
         ((((byte)cVar1 & 0x8f) == 0x83 ||
          (((char)(byte)cVar1 < '\0' && ((pcVar6->base->code & 0x8f) == 0x83)))))) {
        if (g_ms_extensions == '\0') {
          diag_warning(1,0x9b);
        }
        else {
          diag_warning(2,0x9c);
          is_array = '\x01';
        }
      }
      if ((pcVar6->code & 0x8f) == 0x83) {
        diag_warning(1,0x9a);
        pcVar6 = conv_array_to_pointer_type(operand);
        operand->type = pcVar6;
      }
      pcVar4 = operand;
      if ((operand->type->code & 0x300) != 0) {
        flags = '\0';
        mode = '\x02';
        pcVar6 = type_basic(0x807);
        pcVar4 = conv_convert_expression(0x8d,pcVar6,pcVar4,mode,flags);
        pcVar6 = pcVar4->type;
      }
      if ((pcVar6->code & 0x8f) == 0x82) {
        if (bound != (c1_node *)0x0) {
          if (g_ms_extensions == '\0') {
            diag_error(0xcb);
          }
          else {
            diag_warning(4,0xd0);
            stmt_emit_expression(bound);
          }
        }
        if ((pcVar6->flags & 0x18) == 0x18) {
          pcVar4 = expr_based_pointer_fixup(pcVar4);
          pcVar6 = pcVar6->base;
          local_10.debug_index = 0;
          local_10.code = 0x82;
          local_10.flags = decl_apply_default_calling_convention(0x82,0);
          local_10.extra.cls = (c1_symbol *)0x0;
          local_10.base = pcVar6;
          pcVar6 = type_intern(&local_10);
          pcVar4->type = pcVar6;
        }
        array_type = type_base(pcVar6);
        if ((array_type->code & 0x8f) == 0x83) {
          array_type = type_array_innermost_element(array_type);
          pcVar6 = type_pointer_with_qualifiers(array_type,0);
        }
        entity = sym_new_local_key();
        pcVar3 = tree_new_leaf_9c(entity,pcVar6);
        pcVar4 = tree_new_binary('4',pcVar3,pcVar4);
        pcVar3 = tree_new_leaf_9c(entity,pcVar6);
        pcVar3 = tree_new_rvalue(pcVar3);
        pcVar4 = tree_new_node('7',pcVar4,pcVar3,pcVar6);
        if ((array_type->code & 0x200) != 0) {
          cls = (array_type->extra).cls;
          if ((cls->flags2 & 4) == 0) {
            tmpl_instantiate_if_needed(cls);
            if ((cls->flags2 & 4) == 0) {
              diag_warning(2,0x96,cls);
              goto LAB_104403b7;
            }
          }
          name = g_name_array_delete;
          if (is_array == '\0') {
            name = g_name_delete;
          }
          delete_set = class_lookup_member_set
                                 (g_current_scope,cls,name,2,(-(uint)bVar7 & 0xfffffe7f) + 0x181);
          if (((delete_set != (c1_symbol *)0x0) &&
              ((((cls->detail).cls)->implicit_state41 & 0x10) != 0)) && (!bVar7)) {
            pcVar4 = expr_build_class_operator_delete_call(delete_set,pcVar4,cls);
            return pcVar4;
          }
          if ((((cls->detail).cls)->implicit_state41 & 0x10) == 0) {
            if ((cls->flags2 & 4) == 0) {
              tmpl_instantiate_if_needed(cls);
            }
            if (((((cls->detail).cls)->implicit_state41 & 0x10) != 0) ||
               ((((cls->detail).cls)->implicit_state43 & 0x10) != 0)) {
              bVar2 = true;
              operand = (c1_node *)CONCAT31(operand._1_3_,1);
              pbVar5 = class_find_member_function_walk_overloads(cls,g_name_dtor,(void *)0x0);
              if ((bVar7) && (((pbVar5[0x21] >> 1 & 1) != 0 || (delete_set != (c1_symbol *)0x0)))) {
                bVar2 = false;
                operand = (c1_node *)((uint)operand._1_3_ << 8);
              }
              pcVar4 = expr_build_destructor_call(cls,pcVar4,(is_array != '\0') + 4,0,(int)operand);
              if (bVar2) {
                return pcVar4;
              }
            }
          }
        }
LAB_104403b7:
        pcVar4 = (c1_node *)expr_build_generated_operator_delete_call(pcVar4,is_array);
        return pcVar4;
      }
    }
    diag_error(0x21d);
  }
  return (c1_node *)0x0;
}

