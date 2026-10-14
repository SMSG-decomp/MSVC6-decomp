c1_node * __cdecl tree_append_list_item(c1_node *list,c1_node *item,int flag)

{
  c1_node *left;
  c1_type *type;
  c1_node *pcVar1;
  
  if ((item != (c1_node *)0x0) && (item->op == 0xe8)) {
    item = property_build_access('t',item,(c1_node *)0x0);
  }
  left = expr_resolve_address_of_overload(item);
  type = g_type_none;
  if (flag != 1) {
    if (left == (c1_node *)0x0) {
      type = (c1_type *)0x0;
    }
    else {
      type = left->type;
    }
  }
  pcVar1 = tree_new_node('`',left,list,type);
  if ((left != (c1_node *)0x0) && ((left->kind & 8) != 0)) {
    pcVar1->kind = pcVar1->kind | 8;
  }
  if (list == (c1_node *)0x0) {
    pcVar1->link = pcVar1;
  }
  else {
    pcVar1->link = list->link;
    list->link = pcVar1;
  }
  if (left != (c1_node *)0x0) {
    left->link = pcVar1;
  }
  return pcVar1;
}

