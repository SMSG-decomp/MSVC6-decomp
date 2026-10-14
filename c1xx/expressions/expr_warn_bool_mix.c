byte __cdecl expr_warn_bool_mix(c1_node *left,c1_node *right,byte op)

{
  byte bVar1;
  c1_type *pcVar2;
  uint uVar3;
  c1_node *pcVar4;
  c1_node *pcVar5;
  byte local_5;
  
  uVar3 = (uint)op;
  local_5 = 0;
  switch(uVar3) {
  case 0x31:
  case 0x33:
  case 0x4d:
  case 0x4e:
  case 0x5b:
  case 0x5c:
    pcVar4 = right;
    pcVar5 = left;
    if (((right->type->code & 0xfff) == 0x10) &&
       (pcVar4 = left, pcVar5 = right, (left->type->code & 0xfff) == 0x10)) {
      return 1;
    }
    bVar1 = pcVar4->flags;
    if ((bVar1 & 1) != 0) {
      return 1;
    }
    if ((pcVar5->kind & 7) == 3) {
      if (op == 0x31) {
        return 1;
      }
      if (op != 0x33) {
        return 0;
      }
      if ((bVar1 & 4) != 0) {
        return 0;
      }
      return 1;
    }
    if ((pcVar4->kind & 7) == 3) {
      if (pcVar4->left == (void *)0x0 && pcVar4->right == (void *)0x0) {
        return 1;
      }
      if ((pcVar4->left == (void *)0x1) && (pcVar4->right == (void *)0x0)) {
        return 1;
      }
      diag_warning(1,0x326,uVar3,pcVar5->type,pcVar4->type);
      return 0;
    }
    if ((bVar1 & 4) != 0) {
      if (op != 0x31) {
        return 0;
      }
      return 1;
    }
    if ((g_op_flags_table[pcVar5->op] & 1) != 0) {
      return 0;
    }
    diag_warning(1,0x325,uVar3,left->type,right->type);
    return 0;
  default:
    goto switchD_10419b7c_caseD_32;
  case 0x34:
    if ((left->type->code & 0xfff) == 0x10) {
      return 1;
    }
    if (((left->flags & 4) != 0) && ((left->flags & 1) == 0)) {
      return 0;
    }
    return 1;
  case 0x39:
  case 0x3a:
  case 0x42:
  case 0x48:
  case 0x49:
  case 0x57:
    break;
  case 0x3b:
  case 0x4c:
    pcVar4 = right;
    pcVar5 = left;
    if (((right->type->code & 0xfff) == 0x10) &&
       (pcVar4 = left, pcVar5 = right, (left->type->code & 0xfff) == 0x10)) {
      return 1;
    }
    if ((pcVar4->flags & 1) != 0) {
      return 1;
    }
    pcVar2 = pcVar4->type;
    if (((byte)pcVar2->code >> 5 & 1) == 0) {
      if (((pcVar5->kind & 7) == 3) && (pcVar5->left == (void *)0x0 && pcVar5->right == (void *)0x0)
         ) {
        return 1;
      }
      if ((pcVar4->kind & 7) == 3) {
        if (pcVar4->left == (void *)0x0 && pcVar4->right == (void *)0x0) {
          return 1;
        }
        if ((pcVar4->left == (void *)0x1) && (pcVar4->right == (void *)0x0)) {
          return 1;
        }
        diag_warning(1,0x326,uVar3,pcVar5->type,pcVar2);
        return 1;
      }
      if ((pcVar4->flags & 4) != 0) {
        diag_warning(1,0x327,uVar3,pcVar5->type,pcVar2);
        return 1;
      }
      if ((g_op_flags_table[pcVar5->op] & 1) != 0) {
        return 1;
      }
    }
    diag_warning(1,0x325,uVar3,left->type,right->type);
    return 1;
  case 0x3e:
  case 0x3f:
  case 0x44:
  case 0x45:
    local_5 = 1;
    if (((left->type->code & 0xfff) == 0x10) && ((right->type->code & 0xfff) == 0x10)) {
      return 1;
    }
    break;
  case 0x43:
  case 0x58:
    goto LAB_1047ff2f;
  case 0x47:
  case 0x4b:
  case 0x52:
    right = left;
LAB_1047ff2f:
    if ((right->type->code & 0xfff) != 0x10) {
      return 0;
    }
  }
  diag_warning(1,0x324,uVar3);
switchD_10419b7c_caseD_32:
  return local_5;
}

