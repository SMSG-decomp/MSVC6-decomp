void _OverlayIAT__YGXPAU_IMAGE_THUNK_DATA32__PBU1__Z(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = *param_1;
  piVar2 = param_1;
  while (iVar1 != 0) {
    piVar2 = piVar2 + 1;
    iVar3 = iVar3 + 1;
    iVar1 = *piVar2;
  }
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

