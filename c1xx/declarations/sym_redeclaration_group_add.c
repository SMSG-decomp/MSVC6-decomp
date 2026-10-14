void __thiscall sym_redeclaration_group_add(void *list,c1_symbol *sym)

{
  byte *pbVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  piVar3 = sym_list_1b58_lookup(sym);
  piVar4 = *(int **)list;
  iVar2 = *piVar3;
  if (piVar4 != (int *)0x0) {
    do {
      if (*piVar4 == iVar2) break;
      piVar4 = (int *)piVar4[3];
    } while (piVar4 != (int *)0x0);
    if (piVar4 != (int *)0x0) goto LAB_10499c05;
  }
  piVar4 = arena_alloc(g_arenas + 1,0x10);
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    *piVar4 = iVar2;
    piVar4[1] = 0;
    piVar4[2] = 0;
    piVar4[3] = 0;
  }
  if (*(int *)list == 0) {
    *(int **)list = piVar4;
  }
  else if (*(int *)((int)list + 4) != 0) {
    *(int **)(*(int *)((int)list + 4) + 0xc) = piVar4;
  }
  *(int **)((int)list + 4) = piVar4;
LAB_10499c05:
  sorted_list_insert(piVar4 + 1,piVar3[1]);
  pbVar1 = (byte *)((int)&sym->tail + 10);
  *pbVar1 = *pbVar1 & 0x7f;
  return;
}

