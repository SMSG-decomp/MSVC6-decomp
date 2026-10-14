void * __fastcall tmpl_enclosing_class_scope(void *scope)

{
  void *pvVar1;
  
  for (pvVar1 = *(void **)((int)scope + 4);
      (pvVar1 != (void *)0x0 && (*(byte *)((int)pvVar1 + 8) < 0xfb));
      pvVar1 = *(void **)((int)pvVar1 + 4)) {
  }
  return pvVar1;
}

