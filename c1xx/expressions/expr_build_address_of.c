c1_node * __cdecl expr_build_address_of(c1_node *e,uint mode)

{
  c1_u16 cVar1;
  ushort uVar2;
  void *pvVar3;
  uint uVar4;
  ushort uVar5;
  c1_type *pcVar6;
  int iVar7;
  c1_node *pcVar8;
  c1_symbol *pcVar9;
  c1_node *pcVar10;
  byte storage;
  
  if ((e->kind & 7) == 3) {
    diag_error(0x65,0x31);
    return e;
  }
  pcVar6 = e->type;
  cVar1 = pcVar6->code;
  if ((cVar1 == 0x80c) || (cVar1 == 0x80e)) {
    pcVar8 = expr_build_builtin_unary(0x31,e);
    return pcVar8;
  }
  if (((byte)cVar1 & 0x83) == 0x81) {
    if ((mode & 0x10) != 0) {
      pcVar6 = type_as_function_code(pcVar6);
    }
    pcVar6 = type_member_pointer_to_2(pcVar6,'\x01');
  }
  if ((((byte)pcVar6->code & 0x8f) == 0x86) && (pcVar6->code == 0x4086)) {
    pcVar6 = type_member_pointer_to_3(pcVar6,2);
    e->type = pcVar6;
    return e;
  }
  iVar7 = expr_is_adjusted_this(e);
  if ((char)iVar7 != '\0') {
    pcVar8 = expr_new_shared_temporary(e);
    return pcVar8;
  }
  pcVar8 = expr_lvalue_address(e,mode);
  if (pcVar8 == (c1_node *)0x0) {
    uVar2 = e->type->code;
    uVar5 = uVar2 & 0x8f;
    if (uVar5 != 0x83) {
      if ((uVar5 != 0x86) && ((-1 < (char)uVar2 || (uVar5 != 0x84)))) {
        if ((mode & 2) != 0) {
          return e;
        }
        diag_error(0x66,0x31);
        return (c1_node *)0x0;
      }
      if (uVar2 == 0x8086) {
        diag_error(0x66,0x31);
      }
      return e;
    }
    pcVar8 = e;
    if ((e->kind & 7) == 5) {
      pcVar8 = expr_build_address_of_tail(e);
      return pcVar8;
    }
  }
  if (((pcVar8->kind & 7) == 4) && (pcVar8->op != 0x9c)) {
    pcVar9 = pcVar8->left;
    if ((pcVar9->kind & 0x1f) == 0x17) {
      diag_error(0x37b,pcVar9);
      return pcVar8;
    }
    if ((mode & 4) != 0) {
      pcVar9->flags5 = pcVar9->flags5 | 8;
    }
    storage = pcVar9->storage & 7;
    if (4 < storage) {
      pcVar8 = expr_build_address_of_retype(storage,pcVar9,pcVar8,pcVar6);
      return pcVar8;
    }
  }
  else {
    if ((pcVar8->op == '5') && ((mode & 4) != 0)) {
      diag_error(0x68,0x31);
    }
    if ((pcVar8->op == 'S') && (pvVar3 = pcVar8->left, (*(byte *)((int)pvVar3 + 1) & 7) == 3)) {
      pcVar8 = pcVar8->right;
      uVar4 = *(uint *)((int)pvVar3 + 0x10);
      iVar7 = *(int *)((int)pvVar3 + 0x14);
      pvVar3 = pcVar8->left;
      pcVar8->left = (void *)((int)pvVar3 + uVar4);
      pcVar8->right = (void *)((int)pcVar8->right + (uint)CARRY4((uint)pvVar3,uVar4) + iVar7);
    }
    else {
      pcVar9 = expr_find_base_symbol(pcVar8);
      if (pcVar9 == (c1_symbol *)0x0) {
        pcVar10 = expr_find_lvalue_symbol_node(pcVar8);
        if (((pcVar10 == (c1_node *)0x0) && (((byte)g_compile_flags_c8 & 4) != 0)) &&
           (pcVar8->op == 'p')) {
          pcVar8 = expr_check_lvalue(pcVar8,pcVar6);
          return pcVar8;
        }
      }
      else {
        pcVar9->flags5 = pcVar9->flags5 | 8;
      }
    }
  }
  pcVar6 = type_pointer_with_qualifiers(pcVar6,0);
  pcVar8->type = pcVar6;
  if (((byte)g_compile_flags_c8 & 4) != 0) {
    pcVar8->kind = pcVar8->kind | 0x20;
  }
  return pcVar8;
}

