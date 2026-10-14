void __cdecl decl_compare_parameter_lists(int newp,int oldp)

{
  char cVar1;
  c1_type *pcVar2;
  c1_type *pcVar3;
  c1_type *pcVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  c1_type **new_param;
  
  iVar6 = oldp;
  oldp = **(int **)(oldp + 0xc);
  iVar7 = **(int **)(newp + 0xc);
  if (oldp < iVar7) {
    if (g_ms_extensions == '\0') {
      diag_error(0xbe);
    }
    else {
      diag_warning(1,0x1e);
    }
  }
  else {
    bVar5 = iVar7 < oldp;
    oldp = iVar7;
    if (bVar5) {
      if (g_ms_extensions == '\0') {
        diag_error(0xbf);
      }
      else {
        diag_warning(1,0x1f);
      }
    }
  }
  iVar7 = 1;
  new_param = (c1_type **)(*(int *)(newp + 0xc) + 8);
  piVar8 = (int *)(*(int *)(iVar6 + 0xc) + 8);
  if (0 < oldp) {
    do {
      pcVar2 = *new_param;
      pcVar3 = (c1_type *)*piVar8;
      if ((pcVar2 != pcVar3) && ((g_compile_flags_cc & 0x200000) != 0)) {
        cVar1 = (char)pcVar2->code;
        pcVar4 = pcVar2;
        while (cVar1 < '\0') {
          pcVar4 = pcVar4->base;
          cVar1 = (char)pcVar4->code;
        }
        if ((pcVar4->code & 0xfff) != 0x801) {
          cVar1 = (char)pcVar3->code;
          pcVar4 = pcVar3;
          while (cVar1 < '\0') {
            pcVar4 = pcVar4->base;
            cVar1 = (char)pcVar4->code;
          }
          if ((pcVar4->code & 0xfff) != 0x801) {
            cVar1 = (char)pcVar2->code;
            while (cVar1 < '\0') {
              pcVar2 = pcVar2->base;
              cVar1 = (char)pcVar2->code;
            }
            cVar1 = (char)pcVar3->code;
            while (cVar1 < '\0') {
              pcVar3 = pcVar3->base;
              cVar1 = (char)pcVar3->code;
            }
            if (pcVar2->code != pcVar3->code) {
              if (g_ms_extensions == '\0') {
                diag_error(0xc0,iVar7);
              }
              else {
                diag_warning(1,0x1c);
              }
            }
          }
        }
      }
      iVar7 = iVar7 + 1;
      new_param = new_param + 1;
      piVar8 = piVar8 + 1;
    } while (iVar7 <= oldp);
  }
  return;
}

