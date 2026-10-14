c1_node * __cdecl expr_build_call_with_temporaries(c1_node *node,c1_symbol *fn,ushort ret_code)

{
  c1_type *type;
  void *pvVar1;
  bool bVar2;
  c1_u8 *pcVar3;
  byte bVar4;
  c1_type *type_00;
  uint entity;
  c1_node *pcVar5;
  c1_type *pcVar6;
  c1_node *pcVar7;
  c1_node *pcVar8;
  ushort uVar9;
  c1_node *left;
  int flag;
  c1_node *local_8;
  uint position;
  c1_node *args;
  
  pcVar8 = node;
  if ((fn == (c1_symbol *)0x0) || (bVar2 = true, (fn->flags1 & 0x10) != 0x10)) {
    bVar2 = false;
  }
  type = node->type;
  args = node->right;
  node->flags = (node->flags ^ (type->code & 0xfff) == 0x10) & 1 ^ node->flags;
  if ((args != (c1_node *)0x0) && (args->op == '7')) {
    pvVar1 = args->left;
    args->left = args->right;
    args->right = node->left;
    node->left = args;
    node->right = pvVar1;
  }
  if ((ret_code & 0x8000) != 0) {
    local_8 = node;
    if ((type->code & 0x200) == 0) {
      node = (c1_node *)0x0;
    }
    else {
      node = (c1_node *)(type->extra).cls;
    }
    left = pcVar8;
    if (pcVar8->op == '7') {
      left = pcVar8->right;
    }
    type_00 = type_this_pointer((c1_symbol *)node,0,0);
    pcVar6 = type;
    entity = sym_new_local_key();
    pcVar5 = tree_new_leaf_9c(entity,pcVar6);
    pcVar6 = type_pointer_with_qualifiers(type,0);
    pcVar5 = tree_new_cast(pcVar6,pcVar5);
    pcVar7 = tree_append_list_item((c1_node *)0x0,pcVar5,2);
    pcVar7->type = type_00;
    if (left->right == (void *)0x0) {
      left->right = pcVar7;
    }
    else {
      pcVar7->link = *(c1_node **)((int)left->right + 8);
      *(c1_node **)(*(int *)((int)left->right + 8) + 0x14) = pcVar7;
      *(c1_node **)((int)left->right + 8) = pcVar7;
    }
    left->type = type_00;
    pcVar8->type = type_00;
    bVar4 = class_type_needs_destructor_call(type_00);
    pcVar7 = local_8;
    if (bVar4 != 0) {
      pcVar7 = expr_build_destructor_call((c1_symbol *)node,pcVar5,3,1,0);
      pcVar7 = expr_build_eh_state_update(left,pcVar7,(c1_symbol *)node);
      if (pcVar8->op == '7') {
        pcVar8->right = pcVar7;
        pcVar7 = local_8;
      }
    }
    local_8 = pcVar7;
    eh_register_temporary_destructor(pcVar5,type_00);
    node = local_8;
  }
  if (node != (c1_node *)0x0) {
    bVar4 = (byte)node->type->code;
    if (((char)bVar4 < '\0') && ((bVar4 & 0x8f) == 0x80)) {
      node = expr_build_builtin_unary(0x3d,node);
      node->kind = node->kind | 0x10;
    }
    else if (bVar2) {
      node = expr_build_builtin_unary(0x3d,node);
      if ((node != (c1_node *)0x0) &&
         ((((g_scope_vector->entries[(short)fn->scope_index]->detail).cls)->layout_flags3b & 0x10)
          != 0)) {
        pvVar1 = node->left;
        flag = 2;
        pcVar8 = tree_new_int_constant(1);
        pcVar8 = tree_append_list_item(*(c1_node **)((int)pvVar1 + 0x14),pcVar8,flag);
        *(c1_node **)((int)pvVar1 + 0x14) = pcVar8;
      }
    }
    else if ((ret_code & 0x8000) == 0) {
      if ((ret_code & 0x4000) == 0) {
        bVar4 = (byte)type->code;
        if (((char)bVar4 < '\0') && ((bVar4 & 0x8f) == 0x82)) {
          uVar9 = type->flags & 0x18;
          if (uVar9 == 0x18) {
            node = expr_based_pointer_fixup(node);
          }
          else if (uVar9 == 8) {
            pcVar8 = expr_build_call_with_temporaries_based_return(fn,node);
            return pcVar8;
          }
        }
      }
      else {
        node = expr_spill_and_comma(node);
      }
    }
    else {
      node = expr_build_builtin_unary(0x3d,node);
      node->kind = node->kind | 0x20;
      if (node->type != type) {
        pcVar8 = expr_build_call_with_temporaries_retype(fn,node,type);
        return pcVar8;
      }
    }
    pcVar3 = g_arenas[0].cur;
    if ((g_opt_Ct != '\0') && (g_inline_level != 0)) {
      g_arenas[0].cur = g_arenas[0].cur + 8;
      position = ((g_current_function->tail).fn.record)->unk14;
      if (g_arenas[0].end < g_arenas[0].cur) {
        arena_grow(g_arenas);
      }
      *(c1_symbol **)pcVar3 = fn;
      *(uint *)(pcVar3 + 4) = position;
      ((g_current_function->tail).fn.record)->unk14 = (c1_u32)pcVar3;
    }
    return node;
  }
  return (c1_node *)0x0;
}

