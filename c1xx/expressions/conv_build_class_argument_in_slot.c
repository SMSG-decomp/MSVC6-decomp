c1_node * __fastcall conv_build_class_argument_in_slot(c1_conversion *conv)

{
  c1_type *type;
  uint entity;
  c1_node *pcVar1;
  c1_node *pcVar2;
  int iVar3;
  c1_node *item;
  
  type = type_pointer_with_qualifiers(conv->target,0);
  entity = sym_new_local_key();
  pcVar1 = tree_new_leaf_9c(entity,type);
  pcVar2 = tree_new_leaf_9c((int)pcVar1->left,pcVar1->type);
  pcVar2 = tree_new_unary('=',pcVar1->type,pcVar2);
  iVar3 = type_size(conv->target);
  pcVar1 = tree_new_argument_slot_intrinsic(conv->target,iVar3,pcVar1);
  if (pcVar2 != (c1_node *)0x0) {
    conv->target_symbol = (c1_symbol *)0x0;
    conv->target_kind = 5;
    pcVar2 = conv_apply_conversion(conv,pcVar2);
    pcVar2 = expr_build_address_of(pcVar2,2);
    iVar3 = type_size(conv->target);
    item = tree_new_int_constant(iVar3);
    pcVar2 = tree_append_list_item((c1_node *)0x0,pcVar2,2);
    pcVar1 = tree_append_list_item(pcVar2,pcVar1,2);
    pcVar1 = tree_append_list_item(pcVar1,item,2);
    pcVar2 = tree_new_int_constant(0xdf);
    pcVar1 = tree_new_binary('w',pcVar2,pcVar1);
    pcVar1->type = conv->target;
    return pcVar1;
  }
  diag_fatal(1,".\\convert.cpp",0x160e);
}

