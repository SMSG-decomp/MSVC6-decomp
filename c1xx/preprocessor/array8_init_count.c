void * __thiscall array8_init_count(void *array,uint n)

{
  void *pvVar1;
  uint uVar2;
  
  if (n == 0) {
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = __2_YAPAXI_Z(n * 8);
  }
  *(void **)array = pvVar1;
  uVar2 = -(uint)(pvVar1 != (void *)0x0) & n;
  *(uint *)((int)array + 8) = uVar2;
  *(uint *)((int)array + 4) = uVar2;
  return array;
}

