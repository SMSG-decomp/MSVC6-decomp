int __cdecl class_check_member_redefinition(void *name)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  
  if (((*(uint *)((int)name + 8) & 0x40000) != 0) && (name != g_name_alignment_member)) {
    pvVar1 = (g_struct_layouts[g_class_depth].tag)->members;
    if (pvVar1 == (void *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = *(int **)((int)pvVar1 + 4);
    }
    if (piVar2 != (int *)0x0) {
      while( true ) {
        if ((void *)*piVar2 == name) {
          diag_error(0x14,name,(g_struct_layouts[g_class_depth].tag)->type);
          iVar3 = class_check_member_redefinition_fragment();
          return iVar3;
        }
        if (piVar2 == (int *)0x0) break;
        piVar2 = (int *)piVar2[1];
        if (piVar2 == (int *)0x0) {
          return 0;
        }
      }
    }
  }
  return 0;
}

