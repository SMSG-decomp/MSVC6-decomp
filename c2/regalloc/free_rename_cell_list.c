void __fastcall free_rename_cell_list(void *list)

{
  int *piVar1;
  void *pvVar2;
  int *piVar3;
  
  piVar1 = *(int **)list;
  if (*(int **)list == (int *)0x0) {
    pvVar2 = list;
    *(void **)list = g_rename_cell_free;
    g_rename_cell_free = pvVar2;
    return;
  }
  do {
    piVar3 = piVar1;
    piVar1 = (int *)*piVar3;
  } while (piVar1 != (int *)0x0);
  pvVar2 = list;
  *piVar3 = (int)g_rename_cell_free;
  g_rename_cell_free = pvVar2;
  return;
}

