void __fastcall pass_remove_redundant_branches(c2_function *fn)

{
  int iVar1;
  
  iVar1 = remove_redundant_branches_once(fn);
  while (iVar1 != 0) {
    iVar1 = remove_redundant_branches_once(fn);
  }
  return;
}

