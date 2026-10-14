c1_node * __cdecl
init_collect_destructible_item_member(c1_symbol *cls_tag,c1_node *item,void *obj_type)

{
  c1_node *pcVar1;
  
  if (obj_type == g_scope_vector->entries[(short)cls_tag->scope_index]) {
    return item->right;
  }
  pcVar1 = tree_append_list_item((c1_node *)0x0,item,2);
  return pcVar1;
}

