uint __cdecl sym_list_has_flagged_scope_entry(int paths_rec)

{
  int *piVar1;
  
  piVar1 = (int *)**(int **)(paths_rec + 0x14);
  if (piVar1 != (int *)0x0) {
    paths_rec = CONCAT31((int3)((uint)paths_rec >> 8),1);
    do {
      if (((*(byte *)piVar1[2] & 0x1f) == 0xf) && ((((byte *)piVar1[2])[0x1a] & 1) != 0)) {
        return paths_rec;
      }
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)0x0);
  }
  return paths_rec & 0xffffff00;
}

