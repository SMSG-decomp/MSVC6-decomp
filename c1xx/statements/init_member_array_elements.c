void __cdecl
init_member_array_elements
          (c1_symbol *member,c1_symbol *elem_class,c1_node *inits,int offset,char copy_mode)

{
  int size;
  c1_symbol *pcVar1;
  c1_node *pcVar2;
  c1_node *pcVar3;
  c1_type *pcVar4;
  c1_node *pcVar5;
  c1_node *pcVar6;
  c1_node *pcVar7;
  c1_node *object;
  char *pcVar8;
  char cVar9;
  char cVar10;
  int iVar11;
  uint jump_if_true;
  uint local_8;
  uint local_4;
  
  local_4 = 1;
  local_8 = 0;
  pcVar8 = (char *)(-(uint)((member->type->code & 0x80) != 0) & (uint)member->type);
  iVar11 = *(int *)(pcVar8 + 8);
  size = sym_element_size((int)member);
  if (copy_mode == '\0') {
    if ((inits == (c1_node *)0x0) && ((((elem_class->detail).cls)->implicit_state41 & 2) != 0)) {
      return;
    }
  }
  else if ((((elem_class->detail).cls)->implicit_state41 & 4) != 0) {
    init_member_memcpy_string((c1_type *)member,offset,inits);
    return;
  }
  while ((pcVar8 = *(char **)(pcVar8 + 4), pcVar2 = inits, *pcVar8 < '\0' && (pcVar8 != (char *)0x0)
         )) {
    local_4 = *(int *)(pcVar8 + 8) * local_4;
  }
  for (; pcVar2 != (c1_node *)0x0; pcVar2 = pcVar2->right) {
    local_8 = local_8 + 1;
  }
  if (copy_mode == '\0') {
    if (iVar11 == 0) {
      if (local_4 < local_8) {
        local_8 = local_8 - ((local_8 - local_4) / local_4) * local_4;
      }
    }
    else if (iVar11 * local_4 < local_8) {
      diag_error(0x4e);
      local_8 = 0;
    }
    else {
      local_8 = iVar11 * local_4 - local_8;
    }
    if (inits != (c1_node *)0x0) {
      pcVar2 = inits->link;
      cVar10 = '\x01';
      inits->link = (c1_node *)0x0;
      pcVar3 = pcVar2->link;
      iVar11 = 1;
      cVar9 = '\x01';
      pcVar2->link = pcVar2;
      pcVar5 = expr_this_plus_offset((int)elem_class,0,offset);
      expr_build_call_of((c1_symbol *)0x0,elem_class,pcVar5,pcVar2,cVar9,iVar11,cVar10);
      while (offset = offset + size, pcVar3 != (c1_node *)0x0) {
        cVar10 = '\x01';
        iVar11 = 1;
        cVar9 = '\x01';
        pcVar3->right = (void *)0x0;
        pcVar2 = pcVar3->link;
        pcVar3->link = pcVar3;
        pcVar5 = expr_this_plus_offset((int)elem_class,0,offset);
        expr_build_call_of((c1_symbol *)0x0,elem_class,pcVar5,pcVar3,cVar9,iVar11,cVar10);
        pcVar3 = pcVar2;
      }
    }
  }
  else {
    local_8 = iVar11 * local_4;
  }
  if (local_8 != 0) {
    iVar11 = 0;
    if (copy_mode != '\0') {
      pcVar1 = decl_new_compiler_variable(4,g_type_unsigned_int);
      pcVar2 = expr_reference_named_entity(pcVar1,iVar11);
      pcVar3 = tree_new_int_constant(local_8);
      pcVar3 = expr_build_builtin_binary('4',pcVar2,pcVar3);
      stmt_emit_expression(pcVar3);
      iVar11 = 0;
      pcVar4 = type_this_pointer(elem_class,0,0);
      pcVar1 = decl_new_compiler_variable(4,pcVar4);
      pcVar3 = expr_reference_named_entity(pcVar1,iVar11);
      pcVar4 = pcVar3->type;
      pcVar5 = tree_new_int_constant(offset);
      pcVar6 = expr_this_pointer((c1_symbol *)0x0);
      pcVar5 = tree_new_node('Q',pcVar6,pcVar5,pcVar4);
      pcVar5 = expr_build_builtin_binary('4',pcVar3,pcVar5);
      stmt_emit_expression(pcVar5);
      iVar11 = 0;
      pcVar4 = type_this_pointer(elem_class,0,0);
      pcVar1 = decl_new_compiler_variable(4,pcVar4);
      pcVar5 = expr_reference_named_entity(pcVar1,iVar11);
      pcVar6 = conv_convert_expression('4',pcVar5->type,inits->left,'\x04','\0');
      pcVar6 = expr_build_builtin_binary('4',pcVar5,pcVar6);
      stmt_emit_expression(pcVar6);
      pcVar6 = label_new(5);
      label_emit_definition(pcVar6);
      iVar11 = 2;
      pcVar7 = expr_build_builtin_unary(0x3d,pcVar5);
      pcVar7 = tree_append_list_item((c1_node *)0x0,pcVar7,iVar11);
      cVar10 = '\x01';
      iVar11 = 1;
      cVar9 = '\x01';
      object = tree_copy_to_arena(pcVar3,0);
      expr_build_call_of((c1_symbol *)0x0,elem_class,object,pcVar7,cVar9,iVar11,cVar10);
      pcVar7 = tree_new_int_constant(1);
      pcVar3 = expr_build_builtin_binary('R',pcVar3,pcVar7);
      stmt_emit_expression(pcVar3);
      pcVar3 = tree_new_int_constant(1);
      pcVar3 = expr_build_builtin_binary('R',pcVar5,pcVar3);
      stmt_emit_expression(pcVar3);
      pcVar3 = tree_new_int_constant(1);
      pcVar3 = expr_build_builtin_binary('8',pcVar2,pcVar3);
      stmt_emit_expression(pcVar3);
      jump_if_true = 1;
      pcVar3 = tree_new_int_constant(0);
      pcVar2 = expr_build_builtin_binary('>',pcVar2,pcVar3);
      stmt_emit_condition(pcVar2,pcVar6,jump_if_true);
      return;
    }
    pcVar4 = type_this_pointer(elem_class,0,0);
    pcVar2 = tree_new_int_constant(offset);
    pcVar3 = expr_this_pointer((c1_symbol *)0x0);
    pcVar2 = tree_new_node('Q',pcVar3,pcVar2,pcVar4);
    iVar11 = 0;
    pcVar3 = tree_new_int_constant(local_8);
    pcVar3 = expr_build_vector_ctor_iterator_call(pcVar2,size,pcVar3,iVar11);
    if (((elem_class->flags1 & 0x20) == 0x20) &&
       ((((elem_class->detail).cls)->implicit_state41 & 0x10) == 0)) {
      pcVar4 = elem_class->type;
      pcVar5 = tree_new_int_constant(local_8);
      pcVar2 = expr_build_vector_dtor_call(pcVar2,size,pcVar5,pcVar4);
      pcVar3 = expr_build_eh_state_update(pcVar3,pcVar2,elem_class);
    }
    stmt_emit_expression(pcVar3);
  }
  return;
}

