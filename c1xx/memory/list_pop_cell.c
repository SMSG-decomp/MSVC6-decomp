void __fastcall list_pop_cell(int *list)

{
  int *piVar1;
  
  if ((list != (int *)0x0) && (piVar1 = (int *)*list, piVar1 != (int *)0x0)) {
    *list = *piVar1;
    *piVar1 = list[1];
    list[1] = (int)piVar1;
  }
  return;
}

