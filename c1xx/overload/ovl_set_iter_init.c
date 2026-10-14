c1xx_ovl_set_iter * __thiscall ovl_set_iter_init(c1xx_ovl_set_iter *iter,void *set)

{
  byte bVar1;
  
  iter->next = (c1_sym_link *)0x0;
  iter->current = (c1_sym_link *)0x0;
  iter->start = set;
  iter->vtbl = (c1xx_ovl_set_iter_vtbl *)&PTR_ovl_set_iter_next_104bcaf0;
  if (set != (void *)0x0) {
    bVar1 = *(byte *)((int)set + -8) & 0x1f;
    if ((((bVar1 != 7) && (bVar1 != 8)) && (bVar1 != 6)) &&
       ((*(byte *)((int)set + -8) & 0x1f) != 0x1a)) {
      set = *(void **)((int)set + 0xc);
    }
    iter->next = set;
  }
  return iter;
}

