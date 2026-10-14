int __fastcall fpo_frame_reference_count_ok(c2_function *fn,int nlocals)

{
  c2_tuple *pcVar1;
  uint uVar2;
  c2_operand *pcVar3;
  uint32_t uVar4;
  int iVar5;
  
  iVar5 = 0;
  pcVar1 = fn->cfg->first->head;
  do {
    if (pcVar1 == (c2_tuple *)0x0) {
      return 1;
    }
    if (((((pcVar1->flags & 1) != 0) && (pcVar1->kind != '\x13')) &&
        (uVar2 = pcVar1->op, uVar2 != 0x1a0)) && ((uVar2 != 0x19e && (uVar2 != 0x1a4)))) {
      if ((uVar2 == 0) || ((0x143 < uVar2 || ((g_x86_op_flags[uVar2] & 0x800) != 0)))) {
        if ((pcVar1->dst != (c2_operand *)0x0) &&
           ((uVar4 = pcVar1->dst->op, uVar4 == 0x14a || (uVar4 == 0x14e)))) {
          iVar5 = iVar5 + 1;
        }
        uVar4 = pcVar1->src->op;
joined_r0x1076b67f:
        if ((uVar4 == 0x14a) || (uVar4 == 0x14e)) {
          iVar5 = iVar5 + 1;
        }
      }
      else {
        pcVar3 = pcVar1->src;
        if (pcVar3 != (c2_operand *)0x0) {
          if ((pcVar3->op == 0x14a) || (pcVar3->op == 0x14e)) {
            iVar5 = iVar5 + 1;
          }
          if (pcVar3->next != (c2_operand *)0x0) {
            uVar4 = pcVar3->next->op;
            goto joined_r0x1076b67f;
          }
        }
      }
      if ((int)((-(uint)(nlocals != 0) & 0xfffffffd) + 4) < iVar5) {
        return 0;
      }
    }
    pcVar1 = pcVar1->next;
  } while( true );
}

