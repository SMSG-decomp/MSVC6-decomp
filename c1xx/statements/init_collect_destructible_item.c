c1_node * __cdecl init_collect_destructible_item(void *obj_type,c1_node *item)

{
  c1_u8 cVar1;
  c1_symbol *cls_tag;
  c1_node *pcVar2;
  
  if (item == (c1_node *)0x0) {
    return item;
  }
  if ((((*(byte *)((int)obj_type + 1) & 0x10) == 0x10) && (cVar1 = item->op, cVar1 != '.')) &&
     (cVar1 != '`')) {
    if (((cVar1 == 'p') && (*(char *)item->left == -0x67)) &&
       (cls_tag = *(c1_symbol **)(*(int *)((int)item->left + 0x10) + 0x10),
       (cls_tag->flags1 & 0x10) == 0x10)) {
      pcVar2 = init_collect_destructible_item_member(cls_tag,item,obj_type);
      return pcVar2;
    }
    pcVar2 = tree_append_list_item((c1_node *)0x0,item,2);
    return pcVar2;
  }
  return item;
}

