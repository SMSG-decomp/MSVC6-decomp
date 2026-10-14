c1_arg_item * __thiscall
pch_fixup_list_object_ctor(c1_arg_item *item,c1_type *type,c1_u8 given_explicitly)

{
  item->next = (c1_arg_item *)0x0;
  item->prev = (c1_arg_item *)0x0;
  item->vtbl = &PTR_pch_fixup_list_object_104c4c3c;
  item->kind = (given_explicitly & 1) << 2 | item->kind & 0xf8;
  (item->value).type = type;
  return item;
}

