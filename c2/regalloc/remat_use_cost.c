int __fastcall remat_use_cost(c2_operand *use_addr,c2_tuple *def)

{
  c2_operand *pcVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if (g_opt_favor_speed != 0) {
    return 0;
  }
  pcVar1 = def->src;
  if (pcVar1->op == 0x14e) {
    uVar3 = (uint)(use_addr->disp == 0);
    if (pcVar1->index == (c2_operand *)0x0) {
      return uVar3;
    }
    return uVar3 + 1;
  }
  if (((pcVar1->base_sym == (c2_symbol *)0x0) && (iVar4 = pcVar1->disp, -0x81 < iVar4)) &&
     (iVar4 < 0x80)) {
    if (iVar4 != 0) {
      iVar2 = use_addr->disp;
      if (iVar2 == 0) {
        iVar4 = 1;
        goto LAB_1076e3fc;
      }
      if ((-0x81 < iVar2) && (iVar2 < 0x80)) {
        if (iVar2 + iVar4 < -0x80) goto LAB_1076e43b;
        if (0x7f < iVar2 + iVar4) {
          iVar4 = 3;
          goto LAB_1076e3fc;
        }
      }
    }
  }
  else {
    iVar4 = use_addr->disp;
    if (iVar4 == 0) {
      iVar4 = 4;
      goto LAB_1076e3fc;
    }
    if ((-0x81 < iVar4) && (iVar4 < 0x80)) {
LAB_1076e43b:
      iVar4 = 3;
      goto LAB_1076e3fc;
    }
  }
  iVar4 = 0;
LAB_1076e3fc:
  if (pcVar1->index != (c2_operand *)0x0) {
    iVar4 = iVar4 + 1;
  }
  return iVar4;
}

