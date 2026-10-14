int __cdecl ovl_count_builtin_operator_candidates(char *rows,c1_node *left,c1_node *right)

{
  char *pcVar1;
  char cVar2;
  char cVar3;
  c1_type *pcVar4;
  ushort *puVar5;
  byte bVar6;
  ushort uVar7;
  c1_symbol *pcVar8;
  int iVar9;
  int iVar10;
  c1_type *pcVar11;
  int iVar12;
  
  pcVar4 = left->type;
  iVar10 = 0;
  if (right == (c1_node *)0x0) {
    pcVar11 = (c1_type *)0x0;
  }
  else {
    pcVar11 = right->type;
  }
  if (rows == (char *)0x0) {
    return 0;
  }
  cVar2 = *rows;
  do {
    if ((right != (c1_node *)0x0) == (*(int *)(rows + 8) != 0)) {
      if ((pcVar4->code & 0x200) == 0) {
        bVar6 = (byte)pcVar4->code;
        if ((((char)bVar6 < '\0') && ((bVar6 & 0x8f) == 0x80)) &&
           ((pcVar4->base->code & 0x200) != 0)) {
          pcVar8 = (pcVar4->base->extra).cls;
          goto LAB_1041641b;
        }
        iVar12 = 1;
      }
      else {
        pcVar8 = (pcVar4->extra).cls;
LAB_1041641b:
        uVar7 = counted_array_count(&((pcVar8->detail).cls)->conversion_functions->count);
        iVar12 = (int)(short)uVar7;
      }
      if (pcVar11 == (c1_type *)0x0) {
LAB_10416457:
        iVar9 = 1;
      }
      else {
        if ((pcVar11->code & 0x200) == 0) {
          bVar6 = (byte)pcVar11->code;
          if (((-1 < (char)bVar6) || ((bVar6 & 0x8f) != 0x80)) ||
             ((pcVar11->base->code & 0x200) == 0)) goto LAB_10416457;
          pcVar8 = (pcVar11->base->extra).cls;
        }
        else {
          pcVar8 = (pcVar11->extra).cls;
        }
        uVar7 = counted_array_count(&((pcVar8->detail).cls)->conversion_functions->count);
        iVar9 = (int)(short)uVar7;
      }
      if (pcVar11 == (c1_type *)0x0) {
        iVar10 = iVar10 + iVar12;
      }
      else {
        puVar5 = *(ushort **)(rows + 8);
        cVar3 = (char)*puVar5;
        while (cVar3 < '\0') {
          puVar5 = *(ushort **)(puVar5 + 2);
          cVar3 = (char)*puVar5;
        }
        if ((*puVar5 & 0xfff) == 0x809) {
          iVar9 = iVar9 + iVar12;
        }
        else {
          iVar9 = iVar9 * iVar12;
        }
        iVar10 = iVar10 + iVar9;
      }
    }
    pcVar1 = rows + 0x14;
    rows = rows + 0x14;
    if (*pcVar1 != cVar2) {
      return iVar10;
    }
  } while( true );
}

