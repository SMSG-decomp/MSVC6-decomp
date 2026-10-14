void __thiscall class_member_iter_init(c1_member_iter *iter,void *cls_entry,int filter)

{
  void *pvVar1;
  
  if (*(int *)((int)cls_entry + 0x20) == 0) {
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = *(void **)(*(int *)((int)cls_entry + 0x20) + 4);
  }
  iter->cls = cls_entry;
  iter->filter = filter;
  (iter->cursor).current = pvVar1;
  (iter->cursor).valid = pvVar1 != (void *)0x0;
  iter->current = (void *)0x0;
  iter->next = (void *)0x0;
  if (pvVar1 != (void *)0x0) {
    iter->next = pvVar1;
  }
  return;
}

