c1_node * __cdecl expr_build_address_of(c1_node *operand,uint mode)

{
  char cVar1;
  ushort uVar2;
  void *pvVar3;
  c1_type *pcVar4;
  ushort uVar5;
  c1_node *pcVar6;
  c1_symbol *pcVar7;
  c1_type *pcVar8;
  uint uVar9;
  int iVar10;
  
  if ((operand->kind & 7) == 3) {
    diag_error(0x65,0x31);
    return operand;
  }
  pcVar8 = operand->type;
  if ((pcVar8->code & 0x83) == 0x81) {
    pcVar8 = type_pointer_to_function(pcVar8);
  }
  if ((((byte)pcVar8->code & 0x8f) == 0x86) && (pcVar8->code == 0x4086)) {
    pcVar8 = type_member_pointer_to_3(pcVar8,2);
    operand->type = pcVar8;
    if (((char)pcVar8->code < '\0') &&
       (*(int *)((-(uint)((pcVar8->code & 0x80) != 0) & (uint)pcVar8) + 4) != 0)) {
      cVar1 = (char)pcVar8->code;
      pcVar4 = pcVar8;
      while (cVar1 < '\0') {
        pcVar4 = pcVar4->base;
        cVar1 = (char)pcVar4->code;
      }
      if ((pcVar4->flags & 7) != 5) {
        cVar1 = (char)pcVar8->code;
        pcVar4 = pcVar8;
        while (cVar1 < '\0') {
          pcVar4 = pcVar4->base;
          cVar1 = (char)pcVar4->code;
        }
        if ((pcVar4->flags & 7) != 3) {
          return operand;
        }
      }
      if (((*(ushort *)(*(int *)(((uint)pcVar8 & -(uint)((pcVar8->code & 0x80) != 0)) + 4) + 2) &
           0x2000) != 0) && (iVar10 = (*g_idb->vtbl->idb_note_predefined_macro)(g_idb), iVar10 == 0)
         ) {
        diag_fatal(0x49,".\\trees.c",0xef4);
      }
    }
    return operand;
  }
  pcVar6 = expr_warn_cast_on_lvalue(operand,mode);
  if (pcVar6 == (c1_node *)0x0) {
    uVar2 = operand->type->code;
    uVar5 = uVar2 & 0x8f;
    if (uVar5 != 0x83) {
      if ((uVar5 != 0x86) && ((-1 < (char)uVar2 || (uVar5 != 0x84)))) {
        if ((mode & 2) != 0) {
          return operand;
        }
        diag_error(0x66,0x31);
        return (c1_node *)0x0;
      }
      if (uVar2 == 0x8086) {
        diag_error(0x66,0x31);
      }
      return operand;
    }
    pcVar6 = operand;
    if ((operand->kind & 7) == 5) {
      return operand;
    }
  }
  if ((pcVar6->kind & 7) == 4) {
    pvVar3 = pcVar6->left;
    *(byte *)((int)pvVar3 + 4) = *(byte *)((int)pvVar3 + 4) | 8;
    if (((mode & 4) != 0) &&
       (uVar9 = CONCAT31((int3)((uint)pvVar3 >> 8),*(undefined1 *)((int)pvVar3 + 0x20)) & 0xffffff07
       , 4 < (byte)uVar9)) {
      pcVar6 = expr_report_register_address_2(uVar9,pcVar6,pcVar8);
      return pcVar6;
    }
  }
  else {
    if ((pcVar6->op == '5') && ((mode & 4) != 0)) {
      diag_error(0x68,0x31);
    }
    if ((pcVar6->op == 'S') && (pvVar3 = pcVar6->left, (*(byte *)((int)pvVar3 + 1) & 7) == 3)) {
      pcVar6 = pcVar6->right;
      uVar9 = *(uint *)((int)pvVar3 + 0x10);
      iVar10 = *(int *)((int)pvVar3 + 0x14);
      pvVar3 = pcVar6->left;
      pcVar6->left = (void *)((int)pvVar3 + uVar9);
      pcVar6->right = (void *)((int)pcVar6->right + (uint)CARRY4((uint)pvVar3,uVar9) + iVar10);
      pcVar8 = type_pointer_with_qualifiers(pcVar8,0);
      pcVar6->type = pcVar8;
      return pcVar6;
    }
    pcVar7 = expr_find_base_symbol(pcVar6);
    if (pcVar7 != (c1_symbol *)0x0) {
      pcVar7->flags4 = pcVar7->flags4 | 8;
      pcVar8 = type_pointer_with_qualifiers(pcVar8,0);
      pcVar6->type = pcVar8;
      return pcVar6;
    }
    expr_find_lvalue_symbol_node(pcVar6);
  }
  pcVar8 = type_pointer_with_qualifiers(pcVar8,0);
  pcVar6->type = pcVar8;
  return pcVar6;
}

