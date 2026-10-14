void * __cdecl name_intern_numbered(int n)

{
  void *pvVar1;
  char local_20 [32];
  
  sprintf(local_20,"$N%u",n);
  pvVar1 = name_intern(local_20);
  return pvVar1;
}

