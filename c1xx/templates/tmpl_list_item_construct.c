c1_arg_item * __thiscall tmpl_list_item_construct(c1_arg_item *item,byte kind,byte flag)

{
  item->next = (c1_arg_item *)0x0;
  item->prev = (c1_arg_item *)0x0;
  item->vtbl = &PTR_pch_mark_object_links_104ca9b4;
  item->kind = item->kind & 0xf8 ^ kind & 3 | (flag & 1) << 2;
  return item;
}

