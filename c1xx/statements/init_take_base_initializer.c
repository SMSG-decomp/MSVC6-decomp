c1_node * __cdecl init_take_base_initializer(int *list,byte *base)

{
  int iVar1;
  byte *pbVar2;
  c1_u8 *pcVar3;
  byte *pbVar4;
  char *pcVar5;
  int *piVar6;
  bool bVar7;
  c1_node *local_8;
  uint *local_4;
  
  iVar1 = *list;
  local_8 = (c1_node *)0x0;
  local_4 = (uint *)0x0;
  piVar6 = list;
  do {
    if (iVar1 == 0) {
LAB_1041b53a:
      if ((g_opt_Zg == '\0') && (local_4 != (uint *)0x0)) {
        eh_build_throw_info(local_4,0);
      }
      return local_8;
    }
    list = (int *)0x0;
    pcVar5 = *(char **)(*piVar6 + 0x10);
    if ((pcVar5 != (char *)0x0) && (*pcVar5 == -0x4b)) {
      list = *(int **)(pcVar5 + 0x14);
      pcVar5 = *(char **)(pcVar5 + 0x10);
    }
    pbVar4 = *(byte **)(*(int *)(pcVar5 + 0x10) + 0x10);
    if ((*pbVar4 & 0x1f) == 0x12) {
      if ((((*base & 0x1f) != 0xf) ||
          (g_scope_vector->entries[*(short *)(base + 0x18)] == (c1_symbol *)0x0)) ||
         (((*(uint *)(*(int *)(**(int **)(pbVar4 + 0x14) + 8) + 0x1c) ^
           g_scope_vector->entries[*(short *)(base + 0x18)]->entity) & 0xffffff) != 0))
      goto LAB_1041b606;
LAB_1041b591:
      local_4 = (uint *)list;
      *piVar6 = *(int *)(*piVar6 + 0x14);
      local_8 = *(c1_node **)(pcVar5 + 0x14);
      goto LAB_1041b53a;
    }
    if (*(void **)(pbVar4 + 8) == *(void **)(base + 8)) goto LAB_1041b591;
    bVar7 = false;
    if ((pbVar4[0x20] & 7) == 0) {
      pcVar3 = expr_build_member_access_implicit(g_current_scope,*(void **)(pbVar4 + 8));
      if (pcVar3 == (c1_u8 *)0x0) {
        pbVar4 = (byte *)0x0;
      }
      else {
        pbVar4 = *(byte **)pcVar3;
        if (*(int *)(pcVar3 + 4) != 0) {
          bVar7 = *(char *)(*(int *)(pcVar3 + 4) + 8) == -6;
          goto LAB_1041b5e5;
        }
      }
      bVar7 = false;
    }
LAB_1041b5e5:
    if (pbVar4 != (byte *)0x0) {
      if ((*pbVar4 & 0x1f) == 0x12) {
        pbVar4 = *(byte **)(**(int **)(pbVar4 + 0x14) + 8);
      }
      if ((((pbVar4[0x20] & 7) == 7) && ((**(ushort **)(pbVar4 + 0x14) & 0x300) != 0)) &&
         ((pbVar2 = *(byte **)(*(ushort **)(pbVar4 + 0x14) + 4), (*pbVar2 & 0x1f) == 4 &&
          (*(int *)(pbVar2 + 8) == *(int *)(base + 8))))) {
        if (!bVar7) {
          diag_warning(4,0x61,0x53,pbVar4,0x53,pbVar2);
        }
        goto LAB_1041b591;
      }
    }
LAB_1041b606:
    piVar6 = (int *)(*piVar6 + 0x14);
    iVar1 = *piVar6;
  } while( true );
}

