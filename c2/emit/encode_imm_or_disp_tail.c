uint8_t encode_imm_or_disp_tail
                  (c2_operand *opnd,int nbytes,int32_t value,int fixup_offset,int nbytes_slot,
                  uint32_t operand_op,uint8_t s_bit,int allow_sign_extend)

{
  c2_symbol *pcVar1;
  uint uVar2;
  int iVar3;
  uint32_t value_00;
  c2_fe_symbol *target;
  
  pcVar1 = opnd->base_sym;
  value_00 = value + opnd->disp;
  if (pcVar1 == (c2_symbol *)0x0) {
    target = (c2_fe_symbol *)0x0;
  }
  else {
    target = pcVar1->storage->fe;
    value_00 = value_00 + (pcVar1->offset - pcVar1->storage->offset);
    if (((target != (c2_fe_symbol *)0x0) && (target->cls == '\x01')) &&
       ((uVar2 = target->storage & 0x70, uVar2 == 0x10 || (uVar2 == 0x30)))) {
      value_00 = value_00 + target->offset;
    }
  }
  if (g_encode_emit_relocs == 0) goto LAB_10735dab;
  if (((target == (c2_fe_symbol *)0x0) ||
      ((target->cls == '\x01' &&
       ((uVar2 = target->storage & 0x70, uVar2 == 0x10 || (uVar2 == 0x30)))))) || (nbytes < 2)) {
    if ((operand_op != 0x150) || (target = g_cur_func_sym, opnd->base_sym != (c2_symbol *)0x0))
    goto LAB_10735dab;
  }
  else {
    if (nbytes != 6) {
      switch(operand_op) {
      case 0x151:
        (*g_writer_reloc_type9_hook)(fixup_offset,target);
        nbytes = nbytes_slot;
        break;
      default:
        goto LAB_10735e51;
      case 0x154:
      case 0x155:
        (*g_hook_add_reloc_rel32)(fixup_offset,target);
        nbytes = nbytes_slot;
      }
      goto LAB_10735dab;
    }
    (*g_writer_reloc_type9_hook)(fixup_offset,target);
    fixup_offset = fixup_offset + 2;
  }
LAB_10735e51:
  (*g_hook_add_reloc_dir32)(fixup_offset,target);
  nbytes = nbytes_slot;
LAB_10735dab:
  if ((((allow_sign_extend == 0) || (nbytes < 2)) || (operand_op != 0x146)) ||
     (iVar3 = fits_signed_imm8(value_00), nbytes = nbytes_slot, iVar3 == 0)) {
    nbytes_slot = nbytes;
    if (nbytes == 6) {
      emit_value_bytes(0,2);
      nbytes_slot = 4;
    }
  }
  else {
    nbytes_slot = 1;
    s_bit = '\x02';
  }
  emit_value_bytes(value_00,nbytes_slot);
  return s_bit;
}

