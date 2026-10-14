c1_node * __cdecl
expr_build_helper_call_4
          (c1_node *item,int value,c1_node *item2,c1_node *item3,c1_node *item4,c1_node *left)

{
  uint uVar1;
  c1_node *pcVar2;
  c1_node *item_00;
  c1_type *pcVar3;
  int flag;
  c1_type local_10;
  
  pcVar3 = item->type;
  if ((pcVar3->flags & 0x3e0) != 0) {
    uVar1._0_2_ = pcVar3->code;
    uVar1._2_2_ = pcVar3->flags;
    local_10.base = pcVar3->base;
    local_10.extra = pcVar3->extra;
    local_10._0_4_ = uVar1 & 0xfc1fffff;
    local_10.debug_index = pcVar3->debug_index;
    pcVar3 = type_intern(&local_10);
  }
  item->type = pcVar3;
  pcVar2 = tree_append_list_item((c1_node *)0x0,item,2);
  flag = 2;
  item_00 = tree_new_int_constant(value);
  pcVar2 = tree_append_list_item(pcVar2,item_00,flag);
  pcVar2 = tree_append_list_item(pcVar2,item2,2);
  pcVar2 = tree_append_list_item(pcVar2,item3,2);
  if (item4 != (c1_node *)0x0) {
    pcVar2 = tree_append_list_item(pcVar2,item4,2);
  }
  pcVar2 = (c1_node *)expr_build_call(left,pcVar2);
  return pcVar2;
}

