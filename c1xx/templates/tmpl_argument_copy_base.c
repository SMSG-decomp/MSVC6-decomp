void __thiscall tmpl_argument_copy_base(c1_arg_item *copy,c1_arg_item *src)

{
  byte bVar1;
  byte bVar2;
  
  copy->next = (c1_arg_item *)0x0;
  copy->prev = (c1_arg_item *)0x0;
  bVar2 = (copy->kind ^ src->kind) & 3 ^ copy->kind;
  copy->kind = bVar2;
  bVar1 = src->kind;
  copy->vtbl = &PTR_pch_mark_object_links_104ca9b4;
  copy->kind = (bVar2 ^ bVar1) & 4 ^ bVar2;
  return;
}

