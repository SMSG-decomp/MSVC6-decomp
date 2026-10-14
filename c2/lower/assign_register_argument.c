int __fastcall
assign_register_argument
          (c2_function *fn,uint32_t *used_regs,c2_operand *op,int conv,int is_callee_param)

{
  ushort uVar1;
  ushort uVar2;
  c2_tuple *pcVar3;
  uint32_t uVar4;
  c2_fe_symbol *pcVar5;
  int iVar6;
  c2_symbol *pcVar7;
  uint32_t *arg_regs;
  int iVar8;
  uint32_t *arg_reg;
  
  if (is_callee_param == 0) {
    if (op->kind != '\x01') {
      return 0;
    }
    if (op->sym->cls != '\x03') {
      return 0;
    }
    pcVar3 = op->sym->def;
    if (pcVar3 == (c2_tuple *)0x0) {
      return 0;
    }
    if ((pcVar3->op != 0x15a) && (pcVar3->op != 0x16a)) {
      return 0;
    }
    if (((pcVar3->src->kind == '\x03') &&
        (pcVar5 = pcVar3->src->sym->fe, pcVar5 != (c2_fe_symbol *)0x0)) &&
       ((pcVar5->storage & 0x40000) != 0)) {
      return 0;
    }
  }
  else if (op->sym->storage->fe == fn->struct_return) {
    return 0;
  }
  uVar1 = op->type;
  if (uVar1 < 0x2003) {
    if (uVar1 < 0x2001) {
      if (uVar1 < 0x1001) {
        return 0;
      }
      if ((0x1002 < uVar1) && (uVar1 != 0x1004)) {
        return 0;
      }
    }
  }
  else if (uVar1 != 0x2004) {
    return 0;
  }
  if ((conv == 4) || (conv == 0x18)) {
    arg_regs = g_fastcall_arg_regs;
    iVar8 = 2;
  }
  else {
    arg_regs = g_thiscall_arg_regs;
    iVar8 = 1;
  }
  iVar6 = 0;
  if (iVar8 == 0) {
    return 0;
  }
  arg_reg = arg_regs;
  do {
    if ((*used_regs & 1 << ((byte)*arg_reg & 0x1f)) == 0) {
      uVar4 = arg_regs[iVar6];
      *used_regs = 1 << ((byte)uVar4 & 0x1f) | *used_regs;
      if (((is_callee_param == 0) ||
          (pcVar7 = op->sym->storage, uVar2 = pcVar7->type, pcVar7 == op->sym)) ||
         ((1 << (byte)(uVar2 >> 0xc) & 0xeU) == 0)) {
        uVar2 = uVar1;
      }
      if (((op->kind == '\x01') && (op->sym->cls == '\x03')) &&
         (pcVar3 = op->sym->def, pcVar3 != (c2_tuple *)0x0)) {
        pcVar7 = reg_find_subreg(g_reg_symbols + uVar4,(uVar2 & 0xfff) << 3,0);
        (pcVar3->dst->u18).reg = pcVar7;
      }
      pcVar7 = reg_find_subreg(g_reg_symbols + uVar4,(uVar2 & 0xfff) << 3,0);
      set_operand_home(op,pcVar7);
      return 1;
    }
    iVar6 = iVar6 + 1;
    arg_reg = arg_reg + 1;
  } while (iVar6 < iVar8);
  return 0;
}

