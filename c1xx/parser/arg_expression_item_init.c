c1_arg_item * __thiscall
arg_expression_item_init(c1_arg_item *item,c1_node *expr,c1_u8 given_explicitly,char keep_tree)

{
  c1_node *pcVar1;
  
  item->next = (c1_arg_item *)0x0;
  item->prev = (c1_arg_item *)0x0;
  item->vtbl = &PTR_pch_fixup_tree_list_object_104bcbcc;
  item->kind = item->kind & 0xf8 ^ 1 | (given_explicitly & 1) << 2;
  if (keep_tree != '\0') {
    (item->value).expr = expr;
    return item;
  }
  pcVar1 = tree_copy_to_arena(expr,0);
  (item->value).expr = pcVar1;
  return item;
}

