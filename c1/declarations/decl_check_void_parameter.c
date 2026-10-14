int * __cdecl decl_check_void_parameter(void *list,c1_u8 *fn_type,int context)

{
  byte *pbVar1;
  bool bVar2;
  uchar *list_00;
  int iVar3;
  c1_param_list *pcVar4;
  byte bVar5;
  uchar *puVar6;
  int iVar7;
  
  if (list == (void *)0x0) {
    fn_type[1] = fn_type[1] | 0x20;
    pcVar4 = decl_empty_parameter_list();
    return &pcVar4->count;
  }
  if (context != 5) {
    iVar3 = *(int *)((int)list + 4);
    iVar7 = 0;
    bVar2 = false;
    if (iVar3 == 0) {
      fn_type[1] = fn_type[1] | 0x20;
      pcVar4 = decl_empty_parameter_list();
      return &pcVar4->count;
    }
LAB_10608265:
    bVar5 = *(byte *)(iVar3 + -8) & 0x1f;
    if ((bVar5 == 0xb) || (bVar5 == 0xc)) {
      if (*(c1_type **)(iVar3 + 0xc) == g_type_void) {
        bVar2 = true;
      }
      iVar7 = iVar7 + 1;
      if ((*(c1_type **)(iVar3 + 0xc))->code == 0x80d) {
        fn_type[1] = fn_type[1] | 0x80;
LAB_1060829a:
        list_00 = g_arenas[3].cur;
        if (!bVar2) {
          if (iVar7 == 0) {
            fn_type[1] = fn_type[1] | 0x20;
            pcVar4 = decl_empty_parameter_list();
            return &pcVar4->count;
          }
          g_arenas[3].cur = g_arenas[3].cur + iVar7 * 4 + 8;
          if (g_arenas[3].end < g_arenas[3].cur) {
            arena_grow(g_arenas + 3);
          }
          *(int *)list_00 = iVar7;
          puVar6 = list_00 + 8;
          for (iVar3 = *(int *)((int)list + 4); iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
            bVar5 = *(byte *)(iVar3 + -8) & 0x1f;
            if ((bVar5 == 0xb) || (bVar5 == 0xc)) {
              *(undefined4 *)puVar6 = *(undefined4 *)(iVar3 + 0xc);
              puVar6 = puVar6 + 4;
            }
            if (iVar3 == 0) break;
          }
          pcVar4 = type_intern_parameter_list((c1_param_list *)list_00);
          return &pcVar4->count;
        }
        if ((iVar7 != 1) && ((*(byte *)(*(int *)((int)list + 4) + -6) & 1) == 0)) {
          diag_error(0x35c);
          pbVar1 = (byte *)(*(int *)((int)list + 4) + -6);
          *pbVar1 = *pbVar1 | 1;
        }
        goto LAB_10608336;
      }
    }
    if ((iVar3 == 0) || (iVar3 = *(int *)(iVar3 + 4), iVar3 == 0)) goto LAB_1060829a;
    goto LAB_10608265;
  }
LAB_10608336:
  fn_type[1] = fn_type[1] | 0x40;
  pbVar1 = (byte *)(*(int *)((int)list + 4) + -7);
  *pbVar1 = *pbVar1 | 2;
  pcVar4 = decl_void_parameter_list();
  return &pcVar4->count;
}

