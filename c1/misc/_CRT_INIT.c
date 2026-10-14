int _CRT_INIT(void *hinst,int reason,void *reserved)

{
  uint *onexit_begin;
  int iVar1;
  uint *onexit_cursor;
  
  if (reason == 0) {
    if (0 < __proc_attached) {
      __proc_attached = __proc_attached + -1;
      goto LAB_10617daa;
    }
LAB_1065122b:
    iVar1 = 0;
  }
  else {
LAB_10617daa:
    _adjust_fdiv = *(int *)_adjust_fdiv_exref;
    if (reason == 1) {
      __onexitbegin = malloc(0x80);
      if (__onexitbegin == (uint *)0x0) goto LAB_1065122b;
      *__onexitbegin = 0;
      __onexitend = __onexitbegin;
      _initterm(&__xc_a,&__xc_z);
      __proc_attached = __proc_attached + 1;
    }
    else if ((reason == 0) &&
            (onexit_begin = __onexitbegin, onexit_cursor = __onexitend, __onexitbegin != (uint *)0x0
            )) {
      while (onexit_cursor = onexit_cursor + -1, onexit_begin <= onexit_cursor) {
        if ((code *)*onexit_cursor != (code *)0x0) {
          (*(code *)*onexit_cursor)();
          onexit_begin = __onexitbegin;
        }
      }
      free(onexit_begin);
      __onexitbegin = (uint *)0x0;
    }
    iVar1 = 1;
  }
  return iVar1;
}

