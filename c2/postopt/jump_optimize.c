int __fastcall jump_optimize(c2_function *fn)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = jump_optimize_sweep(fn);
  while ((iVar1 != 0 && (iVar2 = iVar2 + 1, iVar2 < 0x11))) {
    iVar1 = jump_optimize_sweep(fn);
  }
  return iVar1;
}

