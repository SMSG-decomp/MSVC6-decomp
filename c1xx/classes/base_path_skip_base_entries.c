int * __cdecl base_path_skip_base_entries(int *cell)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = cell;
  while ((piVar1 = cell, piVar1 != (int *)0x0 && ((*(byte *)piVar1[2] & 0x1f) == 0xf))) {
    cell = (int *)*piVar1;
    piVar2 = piVar1;
  }
  return piVar2;
}

