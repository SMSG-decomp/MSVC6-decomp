void __thiscall using_cell_release(void *list,int ns)

{
  int *piVar1;
  
  for (piVar1 = *(int **)list; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
    if (*piVar1 == ns) goto LAB_10493268;
  }
  piVar1 = (int *)0x0;
LAB_10493268:
  piVar1[2] = piVar1[2] + -1;
  return;
}

