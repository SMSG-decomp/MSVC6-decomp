int __fastcall class_member_iter_step(c1_list_cursor *cursor)

{
  void *pvVar1;
  
  if (cursor->current != (void *)0x0) {
    pvVar1 = *(void **)((int)cursor->current + 4);
    cursor->current = pvVar1;
    return CONCAT31((int3)((uint)pvVar1 >> 8),pvVar1 != (void *)0x0);
  }
  return 0;
}

