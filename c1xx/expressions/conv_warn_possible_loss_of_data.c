void __cdecl conv_warn_possible_loss_of_data(uint op,c1_node *e,c1_type *target)

{
  ushort uVar1;
  ushort uVar2;
  c1_type *t;
  bool bVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint op_00;
  void *const_lo;
  void *const_hi;
  
  if (g_warning_state->level < 2) {
    return;
  }
  uVar1 = target->code;
  if ((uVar1 & 0x30) == 0) {
    return;
  }
  op_00 = op & 0xff;
  switch(op_00) {
  case 0x34:
  case 0x3a:
  case 0x47:
  case 0x4b:
  case 0x52:
  case 0x70:
  case 0x74:
  case 0x7d:
    break;
  default:
    return;
  }
  if (e == (c1_node *)0x0) {
    return;
  }
  t = e->type;
  uVar2 = t->code;
  if ((uVar2 & 0x30) == 0) {
    return;
  }
  bVar3 = false;
  if (((byte)uVar2 >> 5 & 1) == 0) {
    if (((byte)uVar1 >> 5 & 1) == 0) {
      if ((e->kind & 7) == 3) {
        const_lo = e->left;
        const_hi = e->right;
        if ((((((uVar1 & 0x2000) != 0) ||
              ((((uVar1 & 0xfff) == 0x11 && ((uVar1 & 0x1000) == 0)) &&
               (g_opt_J_unsigned_char != '\0')))) && ((uVar2 & 0x2000) == 0)) &&
            ((((uVar2 & 0xfff) != 0x11 || ((uVar2 & 0x1000) != 0)) ||
             (g_opt_J_unsigned_char == '\0')))) && (((int)const_hi < 1 && ((int)const_hi < 0)))) {
          diag_warning(4,0xf5,op_00,t,target);
        }
        uVar1 = target->code;
        uVar2 = t->code;
        if (uVar1 == uVar2) {
          return;
        }
        if ((uVar2 & 0x2000) == 0) {
          if ((((uVar2 & 0xfff) == 0x11) && ((uVar2 & 0x1000) == 0)) &&
             (g_opt_J_unsigned_char != '\0')) {
            conv_warn_possible_loss_of_data_fragment_ecx
                      (uVar1,g_opt_J_unsigned_char,(uint)const_hi,(uint)const_lo,target,op_00,t);
            return;
          }
          iVar8 = 0;
        }
        else {
          iVar8 = 1;
        }
        if ((uVar1 & 0x2000) == 0) {
          if ((((uVar1 & 0xfff) == 0x11) && ((uVar1 & 0x1000) == 0)) &&
             (g_opt_J_unsigned_char != '\0')) {
            conv_warn_possible_loss_of_data_fragment_eax
                      (iVar8,(uint)const_hi,(uint)const_lo,target,op_00,t);
            return;
          }
          iVar7 = 0;
        }
        else {
          iVar7 = 1;
        }
        uVar5 = type_size_scalar(target);
        iVar8 = conv_constant_out_of_range(uVar5,iVar7,iVar8,(uint)const_lo,(uint)const_hi);
        if (iVar8 == 0) {
          return;
        }
        diag_warning(2,0x131,op_00,t,target);
        return;
      }
      uVar5 = type_size_scalar(t);
      uVar6 = type_size_scalar(target);
      if (uVar5 <= uVar6) {
        return;
      }
      if ((((t->code & 0x110) != 0) && ((e->op == 'p' || (e->op == '=')))) &&
         (bVar4 = diag_warning(3,0xf2,op_00,t,target), bVar4 != 0)) {
        bVar3 = true;
      }
      if ((((byte)t->code & 0x1f) == 0x13) || (iVar8 = 3, (t->code & 0x100) != 0)) {
        iVar8 = 4;
      }
      if (bVar3) {
        return;
      }
      goto LAB_104961f9;
    }
    uVar5 = type_size_scalar(t);
    uVar6 = type_size_scalar(target);
    if (uVar5 < uVar6) {
      return;
    }
    if ((e->kind & 7) == 3) {
      conv_warn_float_truncation_1(op,e,target,(c1xx_float_const *)0x0,'\x01');
      return;
    }
  }
  else if (((byte)uVar1 >> 4 & 1) == 0) {
    if ((e->kind & 7) == 3) {
      conv_warn_float_truncation_2((byte)op,e,target);
      return;
    }
    uVar5 = type_size_scalar(t);
    uVar6 = type_size_scalar(target);
    if (uVar6 < uVar5) {
      iVar8 = 3;
    }
    else {
      iVar8 = type_size_scalar(t);
      iVar7 = type_size_scalar(target);
      if (iVar7 != iVar8) {
        return;
      }
      if ((t->code & 0x28) != 0x28) {
        return;
      }
      if ((target->code & 0x28) == 0x28) {
        return;
      }
      iVar8 = 4;
    }
    goto LAB_104961f9;
  }
  iVar8 = 2;
LAB_104961f9:
  diag_warning(iVar8,0xf4,op_00,t,target);
  return;
}

