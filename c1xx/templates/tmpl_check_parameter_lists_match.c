void __cdecl tmpl_check_parameter_lists_match(int value,void *key)

{
  ushort *puVar1;
  ushort *puVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  short n;
  
  if ((*(byte *)(*(int *)((int)key + 0x24) + 0x3e) & 2) != 0) {
    pvVar4 = tmpl_lookup_parameter_list(key);
    if (pvVar4 != (void *)0x0) {
      if (value == 0) {
        iVar7 = 0;
      }
      else {
        iVar7 = *(int *)(value + 4);
      }
      iVar5 = *(int *)((int)pvVar4 + 4) + -8;
      iVar6 = iVar7 + -8;
      iVar3 = *(int *)((int)pvVar4 + 4);
      while (iVar5 != 0) {
        if (iVar6 == 0) {
          if (iVar5 == 0) goto LAB_104500c4;
          n = 0x3d6;
          goto LAB_104b76d8;
        }
        puVar1 = *(ushort **)(iVar5 + 0x14);
        puVar2 = *(ushort **)(iVar6 + 0x14);
        if ((puVar1 != puVar2) && (((*puVar1 & 0x200) == 0 || ((*puVar2 & 0x200) == 0)))) {
          diag_error(0x3d8,key,puVar1,puVar2);
        }
        iVar6 = 0;
        if ((iVar3 == 0) || (iVar6 = *(int *)(iVar3 + 4), iVar6 == 0)) {
          iVar5 = 0;
        }
        else {
          iVar5 = iVar6 + -8;
        }
        iVar8 = 0;
        iVar3 = iVar6;
        if ((iVar7 == 0) || (iVar8 = *(int *)(iVar7 + 4), iVar8 == 0)) {
          iVar6 = 0;
          iVar7 = iVar8;
        }
        else {
          iVar6 = iVar8 + -8;
          iVar7 = iVar8;
        }
      }
      if (iVar6 != 0) {
        n = 0x3d7;
LAB_104b76d8:
        diag_error(n,key);
      }
    }
LAB_104500c4:
    tmpl_set_parameter_list((c1_sym_list *)value,key);
  }
  return;
}

