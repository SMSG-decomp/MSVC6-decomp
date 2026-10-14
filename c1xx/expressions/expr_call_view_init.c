void * __thiscall expr_call_view_init(void *view,char *expr)

{
  int *piVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  int *piVar5;
  
  piVar1 = (int *)((int)view + 4);
  *(char **)view = expr;
  piVar5 = piVar1;
  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar5 = 0;
    piVar5 = piVar5 + 1;
  }
  if (expr != (char *)0x0) {
    *piVar1 = (int)expr;
    cVar2 = *expr;
    while (cVar2 != 'p') {
      pcVar3 = *(char **)(*piVar1 + 0x10);
      *piVar1 = (int)pcVar3;
      cVar2 = *pcVar3;
    }
  }
  return view;
}

