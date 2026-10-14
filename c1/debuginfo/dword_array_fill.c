void __thiscall dword_array_fill(Array_DWORD *array,c1_u32 *value)

{
  uint uVar1;
  
  uVar1 = 0;
  if (array->itMac != 0) {
    do {
      array->rgt[uVar1] = *value;
      uVar1 = uVar1 + 1;
    } while (uVar1 < array->itMac);
  }
  return;
}

