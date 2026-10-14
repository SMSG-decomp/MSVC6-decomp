uint32_t modrm_mod_for_operand(c2_operand *opnd,int *disp_size)

{
  uint32_t uVar1;
  c2_symbol *pcVar2;
  int iVar3;
  
  uVar1 = opnd->op;
  if (uVar1 == 0x14a) {
    pcVar2 = opnd->sym;
  }
  else {
    pcVar2 = opnd->base_sym;
  }
  if (pcVar2 == (c2_symbol *)0x0) {
    iVar3 = opnd->disp;
    if ((iVar3 == 0) && (((opnd->base->u18).reg)->id != 6)) {
      *disp_size = 0;
      return g_modrm_mod_by_disp_size[0];
    }
  }
  else {
    if (uVar1 == 0x14a) {
      iVar3 = fits_signed_imm8(pcVar2->offset - opnd->rank);
      iVar3 = (-(uint)(iVar3 != 0) & 0xfffffffd) + 4;
      *disp_size = iVar3;
      return g_modrm_mod_by_disp_size[iVar3];
    }
    if (uVar1 != 0x14e) {
      *disp_size = 4;
      return g_modrm_mod_by_disp_size[*disp_size];
    }
    iVar3 = (pcVar2->offset - opnd->rank) + opnd->disp;
  }
  iVar3 = fits_signed_imm8(iVar3);
  iVar3 = (-(uint)(iVar3 != 0) & 0xfffffffd) + 4;
  *disp_size = iVar3;
  return g_modrm_mod_by_disp_size[iVar3];
}

