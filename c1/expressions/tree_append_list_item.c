c1_node * __cdecl tree_append_list_item(c1_node *list,c1_node *expr,int mode)

{
  c1_node *pcVar1;
  
  if (expr == (c1_node *)0x0) {
    return list;
  }
  pcVar1 = expr_check_call_arguments(expr,mode);
  if (pcVar1 != (c1_node *)0x0) {
    pcVar1->right = list;
    if (list != (c1_node *)0x0) {
      pcVar1->link = list->link;
      list->link = pcVar1;
      return pcVar1;
    }
    pcVar1->link = pcVar1;
    return pcVar1;
  }
  return (c1_node *)0x0;
}

