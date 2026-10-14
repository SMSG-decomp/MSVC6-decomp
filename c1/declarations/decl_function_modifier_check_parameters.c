void __thiscall decl_function_modifier_check_parameters(void *modifier,int list,int kind)

{
  int *piVar1;
  int *piVar2;
  
  if (kind == 2) {
    if (g_ms_extensions != '\0') {
      if (list == 0) {
        piVar1 = (int *)0x0;
      }
      else {
        piVar1 = *(int **)(list + 4);
      }
      if (piVar1 != (int *)0x0) {
        do {
          piVar2 = piVar1;
          if (piVar2 == (int *)0x0) break;
          piVar1 = (int *)piVar2[1];
        } while ((int *)piVar2[1] != (int *)0x0);
        if ((piVar2 != (int *)0x8) && ((void *)*piVar2 == g_name_ellipsis)) {
          *(byte *)((int)modifier + 3) = *(byte *)((int)modifier + 3) | 0x80;
        }
      }
    }
    list = 0;
  }
  piVar1 = decl_check_void_parameter((void *)list,(c1_u8 *)((int)modifier + 2),kind);
  *(int **)((int)modifier + 8) = piVar1;
  return;
}

