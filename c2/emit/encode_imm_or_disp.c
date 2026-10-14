uint8_t __fastcall encode_imm_or_disp(c2_operand *opnd,int nbytes,int allow_sign_extend)

{
  int32_t *piVar1;
  c2_symbol *pcVar2;
  uint8_t uVar3;
  uint uVar4;
  int iVar5;
  uint32_t value;
  c2_fe_symbol *target;
  uint32_t operand_op;
  uint8_t uVar6;
  
  operand_op = opnd->op;
  iVar5 = (int)g_encode_cursor - (int)g_encode_buffer;
  uVar3 = '\0';
  uVar6 = '\0';
  switch(operand_op) {
  case 0x146:
    value = (opnd->u18).lo;
    target = (c2_fe_symbol *)0x0;
    break;
  default:
    value = opnd->disp;
    pcVar2 = opnd->base_sym;
    if (pcVar2 == (c2_symbol *)0x0) {
LAB_10735da0:
      target = (c2_fe_symbol *)0x0;
    }
    else {
      target = pcVar2->storage->fe;
      value = value + (pcVar2->offset - pcVar2->storage->offset);
      if (((target != (c2_fe_symbol *)0x0) && (target->cls == '\x01')) &&
         ((uVar4 = target->storage & 0x70, uVar4 == 0x10 || (uVar4 == 0x30)))) {
        value = value + target->offset;
      }
    }
    break;
  case 0x14a:
    emit_value_bytes(opnd->sym->offset - opnd->rank,nbytes);
    return '\0';
  case 0x14b:
    pcVar2 = opnd->sym->storage;
    target = pcVar2->fe;
    value = opnd->sym->offset - pcVar2->offset;
    break;
  case 0x14e:
    emit_value_bytes((opnd->base_sym->offset - opnd->rank) + opnd->disp,nbytes);
    return '\0';
  case 0x150:
    if (nbytes != 4) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\code.c",0x453);
    }
    if (opnd->base_sym == (c2_symbol *)0x0) {
      uVar3 = encode_imm_or_disp_tail
                        (opnd,4,g_encode_insn_offset - g_cur_func_sym->offset,iVar5,4,operand_op,
                         '\0',allow_sign_extend);
      return uVar3;
    }
    uVar3 = encode_imm_or_disp_tail(opnd,4,0,iVar5,4,operand_op,'\0',allow_sign_extend);
    return uVar3;
  case 0x153:
  case 0x154:
    target = (c2_fe_symbol *)opnd->sym;
    if ((operand_op != 0x153) && (target->cls != '\x04')) {
      value = (int)target->offset + ((-iVar5 - g_encode_insn_offset) - nbytes);
      goto LAB_10735da0;
    }
    value = 0;
    break;
  case 0x155:
    target = opnd->base_sym->fe;
    if (target->cls == '\x04') {
      value = opnd->disp;
    }
    else {
      piVar1 = &target->offset;
      target = (c2_fe_symbol *)0x0;
      value = (((*piVar1 + opnd->disp) - g_encode_insn_offset) - iVar5) - nbytes;
    }
    break;
  case 0x156:
    target = (c2_fe_symbol *)0x0;
    value = (opnd->disp - iVar5) - nbytes;
  }
  if (g_encode_emit_relocs == 0) goto LAB_10735dab;
  if (((target == (c2_fe_symbol *)0x0) ||
      ((target->cls == '\x01' &&
       ((uVar4 = target->storage & 0x70, uVar4 == 0x10 || (uVar4 == 0x30)))))) || (nbytes < 2)) {
    if ((operand_op != 0x150) ||
       (target = g_cur_func_sym, uVar3 = '\0', opnd->base_sym != (c2_symbol *)0x0))
    goto LAB_10735dab;
  }
  else {
    if (nbytes != 6) {
      uVar6 = '\0';
      switch(operand_op) {
      case 0x151:
        (*g_writer_reloc_type9_hook)(iVar5,target);
        break;
      default:
        uVar3 = '\0';
        goto LAB_10735e51;
      case 0x154:
      case 0x155:
        (*g_hook_add_reloc_rel32)(iVar5,target);
      }
      goto LAB_10735dab;
    }
    (*g_writer_reloc_type9_hook)(iVar5,target);
    iVar5 = iVar5 + 2;
  }
LAB_10735e51:
  uVar6 = uVar3;
  (*g_hook_add_reloc_dir32)(iVar5,target);
LAB_10735dab:
  if ((((allow_sign_extend == 0) || (nbytes < 2)) || (operand_op != 0x146)) ||
     (iVar5 = fits_signed_imm8(value), iVar5 == 0)) {
    if (nbytes == 6) {
      emit_value_bytes(0,2);
      nbytes = 4;
    }
  }
  else {
    nbytes = 1;
    uVar6 = '\x02';
  }
  emit_value_bytes(value,nbytes);
  return uVar6;
}

