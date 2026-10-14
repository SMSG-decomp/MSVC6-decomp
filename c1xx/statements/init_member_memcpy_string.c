void __cdecl init_member_memcpy_string(c1_type *t,int offset,c1_node *str)

{
  int iVar1;
  c1_type *target;
  c1_node *pcVar2;
  c1_node *pcVar3;
  int iVar4;
  c1_node *item;
  c1_type *type;
  c1_type local_10;
  
  iVar1 = type_array_element_count(t[1].base,&t);
  if (iVar1 != 0) {
    local_10.flags = decl_apply_default_calling_convention(0x82,0);
    local_10.debug_index = 0;
    local_10.code = 0x82;
    local_10.base = t;
    local_10.extra.cls = (c1_symbol *)0x0;
    target = type_intern(&local_10);
    type = target;
    pcVar2 = tree_new_int_constant(offset);
    pcVar3 = expr_this_pointer((c1_symbol *)0x0);
    pcVar2 = tree_new_node('Q',pcVar3,pcVar2,type);
    pcVar3 = conv_convert_expression('t',target,str->left,'\x04','\0');
    iVar4 = type_size(t);
    item = tree_new_int_constant(iVar4 * iVar1);
    pcVar2 = tree_append_list_item((c1_node *)0x0,pcVar2,1);
    pcVar2 = tree_append_list_item(pcVar2,pcVar3,1);
    pcVar2 = tree_append_list_item(pcVar2,item,1);
    stmt_emit_intrinsic_call(0xac,pcVar2);
  }
  return;
}

