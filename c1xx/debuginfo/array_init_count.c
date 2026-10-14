c1xx_pdb_array * __thiscall array_init_count(c1xx_pdb_array *array,uint count)

{
  c1_u32 *pcVar1;
  uint uVar2;
  
  if (count == 0) {
    pcVar1 = (c1_u32 *)0x0;
  }
  else {
    pcVar1 = __2_YAPAXI_Z(count * 4);
  }
  array->data = pcVar1;
  uVar2 = -(uint)(pcVar1 != (c1_u32 *)0x0) & count;
  array->capacity = uVar2;
  array->count = uVar2;
  return array;
}

