c1_node * __cdecl expr_build_throw(c1_node *node)

{
  void *pvVar1;
  byte bVar2;
  c1_node *pcVar3;
  c1_node *pcVar4;
  c1_symbol *sym;
  uint uVar5;
  c1_type *type;
  c1_vector *local_8;
  c1_node *local_4;
  
  local_8 = (c1_vector *)0x0;
  if (node == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  pcVar3 = expr_resolve_address_of_overload(node);
  type = pcVar3->type;
  if (((type->code == 0x80c) || (pcVar4 = pcVar3, type->code == 0x80e)) &&
     (pcVar4 = expr_resolve_function_address((c1_type *)0x0,pcVar3), pcVar4 == (c1_node *)0x0)) {
    expr_report_function_operand(0xac,pcVar3);
    return (c1_node *)0x0;
  }
  sym = eh_throw_info_symbol(type,&local_8);
  if (sym == (c1_symbol *)0x0) {
    return (c1_node *)0x0;
  }
  if (local_8 != (c1_vector *)0x0) {
    bVar2 = (byte)type->code;
    pvVar1 = *local_8->data;
    if (((char)bVar2 < '\0') && ((bVar2 & 0x8f) == 0x80)) {
      type = type->base;
    }
    uVar5 = sym_new_local_key();
    pcVar3 = tree_new_leaf_9c(uVar5,type);
    local_4 = tree_new_leaf_9c(uVar5,PTR_104d152c);
    if ((*(int *)((int)pvVar1 + 0x10) == 0) ||
       ((*(byte *)(*(int *)(*(int *)((int)pvVar1 + 0x18) + 0x24) + 0x41) & 4) != 0)) {
      pcVar3 = tree_new_binary('4',pcVar3,pcVar4);
    }
    else {
      pcVar4 = tree_append_list_item((c1_node *)0x0,pcVar4,2);
      pcVar3 = expr_build_call_node(*(c1_symbol **)((int)pvVar1 + 0x10),pcVar3,(int)pcVar4,0,1,0);
      if (pcVar3 == (c1_node *)0x0) {
        return (c1_node *)0x0;
      }
      pcVar3->type = PTR_104d152c;
    }
    uVar5 = 4;
    pcVar4 = expr_reference_named_entity(sym,0);
    pcVar4 = expr_build_address_of(pcVar4,uVar5);
    pcVar4 = expr_build_throw_intrinsic_call(local_4,pcVar4);
    pcVar3 = expr_build_binary('7',pcVar3,pcVar4);
    return pcVar3;
  }
  return (c1_node *)0x0;
}

