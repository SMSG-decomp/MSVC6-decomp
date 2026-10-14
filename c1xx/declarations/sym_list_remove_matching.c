void __cdecl sym_list_remove_matching(int *paths,c1_symtab *seen)

{
  int iVar1;
  int *piVar2;
  
  if (((paths != (int *)0x0) && (iVar1 = *paths, iVar1 != paths[1])) &&
     (piVar2 = paths, seen != (c1_symtab *)0x0)) {
    while (iVar1 != 0) {
      iVar1 = base_path_has_seen_virtual_base((int *)*piVar2,seen);
      if ((char)iVar1 == '\0') {
        paths[1] = *piVar2;
        piVar2 = (int *)(*piVar2 + 4);
      }
      else {
        *piVar2 = *(int *)(*piVar2 + 4);
      }
      iVar1 = *piVar2;
    }
  }
  return;
}

