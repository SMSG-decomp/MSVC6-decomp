void __fastcall
shrink_wrap_place_saves(c2_function *fn,c2_callee_save_site **saves,c2_callee_save_site **restores)

{
  c2_block **ppcVar1;
  c2_block *block;
  c2_bitset *pcVar2;
  c2_edge *pcVar3;
  uint uVar4;
  c2_callee_save_site **ppcVar5;
  uint uVar6;
  int iVar7;
  c2_block *pcVar8;
  c2_block *block_00;
  c2_edge *pcVar9;
  uint local_10;
  uint local_c;
  
  block = fn->cfg->first;
  do {
    if (block == (c2_block *)0x0) {
      return;
    }
    pcVar3 = block->preds;
    uVar4 = 0;
    local_c = 0;
    if (pcVar3 == (c2_edge *)0x0) {
      local_10 = 0;
LAB_107364f6:
      iVar7 = 4;
      ppcVar5 = saves + 4;
    }
    else {
      uVar6 = 0xffffffff;
      local_10 = 0xffffffff;
      if (pcVar3 == (c2_edge *)0x0) goto LAB_107364f6;
      do {
        ppcVar1 = &pcVar3->from;
        pcVar3 = pcVar3->next_pred;
        pcVar2 = (*ppcVar1)->de;
        uVar4 = uVar4 | (uint)pcVar2;
        uVar6 = uVar6 & (uint)pcVar2;
      } while (pcVar3 != (c2_edge *)0x0);
      iVar7 = 4;
      ppcVar5 = saves + 4;
      local_10 = uVar6;
      local_c = uVar4;
    }
    do {
      uVar4 = 1 << ((byte)iVar7 & 0x1f);
      if ((((uint)block->de & uVar4) != 0) && ((local_10 & uVar4) == 0)) {
        if ((local_c & uVar4) == 0) {
          prolog_note_saved_reg(ppcVar5,iVar7,block,(c2_edge *)0x0,"save");
        }
        else {
          for (pcVar3 = block->preds; pcVar3 != (c2_edge *)0x0; pcVar3 = pcVar3->next_pred) {
            pcVar8 = pcVar3->from;
            if (((uint)pcVar8->de & uVar4) == 0) {
              if ((pcVar8->succs == (c2_edge *)0x0) || (pcVar8->succs->next_succ != (c2_edge *)0x0))
              {
                pcVar9 = pcVar3;
                if ((int)pcVar8->rpo != pcVar3->to->rpo + -1) {
                  pcVar8 = (c2_block *)0x0;
                }
              }
              else {
                pcVar9 = (c2_edge *)0x0;
              }
              prolog_note_saved_reg(ppcVar5,iVar7,pcVar8,pcVar9,"save");
            }
          }
        }
      }
      iVar7 = iVar7 + 1;
      ppcVar5 = ppcVar5 + 1;
    } while (iVar7 < 9);
    pcVar3 = block->succs;
    uVar4 = 0;
    local_c = 0;
    if (pcVar3 == (c2_edge *)0x0) {
      local_10 = 0;
LAB_107365dc:
      iVar7 = 4;
      ppcVar5 = restores + 4;
    }
    else {
      uVar6 = 0xffffffff;
      local_10 = 0xffffffff;
      if (pcVar3 == (c2_edge *)0x0) goto LAB_107365dc;
      do {
        ppcVar1 = &pcVar3->to;
        pcVar3 = pcVar3->next_succ;
        pcVar2 = (*ppcVar1)->de;
        uVar4 = uVar4 | (uint)pcVar2;
        uVar6 = uVar6 & (uint)pcVar2;
      } while (pcVar3 != (c2_edge *)0x0);
      iVar7 = 4;
      ppcVar5 = restores + 4;
      local_10 = uVar6;
      local_c = uVar4;
    }
    do {
      uVar4 = 1 << ((byte)iVar7 & 0x1f);
      if ((((uint)block->de & uVar4) != 0) && ((local_10 & uVar4) == 0)) {
        if ((local_c & uVar4) == 0) {
          prolog_note_saved_reg(ppcVar5,iVar7,block,(c2_edge *)0x0,"restore");
        }
        else {
          for (pcVar3 = block->succs; pcVar3 != (c2_edge *)0x0; pcVar3 = pcVar3->next_succ) {
            pcVar8 = pcVar3->to;
            if (((uint)pcVar8->de & uVar4) == 0) {
              if ((pcVar8->preds == (c2_edge *)0x0) || (pcVar8->preds->next_pred != (c2_edge *)0x0))
              {
                block_00 = pcVar3->from;
                pcVar9 = pcVar3;
                if ((int)block_00->rpo != pcVar8->rpo + -1) {
                  block_00 = (c2_block *)0x0;
                }
              }
              else {
                block_00 = pcVar8;
                pcVar9 = (c2_edge *)0x0;
              }
              prolog_note_saved_reg(ppcVar5,iVar7,block_00,pcVar9,"restore");
            }
          }
        }
      }
      iVar7 = iVar7 + 1;
      ppcVar5 = ppcVar5 + 1;
    } while (iVar7 < 9);
    block = block->next;
  } while( true );
}

