c2_seh_try_scope * __fastcall seh_find_try_record(c2_seh_try_scope *list,int level)

{
  if (level == -1) {
    list = (c2_seh_try_scope *)0x0;
  }
  else {
    while( true ) {
      if (list == (c2_seh_try_scope *)0x0) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\except.c",0x53e);
      }
      if (list->level == level) break;
      list = list->next;
    }
  }
  return list;
}

