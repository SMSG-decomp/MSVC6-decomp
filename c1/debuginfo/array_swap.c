void __thiscall array_swap(Array_DWORD *array,Array_DWORD *other)

{
  ulong *puVar1;
  uint uVar2;
  
  puVar1 = array->rgt;
  array->rgt = other->rgt;
  other->rgt = puVar1;
  uVar2 = array->itMac;
  array->itMac = other->itMac;
  other->itMac = uVar2;
  uVar2 = array->itMax;
  array->itMax = other->itMax;
  other->itMax = uVar2;
  return;
}

