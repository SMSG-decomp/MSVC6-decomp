int __cdecl lookup_adl_class_and_bases(int cls,int name,int found)

{
  int *piVar1;
  c1_symbol *cls_00;
  int *piVar2;
  int *piVar3;
  
  found = lookup_adl_class_namespace(cls,name,found);
  if (*(int *)(cls + 0x28) == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = *(int **)(*(int *)(cls + 0x28) + 4);
  }
  piVar3 = (int *)0x0;
  if (piVar1 != (int *)0x0) {
    piVar3 = piVar1;
  }
  do {
    while( true ) {
      piVar2 = piVar3;
      if (piVar2 == (int *)0x0) {
        return found;
      }
      if ((piVar1 == (int *)0x0) ||
         (piVar3 = (int *)piVar1[1], piVar1 = piVar3, piVar3 == (int *)0x0)) {
        piVar3 = (int *)0x0;
      }
      if ((*(byte *)(piVar2 + -2) & 0x1f) == 3) break;
      if ((((g_compile_flags_cc & 0x100000) == 0) || ((*(byte *)(piVar2 + -2) & 0x1f) != 0xf)) ||
         ((*(byte *)((int)piVar2 + 0x12) & 2) == 0)) {
        if ((*(byte *)(piVar2 + -2) & 0x1f) != 0xf) {
          return found;
        }
        if ((*(byte *)((int)piVar2 + 0x12) & 2) == 0) {
          cls_00 = g_scope_vector->entries[(short)piVar2[4]];
        }
        else {
          cls_00 = (c1_symbol *)0x0;
        }
        found = lookup_adl_class_and_bases((int)cls_00,name,found);
      }
    }
  } while (((void *)*piVar2 == g_name_vbptr) || ((void *)*piVar2 == g_name_vfptr));
  return found;
}

