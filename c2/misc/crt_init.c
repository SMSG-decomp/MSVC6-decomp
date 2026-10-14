int crt_init(HMODULE module,uint32_t reason,void *reserved)

{
  void **_Memory;
  int iVar1;
  void **ppvVar2;
  
  if (reason == 0) {
    if (0 < __proc_attached) {
      __proc_attached = __proc_attached + -1;
      goto LAB_107500ab;
    }
LAB_10797fd4:
    iVar1 = 0;
  }
  else {
LAB_107500ab:
    __adjust_fdiv = *(int *)_adjust_fdiv_exref;
    if (reason == 1) {
      g_onexit_begin = malloc(0x80);
      if (g_onexit_begin == (void **)0x0) goto LAB_10797fd4;
      *g_onexit_begin = (void *)0x0;
      __onexitend = g_onexit_begin;
      _initterm(&__xc_a,&__xc_z);
      __proc_attached = __proc_attached + 1;
    }
    else if ((reason == 0) &&
            (_Memory = g_onexit_begin, ppvVar2 = __onexitend, g_onexit_begin != (void **)0x0)) {
      while (ppvVar2 = ppvVar2 + -1, _Memory <= ppvVar2) {
        if (*ppvVar2 != (code *)0x0) {
          (**ppvVar2)();
          _Memory = g_onexit_begin;
        }
      }
      free(_Memory);
      g_onexit_begin = (void **)0x0;
    }
    iVar1 = 1;
  }
  return iVar1;
}

