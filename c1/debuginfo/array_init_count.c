Array_DWORD * __thiscall array_init_count(Array_DWORD *array,uint n)

{
  ulong *puVar1;
  uint uVar2;
  
  if (n == 0) {
    puVar1 = (ulong *)0x0;
  }
  else {
    puVar1 = __2_YAPAXI_Z(n * 4);
  }
  array->rgt = puVar1;
  uVar2 = -(uint)(puVar1 != (ulong *)0x0) & n;
  array->itMax = uVar2;
  array->itMac = uVar2;
  return array;
}

